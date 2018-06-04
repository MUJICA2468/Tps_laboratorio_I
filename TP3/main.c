#include <stdio.h>
#include <stdlib.h>

#include "funcion.h"
#include "utn.h"
#include "movie.h"

#define QTY_CANT 30
int main()
{
    Movie* pArrayMovie[QTY_CANT];
    int QTY_OCUPADO = 0;
    char seguir='s';
    int opcion=0;
    int idMovie;
    funcion_loadMovieWebPage(pArrayMovie, &QTY_OCUPADO, QTY_CANT, "archivo de datos/datos.txt");
    while(seguir=='s')
    {
        getIntB("1- Agregar pelicula\
                \n2- Borrar pelicula\
                \n3- Generar pagina web\
                \n4- Modificar\
                \n5- Salir\n","\nINVALIDO \n",2, 1, 6, &opcion);
        switch(opcion)
        {
            case 1:
                printf("Agregar\n");
                movie_alta(pArrayMovie, &QTY_OCUPADO);
                break;
            case 2:
                printf("Borrar\n");
                getValidInt("Ingrese el ID de la pelicula a dar de baja \n", "INVALIDO \n", &idMovie, 0, 30, 2);
                movie_baja(pArrayMovie, &QTY_OCUPADO, idMovie);
                break;
            case 3:
                printf("Generar pag\n");
                funcion_generateWebPage(pArrayMovie, &QTY_OCUPADO, QTY_CANT, "web page/TP3_template/template/index.html");
               break;
            case 4:
                printf("Modificar\n");
                getValidInt("Ingrese el ID de la pelicula a modificar \n", "INVALIDO \n", &idMovie, 0, 30, 2);
                movie_modificar(pArrayMovie, &QTY_OCUPADO, idMovie);
                break;
            case 5:
                seguir = 'n';
                break;
        }
    }
    funcion_dumpMovieWebPage(pArrayMovie, &QTY_OCUPADO, QTY_CANT, "archivo de datos/datos.txt");
    return 0;
}
