#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "movie.h"
#include "utn.h"

/** \brief Es un Id estatico
 *
 * \param this Movie* llama a la estructura
* \param idMovie int variable para el id de la pelicula
 * \return int retorna un valor negativo si no entra
 *
 */
static int movie_setIdMovie(Movie* this, int idMovie);

/** \brief Asigna espacios en la memoria dinamica
 *
 * \return Movie* retorna NULL si no logra asingar mas espacio
 *
 */
Movie* movie_newMovie()
{
    Movie* arrayMovies=NULL;
    arrayMovies = (Movie*) malloc(sizeof(Movie));
    return arrayMovies;
}

/** \brief Se subiran los datos de una nueva pelicula
 *
 * \param titulo char* Se suben los datos del titulo
 * \param genero char* Se suben los datos del genero
 * \param duracion int Se suben los datos del duracion
 * \param descripcion char* Se suben los datos del descipcion
 * \param puntaje int Se suben los datos del puntaje
 * \param link char* Se suben los datos del link
 * \return Movie* retorna un valor negativo si no entra
 *
 */
Movie* movie_newMovieUp(char* titulo, char* genero, int duracion, char* descripcion, int puntaje,char* link)
{
    Movie *retorno = movie_newMovie();
    //if(titulo!=NULL && descripcion!=NULL && link!=NULL && retorno!=NULL){
        movie_setTitulo(retorno, titulo);
        movie_setGenero(retorno, genero);
        movie_setDuracion(retorno, duracion);
        movie_setDescripcion(retorno, descripcion);
        movie_setPuntaje(retorno, puntaje);
        movie_setLink(retorno, link);
        movie_setIdMovie(retorno, -1);
    //}
    return retorno;
}

/** \brief Carga los datos ingresados previamente
 *
 * \param titulo char* se cargan los datos del titulo
 * \param genero char* se cargan los datos del genero
 * \param duracion int se cargan los datos del duracion
 * \param descripcion char* se cargan los datos del descripcion
 * \param puntaje int se cargan los datos del puntaje
 * \param link char* se cargan los datos del link
 * \param id int se cargan los datos del ID
 * \return Movie*
 *
 */
Movie* movie_newMovieLoad(char* titulo, char* genero,int duracion,char* descripcion,int puntaje,char* link, int id)
{
    Movie* auxMovie = movie_newMovie();
    if(     !movie_setTitulo(auxMovie, titulo)
       &&   !movie_setGenero(auxMovie, genero)
       &&   !movie_setDuracion(auxMovie, duracion)
       &&   !movie_setDescripcion(auxMovie, descripcion)
       &&   !movie_setPuntaje(auxMovie, puntaje)
       &&   !movie_setLink(auxMovie, link)
       &&   !movie_setIdMovie(auxMovie, id))
    {
        return auxMovie;
    }
    movie_deleteMovie(auxMovie);
    return NULL;
}

/** \brief Aca se realiza la cargas de los datos
 *
 * \param arrayMovies Movie** se llama a la estructura
 * \param qtyMovie int* escarba la estructura
 * \return int retorna un valor negativo si no entra
 *
 */
int movie_alta(Movie** arrayMovies, int* qtyMovie)
{
    int retorno = -1;
    char titulo[100];
    char genero[50];
    int duracion;
    char descripcion[200];
    int puntaje;
    char link[200];
    if(arrayMovies!=NULL && *qtyMovie > -1)
    {
        getString("Ingrese titulo de la pelicula\n", titulo);
        getString("Ingrese genero de la pelicula\n", genero);
        getValidInt("Ingrese duracion de la pelicula \n", "INVALIDO \n", &duracion, 50, 120, 2);
        getString("Ingrese una descripcion\n", descripcion);
        getValidInt("Ingrese puntaje de la pelicula \n", "INVALIDO \n", &puntaje, 1,100,2);
        getValidUrl("Ingrese un link \n", "\nINVALIDO \n","\nSE PASO \n",link,200,2);
        retorno = 0;
        arrayMovies[*qtyMovie]= movie_newMovieUp(titulo, genero, duracion, descripcion, puntaje, link);
        *qtyMovie = *qtyMovie+1;
        printf("Id pelicula: %d fue subida y listya para subir\n", *qtyMovie);
    }
    return retorno;
}


/** \brief Se modifica los datos de determinada pelicula
 *
 * \param ArrayMovie Movie** llama a la estructura
 * \param qtyMovieActual int* limite
 * \param id int variable para ingresar el id
 * \return int retorna un valor negativo si no entra
 *
 */
int movie_modificar(Movie **ArrayMovie, int *qtyMovieActual, int id)
{
    int retorno = -1;
    char auxTitulo[100];
    char auxGenero[50];
    int auxDuracion;
    char auxDescripcion[200];
    int auxPuntaje;
    char auxLink[200];
    int auxId;
    int i;

    if(ArrayMovie != NULL && *qtyMovieActual > 0)
    {
        retorno = -2;
        if(id >= 0)
        {
            for(i = 0; i < *qtyMovieActual; i++)
            {
                movie_getIdMovie(ArrayMovie[i], &auxId);
                if(auxId == id)
                {
                    retorno = 0;
                    break;
                }
                retorno = -3;
            }
            if(retorno == 0)
            {
            getString("Ingrese el titulo: ", auxTitulo);
            getString("Ingrese el genero: ", auxGenero);
            getString("Ingrese la descripcion: ", auxDescripcion);
            getValidInt("Ingrese la duracion: ", "\nError\n", &auxDuracion, 30, 250, 2);
            getValidUrl("Ingrese el link de la imagen: ", "\nError\n", "Link de la imagen demasiado largo", auxLink, 200, 2);
            getValidInt("Ingrese el puntaje: ", "\nError\n", &auxPuntaje, 1, 10, 2);
            ArrayMovie[i] = movie_newMovieUp(auxTitulo, auxGenero, auxDuracion, auxDescripcion, auxPuntaje, auxLink);
            }
        }
    }
    return retorno;
}

int movie_baja(Movie **arrayMovies, int *qtyMovie, int id)
{
    int retorno = -1;
    int i;
    int j;
    int auxId;

    if(arrayMovies != NULL && *qtyMovie > 0)
    {
        retorno = -2;
        if(id >= 0)
        {
            for(i = 0; i < *qtyMovie; i++)
            {
                movie_getIdMovie(arrayMovies[i], &auxId);
                if(auxId == id)
                {
                    retorno = 0;
                    break;
                }
                retorno = -3;
            }
            if(retorno == 0)
            {
                if(i < *qtyMovie)
                {
                    for(j = i; j < *qtyMovie; j++)
                    {
                        arrayMovies[i] = arrayMovies[i+1];
                    }
                }
                movie_deleteMovie(arrayMovies[*qtyMovie]);
                *qtyMovie = *qtyMovie - 1;
            }
        }
    }
    return retorno;
}

/** \brief Se vacia el espacio asigna por el newMovie
 *
 * \param this Movie* llama a la estructura
 * \return void
 *
 */
void movie_deleteMovie(Movie* this)
{
    free(this);
}

/** \brief Ingresa el titulo al array de peliculas
 *
 * \param this Movie* Array de las peliculas
 * \param titulo char* Titulo de la pelicula a guardar
 * \return int 0 Si todo es correcto, -1 Error
 *
 */
int movie_setTitulo(Movie* this, char* titulo)
{
    int retorno = -1;
    if(this != NULL && titulo != NULL)
    {
        retorno = 0;
        strcpy(this->titulo, titulo);
    }
    return retorno;
}
/** \brief Obtiene el titulo de una pelicula
 *
 * \param this Movie* Array de las peliculas
 * \param titulo char* Donde se guarda el titulo por referencia
 * \return int retorna un valor negativo si no entra
 *
 */
int movie_getTitulo(Movie* this, char* titulo)
{
    int retorno = -1;
    if(this != NULL && titulo != NULL)
    {
        strcpy(titulo,this->titulo);
        retorno = 0;
    }
    return retorno;
}
/** \brief Ingresa la duracion al array de peliculas
 *
 * \param this Movie* se llama a la Array de las peliculas
 * \param genero char* duracion de la pelicula a guardar
 * \return int retorna un valor negativo si no entra
 *
 */
int movie_setGenero(Movie* this, char* genero)
{
    int retorno = -1;
    if(this != NULL && genero != NULL)
    {
        retorno = 0;
        strcpy(this->genero, genero);
    }
    return retorno;
}
/** \brief Obtiene la duracion de una pelicula
 *
 * \param this Movie* se llama a la Array de las peliculas
 * \param genero char* Donde se guarda el genero por referencia
 * \return int retorna un valor negativo si no entra
 *
 */
int movie_getGenero(Movie* this, char* genero)
{
    int retorno = -1;
    if(this != NULL && genero != NULL)
    {
        retorno = 0;
        strcpy(genero, this->genero);
    }
    return retorno;
}
/** \brief Ingresa la duracion al array de peliculas
 *
 * \param this Movie* se llama a la Array de las peliculas
 * \param duracion char* duracion de la pelicula a guardar
 * \return int retorna un valor negativo si no entra
 *
 */
int movie_setDuracion(Movie* this, int duracion)
{
    int retorno = -1;
    if(this != NULL)
    {
        retorno = 0;
        this->duracion = duracion;
    }
    return retorno;
}
/** \brief Obtiene la duracion de una pelicula
 *
 * \param this Movie* se llama a la Array de las peliculas
 * \param duracion char* Donde se guarda el titulo por referencia
 * \return int retorna un valor negativo si no entra
 *
 */
int movie_getDuracion(Movie* this, int* duracion)
{
    int retorno = -1;
    if(this != NULL && duracion != NULL)
    {
        retorno = 0;
        *duracion = this->duracion;
    }
    return retorno;
}
/** \brief Ingresa la descripcion al array de peliculas
 *
 * \param this Movie* se llama a la Array de las peliculas
 * \param descripcion char* descipcion de la pelicula a guardar
 * \return int retorna un valor negativo si no entra
 *
 */
int movie_setDescripcion(Movie* this, char* descripcion)
{
    int retorno = -1;
    if(this != NULL && descripcion != NULL)
    {
        retorno = 0;
        strcpy(this->descripcion, descripcion);
    }
    return retorno;
}
/** \brief Obtiene la descripcion de una pelicula
 *
 * \param this Movie* se llama a la Array de las peliculas
 * \param descripcion char* Donde se guarda la descripcion por referencia
 * \return int retorna un valor negativo si no entra
 *
 */
int movie_getDescripcion(Movie* this, char* descripcion)
{
    int retorno = -1;
    if(this != NULL && descripcion != NULL)
    {
        retorno = 0;
        strcpy(descripcion,this->descripcion);
    }
    return retorno;
}
/** \brief Ingresa el puntaje al array de peliculas
 *
 * \param this Movie* se llam a la Array de las peliculas
 * \param puntaje char* puntaje de la pelicula a guardar
 * \return int retorna un valor negativo si no entra
 *
 */
int movie_setPuntaje(Movie* this, int puntaje)
{
    int retorno = -1;
    if(this != NULL)
    {
        retorno = 0;
        this->puntaje = puntaje;
    }
    return retorno;
}
/** \brief Obtiene el puntaje de una pelicula
 *
 * \param this Movie* se llam a la Array de las peliculas
 * \param puntaje char* Donde se guarda el Puntaje por referencia
 * \return int retorna un valor negativo si no entra
 *
 */
int movie_getPuntaje(Movie* this, int* puntaje)
{
    int retorno = -1;
    if(this != NULL && puntaje != NULL)
    {
        retorno = 0;
        *puntaje = this->puntaje;
    }
    return retorno;
}
/** \brief Ingresa el Link al array de peliculas
 *
 * \param this Movie* se llana a la Array de las peliculas
 * \param link char* link de la pelicula a guardar
 * \return int retorna un valor negativo si no entra
 *
 */
int movie_setLink(Movie* this, char* link)
{
    int retorno = -1;
    if(this != NULL && link != NULL)
    {
        retorno = 0;
        strcpy(this->link, link);
    }
    return retorno;
}
/** \brief Obtiene el Link de una pelicula
 *
 * \param this Movie* se llama a la Array de las peliculas
 * \param link char* Donde se guarda el Link por referencia
 * \return int retorna un valor negativo si no entra
 *
 */
int movie_getLink(Movie* this, char* link)
{
    int retorno = -1;
    if(this != NULL && link != NULL)
    {
        retorno = 0;
        strcpy(link, this->link);
    }
    return retorno;
}
/** \brief Ingresa el ID al array de peliculas
 *
 * \param this Movie* se llama a la Array de las peliculas
 * \param id char* ID de la pelicula a guardar
 * \return int retorna un valor negativo si no entra
 *
 */
static int movie_setIdMovie(Movie* this, int idMovie)
{
    static int maximoId= -1;
    int retorno = -1;
    if(this != NULL)
    {
        retorno = 0;
        if(idMovie > 0)
        {
            this->idMovie = idMovie;
            if(idMovie > maximoId)
                maximoId = idMovie;
        }
        else
        {
            maximoId++;
            this->idMovie =  maximoId;
        }
    }
    return retorno;
}
/** \brief Obtiene el ID de una pelicula
 *
 * \param this Movie* se llama al Array de las peliculas
 * \param id char* Donde se guarda el ID por referencia
 * \return int retorna un valor negativo si no entra
 *
 */
int movie_getIdMovie(Movie* this, int* idMovie)
{
    int retorno = -1;
    if(this != NULL && idMovie != NULL)
    {
        retorno = 0;
        *idMovie = this->idMovie;
    }
    return retorno;
}

