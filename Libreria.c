#include "Libreria.h" 

//Funciones usuario

int ingresar_usuario(char* nombre, char* clave, int CIprove)
{
    Usuario har[100];

    FILE* flujo;
    flujo = fopen("Usuario.txt", "r");
    if (flujo == NULL)
    {
        printf("error al abrir el archivo\n");
    }
    int i = 0;
    while (feof(flujo) == 0)
    {
        fscanf (flujo, "%s %s %s %d %d %d\n", har[i].nombre, har[i].apellido, har[i].clave, &har[i].cedula, &har[i].edad, &har[i].intentos);
        i++;
    }
    fclose(flujo);
    har[i].nombre[0] = 'x';

    int aprobar;
    int aprobar2; 
    int indx;
    int i1;
    for (i1 = 0; har[i1].nombre[0] != 'x'; i1++)
    {
        aprobar = 1;
        for (int i2 = 0; nombre[i2] != '\0'; i2++)
        {
            if (nombre[i2] != har[i1].nombre[i2])
            {
                aprobar = 0;
                break;
            }
        }   
        if (aprobar == 1)
        {
            aprobar = 2;
            for (int i3 = 0; clave[i3] != '\0' ; i3++)
            {
                if (clave[i3] != har[i1].clave[i3])
                {
                    aprobar = 1;
                    break;
                }
            }  
            if (aprobar == 2 && har[i1].cedula == CIprove && har[i1].intentos < 3)
            {   
                break;
            }
            else if (aprobar == 2 && har[i1].cedula == CIprove && har[i1].intentos == 3)
            {
                return 3;
            }
        }
        if (aprobar == 1 && har[i1].cedula == CIprove)
        {
            aprobar2 = 1;
            indx = i1;
        }
    }
    if (aprobar2 == 1 && aprobar != 2)
    {
        har[indx].intentos++;

        FILE* flujo2;
        flujo2 = fopen("Usuario.txt", "w");
        if (flujo2 == NULL)
        {
            printf("Error al abrir el archivo");
        }
        for (int i2 = 0; har[i2].nombre[0] != 'x'; i2++)
        {
            fprintf(flujo2, "%s %s %s %d %d %d\n", har[i2].nombre, har[i2].apellido, har[i2].clave, har[i2].cedula, har[i2].edad, har[i2].intentos);
        } 
        fclose(flujo2);

        if (har[indx].intentos == 3)
        {
            return 3;
        }
        return aprobar2;
    }
    else if (aprobar == 2)
    {
        har[i1].intentos = 0;

        FILE* flujo2;
        flujo2 = fopen("Usuario.txt", "w");
        if (flujo2 == NULL)
        {
            printf("Error al abrir el archivo");
        }
        for (int i2 = 0; har[i2].nombre[0] != 'x'; i2++)
        {
            fprintf(flujo2, "%s %s %s %d %d %d\n", har[i2].nombre, har[i2].apellido, har[i2].clave, har[i2].cedula, har[i2].edad, har[i2].intentos);
        } 
        fclose(flujo2);

        return aprobar;
    }
    else 
    {
        return aprobar;
    }
};

int buscar_usuario(char* nombre, char* clave)
{
    Usuario har[100];

    FILE* flujo;
    flujo = fopen("Usuario.txt", "r");
    if (flujo == NULL)
    {
        printf("error al abrir el archivo\n");
    }
    int i = 0;
    while (feof(flujo) == 0)
    {
        fscanf (flujo, "%s %s %s %d %d\n", har[i].nombre, har[i].apellido, har[i].clave, &har[i].cedula, &har[i].edad);
        i++;
    }
    fclose(flujo);
    har[i].nombre[0] = 'x';

    int aprobar;
    int aprobar2; 
    int i1;
    for (i1 = 0; har[i1].nombre[0] != 'x'; i1++)
    {
        aprobar = 1;
        for (int i2 = 0; nombre[i2] != '\0'; i2++)
        {
            if (nombre[i2] != har[i1].nombre[i2])
            {
                aprobar = 0;
                break;
            }
        }   
        if (aprobar == 1)
        {
            aprobar = 2;
            for (int i3 = 0; clave[i3] != '\0' ; i3++)
            {
                if (clave[i3] != har[i1].clave[i3])
                {
                    aprobar = 1;
                    break;
                }
            }  
            if (aprobar == 2)
            {
                break;
            }
        }
        if (aprobar == 1)
        {
            aprobar2 = 1;
        }
    }
    return i1;
};

void mostrar_productos()
{
    Productos har[100];
    
    FILE* flujo;
    flujo = fopen("Productos.txt", "r");
    
    if (flujo == NULL)
    {
        printf("Error al abrir el archivo\n");
    }
    
    int i = 0;
    while (feof(flujo) == 0)
    {
        fscanf(flujo, "%s %f %s %f %d %s %f\n", har[i].nombre, &har[i].peso, har[i].marca, &har[i].precio, &har[i].existencias, har[i].talla, &har[i].capacidad);
        quitar_espacios(har[i].nombre);
        quitar_espacios(har[i].marca);
        i++;
    }
    fclose(flujo);
    int control = 0;
    int control2 = i/3;
    int z = 0;
    do
    {
        har[i].nombre[0] = 'x';
        printf("     Catalogo De Productos\n\n");
        while ((har[z].nombre[0] != 'x') && (z < control2))
        {
            if (har[z].peso == 0 && har[z].talla[0] != '&' && har[z].capacidad != 0 && har[z].existencias != 0)
            {
                printf("%s %d\nDescripcion:\nMarca: %s®\nTalla: %s\nCapacidad: %.2fml\nStock: %d\nPrecio: %.2f$\n\n", 
                har[z].nombre, z + 1, har[z].marca, har[z].talla, har[z].capacidad, har[z].existencias, har[z].precio * 1.43);
            }
            else if (har[z].peso != 0 && har[z].talla[0] == '&' && har[z].capacidad != 0 && har[z].existencias != 0)
            {
                printf("%s %d\nDescripcion:\nMarca: %s®\nPeso: %.2fkg\nCapacidad: %.2fml\nStock: %d\nPrecio: %.2f$\n\n", 
                har[z].nombre, z + 1, har[z].marca, har[z].peso, har[z].capacidad, har[z].existencias, har[z].precio * 1.43);
            }
            else if (har[z].peso != 0 && har[z].talla[0] != '&' && har[z].capacidad == 0 && har[z].existencias != 0)
            {
                printf("%s %d\nDescripcion:\nMarca: %s®\nPeso: %.2fkg\nTalla: %s\nStock: %d\nPrecio: %.2f$\n\n", 
                har[z].nombre, z + 1, har[z].marca, har[z].peso, har[z].talla, har[z].existencias,
                har[z].precio * 1.43);
            }    
            
            else if (har[z].peso == 0 && har[z].talla[0] == '&' && har[z].capacidad != 0 && har[z].existencias != 0)
            {
                printf("%s %d\nDescripcion:\nMarca: %s®\nCapacidad: %.2fml\nStock: %d\nPrecio: %.2f$\n\n", 
                har[z].nombre, z + 1, har[z].marca, har[z].capacidad, har[z].existencias,
                har[z].precio * 1.43);
            }   
            else if (har[z].peso == 0 && har[z].talla[0] != '&' && har[z].capacidad == 0 && har[z].existencias != 0)
            {
                printf("%s %d\nDescripcion:\nMarca: %s®\nTalla: %s\nStock: %d\nPrecio: %.2f$\n\n", 
                har[z].nombre, z + 1, har[z].marca, har[z].talla, har[z].existencias,
                har[z].precio * 1.43);
            }
            else if (har[z].peso != 0 && har[z].talla[0] == '&' && har[z].capacidad == 0 && har[z].existencias != 0)
            {
                printf("%s %d\nDescripcion:\nMarca: %s®\nPeso: %.2fkg\nStock: %d\nPrecio: %.2f$\n\n", 
                har[z].nombre, z + 1, har[z].marca, har[z].peso, har[z].existencias,
                har[z].precio * 1.43);
            }
            else if (har[z].peso == 0 && har[z].talla[0] == '&' && har[z].capacidad == 0 && har[z].existencias != 0)
            {
                printf("%s %d\nDescripcion:\nMarca: %s®\nStock: %d\nPrecio: %.2f$\n\n", 
                har[z].nombre, z + 1, har[z].marca, har[z].existencias,
                har[z].precio * 1.43);
            }
            else if (har[z].existencias != 0)
            {
                printf("%s %d\nDescripcion:\nMarca: %s®\nPeso: %.2fkg\nTalla: %s\nCapacidad: %.2fml\nStock: %d\nPrecio: %.2f$\n\n", 
                har[z].nombre, z + 1, har[z].marca, har[z].peso, har[z].talla, har[z].capacidad, har[z].existencias,
                har[z].precio * 1.43);
            }
            z++;
        }
        printf("Todos nuestros productos traen el IVA incluido\n");

            if (z <= i/3)
            {
                printf("Si desea ver los otros productos de la siguiente pagina seleccione 1, si desea salir seleccione 2\n");
                scanf("%d", &control);                
                if (control == 1)
                {
                    control2 = 2*(control2);
                    z = z - 1;
                    control = 0;
                    system("cls");
                }
            }
            else if ((z > i/3) && (z < i))
            {
                printf("Si desea ver los otros productos de la siguiente pagina seleccione 1, si desea ir a la pagina anterior seleccione 2 y si desea salir seleccione 3\n");
                scanf("%d", &control);        
                if (control == 1)
                   {
                        control2 = i;
                        z = z - 1;
                        control = 0;
                        system("cls");
                   }
                else if (control == 2)
                   {
                        control2 = i/3;
                        z = 0;
                        control = 0;
                        system("cls");
                   }
                else if (control == 3)
                   {
                         control = 2;
                   }
            }
            else if (z >= i)
            {
                printf("Si desea ver los otros productos de la pagina anterior seleccione 1, si desea salir seleccione 2\n");
                scanf("%d", &control);                
                if (control == 1)
                {
                    control2 = 2*(i/3);
                    z = i/3;
                    control = 0;
                    system("cls");
                }
            }
            else
            {
                printf("Seleccione una opcion valida\n");
            }
    } while (control != 2);
};

void quitar_product(Productos* carrito, int* indice_carrito)
{
    printf("\n\nCarrito\n\n");
    int cant_products=0;
    int control;
    int posicion_product,cantidad_product, imp = 1;
    while (cant_products < (*indice_carrito))
    {
        printf("%d)  %s %s %d %.2f\n", imp, carrito[cant_products].nombre, carrito[cant_products].marca, carrito[cant_products].existencias, (((carrito[cant_products].precio)*1.43) * carrito[cant_products].existencias));
        cant_products++;
        imp++;         
    }
    printf("\n\nIndique que producto desea devolver: ");
    scanf("%d", &posicion_product);
    printf("Cuántas unidades?: ");
    scanf("%d", &cantidad_product);

    if ((cantidad_product <= carrito[posicion_product - 1].existencias) && (cantidad_product > 0))
    {    
        if (cantidad_product == carrito[posicion_product - 1].existencias)
        {
            int control,cont=0;
            control=posicion_product-1;
            while(control < (*indice_carrito) - 1)
            {
                
                carrito[control] = carrito[control+1];
                control++;
            }
            *indice_carrito = (*indice_carrito) - 1;
        }
        else if(cantidad_product < carrito[posicion_product - 1].existencias)
        {
            carrito[posicion_product - 1].existencias = carrito[posicion_product - 1].existencias - cantidad_product;
        }
        printf("\n\nSe ha sacado el producto correctamente\n");
    }
    else if ((cantidad_product > carrito[posicion_product].existencias) || (cantidad_product < 0))
    {
        printf("Seleccione una cantidad valida de productos a devolver\n");
    }   

}; 

void agregar_carrito(Productos* carrito, int* indice_carrito)
{
    int pasa_product = 0;
    int posicion_product;
    int cantidad;

    FILE* archivo;
    Productos auxiliar[100];
    archivo = fopen("Productos.txt","r");
    if (archivo == NULL)
    {
        printf("Error al abrir el archivo\n");
    }
    while (feof(archivo) == 0)
    {
        fscanf(archivo,"%s %f %s %f %d %s %f", auxiliar[pasa_product].nombre, &auxiliar[pasa_product].peso, 
                auxiliar[pasa_product].marca, &auxiliar[pasa_product].precio, &auxiliar[pasa_product].existencias, 
                auxiliar[pasa_product].talla, &auxiliar[pasa_product].capacidad);
        quitar_espacios(auxiliar[pasa_product].nombre);
        quitar_espacios(auxiliar[pasa_product].marca);
        pasa_product++;           
    }
    fclose(archivo);
    int it = 0;
    do 
    {
        if (it != 0)
        {
           mostrar_productos(); 
        }
        printf("\nSalir = 0\n");
        printf("Ingrese el numero del producto que desea llevar: ");
        scanf("%d", &posicion_product);
        if (posicion_product == 0)
        {
            break;
        }
        printf("Ingrese cuantos productos desea llevar: ");
        scanf("%d", &cantidad);

        if (cantidad > auxiliar[posicion_product-1].existencias)
        {
            system("cls");
            system("cls");
            printf("ADVERTENCIA: INGRESE UNA CANTIDAD VALIDA DE PRODUCTOS A LLEVAR\n\n");
        }
        else
        {
            int sum = 0;
            int c1;
            for (c1 = 0; c1 < *indice_carrito; c1++)
            {
                int control1 = 1;
                for (int c3 = 0; carrito[c1].nombre[c3] != '\0'; c3++)
                { 
                    if (carrito[c1].nombre[c3] != auxiliar[posicion_product - 1].nombre[c3])
                    {
                        control1 = 0;
                        break;
                    }
                    else if (c3 == 19)
                    {
                        break;
                    }
                }
                if (control1 == 1)
                {
                    sum = sum + carrito[c1].existencias;
                    break;
                }
            } 
            if (sum + cantidad > auxiliar[posicion_product - 1].existencias)
            {
                system("cls");
                system("cls");
                printf("\nHas selecionado mas existencias de las que tenemos en stock\nTienes en este momento %d %s en tu carrito\n\n", sum, auxiliar[posicion_product - 1].nombre);
            }
            else if (sum != 0)
            {
                carrito[c1].existencias = carrito[c1].existencias + cantidad;
                system("cls");
                system("cls");
                printf("\nEl producto ha sido agregado exitosamente\n\n");
            }
            else 
            {
                carrito[*indice_carrito] = auxiliar[posicion_product-1];
                carrito[*indice_carrito].existencias = cantidad;
                *indice_carrito = (*indice_carrito) + 1; 
                system("cls");
                system("cls");
                printf("\nEl producto ha sido agregado exitosamente\n\n");
            }
        }  
        it++;
    }while(pasa_product);
};

void carrito_compras(char* nombre, Productos* carrito, int* indice_carrito)
{
    int cant_products = 0;
    int control;
    do
    {
        cant_products = 0;
        printf("\nCarrito\n");
        if (*indice_carrito == 0)
        {
            printf("Su carrito se encuentra vacio\n");
            printf("\nSalir = 0:  ");
            scanf("%d", &control);
            system("cls");
        }
        else
        {
            while (cant_products < (*indice_carrito))
            {
                printf("%s %s %d %.2f\n", carrito[cant_products].nombre, carrito[cant_products].marca, carrito[cant_products].existencias, (((carrito[cant_products].precio) * 1.43) * carrito[cant_products].existencias));
                cant_products++;         
            }
            printf("\nSalir = 0\nSacar producto = 1\nRealizar compra = 2\nSelecione la opcion: ");
            scanf("%d", &control);
            switch (control)
            {
                case 1:
                    system("cls");
                    quitar_product(carrito,indice_carrito);
                    system("cls");
                    break;
                case 2:
                    system("cls");
                    comprar(nombre,carrito,indice_carrito);
                    control = 0;
                    break;
                default:
                    system("cls");
                    break;
            } 
        }
    }while (control != 0);
    
};

void comprar(char* nombre, Productos carrito[100], int* indice_carrito)
{
    FILE* facturar;
    facturar = fopen("Productos.txt","r");
    Productos aux[100];
    int k = 0;
    if (facturar == NULL)
    {
        printf("Error al abrir el archivo\n");
    }
    else
    {
        while (feof(facturar) == 0)
        {
            fscanf(facturar,"%s %f %s %f %d %s %f\n", aux[k].nombre, &aux[k].peso, aux[k].marca,
                &aux[k].precio, &aux[k].existencias, aux[k].talla, &aux[k].capacidad);  
            quitar_espacios(aux[k].nombre);
            quitar_espacios(aux[k].marca);
            k++;        
        }
        aux[k].nombre[0] = 'x';
        fclose(facturar);
        
        for (int c1 = 0; c1 < *indice_carrito; c1++)
        {
            for (int c2 = 0; c2 < k; c2++)
            {
                int control1 = 1;
                for (int c3 = 0; carrito[c1].nombre[c3] != '\0'; c3++)
                {
                    if (carrito[c1].nombre[c3] != aux[c2].nombre[c3])
                    {
                        control1=0;
                        break;
                    }
                    else if (c3 == 19)
                    {
                        break;
                    }
                }
                if (control1 == 1)
                {
                    aux[c2].existencias = (aux[c2].existencias) - (carrito[c1].existencias);
                    break;
                }
            }
        } 

        for (int c5 = 0; c5 < *indice_carrito ; c5++)
        {
            poner_espacios(carrito[c5].nombre);
            poner_espacios(carrito[c5].marca);
        }
        for (int c5 = 0; aux[c5].nombre[0] != 'x'; c5++)
        {
            poner_espacios(aux[c5].nombre);
            poner_espacios(aux[c5].marca);
        }

        FILE* actualizar;
        actualizar = fopen("Productos.txt","w");
        int retorno=0;
        while (retorno < k)
        {
            fprintf(actualizar, "%s %.2f %s %.2f %d %s %.2f \n", aux[retorno].nombre, aux[retorno].peso, 
                    aux[retorno].marca, aux[retorno].precio, aux[retorno].existencias, 
                    aux[retorno].talla, aux[retorno].capacidad);
            retorno++;     
        }  
        fclose(actualizar); 

        FILE* agregar_fac;
        agregar_fac = fopen("Facturas.txt","a");
        int contador = 0;
        fprintf(agregar_fac, "%s %d\n", nombre, *indice_carrito);
        while (contador < *indice_carrito)
        {
            fprintf(agregar_fac, "%s %s %d %.2f\n", carrito[contador].nombre, carrito[contador].marca, 
                    carrito[contador].existencias, (carrito[contador].precio * 1.43 * carrito[contador].existencias));
            contador++;
        }
        float iva, total_pagar;
        int calculo_imp = 0;
        float sumatoria = 0;
        while (calculo_imp < *indice_carrito)
        {
            sumatoria = sumatoria + (carrito[calculo_imp].precio * carrito[calculo_imp].existencias);
            calculo_imp++;
        }
        iva = sumatoria * 0.13;
        total_pagar = sumatoria * 1.43;
        fprintf(agregar_fac, "%.2f\n%.2f\n", iva, total_pagar);
        fclose(agregar_fac);

        for (int c5 = 0; c5 < *indice_carrito; c5++)
        {
            quitar_espacios(carrito[c5].nombre);
            quitar_espacios(carrito[c5].marca);
        }
        int contador2 = 0;
        printf("\n\n--------------------\n");
        printf("%s\n",nombre);
        while (contador2 < *indice_carrito)
        {
            printf("%s %s %d %.2f\n", carrito[contador2].nombre, carrito[contador2].marca, 
                    carrito[contador2].existencias, (carrito[contador2].precio * 1.43 * carrito[contador2].existencias));
            contador2++;
        }
        printf("\n\n--------------------\n");
        printf("IVA                  %.2f\ntotal                %.2f\n", iva, total_pagar);
        //reiniciar carrito
        int contador3 = 0;
        int contador_aux = 0;
        while (contador3 < *indice_carrito)
        {
            carrito[contador3].nombre[0]='\0';
            carrito[contador3].peso=0;
            carrito[contador3].marca[0]='\0';
            carrito[contador].precio=0;
            carrito[contador].existencias=0;
            carrito[contador3].talla[0]='\0';
            carrito[contador].capacidad=0;
            contador3++;
        }
        *indice_carrito = 0;
    }
    int iti;
    do 
    {
        printf("\n\nRetroceder = 0: ");
        scanf("%d", &iti);
    }while (iti != 0);  
    if (iti == 0)
    {
        system("cls");
    }  
};

void mostrar_facturas(char* nombre2)
{ 
    Factura har[100];
    
    FILE* flujo;
    flujo = fopen("Facturas.txt", "r");
    
    if (flujo == NULL)
    {
        printf("Error al abrir el archivo");
    }
    
    int i = 0;
    int n2;
    int nveces;
    while (feof(flujo) == 0)
    {   
        n2 = 0;       
        fscanf(flujo, "%s %d\n", har[i].nombre, &nveces);
        int n3 = nveces;
        while (nveces)
        {
            fscanf(flujo, "%s %s %d %f\n", har[i].comprados[n2].nombre, har[i].comprados[n2].marca, &har[i].comprados[n2].existencias, &har[i].comprados[n2].precio);
            quitar_espacios(har[i].comprados[n2].nombre);
            quitar_espacios(har[i].comprados[n2].marca);
            nveces--;
            n2++;
            if (n2 == n3)
            {
            har[i].comprados[n2].nombre[0] = 'x';
            }
        }
        fscanf(flujo, "%f\n%f\n", &har[i].impuesto, &har[i].total);
        i++;
    }
    fclose(flujo);
    har[i].nombre[0] = 'x'; 
    
    int u;
    int z;       
    int imprimir;
    printf("\n\n     Listado De Facturas - Compras Personales\n\n");              
    for (z = 0; har[z].nombre[0] != 'x'; z++)
    {
        imprimir = 1;
        for (int c1 = 0; nombre2[c1] != '\0'; c1++)
        {
            if (nombre2[c1] != har[z].nombre[c1])
            {
                imprimir = 0;
                break;
            } 
        }
        if (imprimir == 0)
        {
            continue;
        }
        printf("--------------------\n");
        printf("%s\n", har[z].nombre);
        for (u = 0; har[z].comprados[u].nombre[0] != 'x'; u++)
        {
            printf("%s %s %d %.2f\n", har[z].comprados[u].nombre, har[z].comprados[u].marca, har[z].comprados[u].existencias, har[z].comprados[u].precio);
        }
        printf("--------------------\n");
        printf("IVA                  %.2f\ntotal                %.2f\n", har[z].impuesto, har[z].total);
    }
};

//Funciones Auxiliares

void quitar_espacios(char* frase)
{
    for (int i = 0; frase[i] != '\0'; i++)
    {
        if (frase[i] == '_')
        {
            frase[i] = ' ';
        }
    }
};

void poner_espacios(char* frase2)
{
    for (int i = 0; frase2[i] != '\0'; i++)
    {
        if (frase2[i] == ' ')
        {
            frase2[i] = '_';
        }
    }
};

//Funciones de administrador

void mostrar_clientes()
{
    Usuario har[100];

    FILE* flujo;
    flujo = fopen("Usuario.txt", "r");
    if (flujo == NULL)
    {
        printf("error al abrir el archivo\n");
    }
        int control = 0; 
        int i = 0;
        while (feof(flujo) == 0)
        {
            fscanf (flujo, "%s %s %s %d %d %d\n", har[i].nombre, har[i].apellido, har[i].clave, &har[i].cedula, &har[i].edad, &har[i].intentos);
            i++;
        }
    int control2 = i/3;
    int z = 0;
    do
    { 

        fclose(flujo);
        har[i].nombre[0] = 'x';
        printf("     Base De Datos De Usuarios\n\n");
        while ((har[z].nombre[0] != 'x') && (z < control2))
        {
            printf("%s  usuario %d\n%s\nClave: %s\nC.I: %d\nEdad: %d\n\n", 
            har[z].nombre, z + 1, har[z].apellido, har[z].clave, har[z].cedula, har[z].edad);
            z++;
        }
            if (z <= i/3)
            {
                printf("Si desea ver los clientes de la siguiente pagina seleccione 1, si desea salir seleccione 2\n");
                scanf("%d", &control);                
                if (control == 1)
                {
                    control2 = 2*(control2);
                    z = z - 1;
                    control = 0;
                }
                else
                {
                    control = 2;
                }
                system("cls");
            }
            else if ((z > i/3) && (z < i))
            {
                printf("Si desea ver los otros clientes de la siguiente pagina seleccione 1, si desea ir a la pagina anterior seleccione 2 y si desea salir seleccione 3\n");
                scanf("%d", &control);        
                if (control == 1)
                   {
                        control2 = i;
                        z = z - 1;
                        control = 0;
                   }
                else if (control == 2)
                   {
                        control2 = i/3;
                        z = 0;
                        control = 0;
                   }
                else if (control == 3)
                   {
                         control = 2;
                   }
                system("cls");
            }
            else if (z >= i)
            {
                printf("Si desea ver los clientes de la pagina anterior seleccione 1, si desea salir seleccione 2\n");
                scanf("%d", &control);                
                if (control == 1)
                {
                    control2 = 2*(i/3);
                    z = i/3;
                    control = 0;
                }
                system("cls");
            }
            else
            {
                printf("Seleccione una opcion valida\n");
            }
    } while (control != 2);
};

void mostrar_inventario_admin()
{
    Productos har[100];
    
    FILE* flujo;
    flujo = fopen("Productos.txt", "r");
    
    if (flujo == NULL)
    {
        printf("Error al abrir el archivo");
    }
    
    int i = 0;
    while (feof(flujo) == 0)
    {
        fscanf(flujo, "%s %f %s %f %d %s %f\n", har[i].nombre, &har[i].peso, har[i].marca, &har[i].precio, &har[i].existencias, har[i].talla, &har[i].capacidad);
        quitar_espacios(har[i].nombre);
        quitar_espacios(har[i].marca);
        i++;
    }
    fclose(flujo);
    har[i].nombre[0] = 'x';
    int control = 0;
    int control2= i/3;
    int z = 0;
    do
    {
        printf("\n     Inventario - Almacen\n\n");
        while ((har[z].nombre[0] != 'x') && (z < control2))
        {
            if (har[z].peso == 0 && har[z].talla[0] != '&' && har[z].capacidad != 0)
            {
                printf("%d)  %s\nDescripcion:\nMarca: %s®\nTalla: %s\nCapacidad: %.2fml\nStock: %d\nCosto: %2.f$\n\n", z + 1, 
                        har[z].nombre, har[z].marca, har[z].talla, har[z].capacidad, har[z].existencias,
                        har[z].precio);
            }
            else if (har[z].peso != 0 && har[z].talla[0] == '&' && har[z].capacidad != 0)
            {
                printf("%d)  %s\nDescripcion:\nMarca: %s®\nPeso: %.2fkg\nCapacidad: %.2fml\nStock: %d\nCosto: %2.f$\n\n", z + 1, 
                        har[z].nombre, har[z].marca, har[z].peso, har[z].capacidad, har[z].existencias,
                        har[z].precio);
            }
            else if (har[z].peso != 0 && har[z].talla[0] != '&' && har[z].capacidad == 0)
            {
                printf("%d)  %s\nDescripcion:\nMarca: %s®\nPeso: %.2fkg\nTalla: %s\nStock: %d\nCosto: %2.f$\n\n", z + 1,
                        har[z].nombre, har[z].marca, har[z].peso, har[z].talla, har[z].existencias,
                        har[z].precio);
            }    
            
            else if (har[z].peso == 0 && har[z].talla[0] == '&' && har[z].capacidad != 0)
            {
                printf("%d)  %s\nDescripcion:\nMarca: %s®\nCapacidad: %.2fml\nStock: %d\nCosto: %2.f$\n\n", z + 1, 
                        har[z].nombre, har[z].marca, har[z].capacidad, har[z].existencias,
                        har[z].precio);
            }   
            else if (har[z].peso == 0 && har[z].talla[0] != '&' && har[z].capacidad == 0)
            {
                printf("%d)  %s\nDescripcion:\nMarca: %s®\nTalla: %s\nStock: %d\nCosto: %2.f$\n\n", z + 1, 
                        har[z].nombre, har[z].marca, har[z].talla, har[z].existencias,
                        har[z].precio);
            }
            else if (har[z].peso != 0 && har[z].talla[0] == '&' && har[z].capacidad == 0)
            {
                printf("%d)  %s\nDescripcion:\nMarca: %s®\nPeso: %.2fkg\nStock: %d\nCosto: %2.f$\n\n", z + 1, 
                        har[z].nombre, har[z].marca, har[z].peso, har[z].existencias,
                        har[z].precio);
            }
            else if (har[z].peso == 0 && har[z].talla[0] == '&' && har[z].capacidad == 0)
            {
                printf("%d)  %s\nDescripcion:\nMarca: %s®\nStock: %d\nCosto: %2.f$\n\n", z + 1, 
                        har[z].nombre, har[z].marca, har[z].existencias,
                        har[z].precio);
            }
            else
            {
                printf("%d)  %s\nDescripcion:\nMarca: %s®\nPeso: %.2fkg\nTalla: %s\nCapacidad: %.2fml\nStock: %d\nCosto: %2.f$\n\n", z + 1, 
                        har[z].nombre, har[z].marca, har[z].peso, har[z].talla, har[z].capacidad, har[z].existencias,
                        har[z].precio);
            }
            z++;
        }
        if (z <= i/3)
            {
                printf("Si desea ver los productos de la siguiente pagina seleccione 1, si desea salir seleccione 2\n");
                scanf("%d", &control);                
                if (control == 1)
                {
                    control2 = 2*(control2);
                    z = z - 1;
                    control = 0;
                }
                else
                {
                    control = 2;
                }
                system("cls");
            }
            else if ((z > i/3) && (z < i))
            {
                printf("Si desea ver los productos de la siguiente pagina seleccione 1, si desea ir a la pagina anterior seleccione 2 y si desea salir seleccione 3\n");
                scanf("%d", &control);        
                if (control == 1)
                   {
                        control2 = i;
                        z = z - 1;
                        control = 0;
                   }
                else if (control == 2)
                   {
                        control2 = i/3;
                        z = 0;
                        control = 0;
                   }
                else if (control == 3)
                   {
                        control = 2;
                   }
                system("cls");
            }
            else if (z >= i)
            {
                printf("Si desea ver los otros productos de la pagina anterior seleccione 1, si desea salir seleccione 2\n");
                scanf("%d", &control);                
                if (control == 1)
                {
                    control2 = 2*(i/3);
                    z = i/3;
                    control = 0;
                }
                else
                {
                    control = 2;
                }
                system("cls");
            }
            else
            {
                printf("Seleccione una opcion valida\n");
            }
    } while (control != 2);
};

void mostrar_ventas()
{
    Factura har[100];
    
    FILE* flujo;
    flujo = fopen("Facturas.txt", "r");
    
    if (flujo == NULL)
    {
        printf("Error al abrir el archivo");
    }
    
    int i = 0;
    int n2;
    int nveces;
    while (feof(flujo) == 0)
    {   
        n2 = 0;       
        fscanf(flujo, "%s %d\n", har[i].nombre, &nveces);
        int n3 = nveces;
        while (nveces)
        {
            
            fscanf(flujo, "%s %s %d %f\n", har[i].comprados[n2].nombre, har[i].comprados[n2].marca, &har[i].comprados[n2].existencias, &har[i].comprados[n2].precio);
             nveces--;
             n2++;
             if (n2 == n3)
             {
             har[i].comprados[n2].nombre[0] = 'x';
             }
        }
       fscanf(flujo, "%f\n%f\n", &har[i].impuesto, &har[i].total );
       i++;
    }
    fclose(flujo);
    har[i].nombre[0] = 'x'; 
   
    int i1 = 0;
    float sum2 = har[i1].total + har[i1+1].total;
    for (i1 = 0; har[i1+1].nombre[0] != 'x'; i1++)
    {
        sum2 = sum2 + har[i1+2].total;
    }
    
    int u;
    int z=0;  
    int control=0;
    int control2 = i/3; 
    do
    {
        printf("     Listado De Facturas - Ventas Totales\n\n");      
        u=0; 
        printf("%d %d %d\n",z,i,control2);       
        while ((har[z].nombre[0] != 'x') && (z < control2))
        {
            printf("A nombre de: %s\n", har[z].nombre);
            for (u = 0; har[z].comprados[u].nombre[0] != 'x'; u++)
            {
                printf("%s %s %d %.2f\n", har[z].comprados[u].nombre, har[z].comprados[u].marca, har[z].comprados[u].existencias, har[z].comprados[u].precio);
            }
            printf("IVA = %.2f\ntotal = %.2f\n\n", har[z].impuesto, har[z].total);
            printf("---------------------------------\n");
            z++;
        }
        printf("\n\nVentas totales:   %.2f\n", sum2);
         if (z <= i/3)
            {
                printf("Si desea ver las facturas de la siguiente pagina seleccione 1, si desea salir seleccione 2\n");
                scanf("%d", &control);                
                if (control == 1)
                {
                    printf("%d %d %d\n",z,i,control2);
                    control2 = 2*(control2);
                    z = z - 1;
                    control = 0;
                }
                else
                {
                    control = 2;
                }
                system("cls");
            }
            else if ((z > i/3) && (z < i))
            {
                printf("Si desea ver las facturas de la siguiente pagina seleccione 1, si desea ir a la pagina anterior seleccione 2 y si desea salir seleccione 3\n");
                scanf("%d", &control);        
                if (control == 1)
                   {
                        printf("%d %d %d\n",z,i,control2);
                        control2 = i;
                        z = z - 1;
                        control = 0;
                   }
                else if (control == 2)
                   {
                        control2 = i/3;
                        z = 0;
                        control = 0;
                   }
                else if (control == 3)
                   {
                        control = 2;
                   }
                   system("cls");
            }
            else if (z >= i)
            {
                printf("Si desea ver las facturas de la pagina anterior seleccione 1, si desea salir seleccione 2\n");
                scanf("%d", &control);                
                if (control == 1)
                {
                    control2 = 2*(i/3);
                    z = i/3;
                    control = 0;
                }
                else 
                {
                    control = 2;
                }
                system("cls");
            }
            else
            {
                printf("Seleccione una opcion valida\n");
            }
    } while (control != 2);
        
};

void agregar_producto_admin()
{
    int n;
    Productos har[100];
    printf("\n\ncuantos productos quieres agregar?: ");
    scanf("%d", &n);
    printf("\nselecione signal en caso de que no posea dicha caracteristica\n");
    for (int i = 0; i < n; i++)
    {
        printf ("\ningresa los datos del nuevo producto a agregar %d\n", i+1);
        printf("Nombre: ");
        scanf(" %[^\n]", har[i].nombre);
        poner_espacios(har[i].nombre);
        printf("kg Peso(signal = 0): ");
        scanf("%f", &har[i].peso);
        printf("Marca: ");
        scanf(" %[^\n]", har[i].marca);
        poner_espacios(har[i].marca);
        printf("$ Precio: ");
        scanf("%f", &har[i].precio);
        printf("Existencias: "); 
        scanf("%d", &har[i].existencias);
        printf("talla(signal = &): ");
        scanf("%s", har[i].talla);
        printf("Capacidad(signal = 0): ");
        scanf("%f", &har[i].capacidad);
    }
    
    FILE* flujo = fopen("Productos.txt","a");
    if (flujo == NULL)
    {
        printf("Error al abrir el archivo");
    }

    for (int i = 0; i < n; i++)
    {
        fprintf(flujo, "%s %.2f %s %.2f %d %s %.2f\n", har[i].nombre, har[i].peso, har[i].marca, har[i].precio, har[i].existencias,
                    har[i].talla, har[i].capacidad);
    }
        
    fclose(flujo);
    system("cls");
    printf("\nSe han agregado los productos");
};
    
void agregar_cliente()
{
    int n;
    Usuario har;
    printf ("\ningresa los datos del nuevo usuario\n");
    printf("1er Nombre: ");
    scanf("%s", har.nombre);
    printf("1er Apellido: ");
    scanf("%s", &har.apellido);
    printf("Cedula: ");
    scanf("%d", &har.cedula);
    printf("Edad: "); 
    scanf("%d", &har.edad);
    printf("Clave: ");
    scanf("%s", har.clave);
    
    FILE* flujo = fopen("Usuario.txt","a");
    if (flujo == NULL)
    {
        printf("Error al abrir el archivo");
    }
    fprintf(flujo, "%s %s %s %d %d 0\n", har.nombre, har.apellido, har.clave, har.cedula, har.edad);
    fclose(flujo);
    system("cls");
    printf("\nSe ha agregado el usuario");
};

void eliminar_producto()
{
    Productos har[100];
    
    FILE* flujo;
    flujo = fopen("Productos.txt", "r");
    
    if (flujo == NULL)
    {
        printf("Error al abrir el archivo");
    }
    
    int i = 0;
    while (feof(flujo) == 0)
    {
        fscanf(flujo, "%s %f %s %f %d %s %f\n", har[i].nombre, &har[i].peso, har[i].marca, &har[i].precio, &har[i].existencias, har[i].talla, &har[i].capacidad);
        quitar_espacios(har[i].nombre);
        quitar_espacios(har[i].marca);
        i++;
    }
    fclose(flujo);
    har[i].nombre[0] = 'x';

    printf("\n");
    int edit = 0;
    int edit1 = 0;
    do
    {
        system("cls");
        printf("\n");
        for (int i = 0; har[i].nombre[0] != 'x'; i++)
        {
            printf("%d) %s\n", i+1, har[i].nombre);
        }
        printf("\n(0) salir\n");
        printf("Cual producto quieres eliminar?: ");
        scanf("%d", &edit);
        printf("\n");
        if (edit == 0)
        {
            break;
        }
        if (edit != 0)
        {
            printf("Estas seguro de eliminar este producto por completo?\n(1 = si/0 = no): ");
            scanf("%d", &edit1);
        }
        if (edit1 == 0)
        {
            continue;
        }
        else
        {   
            for (int i = edit-1; har[i].nombre[0] != 'x'; i++)
            {
                har[i] = har[i+1];
            }
            i++;
            har[i] = har[i+1];
        }
    }while(edit);
    
    for (int c2 = 0; har[c2].nombre[0] != 'x'; c2++)
    {
        poner_espacios(har[c2].nombre);
        poner_espacios(har[c2].marca);
    }

    FILE* flujo2;
    flujo2 = fopen("Productos.txt", "w");
    if (flujo2 == NULL)
    {
        printf("Error al abrir el archivo");
    }
    for (int i1 = 0; har[i1].nombre[0] != 'x'; i1++)
    {
        fprintf(flujo2, "%s %.2f %s %.2f %d %s %.2f\n", har[i1].nombre, har[i1].peso, har[i1].marca, har[i1].precio, har[i1].existencias,
                    har[i1].talla, har[i1].capacidad);
    } 
    fclose(flujo2);
    system("cls"); 
    printf("Se han modificado los productos");
};

void editar_producto()
{
    Productos har[100];
    
    FILE* flujo;
    flujo = fopen("Productos.txt", "r");
    
    if (flujo == NULL)
    {
        printf("Error al abrir el archivo");
    }
    
    int i = 0;
    while (feof(flujo) == 0)
    {
        fscanf(flujo, "%s %f %s %f %d %s %f\n", har[i].nombre, &har[i].peso, har[i].marca, &har[i].precio, &har[i].existencias, har[i].talla, &har[i].capacidad);
        quitar_espacios(har[i].nombre);
        quitar_espacios(har[i].marca);
        i++;
    }
    fclose(flujo);
    har[i].nombre[0] = 'x';
    
    printf("\n\n");
    int edit;
    do
    {
        system("cls");
        for (int i = 0; har[i].nombre[0] != 'x'; i++)
        {
            printf("%d)  %s\n", i+1, har[i].nombre);
        }
        printf("\n(0) salir\n");
        printf("Cual producto quieres editar?: ");
        scanf("%d", &edit);
        printf("\n");
        if (edit != 0)
        {
            int edit1;
            do
            {
                system("cls");
                printf("(1)%s\nDescripcion:\n(2)Marca: %s®\n(3)Peso: %.2fkg\n(4)Talla: %s\n(5)Capacidad: %.2fml\n(6)Stock: %d\n(7)Costo: %2.f$\n\n", 
                har[edit-1].nombre, har[edit-1].marca, har[edit-1].peso, har[edit-1].talla, har[edit-1].capacidad, har[edit-1].existencias,
                har[edit-1].precio);
                printf("(0) salir\n");
                printf("Cual caracteristica quieres editar?: ");
                scanf("%d", &edit1);

                switch(edit1)
                {
                    case 1:
                        printf("Selecione el nuevo nombre: ");
                        scanf(" %[^\n]", har[edit-1].nombre);
                        printf("Editado con exito\n");
                        break;
                    case 2:
                        printf("Selecione la nueva marca: ");
                        scanf(" %[^\n]", har[edit-1].marca);
                        printf("Editado con exito\n");
                        break;
                    case 3:
                        printf("Selecione el nuevo peso: ");
                        scanf("%f", &har[edit-1].peso);
                        printf("Editado con exito\n");
                        break;
                    case 4:
                        printf("Selecione la nueva talla: ");
                        scanf("%s", har[edit-1].talla);
                        printf("Editado con exito\n");
                        break;
                    case 5:
                        printf("Selecione la nueva capacidad: ");
                        scanf("%f", &har[edit-1].capacidad);
                        printf("Editado con exito\n");
                        break;
                    case 6:
                        printf("Selecione la nueva cant. de existencias: ");
                        scanf("%d", &har[edit-1].existencias);
                        printf("Editado con exito\n");
                        break;
                    case 7:
                        printf("Selecione el nuevo costo: ");
                        scanf("%f", &har[edit-1].precio);
                        printf("Editado con exito\n");
                        break;
                    default:
                        if (edit1 != 0)
                        {
                            printf("Ingrese una opcion valida");
                        }
                        break;
                }
            }while(edit1 != 0);
        }
    }while(edit != 0);   

    for (int i2 = 0; har[i2].nombre[0] != 'x'; i2++)
    {
        poner_espacios(har[i2].nombre);
        poner_espacios(har[i2].marca);
    }

    FILE* flujo2;
    flujo2 = fopen("Productos.txt", "w");
    if (flujo2 == NULL)
    {
        printf("Error al abrir el archivo");
    }
    for (int i1 = 0; har[i1].nombre[0] != 'x'; i1++)
    {
        fprintf(flujo2, "%s %.2f %s %.2f %d %s %.2f\n", har[i1].nombre, har[i1].peso, har[i1].marca, har[i1].precio, har[i1].existencias,
                    har[i1].talla, har[i1].capacidad);
    } 
    fclose(flujo2);
    printf("Se han modificado los productos");
};

void eliminar_cliente()
{
    Usuario har[100];

    FILE* flujo;
    flujo = fopen("Usuario.txt", "r");
    if (flujo == NULL)
    {
        printf("error al abrir el archivo\n");
    }
    
    int i = 0;
    while (feof(flujo) == 0)
    {
        fscanf (flujo, "%s %s %s %d %d %d\n", har[i].nombre, har[i].apellido, har[i].clave, &har[i].cedula, &har[i].edad, &har[i].intentos);
        i++;
    }
    fclose(flujo);
    har[i].nombre[0] = 'x';

    printf("\n");
    int edit;
    int edit1;
    do
    {
        system("cls");
        printf("\n");
        for (int i = 0; har[i].nombre[0] != 'x'; i++)
        {
            printf("%s num:%d\n", har[i].nombre, i+1);
        }
        printf("\n(0) salir\n");
        printf("Cual usuario quieres eliminar?: ");
        scanf("%d", &edit);
        printf("\n");
        if (edit != 0)
        {
            printf("Estas seguro de eliminar este usuario por completo?(1 = si/0 = no):");
            scanf("%d", &edit1);
        }
        if (edit1 == 0)
        {
            continue;
        }
        if (edit != 0)
        {   
            for (int i = edit-1; har[i].nombre[0] != 'x'; i++)
            {
                har[i] = har[i+1];
            }
            i++;
            har[i] = har[i+1];
        }
    }while(edit != 0);

    FILE* flujo2;
    flujo2 = fopen("Usuario.txt", "w");
    if (flujo2 == NULL)
    {
        printf("Error al abrir el archivo");
    }
    for (int i1 = 0; har[i1].nombre[0] != 'x'; i1++)
    {
        fprintf(flujo2, "%s %s %s %d %d %d\n", har[i1].nombre, har[i1].apellido, har[i1].clave, har[i1].cedula, har[i1].edad, har[i1].intentos);
    } 
    fclose(flujo2);
    system("cls");
    printf("Se han modificado los clientes");
};

void editar_cliente()
{
    Usuario har[100];

    FILE* flujo;
    flujo = fopen("Usuario.txt", "r");
    if (flujo == NULL)
    {
        printf("error al abrir el archivo\n");
    }
    
    int i = 0;
    while (feof(flujo) == 0)
    {
        fscanf (flujo, "%s %s %s %d %d %d\n", har[i].nombre, har[i].apellido, har[i].clave, &har[i].cedula, &har[i].edad, &har[i].intentos);
        i++;
    }
    fclose(flujo);
    har[i].nombre[0] = 'x';
    
    printf("\n\n");
    int edit;
    do
    {
        system("cls");
        for (int i = 0; har[i].nombre[0] != 'x'; i++)
        {
            printf("%s num:%d\n", har[i].nombre, i+1);
        }
        printf("\n(0) salir\n");
        printf("Cual cliente quieres editar?: ");
        scanf("%d", &edit);
        printf("\n");
        if (edit != 0)
        {
            int edit1;
            do
            {
                system("cls");
                printf("(1)Nombre: %s\n(2)Apellido: %s\n(3)Clave: %s\n(4)C.I: %d\n(5)Edad: %d\n\n", 
                        har[edit-1].nombre, har[edit-1].apellido, har[edit-1].clave, har[edit-1].cedula, har[edit-1].edad);
                printf("(0) salir\n");
                printf("Cual caracteristica quieres editar?: ");
                scanf("%d", &edit1);

                switch(edit1)
                {
                    case 1:
                        printf("Selecione el nuevo nombre: ");
                        scanf("%s", har[edit-1].nombre);
                        printf("Editado con exito\n");
                        break;
                    case 2:
                        printf("Selecione el nuevo apellido: ");
                        scanf("%s", har[edit-1].apellido);
                        printf("Editado con exito\n");
                        break;
                    case 3:
                        printf("Selecione la nueva clave: ");
                        scanf("%s", har[edit-1].clave);
                        printf("Editado con exito\n");
                        break;
                    case 4:
                        printf("Selecione la nueva cedula: ");
                        scanf("%d", &har[edit-1].cedula);
                        printf("Editado con exito\n");
                        break;
                    case 5:
                        printf("Seleciones la nueva edad: ");
                        scanf("%d", &har[edit-1].edad);
                        printf("Editado con exito\n");
                        break;
                    default:
                        if (edit1 != 0)
                        {
                            printf("Ingrese una opcion valida");
                        }
                        break;
                }
            }while(edit1 != 0);
        }
    }while(edit != 0);   

    FILE* flujo2;
    flujo2 = fopen("Usuario.txt", "w");
    if (flujo2 == NULL)
    {
        printf("Error al abrir el archivo");
    }
    for (int i1 = 0; har[i1].nombre[0] != 'x'; i1++)
    {
        fprintf(flujo2, "%s %s %s %d %d %d\n", har[i1].nombre, har[i1].apellido, har[i1].clave, har[i1].cedula, har[i1].edad, har[i1].intentos);
    } 
    fclose(flujo2);
    system("cls");
    printf("Se han modificado los clientes");
};

void desbloquear_cliente()
{
    Usuario har[100];

    FILE* flujo;
    flujo = fopen("Usuario.txt", "r");
    if (flujo == NULL)
    {
        printf("error al abrir el archivo\n");
    }
    
    int i = 0;
    while (feof(flujo) == 0)
    {
        fscanf (flujo, "%s %s %s %d %d %d\n", har[i].nombre, har[i].apellido, har[i].clave, &har[i].cedula, &har[i].edad, &har[i].intentos);
        i++;
    }
    fclose(flujo);
    har[i].nombre[0] = 'x';

    int vacio = 0;
    int select;
    do 
    {
        printf("     Base De Datos De Usuarios Bloqueados\n\n");

        for (int c3 = 0; har[c3].nombre[0] != 'x'; c3++)
        {
            if (har[c3].intentos == 3)
            {
                vacio = 1;
                printf("%s  usuario %d\n%s\nClave: %s\nC.I: %d\nEdad: %d\n\n", har[c3].nombre, c3 + 1, har[c3].apellido, har[c3].clave, har[c3].cedula, har[c3].edad);
            }
        }
        if (vacio == 0)
        {
            system("cls");
            printf("No hay usuarios bloqueados\n\n");
        }
    
        int confirm;
        printf("\n\nSalir = 0");
        printf("\nCual Usuario Desea Desbloquear?, marque el numero de usuario: ");
        scanf("%d", &select);
        if (select == 0)
        {
            break;
        }
        printf("\nRealmente deseas desbloquear este usuario?: Si = 1, No = 0\nSeleccione la opcion: " );
        scanf("%d", &confirm);
        if (confirm == 1)
        {
            har[select - 1].intentos = 0;
            system("cls");
            printf("Se ha desbloqueado el usuario exitosamente\n" );
        }
        system("cls");
    }while(select != 0);

    FILE* flujo2;
    flujo2 = fopen("Usuario.txt", "w");
    if (flujo2 == NULL)
    {
        printf("Error al abrir el archivo");
    }
    for (int i1 = 0; har[i1].nombre[0] != 'x'; i1++)
    {
        fprintf(flujo2, "%s %s %s %d %d %d\n", har[i1].nombre, har[i1].apellido, har[i1].clave, har[i1].cedula, har[i1].edad, har[i1].intentos);
    } 
    fclose(flujo2);
};