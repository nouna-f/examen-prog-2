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
void calcularPromedioGrupo(int calificaciones[23][3], int promediosGrupo[3]) {
    int i, j;
    int suma;
    for (j = 0; j < 3; j++) {
        suma = 0;
        for (i = 0; i < 23; i++) {
            suma += calificaciones[i][j];
        }
        ///toda la suma de los promedios la dividimos para el numero de estudiantes 
        promediosGrupo[j] = suma / 23;
    }
}
