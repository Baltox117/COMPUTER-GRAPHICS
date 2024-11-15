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

// Función para dibujar una circunferencia usando el algoritmo de Bresenham
void draw_circle_bresenham(int xc, int yc, int radius, color_t color) {
    int x = 0, y = radius;
    int d = 3 - 2 * radius;

    while (y >= x) {
        // Dibujar los 8 octantes
        draw_pixel(xc + x, yc + y, color);
        draw_pixel(xc - x, yc + y, color);
        draw_pixel(xc + x, yc - y, color);
        draw_pixel(xc - x, yc - y, color);
        draw_pixel(xc + y, yc + x, color);
        draw_pixel(xc - y, yc + x, color);
        draw_pixel(xc + y, yc - x, color);
        draw_pixel(xc - y, yc - x, color);

        // Renderizar el buffer para ver los cambios
        render_color_buffer();
        SDL_RenderPresent(renderer);

        // Agregar un pequeño retraso para visualizar el proceso
        SDL_Delay(50);

        x++;

        if (d > 0) {
            y--;
            d = d + 4 * (x - y) + 10;
        } else {
            d = d + 4 * x + 6;
        }
    }
}

void render(void) {
    // Borra la pantalla con fondo negro
    clear_color_buffer(0xFF000000);

    // Dibuja una circunferencia blanca
    draw_circle_bresenham(window_width / 2, window_height / 2, 100, 0xFFFFFFFF);

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
