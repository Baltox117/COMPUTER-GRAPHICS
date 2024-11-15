#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
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

// Algoritmo de Punto Medio para Elipses
void draw_ellipse_bresenham(int xc, int yc, int a, int b, color_t color) {
    int x = 0, y = b;
    float a2 = a * a;
    float b2 = b * b;
    float d1 = b2 - (a2 * b) + (0.25 * a2);

    // Región 1
    while ((2 * b2 * x) <= (2 * a2 * y)) {
        // Dibujar puntos usando simetría
        draw_pixel(xc + x, yc + y, color);
        draw_pixel(xc - x, yc + y, color);
        draw_pixel(xc + x, yc - y, color);
        draw_pixel(xc - x, yc - y, color);

        x++;
        if (d1 < 0) {
            d1 += (2 * b2 * x) + b2;
        } else {
            y--;
            d1 += (2 * b2 * x) - (2 * a2 * y) + b2;
        }

        // Renderizar el buffer paso a paso
        render_color_buffer();
        SDL_RenderPresent(renderer);
        SDL_Delay(50); // Retraso para visualizar el proceso
    }

    // Región 2
    float d2 = (b2 * (x + 0.5) * (x + 0.5)) + (a2 * (y - 1) * (y - 1)) - (a2 * b2);
    while (y >= 0) {
        // Dibujar puntos usando simetría
        draw_pixel(xc + x, yc + y, color);
        draw_pixel(xc - x, yc + y, color);
        draw_pixel(xc + x, yc - y, color);
        draw_pixel(xc - x, yc - y, color);

        y--;
        if (d2 > 0) {
            d2 += a2 - (2 * a2 * y);
        } else {
            x++;
            d2 += (2 * b2 * x) - (2 * a2 * y) + a2;
        }

        // Renderizar el buffer paso a paso
        render_color_buffer();
        SDL_RenderPresent(renderer);
        SDL_Delay(50); // Retraso para visualizar el proceso
    }
}

void render(void) {
    // Borra la pantalla con fondo negro
    clear_color_buffer(0xFF000000);

    // Dibuja una elipse blanca
    draw_ellipse_bresenham(window_width / 2, window_height / 2, 150, 100, 0xFFFFFFFF);

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
