// Ejercicio 3 - Matrices y Linealización de Memoria
// Gestione las notas de 45 alumnos en 15 materias mediante una matriz de números reales. Utilice funciones recursivas
// para:
// a) Investigar y explicar el término Row-Major Order:
// Método de almacenamiento donde los elementos de cada fila se guardan consecutivamente en memoria. Índice
// lineal: pos = fila * columnas + columna.
// b) Cargar la matriz respetando el orden Row-Major.
// c) Mostrar el contenido de la última fila.
// d) Mostrar el contenido completo de la matriz.
// e) Realizar el mapa de memoria correspondiente a la función del punto c.
// Aclaración: La matriz se considera de dimensión [45][15] (45 alumnos × 15 materias)

#include <stdlib.h>
#include <stdio.h>

#define SIZE_ROWS 15
#define SIZE_COLS 45

void iniciar_matriz(int param_notas[][SIZE_COLS], int param_posicion){
    if(param_posicion == SIZE_ROWS * SIZE_COLS)
        return;
    
        int row = param_posicion / SIZE_COLS;
        int col = param_posicion % SIZE_COLS;

        param_notas[row][col] = 0;
        iniciar_matriz(param_notas, param_posicion + 1);
    return;
}

void cargar_matriz(int param_notas[][SIZE_COLS], int param_posicion){
    if(param_posicion == SIZE_ROWS * SIZE_COLS)
        return;

    int row = param_posicion / SIZE_COLS;
    int col = param_posicion % SIZE_COLS;

    int random = rand() % 10 + 1;
    param_notas[row][col] = random;
    // scanf("%d", &param_notas[row][col]);

    cargar_matriz(param_notas, param_posicion + 1);
}

void mostrar_ultima_fila(int param_notas[][SIZE_COLS], int param_posicion){
    if(param_posicion == SIZE_COLS)
        return;

    int nota = param_notas[SIZE_ROWS - 1][param_posicion];
    printf("[%s%d]", nota == 10 ? "" : " ", nota);

    mostrar_ultima_fila(param_notas, param_posicion + 1);
}

void mostrar_matriz(int param_notas[][SIZE_COLS], int param_posicion){
    if(param_posicion == SIZE_ROWS * SIZE_COLS)
        return;

    int row = param_posicion / SIZE_COLS;
    int col = param_posicion % SIZE_COLS;

    if(param_posicion % SIZE_COLS == 0)
        printf("\n");

    int nota = param_notas[row][col];
    printf("[%s%d]", nota == 10 ? "" : " ", nota);

    mostrar_matriz(param_notas, param_posicion + 1);
}

int main(){
    int notas[SIZE_ROWS][SIZE_COLS];

    iniciar_matriz(notas, 0);
    cargar_matriz(notas, 0);

    printf("\n\nMatriz completa:\n");
    mostrar_matriz(notas, 0);

    printf("\n\nUltima fila:\n");
    mostrar_ultima_fila(notas, 0);

    return 0;
}