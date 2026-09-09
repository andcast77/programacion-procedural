#include <stdlib.h>
#include <stdio.h>

#define CANT_PRODUCTOS 150
#define STRING_LENGHT 30

typedef struct
{
    int codigo;
    char nombre[STRING_LENGHT];
    float precio_unitario;
    int stock;
} Producto;

void generar_productos_aleatorios(Producto param_productos[], int param_size_productos)
{
    for (int i = 0; i < param_size_productos; i++)
    {
        param_productos[i].codigo = i + 1;
        sprintf(param_productos[i].nombre, "Producto N %d", i + 1);
        param_productos[i].precio_unitario = (float)(rand() % 100000) / 100;
        param_productos[i].stock = rand() % 200;
    }
    return;
}

int buscar_producto(Producto param_productos[], int param_size_productos, int param_codigo_producto)
{
    int indice = -1;
    for (int i = 0; i < param_size_productos; i++)
        if (param_productos[i].codigo == param_codigo_producto)
            indice = i;

    if (indice != -1)
        printf("Producto encontrado: %s\n", param_productos[indice].nombre);
    return indice;
}

bool descontar_stock(Producto param_productos[], int param_size_productos, int param_codigo_producto, int param_unidades_producto)
{
    if (param_productos[param_codigo_producto].stock < param_unidades_producto)
    {
        printf("El producto no posee stock suficiente\n");
        return false;
    }

    param_productos[param_codigo_producto].stock -= param_unidades_producto;
    return true;
}

void generar_venta(Producto param_productos[], int param_size_productos)
{
    bool estado = true;

    printf("Generando venta\n");

    while (estado)
    {
        int codigo_producto = 0;
        printf("Ingrese el codigo de producto: ");
        scanf("%d", &codigo_producto);
        if (codigo_producto == 0)
        {
            printf("Finalizando la carga de productos\n");
            estado = false;
            continue;
        }
        int local_producto = buscar_producto(param_productos, param_size_productos, codigo_producto);
        if (local_producto == -1)
        {
            printf("No se ha encontrado el producto\n");
            continue;
        }
        int local_unidades = 0;
        printf("Ingrese la cantidad de unidades: ");
        scanf("%d", &local_unidades);
        if (descontar_stock(param_productos, param_size_productos, local_producto, local_unidades))
        {
            printf("venta generada correctamente $%.2f\n", param_productos[local_producto].precio_unitario * local_unidades);
        };
    }
}

void ordenar_listado_seleccion(Producto param_productos[], Producto param_productos_ordenados[], int param_size_productos){
    for(int i = 0; i < param_size_productos; i++)param_productos_ordenados[i] = param_productos[i];

    for(int i = 0; i < param_size_productos; i++){
        int menor = i;
        for (int j = i+1; j < param_size_productos; j++)
            if (param_productos[j].stock < param_productos[menor].stock)
                menor = j;
        param_productos_ordenados[i] = param_productos[menor];
    }
}

int main()
{
    Producto array_productos[CANT_PRODUCTOS];
    Producto array_productos_ordenado[CANT_PRODUCTOS];
    
    generar_productos_aleatorios(array_productos, CANT_PRODUCTOS);
    generar_venta(array_productos, CANT_PRODUCTOS);

    return 0;
}
