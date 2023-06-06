#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int calcularPromedioAlumnos(int calificaciones[3]) {
    int i;
    int suma = 0;
    for (i = 0; i < 3; i++) {
        ///usé un acumulador para sumar todas las calificaciones 
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
        ///toda la suma de los promedios la dividi para el no. de estudiantes 
        promediosGrupo[j] = suma / 23;
    }
}

int obtenerMejorAlumno(int promediosAlumnos[23]) {
    int i, indiceMejor = 0;
    for (i = 1; i < 23; i++) {
        
        ///con la condicional obtener el alumno con mayor promedio del grupo 
        if (promediosAlumnos[i] > promediosAlumnos[indiceMejor]) {
            indiceMejor = i;
        }
    }
    return indiceMejor;
}

void generarCalificacionesAleatorias(int calificaciones[23][3]) {
    int i, j;
    srand(time(NULL));
    for (i = 0; i < 23; i++) {
        for (j = 0; j < 3; j++) {
            // Aqui el progroma genera calficaciones entre 1 y 10 
            calificaciones[i][j] = rand() % 10 + 1;
        }
    }
}

void imprimirPromediosAlumnos(int promediosAlumnos[23]) {
    int i;
    printf("El promedio de calificaciones de cada alumno:\n");
    for (i = 0; i < 23; i++) {
        printf("Alumno %i: %d\n", i + 1, promediosAlumnos[i]);
    }
    printf("\n");
}

void imprimirPromediosGrupo(int promediosGrupo[3]) {
    int i;
    printf("El promedio del grupo para cada progreso:\n");
    for (i = 0; i < 3; i++) {
        printf("Progreso %d: %d\n", i + 1, promediosGrupo[i]);
    }
    printf("\n");
}

int main() {
    int calificaciones[23][3];
    int promediosAlumnos[23];
    int promediosGrupo[3];
    int opcion;
    int mejorAlumno;

    generarCalificacionesAleatorias(calificaciones);

    do {
        printf("MENU:\n"); //Funcion menu
        printf("1 - Calificaciones de cada alumno durante el semestre\n");
        printf("2 - Nota promedio del grupo de estudiantes para cada progreso\n");
        printf("3 - Alumno con mayor promedio de calificaciones durante el semestre\n");
        printf("Seleccione una opcion: ");
        scanf("%i", &opcion);

        switch (opcion) {
            case 1:
                for (int i = 0; i < 23; i++) {
                    promediosAlumnos[i] = calcularPromedioAlumnos(calificaciones[i]);
                }
                imprimirPromediosAlumnos(promediosAlumnos);
                break;
            case 2:
                calcularPromedioGrupo(calificaciones, promediosGrupo);
                imprimirPromediosGrupo(promediosGrupo);
                break;
            case 3:
                for (int i = 0; i < 23; i++) {
                    promediosAlumnos[i] = calcularPromedioAlumnos(calificaciones[i]);
                }
                mejorAlumno = obtenerMejorAlumno(promediosAlumnos);
                printf("Alumno con el promedio mas alto de este semestre es el Alumno %i\n", mejorAlumno + 1);
                break;
            default:
                printf("Esa opcion no existe. Seleccione una de las opciones de arriba.\n");
                break;
        }

        printf("\n");
    } while (1);

    return 0;
}