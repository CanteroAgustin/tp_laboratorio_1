#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include "peliculas.h"
#define ELEMENT 1000

int main()
{
    char seguir='s', nombre[50];
    int opcion=0, i;
    EMovie arrayMovies[ELEMENT];
    inicializar(arrayMovies,ELEMENT);

    if(cargarDesdeArchivo(arrayMovies)){
		printf("No se pudo abrir el fichero");
	}
	else{
		printf("Se cargaron las estructuras con exito\n");
	}

	system("pause");

    while(seguir=='s')
    {
        printMenu();

        if(getInt(&opcion,"","\nERROR, ingrese una opcion valida.\n\n",0,9)==-1){
            opcion=-1;
        }

        switch(opcion)
        {
            case 1:
                    agregarPelicula(arrayMovies,ELEMENT);
                break;
            case 2:
                    if(contarPeliculas(arrayMovies,ELEMENT)<1){
                        printf("Error. Debe agregar al menos una pelicula para acceder a esta opcion\n");
                        system("pause");
                    }else{
                    borrarPelicula(arrayMovies,ELEMENT);
                    }
                break;
            case 3:
                    if(contarPeliculas(arrayMovies,ELEMENT)<1){
                        printf("Error. Debe agregar al menos una pelicula para acceder a esta opcion\n");
                        system("pause");
                    }else{
                        modificarPelicula(arrayMovies, ELEMENT);
                    }
                break;
            case 4:
                    if(contarPeliculas(arrayMovies,ELEMENT)<1){
                        printf("Error. Debe agregar al menos una pelicula para acceder a esta opcion\n");
                        system("pause");
                    }else{
                        while(getString(nombre,"* Ingrese nombre y extension del archivo:\n  ","Error, el largo maximo es 20 caracteres. Reingrese\n", 0, 20));
                        generarPagina(arrayMovies,nombre);
                    }
                break;
            case 5:
                    if(guardarEnArchivo(arrayMovies)){
						printf("\nNo se pudo abrir el fichero\n");
					}
					else{
						printf("\nSe guardo la informacion con exito\n");
					}
                    system("pause");
                break;
            case 6:
                    printf("*Peliculas cargadas*\n\n");
                    for(i=0;i<ELEMENT;i++){
                        if(arrayMovies[i].isEmpty==1)
                        printf("%d-%s\n",i,arrayMovies[i].titulo);
                    }
                    printf("\nMostrando %d peliculas...\n",contarPeliculas(arrayMovies, ELEMENT));
                    printf("\n");
                    system("pause");
                break;
            case 0:
                seguir = 'n';
                break;
            default:
                    printf("Ingrese una opcion correcta\n");
                    system("pause");
                break;
        }
    }

    return 0;
}
