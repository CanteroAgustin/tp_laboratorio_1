#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "peliculas.h"
#include "funciones.h"
#define ELEMENT 1000
/** \brief inicializa la extructura recibida
 *
 * \param arrayAviones Eaviones* extructura a inicializar
 * \param length int largo del array
 * \return void
 *
 */

void inicializar(EMovie* arrayMovies, int length)
{
    int i;

    if(arrayMovies != NULL && length > 0)
    {
        for(i=0;i<length;i++)
        {
            arrayMovies[i].isEmpty = -1;
        }
    }
}

/** \brief Encuentra la primer ubicacion disponible en el array
 *
 * \param arrayMovies* array recibido
 * \param length int largo del array
 * \return int la posicion de la ubicacion disponible si sale bien, sino -1
 *
 */
int buscarEspacioLibre(EMovie* arrayMovies, int length){
    int retorno = -1;
    int i;

    if(arrayMovies != NULL && length > 0)
    {
        for(i=0;i<length;i++)
        {
            if(arrayMovies[i].isEmpty==-1){
                retorno=i;
                break;
            }
        }
    }
    return retorno;
}

/**
 *  Agrega una pelicula al archivo binario
 *  @param movie la estructura a ser agregada al archivo
 *  @return retorna 1 o 0 de acuerdo a si pudo agregar la pelicula o no
 */
int agregarPelicula(EMovie* arrayMovies, int length){

    int retorno = 0, i, flagExiste=-1;
    int horas, minutos, puntaje;
    char titulo [50], descripcion[50],linkImagen[50], genero[50];
    int espacioLibre = buscarEspacioLibre(arrayMovies, length);


    system("cls");
    printf("*Agregando nueva pelicula.*\n");

    if(arrayMovies != NULL && length > 0 && espacioLibre!=-1)
    {
        while(getAlNumPunctSpace(titulo,"* Ingrese Titulo:\n  ","Error, el largo maximo es 50 caracteres. Reingrese\n", 0, 50));

        for(i=0;i<length;i++){
            if(strcmp(arrayMovies[i].titulo,titulo)==0 && arrayMovies[i].isEmpty==1){
                flagExiste=-1;
                break;
            }
            flagExiste=0;
        }
        if(!flagExiste){

            while(getString(genero,"* Ingrese Genero:\n  ","Error, el largo maximo es 20 caracteres. Reingrese\n", 0, 20));
            while(getInt(&horas,"* Ingrese Horas de duracion:\n  ","Error, fuera de rango. Reingrese\n", 0, 99));
            while(getInt(&minutos,"* Ingrese Minutos de duracion:\n  ","Error, fuera de rango. Reingrese\n", 0, 59));
            while(getAlNumPunctSpace(descripcion,"* Ingrese Descripcion:\n  ","Error, el largo maximo es 20 caracteres. Reingrese\n", 0, 1000));
            while(getString(linkImagen,"* Ingrese LinkImagen:\n  ","Error, el largo maximo es 20 caracteres. Reingrese\n", 0, 20));
            while(getInt(&puntaje,"* Ingrese Puntaje:\n  ","Error, fuera de rango. Reingrese\n", 1, 10));

            strcpy(arrayMovies[espacioLibre].titulo,titulo);
            strcpy(arrayMovies[espacioLibre].genero,genero);
            strcpy(arrayMovies[espacioLibre].descripcion,descripcion);
            strcpy(arrayMovies[espacioLibre].linkImagen,linkImagen);
            arrayMovies[espacioLibre].duracion.horas=horas;
            arrayMovies[espacioLibre].duracion.minutos=minutos;
            arrayMovies[espacioLibre].puntaje=puntaje;
            arrayMovies[espacioLibre].isEmpty=1;
        }
    }

    return retorno;
}
/**
 *  Borra una pelicula del archivo binario
 *  @param movie la estructura a ser eliminada al archivo
 *  @return retorna 1 o 0 de acuerdo a si pudo eliminar la pelicula o no
 */
int borrarPelicula(EMovie* arrayMovies, int length){
    int i, retorno=0;
    char titulo[50];
    system("cls");
    printf("*Borrando pelicula *\n");

    while(getAlNumPunctSpace(titulo,"* Ingrese Titulo:\n  ","Error, el largo maximo es 50 caracteres. Reingrese\n", 0, 50));

    for(i=0;i<length;i++){
        if(strcmp(titulo,arrayMovies[i].titulo)==0 && arrayMovies[i].isEmpty==1){
            arrayMovies[i].isEmpty=-1;
            retorno=1;
            break;
        }else if(i==length-1){
            printf("Error. No se encontro coincidencias con el titulo ingresado.\n");
            system("pause");
        }
    }

    return retorno;
}

/**
 *  Genera un archivo html a partir de las peliculas cargadas en el archivo binario.
 *  @param lista la lista de peliculas a ser agregadas en el archivo.
 *  @param nombre el nombre para el archivo.
 */
void generarPagina(EMovie* arrayMovies, char nombre[]){

    int i;
    FILE *f;
    f=fopen(nombre, "w");

    if(f == NULL)
    {
        printf("No se pudo abrir el archivo\n");
    }
    else
    {
        for(i=0;i<1000;i++){
            if(arrayMovies[i].isEmpty==1){
                fprintf(f,"<article class='col-md-4 article-intro'><a href='#'><img class='img-responsive img-rounded' src='%s' alt=''></a><h3><a href='#'>%s</a></h3><ul><li>Género:%s</li><li>Puntaje:%d</li><li>Duración:%d:%d</li></ul><p>%s</p></article><br><br><HR>",arrayMovies[i].linkImagen,arrayMovies[i].titulo,arrayMovies[i].genero,arrayMovies[i].puntaje,arrayMovies[i].duracion.horas,arrayMovies[i].duracion.minutos,arrayMovies[i].descripcion);
            }
        }
    }

      fclose(f);

      printf("Listado de peliculas creado con exito\n");
      system("pause");
}


/** \brief itera la estructura contando las peliculas ingresadas
 *
 * \param arrayMovies EMovie* extructura a iterar
 * \param length int largo de la extructura
 * \return int devuelve la cantidad de peliculas
 *
 */
int contarPeliculas(EMovie* arrayMovies,int length){

int i, cont=0;

    for(i=0;i<length;i++){
        if(arrayMovies[i].isEmpty==1){
            cont++;
        }
    }

return cont;
}

void modificarPelicula(EMovie* arrayMovies, int length){
    int i,opcion;
    char seguir='s';
    int horas, minutos, puntaje;
    char titulo [50], descripcion[50],linkImagen[50], genero[50];
    system("cls");
    printf("*Modificando pelicula *\n");

    while(getAlNumPunctSpace(titulo,"* Ingrese Titulo:\n  ","Error, el largo maximo es 50 caracteres. Reingrese\n", 0, 50));

    for(i=0;i<length;i++){
        if(strcmp(titulo,arrayMovies[i].titulo)==0 && arrayMovies[i].isEmpty==1){

            while(seguir=='s')
            {
                printSubMenuModificar();

                if(getInt(&opcion,"","\nERROR, ingrese una opcion valida.\n\n",0,9)==-1){
                    opcion=-1;
                }
                switch(opcion)
                {
                    case 1:
                            while(getAlNumPunctSpace(titulo,"* Ingrese Titulo:\n  ","Error, el largo maximo es 20 caracteres. Reingrese\n", 0, 20));
                            strcpy(arrayMovies[i].titulo,titulo);
                        break;
                    case 2:
                            while(getString(genero,"* Ingrese Genero:\n  ","Error, el largo maximo es 20 caracteres. Reingrese\n", 0, 20));
                            strcpy(arrayMovies[i].genero,genero);
                        break;
                    case 3:
                            while(getAlNumPunctSpace(descripcion,"* Ingrese Descripcion:\n  ","Error, el largo maximo es 20 caracteres. Reingrese\n", 0, 1000));
                            strcpy(arrayMovies[i].descripcion,descripcion);
                        break;
                    case 4:
                            while(getInt(&horas,"* Ingrese Horas de duracion:\n  ","Error, fuera de rango. Reingrese\n", 0, 99));
                            while(getInt(&minutos,"* Ingrese Minutos de duracion:\n  ","Error, fuera de rango. Reingrese\n", 0, 59));
                            arrayMovies[i].duracion.horas=horas;
                            arrayMovies[i].duracion.minutos=minutos;
                        break;
                    case 5:
                            while(getInt(&puntaje,"* Ingrese Puntaje:\n  ","Error, fuera de rango. Reingrese\n", 1, 10));
                            arrayMovies[i].puntaje=puntaje;
                        break;
                    case 6:
                            while(getAlNumPunctSpace(linkImagen,"* Ingrese LinkImagen:\n  ","Error, el largo maximo es 20 caracteres. Reingrese\n", 0, 20));
                            strcpy(arrayMovies[i].linkImagen,linkImagen);
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
        }else if(i==length-1 && opcion!=0){
            printf("Error. No se encontro coincidencias con el titulo ingresado.\n");
            system("pause");
        }
    }
}

int guardarEnArchivo(EMovie * x)
{

	FILE *f;

		f=fopen("bin.dat","wb");
		if(f == NULL)
		{
			return 1;
		}

	fwrite(x,sizeof(EMovie),ELEMENT,f);

	fclose(f);

	return 0;
}

int cargarDesdeArchivo(EMovie *x)
{
	int flag = 0;
	FILE *f;

	f=fopen("bin.dat", "rb");
	if(f==NULL)
	{
		f= fopen("bin.dat", "wb");
		if(f==NULL)
		{
			return 1;
		}

		flag=1;

	}

	if(flag ==0)
	{
	fread(x,sizeof(EMovie),ELEMENT,f);
    }

	fclose(f);
	return 0;

}
