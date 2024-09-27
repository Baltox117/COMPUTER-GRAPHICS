#include "vector.h"
#include <math.h>

// Implementación de las funciones de vectores 2D
float vec2_length(vec2_t v) {
    return sqrt(v.x * v.x + v.y * v.y);
}

vec2_t vec2_add(vec2_t a, vec2_t b) {
    return (vec2_t) { a.x + b.x, a.y + b.y };
}

vec2_t vec2_sub(vec2_t a, vec2_t b) {
    return (vec2_t) { a.x - b.x, a.y - b.y };
}

vec2_t vec2_mul(vec2_t v, float factor) {
    return (vec2_t) { v.x * factor, v.y * factor };
}

vec2_t vec2_div(vec2_t v, float factor) {
    return (vec2_t) { v.x / factor, v.y / factor };
}

void vec2_normalize(vec2_t* v) {
    float length = vec2_length(*v);
    if (length != 0) {
        v->x /= length;
        v->y /= length;
    }
}

// Implementación de las funciones de vectores 3D
float vec3_length(vec3_t v) {
    return sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
}

vec3_t vec3_add(vec3_t a, vec3_t b) {
    return (vec3_t) { a.x + b.x, a.y + b.y, a.z + b.z };
}

vec3_t vec3_sub(vec3_t a, vec3_t b) {
    return (vec3_t) { a.x - b.x, a.y - b.y, a.z - b.z };
}

vec3_t vec3_mul(vec3_t v, float factor) {
    return (vec3_t) { v.x * factor, v.y * factor, v.z * factor };
}

vec3_t vec3_div(vec3_t v, float factor) {
    return (vec3_t) { v.x / factor, v.y / factor, v.z / factor };
}

vec3_t vec3_cross(vec3_t a, vec3_t b) {
    return (vec3_t) {
        .x = a.y * b.z - a.z * b.y,
        .y = a.z * b.x - a.x * b.z,
        .z = a.x * b.y - a.y * b.x
    };
}

float vec3_dot(vec3_t a, vec3_t b) {
    return a.x * b.x + a.y * b.y + a.z * b.z;
}

void vec3_normalize(vec3_t* v) {
    float length = vec3_length(*v);
    if (length != 0) {
        v->x /= length;
        v->y /= length;
        v->z /= length;
    }
}

vec3_t vec3_rotate_x(vec3_t v, float angle) {
    float cos_angle = cos(angle);
    float sin_angle = sin(angle);
    return (vec3_t) {
        .x = v.x,
        .y = v.y * cos_angle - v.z * sin_angle,
        .z = v.y * sin_angle + v.z * cos_angle
    };
}

vec3_t vec3_rotate_y(vec3_t v, float angle) {
    float cos_angle = cos(angle);
    float sin_angle = sin(angle);
    return (vec3_t) {
        .x = v.x * cos_angle + v.z * sin_angle,
        .y = v.y,
        .z = -v.x * sin_angle + v.z * cos_angle
    };
}

vec3_t vec3_rotate_z(vec3_t v, float angle) {
    float cos_angle = cos(angle);
    float sin_angle = sin(angle);
    return (vec3_t) {
        .x = v.x * cos_angle - v.y * sin_angle,
        .y = v.x * sin_angle + v.y * cos_angle,
        .z = v.z
    };
}

// Funciones de conversión
vec4_t vec4_from_vec3(vec3_t v) {
    return (vec4_t) { v.x, v.y, v.z, 1.0f };
}

vec3_t vec3_from_vec4(vec4_t v) {
    return (vec3_t) { v.x, v.y, v.z };
}
