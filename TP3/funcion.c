#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "funcion.h"
#include "utn.h"
#include "movie.h"

/** \brief Se genera la pelicula en la pagina web
 *
 * \param pArrayMovies Movie** se llama a la array de peliculas

 * \return int retorna un valor negativo si no entra
 *
 */
int funcion_generateWebPage(Movie** pArrayMovies, int* qtyArrayMoviesA, int qtyArrayMoviesB, char* path)
{
    FILE* pFile;
    int retorno = -1;
    char titulo[100];
    char genero[50];
    int duracion;
    char descripcion[200];
    int puntaje;
    char link[200];
    int i;

    pFile = fopen(path,"w");
    if(pFile!=NULL && pArrayMovies!=NULL && *qtyArrayMoviesA >= 0 && qtyArrayMoviesB > 0 && qtyArrayMoviesB > *qtyArrayMoviesA)
    {
        retorno = 0;
        fprintf(pFile,"<!DOCTYPE html>\
                <!-- Template by Quackit.com -->\
                <html lang='en'>\
                <head>\
                <meta charset='utf-8'>\
                <meta http-equiv='X-UA-Compatible' content='IE=edge'>\
                <meta name='viewport' content='width=device-width, initial-scale=1'>\
                <!-- The above 3 meta tags *must* come first in the head; any other head content must come *after* these tags -->\
                <title>Lista peliculas</title>\
                <!-- Bootstrap Core CSS -->\
                <link href='css/bootstrap.min.css' rel='stylesheet'>\
                <!-- Custom CSS: You can use this stylesheet to override any Bootstrap styles and/or apply your own styles -->\
                <link href='css/custom.css' rel='stylesheet'>\
                <!-- HTML5 Shim and Respond.js IE8 support of HTML5 elements and media queries -->\
                <!-- WARNING: Respond.js doesn't work if you view the page via file:// -->\
                <!--[if lt IE 9]>\
                <script src='https://oss.maxcdn.com/libs/html5shiv/3.7.0/html5shiv.js'></script>\
                <script src='https://oss.maxcdn.com/libs/respond.js/1.4.2/respond.min.js'></script>\
                <![endif]-->\
                </head>\
                <body>\
                <div class='container'>\
                <div class='row'>\
                <!-- Repetir esto para cada pelicula -->\
                <article class='col-md-4 article-intro'>");

        for(i=0;i<* qtyArrayMoviesA;i++)
        {
            movie_getTitulo(pArrayMovies[i], titulo);
            movie_getGenero(pArrayMovies[i], genero);
            movie_getDuracion(pArrayMovies[i], &duracion);
            movie_getDescripcion(pArrayMovies[i], descripcion);
            movie_getPuntaje(pArrayMovies[i], &puntaje);
            movie_getLink(pArrayMovies[i], link);
            fprintf(pFile,"<a href='#'> <img class='img-responsive img-rounded' src=' %s ' alt=''> </a> <h3> <a href='#'> %s </a> </h3><ul><li>Género: %s </li> <li>Puntaje: %d </li> <li>Duración: %d </li> </ul> <p> %s </p>", link, titulo, genero,
            puntaje, duracion, descripcion);
        }
        printf("\nLa pelicula con el ID: %d fue subida\n", *qtyArrayMoviesA);
        fprintf(pFile,"</article>\
        <!-- Repetir esto para cada pelicula -->\
        </div>\
        <!-- /.row -->\
        </div>\
        <!-- /.container -->\
        <!-- jQuery -->\
        <script src='js/jquery-1.11.3.min.js'></script>\
        <!-- Bootstrap Core JavaScript -->\
        <script src='js/bootstrap.min.js'></script>\
        <!-- IE10 viewport bug workaround -->\
        <script src='js/ie10-viewport-bug-workaround.js'></script>\
        <!-- Placeholder Images -->\
        <script src='js/holder.min.js'></script>\
        </body>\
        </html>");
    }
    fclose(pFile);
    return retorno;
}

/** \brief se carga con los datos del archivo
 *
 * \param pArrayMovies Movie** se llama a la estructura
 * \param qtyArrayMoviesA int* cantidad que ocupa el dato
 * \param qtyArrayMoviesB int   cantidad ocupada cantidad total
 * \param path char* direccion de la pagina
 * \return int retorna un valor negativo si no entra
 *
 */
int funcion_loadMovieWebPage(Movie** pArrayMovies, int* qtyArrayMoviesA, int qtyArrayMoviesB, char* path)
{
    FILE* pFile;
    int retorno = -1;
    char bTitulo[100];
    char bGenero[50];
    char bDuracion[20];
    char bDescripcion[200];
    char bPuntaje[20];
    char bLink[200];
    char bIdMovie[10];

    int auxDuracion;
    int auxPuntaje;
    int auxIdMovie;
    pFile = fopen(path,"r");
    if(pFile!=NULL && pArrayMovies!=NULL &&  *qtyArrayMoviesA >= 0  && qtyArrayMoviesB > 0 && qtyArrayMoviesB > *qtyArrayMoviesA)
    {
        retorno = 0;
        while(!feof(pFile))
        {
            fscanf(pFile," %[^@]@%[^@]@%[^@]@%[^@]@%[^@]@%[^@]@%[^\n]\n",bLink, bTitulo, bGenero,
            bPuntaje, bDuracion, bDescripcion, bIdMovie);
            auxDuracion = atoi(bDuracion);
            auxPuntaje = atoi(bPuntaje);
            auxIdMovie = atoi(bIdMovie);
            pArrayMovies[*qtyArrayMoviesA] = movie_newMovieLoad(bTitulo, bGenero, auxDuracion,
            bDescripcion, auxPuntaje, bLink, auxIdMovie);
            (*qtyArrayMoviesA)++;
        }
    }
    fclose(pFile);
    return retorno;
}

/** \brief crea un archivo con datos cargados
 *
 * \param pArrayMovies Movie** se llama a la estructura
 * \param qtyArrayMoviesA int* cantidad que ocupa el dato
 * \param qtyArrayMoviesB int   cantidad ocupada cantidad total
 * \param path char* direccion de la pagina
 * \return int retorna un valor negativo si no entra
 *
 */
int funcion_dumpMovieWebPage(Movie** pArrayMovies, int* qtyArrayMoviesA, int qtyArrayMoviesB, char* path)
{
    FILE* pFile;
    int retorno = -1;
    char titulo[100];
    char genero[50];
    int duracion;
    char descripcion[200];
    int puntaje;
    char link[200];
    int idMovie;
    int i;

    pFile = fopen(path,"w");
    if(pFile!=NULL && pArrayMovies!=NULL &&  *qtyArrayMoviesA>= 0 && qtyArrayMoviesB > 0 && qtyArrayMoviesB > *qtyArrayMoviesA)
    {
        for(i=0;i<*qtyArrayMoviesA;i++)
        {
            movie_getTitulo(pArrayMovies[i], titulo);
            movie_getGenero(pArrayMovies[i], genero);
            movie_getDuracion(pArrayMovies[i], &duracion);
            movie_getDescripcion(pArrayMovies[i], descripcion);
            movie_getPuntaje(pArrayMovies[i], &puntaje);
            movie_getLink(pArrayMovies[i], link);
            movie_getIdMovie(pArrayMovies[i], &idMovie);
            fprintf(pFile," %s@%s@%s@%d@%d@%s@%d\n",link, titulo, genero,
            puntaje, duracion, descripcion, idMovie);
        }
    }
    fclose(pFile);
    return retorno;
}
