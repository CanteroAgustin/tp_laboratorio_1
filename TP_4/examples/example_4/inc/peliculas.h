#ifndef PELICULAS_H_INCLUDED
#define PELICULAS_H_INCLUDED
#include "ArrayList.h"
typedef struct{
    int horas;
    int minutos;
}Eduracion;

typedef struct{
    char titulo[20];
    char genero[20];
    char descripcion[50];
    int puntaje;
    char linkImagen[500];
    int isEmpty;
    Eduracion duracion;
}EMovie;

//Movies library
EMovie* newMovie();
int buscarEspacioLibre(EMovie* arrayMovies, int length);
int borrarPelicula(EMovie* arrayMovies, int length);
void generarPagina(EMovie* arrayMovies, char nombre[]);
void inicializar (EMovie* arraMovies, int length);
int contarPeliculas(EMovie* arrayMovies,int length);
void modificarPelicula(EMovie* arrayMovies, int length);
EMovie* getMovieByTitulo(ArrayList* lista, char title[]);
void printMovie(EMovie* movie);
//file library
int cargarDesdeArchivo(EMovie *);
int guardarEnArchivo(EMovie *);

#endif // PELICULAS_H_INCLUDED
