#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <SDL.h>
#include "display.h"
#include "vector.h"
#include "mesh.h"
#include "triangle_fill.h"  // Incluir el encabezado para utilizar fill_triangle
#include "shading.h"

// Variables globales
vec3_t cube_rotation = {0, 0, 0};
vec3_t cube_translation = {0, 0, 5};
float fov_factor = 720;

bool is_running = false;
int previous_frame_time = 0;

// Control de renderizado
bool render_triangles = true;
bool render_vertices = false;
bool render_edges = true;
bool use_perspective_projection = true;

// Prototipos
void setup(char* obj_filename);
void process_input(void);
void update(void);
void render(void);

// Configuración inicial
void setup(char* obj_filename) {
    color_buffer = (uint32_t*)malloc(sizeof(uint32_t) * window_width * window_height);
    if (!color_buffer) {
        fprintf(stderr, "Error allocating memory for frame buffer.\n");
    }

    if (obj_filename) {
        printf("Cargando modelo: %s\n", obj_filename);
        load_obj_file_data(obj_filename);
    } else {
        printf("No se proporcionó archivo .obj. Cargando cubo predeterminado.\n");
        load_cube_mesh_data();
    }
    //setup_lighting();
}

// Procesar entrada del usuario
void process_input(void) {
    SDL_Event event;
    SDL_PollEvent(&event);

    switch (event.type) {
        case SDL_QUIT:
            is_running = false;
            break;
        case SDL_KEYDOWN:
            switch (event.key.keysym.sym) {
                case SDLK_SPACE:
                    is_running = false;
                    break;
                case SDLK_f:
                    render_triangles = !render_triangles;
                    break;
                case SDLK_v:
                    render_vertices = !render_vertices;
                    break;
                case SDLK_l:
                    render_edges = !render_edges;
                    break;
                case SDLK_p:
                    use_perspective_projection = !use_perspective_projection;
                    break;
            }
            // Asegurar que al menos uno de los modos esté activo
            if (!render_triangles && !render_vertices && !render_edges) {
                render_edges = true;  // Activa aristas si todo está desactivado
            }
            break;
    }
}

// Actualizar la lógica del programa
void update(void) {
    cube_rotation.x += 0.01f;
    cube_rotation.y += 0.01f;
    cube_rotation.z += 0.01f;
}

// Renderizar el modelo
void render(void) {
    clear_color_buffer(0xFF000000); // Fondo negro

    for (int i = 0; i < array_length(mesh.faces); i++) {
        face_t face = mesh.faces[i];

        vec3_t vertices[3] = {
            mesh.vertices[face.a - 1],
            mesh.vertices[face.b - 1],
            mesh.vertices[face.c - 1],
        };

        vec2_t projected_points[3];
        vec3_t transformed_vertices[3];

        for (int j = 0; j < 3; j++) {
            vec3_t transformed_vertex = vec3_rotate_x(vertices[j], cube_rotation.x);
            transformed_vertex = vec3_rotate_y(transformed_vertex, cube_rotation.y);
            transformed_vertex = vec3_rotate_z(transformed_vertex, cube_rotation.z);
            transformed_vertex.z += cube_translation.z;

            if (use_perspective_projection) {
                projected_points[j] = (vec2_t){
                    .x = transformed_vertex.x * fov_factor / transformed_vertex.z,
                    .y = transformed_vertex.y * fov_factor / transformed_vertex.z
                };
            } else {
                projected_points[j] = (vec2_t){
                    .x = transformed_vertex.x * fov_factor,
                    .y = transformed_vertex.y * fov_factor
                };
            }
        }
        // Calcular la normal de la cara
        vec3_t normal = calculate_normal(
            transformed_vertices[0],
            transformed_vertices[1],
            transformed_vertices[2]
        );
        normal = normalize(normal);

        // Dirección de la cámara
        vec3_t camera_direction = {0, 0, -1};

        // Aplicar back-face culling
        if (vec3_dot(normal, camera_direction) >= 0) {
            continue; // Saltar esta cara porque no es visible
        }

        // Calcular la intensidad de la luz
        float intensity = fmaxf(0.0f, vec3_dot(normal, light_direction));

        // Aplicar la intensidad al color
        uint32_t shaded_color = light_apply_intensity(face.color, intensity);

        uint32_t test_color = light_apply_intensity(0xFF0000, 0.5f);

        fill_triangle(
        projected_points[0].x + window_width / 2, projected_points[0].y + window_height / 2,
        projected_points[1].x + window_width / 2, projected_points[1].y + window_height / 2,
        projected_points[2].x + window_width / 2, projected_points[2].y + window_height / 2,
        test_color
        );
    }

    render_color_buffer();
    SDL_RenderPresent(renderer);
}

// Punto de entrada principal
int main(int argc, char* argv[]) {
    char* obj_filename = NULL;

    if (argc > 1) {
        obj_filename = argv[1];
    }

    is_running = initialize_window();

    setup(obj_filename);

    while (is_running) {
        previous_frame_time = SDL_GetTicks();

        process_input();
        update();
        render();

        int time_to_wait = FRAME_TARGET_TIME - (SDL_GetTicks() - previous_frame_time);
        if (time_to_wait > 0 && time_to_wait <= FRAME_TARGET_TIME) {
            SDL_Delay(time_to_wait);
        }
    }

    destroy_window();
    return 0;
}