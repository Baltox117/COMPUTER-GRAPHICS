#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <math.h>
#include <SDL.h>
#include "display.h"

bool is_running = false;

void setup(void) {
    // Inicializar el buffer de color
    color_buffer = (uint32_t*)malloc(sizeof(uint32_t) * window_width * window_height);

    if (!color_buffer) {
        fprintf(stderr, "Error al asignar memoria para el buffer de color.\n");
    }
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

// Dibujar una línea horizontal desde x1 a x2
void draw_horizontal_line(int y, int x1, int x2, color_t color) {
    for (int x = x1; x <= x2; x++) {
        draw_pixel(x, y, color);
    }

    // Renderiza la pantalla después de dibujar cada línea
    render_color_buffer();
    SDL_RenderPresent(renderer);

    // Añade un pequeño retraso para visualizar el proceso
    SDL_Delay(10);
}

// Relleno de un polígono utilizando el algoritmo Scanline
void fill_polygon(int vertices[][2], int vertex_count, color_t color) {
    int min_y = window_height, max_y = 0;

    // Encuentra el rango de y
    for (int i = 0; i < vertex_count; i++) {
        if (vertices[i][1] < min_y) min_y = vertices[i][1];
        if (vertices[i][1] > max_y) max_y = vertices[i][1];
    }

    // Procesa cada línea horizontal en el rango
    for (int y = min_y; y <= max_y; y++) {
        int intersections[vertex_count];
        int count = 0;

        // Calcula las intersecciones con los bordes
        for (int i = 0; i < vertex_count; i++) {
            int x1 = vertices[i][0];
            int y1 = vertices[i][1];
            int x2 = vertices[(i + 1) % vertex_count][0];
            int y2 = vertices[(i + 1) % vertex_count][1];

            if ((y1 <= y && y2 > y) || (y2 <= y && y1 > y)) {
                float t = (float)(y - y1) / (y2 - y1);
                int x = x1 + t * (x2 - x1);
                intersections[count++] = x;
            }
        }

        // Ordena las intersecciones
        for (int i = 0; i < count - 1; i++) {
            for (int j = 0; j < count - i - 1; j++) {
                if (intersections[j] > intersections[j + 1]) {
                    int temp = intersections[j];
                    intersections[j] = intersections[j + 1];
                    intersections[j + 1] = temp;
                }
            }
        }

        // Dibuja líneas horizontales entre pares de intersecciones
        for (int i = 0; i < count; i += 2) {
            draw_horizontal_line(y, intersections[i], intersections[i + 1], color);
        }

        // Renderiza el progreso
        render_color_buffer();
        SDL_RenderPresent(renderer);

        // Retraso para visualizar el proceso
        SDL_Delay(10);
    }
}

void render(void) {
    // Borra la pantalla con fondo negro
    clear_color_buffer(0xFF000000);

    // Dibuja un círculo relleno
    int circle_center_x = window_width / 4;
    int circle_center_y = window_height / 4;
    int circle_radius = 50;

    for (int y = -circle_radius; y <= circle_radius; y++) {
        int x = (int)sqrt(circle_radius * circle_radius - y * y);
        draw_horizontal_line(circle_center_y + y, circle_center_x - x, circle_center_x + x, 0xFF0000FF);

        // Renderizar después de cada línea
        render_color_buffer();
        SDL_RenderPresent(renderer);
        SDL_Delay(10);
    }

    // Dibuja una elipse rellena
    int ellipse_center_x = (3 * window_width) / 4;
    int ellipse_center_y = window_height / 4;
    int ellipse_a = 70;
    int ellipse_b = 40;

    for (int y = -ellipse_b; y <= ellipse_b; y++) {
        int x = (int)(ellipse_a * sqrt(1 - (y * y) / (float)(ellipse_b * ellipse_b)));
        draw_horizontal_line(ellipse_center_y + y, ellipse_center_x - x, ellipse_center_x + x, 0xFF00FF00);

        // Renderizar después de cada línea
        render_color_buffer();
        SDL_RenderPresent(renderer);
        SDL_Delay(10);
    }

    // Dibuja un triángulo relleno
    int triangle[3][2] = {
        {window_width / 4, (3 * window_height) / 4},
        {window_width / 2, (3 * window_height) / 4},
        {window_width / 3, window_height / 2}
    };
    fill_polygon(triangle, 3, 0xFFFF0000);

    // Dibuja un cuadrado relleno
    int square[4][2] = {
        {(3 * window_width) / 4 - 50, (3 * window_height) / 4 - 50},
        {(3 * window_width) / 4 + 50, (3 * window_height) / 4 - 50},
        {(3 * window_width) / 4 + 50, (3 * window_height) / 4 + 50},
        {(3 * window_width) / 4 - 50, (3 * window_height) / 4 + 50}
    };
    fill_polygon(square, 4, 0xFFFFFF00);

    // Renderiza el buffer de color
    render_color_buffer();
    SDL_RenderPresent(renderer);
}

int main(int argc, char *argv[]) {
    is_running = initialize_window();

    if (!is_running) {
        return -1;
    }

    setup();

    while (is_running) {
        process_input();
        render();
    }

    destroy_window();
    return 0;
}
