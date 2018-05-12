#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "funciones.h"
#define CANT 16

int main()
{
    EPersona lista[CANT];
    char seguir='s';
    int opcion=0;
    int auxId = 0;
    epersona_init(lista, CANT);
    while(seguir=='s')
    {
        GetInt("\n1- Agregar persona \n2- Borrar persona \n3- Imprimir lista ordenada por  nombre \n4- Imprimir grafico de edades\n\n5- Salir \n", "\nINVALIDO \n", 2, 0, 5, &opcion);
        switch(opcion)
        {
            case 1:
                epersona_agregarPersona(lista, CANT);
                break;
            case 2:
                printf("\nBAJAR \n");
                GetInt("\nIngrese DNI a dar de baja: \n", "\nDNI invalido \n", 2, 1 ,45000000, &auxId);
                epersona_borrarPersona(lista, CANT, auxId);
                break;
            case 3:
                printf("\nIMPRIMIR: \n");
                epersona_ordenar(lista, CANT, 0);
                epersona_imprimir(lista, CANT);
                break;
            case 4:
                epersona_mostrarOrdenarEdad(lista,CANT);
                break;
            case 5:
                seguir = 'n';
                break;
        }
        system("pause");
        system("cls");
    }
    return 0;
}
