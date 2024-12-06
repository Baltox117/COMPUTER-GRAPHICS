#ifndef SHADING_H
#define SHADING_H

#include "vector.h"  // Asumiendo que `vec3_t` y funciones de vectores están en este archivo
#include "display.h"

// Dirección de la luz (fuente de luz) en el espacio
extern vec3_t light_direction;


// Funciones de flat shading
vec3_t calculate_normal(vec3_t v1, vec3_t v2, vec3_t v3);
vec3_t normalize(vec3_t v);
uint32_t calculate_flat_shading_color(vec3_t normal);
// Declaración de light_apply_intensity
uint32_t light_apply_intensity(uint32_t original_color, float intensity);

#endif // SHADING_H
