#include "triangle_fill.h"
#include "display.h"

void fill_flat_bottom_triangle(int x0, int y0, int x1, int y1, int x2, int y2, uint32_t color) {
    float inv_slope_1 = (float)(x1 - x0) / (y1 - y0);
    float inv_slope_2 = (float)(x2 - x0) / (y2 - y0);

    float cur_x1 = x0;
    float cur_x2 = x0;

    for (int y = y0; y <= y2; y++) {
        draw_line(cur_x1, y, cur_x2, y, color);
        cur_x1 += inv_slope_1;
        cur_x2 += inv_slope_2;
    }
}

void fill_flat_top_triangle(int x0, int y0, int x1, int y1, int x2, int y2, uint32_t color) {
    float inv_slope_1 = (float)(x2 - x0) / (y2 - y0);
    float inv_slope_2 = (float)(x2 - x1) / (y2 - y1);

    float cur_x1 = x2;
    float cur_x2 = x2;

    for (int y = y2; y >= y0; y--) {
        draw_line(cur_x1, y, cur_x2, y, color);
        cur_x1 -= inv_slope_1;
        cur_x2 -= inv_slope_2;
    }
}

void fill_triangle(int x0, int y0, int x1, int y1, int x2, int y2, uint32_t color) {
    if (y0 > y1) { int temp_x = x0, temp_y = y0; x0 = x1; y0 = y1; x1 = temp_x; y1 = temp_y; }
    if (y1 > y2) { int temp_x = x1, temp_y = y1; x1 = x2; y1 = y2; x2 = temp_x; y2 = temp_y; }
    if (y0 > y1) { int temp_x = x0, temp_y = y0; x0 = x1; y0 = y1; x1 = temp_x; y1 = temp_y; }

    if (y1 == y2) {
        fill_flat_bottom_triangle(x0, y0, x1, y1, x2, y2, color);
    } else if (y0 == y1) {
        fill_flat_top_triangle(x0, y0, x1, y1, x2, y2, color);
    } else {
        int new_x = x0 + (float)(y1 - y0) / (float)(y2 - y0) * (x2 - x0);
        int new_y = y1;

        fill_flat_bottom_triangle(x0, y0, x1, y1, new_x, new_y, color);
        fill_flat_top_triangle(x1, y1, new_x, new_y, x2, y2, color);
    }
}
