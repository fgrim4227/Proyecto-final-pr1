#include <stdio.h>
#include <stdlib.h>

//Structs del programa
typedef struct
{
    char nombre[20];
    float peso;
    char marca[100];
    float precio; 
    int existencias;
    char talla[20];
    float capacidad;
} Productos;
typedef struct 
{
    float impuesto;
    float total;
    char nombre[20];
    Productos comprados[100];
} Factura;
typedef struct
{
    char nombre[100];
    char apellido[100];
    char clave[100];
    int cedula;
    int edad;
    int intentos;
} Usuario;

//Funciones Cliente
int ingresar_usuario(char*, char*, int);

int buscar_usuario(char*, char*);

void mostrar_productos();

void agregar_carrito(Productos*, int*);

void carrito_compras(char*, Productos*, int*);

void quitar_product(Productos*, int*);

void comprar(char*, Productos*, int*);

void mostrar_facturas(char*);

//Funciones auxiliares

void quitar_espacios(char*);

void poner_espacios(char*);

//Funciones administrador

void mostrar_clientes();

void mostrar_inventario_admin();

void mostrar_ventas();

void agregar_producto_admin();

void eliminar_producto();

void editar_producto();

void agregar_cliente();

void eliminar_cliente();

void editar_cliente();

void desbloquear_cliente();