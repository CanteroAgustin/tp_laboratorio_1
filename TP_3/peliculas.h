#ifndef PELICULAS_H_INCLUDED
#define PELICULAS_H_INCLUDED

typedef struct{
    int horas;
    int minutos;
}Eduracion;

typedef struct{
    char titulo[20];
    char genero[20];
    char descripcion[50];
    int puntaje;
    char linkImagen[50];
    int isEmpty;
    Eduracion duracion;
}EMovie;

//Movies library
int buscarEspacioLibre(EMovie* arrayMovies, int length);
int agregarPelicula(EMovie* arrayMovies, int length);
int borrarPelicula(EMovie* arrayMovies, int length);
void generarPagina(EMovie* arrayMovies, char nombre[]);
void inicializar (EMovie* arraMovies, int length);
int contarPeliculas(EMovie* arrayMovies,int length);
void modificarPelicula(EMovie* arrayMovies, int length);

//file library
int cargarDesdeArchivo(EMovie *);
int guardarEnArchivo(EMovie *);

#endif // PELICULAS_H_INCLUDED
