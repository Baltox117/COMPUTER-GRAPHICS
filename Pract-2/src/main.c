#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <SDL.h>
#include "display.h"
#include "vector.h"
#include "mesh.h"
#define N_POINTS (9 * 9 * 9)
// Eliminar esta línea, ya está definido en mesh.h
// #define N_CUBE_VERTICES 8

vec3_t cube_points[N_POINTS];
vec2_t projected_points[N_CUBE_VERTICES]; // Ajuste aquí, usamos los vértices reales del cubo

vec3_t cube_rotation = {0, 0, 0};
vec3_t cube_translation = {0, 0, 0};
vec3_t cube_scale = {1, 1, 1};

float fov_factor = 720;

bool is_running = false;
int previous_frame_time = 0;

void setup(void) {
    // Inicializar el buffer de color
    color_buffer = (uint32_t*)malloc(sizeof(uint32_t) * window_width * window_height);

    if (!color_buffer) {
        fprintf(stderr, "Error allocating memory for frame buffer.\n");
    }

    // Cargar los datos del cubo
    load_cube_mesh_data();  // En lugar de generar puntos, carga los datos del cubo
}

void process_input(void) {
    SDL_Event event;
    SDL_PollEvent(&event);

    switch (event.type) {
        case SDL_QUIT:
            is_running = false;
            break;
        case SDL_KEYDOWN:
            if (event.key.keysym.sym == SDLK_SPACE)
                is_running = false;
            break;
    }
}

// Proyección en perspectiva
vec2_t projectP(vec3_t point) {
    vec2_t projected_point;
    float z_inv = 1.0f / point.z;
    projected_point.x = point.x * z_inv * fov_factor;
    projected_point.y = point.y * z_inv * fov_factor;
    return projected_point;
}

void update(void) {
    // Aumentar las rotaciones para animar el cubo
    cube_rotation.x += 0.01;
    cube_rotation.y += 0.01;
    cube_rotation.z += 0.01;

    // Definir la traslación en Z para que el cubo no esté demasiado cerca de la cámara
    cube_translation.z = 5;

    // Para cada vértice del cubo, aplicar transformaciones y proyectarlo en 2D
    for (int i = 0; i < N_CUBE_VERTICES; i++) {
        // Obtener el vértice original del cubo
        vec3_t original_vertex = cube_vertices[i];

        // Aplicar rotación en X, Y y Z
        vec3_t rotated_vertex = vec3_rotate_x(original_vertex, cube_rotation.x);
        rotated_vertex = vec3_rotate_y(rotated_vertex, cube_rotation.y);
        rotated_vertex = vec3_rotate_z(rotated_vertex, cube_rotation.z);

        // Aplicar traslación en Z para alejar el cubo de la cámara
        rotated_vertex.z += cube_translation.z;

        // Proyectar el vértice 3D transformado en la pantalla 2D
        vec2_t projected_point = projectP(rotated_vertex);

        // Guardar el punto proyectado en el array de puntos proyectados
        projected_points[i] = projected_point;
    }
}

void render(void) {
    // Borra la pantalla
    clear_color_buffer(0xFF000000); // Fondo negro

    // Dibuja las caras del cubo utilizando líneas
    for (int i = 0; i < N_CUBE_FACES; i++) {
        face_t face = cube_faces[i];

        vec2_t points[3];
        points[0] = projected_points[face.a - 1]; // Los índices empiezan en 1
        points[1] = projected_points[face.b - 1];
        points[2] = projected_points[face.c - 1];

        // Dibuja los bordes del triángulo
        draw_line(points[0].x + window_width / 2, points[0].y + window_height / 2, points[1].x + window_width / 2, points[1].y + window_height / 2, face.color);
        draw_line(points[1].x + window_width / 2, points[1].y + window_height / 2, points[2].x + window_width / 2, points[2].y + window_height / 2, face.color);
        draw_line(points[2].x + window_width / 2, points[2].y + window_height / 2, points[0].x + window_width / 2, points[0].y + window_height / 2, face.color);
    }

    // Renderiza el buffer
    render_color_buffer();
    SDL_RenderPresent(renderer);
}

int main(int argc, char *argv[]) {
    is_running = initialize_window();

    setup();

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
