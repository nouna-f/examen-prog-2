#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int calcularPromedioAlumnos(int calificaciones[3]) {
    int i;
    int suma = 0;
    for (i = 0; i < 3; i++) {
        ///usamos un acumulador para sumar todas las calificaciones 
        suma += calificaciones[i];
    }
    return suma / 3;
}