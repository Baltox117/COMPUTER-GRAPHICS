#include <math.h>
#include "shading.h"

// Dirección de la luz (fuente de luz)
vec3_t light_direction = {0.0f, 0.0f, -1.0f};  // Luz que viene desde el frente
//light_direction = normalize(light_direction); // Normalizar

// Calcular la normal de un triángulo (cara)
vec3_t calculate_normal(vec3_t v1, vec3_t v2, vec3_t v3) {
    vec3_t edge1 = vec3_sub(v2, v1);
    vec3_t edge2 = vec3_sub(v3, v1);
    return vec3_cross(edge1, edge2);  // Producto cruzado
}

// Normaliza un vector
vec3_t normalize(vec3_t v) {
    float length = sqrtf(v.x * v.x + v.y * v.y + v.z * v.z);
    return vec3_div(v, length);  // Divide el vector por su longitud
}

// Función para calcular el color plano (flat shading) de una cara
uint32_t calculate_flat_shading_color(vec3_t normal) {
    normal = normalize(normal);
    float intensity = fmaxf(0.0f, vec3_dot(normal, light_direction));
    printf("Intensidad de luz: %f\n", intensity);


    uint8_t color_value = (uint8_t)(intensity * 255.0f);
    return (color_value << 16) | (color_value << 8) | color_value; // Gris basado en intensidad
}
// Aplica la intensidad de la luz a un color
uint32_t light_apply_intensity(uint32_t original_color, float intensity) {
    if (intensity < 0) intensity = 0;
    if (intensity > 1) intensity = 1;

    uint8_t r = ((original_color >> 16) & 0xFF) * intensity; // Rojo
    uint8_t g = ((original_color >> 8) & 0xFF) * intensity;  // Verde
    uint8_t b = (original_color & 0xFF) * intensity;         // Azul

    return (r << 16) | (g << 8) | b; // Combinar los canales en un color RGB
}




