#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <random>


#define CANT_INT 35

void generar_enteros_aleatorios(int param_array[], int param_size){
    for (int i = 0; i < param_size; i++)
        param_array[i] = rand() % 1000;
    return;
}

bool encontrar_numeros_pares(int param_array[], int param_size){
    int contador = 0;
    for(int i = 0; i < param_size; i++)
        if(param_array[i] % 2 == 0)
            contador++;
    return contador == param_size;
}

void calcular_promedio(int param_array[], int param_size){
    float promedio = 0;
    int acumulador = 0;
    for(int i = 0; i < param_size; i++)
        acumulador += param_array[i];
    promedio = (float)acumulador / param_size;
    acumulador = 0;
    for(int i = 0; i < param_size; i++)
        if(param_array[i] > promedio)
            acumulador++;
    printf("En total hay %d que superan el promedio de %.2f\n", acumulador, promedio);
    return;
}

void mostrar_posiciones_memoria(int param_array[], int param_size, int param_numero_control){
    for (int i = 0; i < param_size; i++)
        if(param_array[i] < param_numero_control)
            printf("Direccion %p | valor %d\n", (void*)&param_array[i], param_array[i]);
    return;
}

int main(){
    int array_enteros[CANT_INT];
    int numero_de_control;
        
    generar_enteros_aleatorios(array_enteros, CANT_INT);
    calcular_promedio(array_enteros, CANT_INT);

    printf("La cantidad numeros pares %s que los impares\n", encontrar_numeros_pares(array_enteros, CANT_INT) ? "es igual" : "no es igual");
    printf("Ingrese un numero para mostrar la posicion en memoria de los elementos menores a el\n");
    scanf("%d", &numero_de_control);

    mostrar_posiciones_memoria(array_enteros, CANT_INT, numero_de_control);
    return 0;
}