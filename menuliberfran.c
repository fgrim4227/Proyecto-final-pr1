#include "Libreria.h"

int main(int argc, char** argv)
{
    int verdad = 1;
    if (argc == 1)
    {   
        verdad = 0;
    }
    else 
    {
        char admin [15] = "administrador";
        for (int i = 0; argv[1][i] != '\0'; i++)
        {    
            if (argv[1][i] != admin[i])
            {
                verdad = 0;
                break;
            }
        }
    }
    
    int opcion; 
    int option;
    int option2;
    if (verdad == 1)
    {
        system("cls");
        do 
        {
            printf("\n//  Bienvenidos al menu de administrador //\n\n");
            printf("(1) - Inventario\n");
            printf("(2) - Gestionar Productos\n");
            printf("(3) - Clientes\n");
            printf("(4) - Gestionar Clientes\n");
            printf("(5) - Ventas\n");
            printf("(6) - Salir\n");    
            printf("Seleciona la opción que desees: ");
            
            scanf("%d", &opcion);
            
            switch(opcion)
            {
                case 1:
                    system("cls");
                    mostrar_inventario_admin();
                    int it1;
                    do 
                    {
                        printf("\n\nRetroceder = 0: ");
                        scanf("%d", &it1);
                    }while (it1 != 0);  
                    if (it1 == 0)
                    {
                        system("cls");
                        break;
                    }   
                case 2:
                    system("cls");
                    do 
                    {
                        printf("\n// Gestion de Invetario //\n\n");
                        printf("(1) - Agregar Un Producto\n");
                        printf("(2) - Eliminar Un Producto\n");
                        printf("(3) - Editar Un Producto\n");
                        printf("(4) - Salir\n");
                        printf("Seleciona la opción que desees: ");
                
                        scanf("%d", &option);
                
                        switch (option)
                        {
                            case 1:
                                system("cls");
                                agregar_producto_admin(); 
                                break;
                            case 2:
                                system("cls");
                                eliminar_producto();
                                system("cls");
                                break;
                            case 3:
                                system("cls");
                                editar_producto();
                                system("cls");  
                                break;
                            case 4:
                                system("cls");
                                break;
                            default:
                                system("cls");
                                printf("Seleccione una opcion valida\n");
                                break;
                        }
                    }while (option != 4);
                    break;
                case 3:
                    system("cls");
                    mostrar_clientes();
                    int it2;
                    do 
                    {
                        printf("\n\nRetroceder = 0: ");
                        scanf("%d", &it2);
                    }while (it2 != 0);  
                    if (it2 == 0)
                    {
                        system("cls");
                        break;
                    }  
                    break;
                case 4:
                    system("cls");
                    do 
                    {
                        printf("\n// Gestion De Clientes //\n\n");
                        printf("(1) - Agregar Un Cliente\n");
                        printf("(2) - Eliminar Un Cliente\n");
                        printf("(3) - Editar Un Cliente\n");
                        printf("(4) - Desbloquear Cliente\n");
                        printf("(5) - Salir\n");
                        printf("Seleciona la opción que desees: ");
                
                        scanf("%d", &option2);
                
                        switch (option2)
                        {
                            case 1:
                                system("cls");
                                agregar_cliente(); 
                                break;
                            case 2:
                                system("cls");
                                eliminar_cliente();

                                break;
                            case 3:
                                system("cls");
                                editar_cliente();  
                                break;
                            case 4:
                                system("cls");
                                desbloquear_cliente();
                                system("cls");
                                break;
                            case 5:
                                system("cls");
                                break;    
                            default:
                                system("cls");
                                printf("Seleccione una opcion valida\n");
                                break;
                        }
                    }while (option2 != 5);
                    break;
                case 5:
                    system("cls");
                    mostrar_ventas();
                    int iti;
                    do 
                    {
                        printf("\n\nRetroceder = 0: ");
                        scanf("%d", &iti);
                    }while (iti != 0);  
                    if (iti == 0)
                    {
                        system("cls");
                        break;
                    }
                case 6:
                    system("cls");
                    break;
                default:
                    system("cls");
                    printf("Seleccione una opcion valida\n");
                    break;
            }
        }while (opcion != 6);
    }
    else 
    {
        do 
        {
            system("cls");
            printf("//  Bienvenido a F&L Sports  //\n\n");
            printf("(1) - Ingresar Usuario\n");
            printf("(0) - Salir\n");
            printf("Seleciona la opción que desees: ");
            
            scanf("%d", &opcion);
            system("cls");
            switch(opcion)
            {
                case 1:
                    do 
                    {   
                        char nombre[20];
                        char clave[20];
                        int CI;
                        int estado;
                        printf("\n\n(0) - Salir\n");
                        printf("Ingrese el nombre de usuario: ");
                        scanf("%s", nombre);
                        if (nombre[0] == '0')
                        {
                            break;
                        }
                        printf("Ingrese la cedula de identidad del usuario: ");
                        scanf("%d", &CI);
                        printf("Clave: ");
                        scanf("%s", clave);
                        
                        estado = ingresar_usuario(nombre, clave, CI);
                        if (estado == 2)
                        {  
                            int posicion;
                            posicion = buscar_usuario(nombre, clave);  
                            Productos carrito[100];
                            int ind = 0;
                            int* indice_carrito1 = &ind;
                            system("cls");
                            do
                            {        
                                printf("\n// Bienvenido %s //\n\n", nombre);
                                printf("(1) - Ver Productos\n");
                                printf("(2) - Carrito\n");
                                printf("(3) - Ver Facturas De Compras\n");
                                printf("(4) - Salir\n");
                                printf("Seleciona la opción que desees: ");
            
                                scanf("%d", &option);
                                
                                switch (option)
                                {
                                    case 1:
                                        system("cls");
                                        mostrar_productos();
                                        int decision1;
                                        printf("\nSalir = 0\nSi desea llevar alguno de estos productos seleccione 1: ");
                                        scanf("%d", &decision1);
                                        if (decision1  == 1)
                                        {
                                            agregar_carrito(carrito, indice_carrito1);
                                            system("cls");
                                        }
                                        system("cls");
                                        break;
                                    case 2:
                                        system("cls");
                                        carrito_compras(nombre, carrito, indice_carrito1);
                                        break;
                                    case 3:
                                        system("cls");
                                        mostrar_facturas(nombre); 
                                        int it3;
                                        do 
                                        {
                                            printf("\n\nRetroceder = 0: ");
                                            scanf("%d", &it3);
                                        }while (it3 != 0);  
                                        if (it3 == 0)
                                        {
                                            system("cls");
                                            break;
                                        }   
                                    case 4:
                                        system("cls");
                                        printf("¡Hasta pronto!\n");
                                        break;
                                    default:
                                        system("cls");
                                        printf("Seleccione una opcion valida\n");
                                        break;
                                }
                            }while (option != 4);
                        }
                        else if (estado == 1)
                        {
                            system("cls");
                            printf("\nContraseña incorrecta\n"); 
                        }
                        else if (estado == 0)
                        {
                            system("cls");
                            printf("\nLos datos del usuario no coinciden\n");
                        }
                        if (estado == 3)
                        {
                            system("cls");
                            printf("\nEl usuario %s esta bloqueado por exceder el numero de intentos >:(\nPara desbloquearlo consulte al administrador", nombre);
                        }
                    }while (opcion);
                    break;
                case 0:
                    system("cls");
                    break;
                default:  
                    system("cls");
                    printf("Seleccione una opcion valida\n");
                    break;  
            }
        }while (opcion != 0);
    }
    printf("¡¡Hasta la proxima!!\n");
    return 0;
}