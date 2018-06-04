#ifndef MOVIE_H_INCLUDED
#define MOVIE_H_INCLUDED
typedef struct{
    char titulo[100];
    char genero[50];
    int duracion;
    char descripcion[200];
    int puntaje;
    char link[200];
    int idMovie;
}Movie;
#endif // MOVIE_H_INCLUDED


Movie* movie_new();
void movie_deleteMovie(Movie* this);
Movie* movie_newMovieUp(char* titulo, char* genero, int duracion, char* descripcion, int puntaje,char* link);
Movie* movie_newMovieLoad(char* titulo, char* genero,int duracion,char* descripcion,int puntaje,char* link, int id);
int movie_alta(Movie **arrayMovies, int *qtyMovie);
int movie_baja(Movie **arrayMovies, int *qtyMovie, int id);
int movie_modificar(Movie **arrayMovies, int *qtyMovie, int id);
int movie_lista(Movie** arrayMovies, int qtyMovie);
//SETS
//////////////////////////////////////////////////////

int movie_setTitulo(Movie *this, char* titulo);
int movie_setGenero(Movie *this, char* genero);
int movie_setDuracion(Movie *this, int duracion);
int movie_setDescripcion(Movie *this, char* descripcion);
int movie_setPuntaje(Movie *this, int puntaje);
int movie_setLink(Movie *this, char* link);
//GETS
//////////////////////////////////////////////////////
int movie_getIdMovie(Movie *this, int* id);
int movie_getTitulo(Movie *this, char* titulo);
int movie_getGenero(Movie *this, char* genero);
int movie_getDuracion(Movie *this, int* duracion);
int movie_getDescripcion(Movie *this, char* descripcion);
int movie_getPuntaje(Movie *this, int* puntaje);
int movie_getLink(Movie *this, char* link);

