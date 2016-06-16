#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "../inc/peliculas.h"
#include "../inc/funciones.h"
#define ELEMENT 1000
void printMovie(EMovie* movie)
{
    printf("Titulo:%s Descripcion:%s\r\n",movie->titulo,movie->descripcion);
}

EMovie* getMovieByTitulo(ArrayList* lista, char title[]){
  int i;
  EMovie* mAux=NULL;
  EMovie* retorno=NULL;
  for(i=0;i<lista->len(lista);i++)
  {
      mAux = lista->get(lista,i);
      if(strcmp(mAux->titulo,title)==0){
        retorno = mAux;
        break;
      }
  }
  return retorno;
}

/**
 *  brief instancia una nueva pelicula
 *  @param void
 *  @return devuelve el puntero a la pelicula
 */
EMovie* newMovie(){

    EMovie* returnAux = NULL;
    EMovie* movie = malloc(sizeof(EMovie));

    int horas, minutos, puntaje;
    char titulo [50], descripcion[50],linkImagen[500], genero[50];

    if(movie != NULL)
    {
        while(getAlNumPunctSpace(titulo,"* Ingrese Titulo:\n  ","Error, el largo maximo es 50 caracteres. Reingrese\n", 0, 50));
        while(getString(genero,"* Ingrese Genero:\n  ","Error, el largo maximo es 20 caracteres. Reingrese\n", 0, 20));
        while(getInt(&horas,"* Ingrese Horas de duracion:\n  ","Error, fuera de rango. Reingrese\n", 0, 99));
        while(getInt(&minutos,"* Ingrese Minutos de duracion:\n  ","Error, fuera de rango. Reingrese\n", 0, 59));
        while(getAlNumPunctSpace(descripcion,"* Ingrese Descripcion:\n  ","Error, el largo maximo es 20 caracteres. Reingrese\n", 0, 1000));
        while(getAllString(linkImagen,"* Ingrese LinkImagen:\n  ","Error, el largo maximo es 500 caracteres. Reingrese\n", 0, 500));
        while(getInt(&puntaje,"* Ingrese Puntaje:\n  ","Error, fuera de rango. Reingrese\n", 1, 10));

        strcpy(movie->titulo,titulo);
        strcpy(movie->genero,genero);
        strcpy(movie->descripcion,descripcion);
        strcpy(movie->linkImagen,linkImagen);
        movie->duracion.horas=horas;
        movie->duracion.minutos=minutos;
        movie->puntaje=puntaje;
        movie->isEmpty=1;
        returnAux=movie;
    }
    return returnAux;
}

/** \brief inicializa la extructura recibida
 *
 * \param arrayMovies Emovies* extructura a inicializar
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
        fprintf(f,"<!DOCTYPE html><!-- Template by Quackit.com --><html lang='en'>");
        fprintf(f,"<head><meta charset='utf-8'><meta http-equiv='X-UA-Compatible' content='IE=edge'><meta name='viewport' content='width=device-width, initial-scale=1'><!-- The above 3 meta tags *must* come first in the head; any other head content must come *after* these tags --><title>Lista peliculas</title><!-- Bootstrap Core CSS --><link href='css/bootstrap.min.css' rel='stylesheet'><!-- Custom CSS: You can use this stylesheet to override any Bootstrap styles and/or apply your own styles --><link href='css/custom.css' rel='stylesheet'><!-- HTML5 Shim and Respond.js IE8 support of HTML5 elements and media queries --><!-- WARNING: Respond.js doesn't work if you view the page via file:// --><!--[if lt IE 9]><script src='https://oss.maxcdn.com/libs/html5shiv/3.7.0/html5shiv.js'></script><script src='https://oss.maxcdn.com/libs/respond.js/1.4.2/respond.min.js'></script><![endif]--></head>");
        fprintf(f,"<body><div class='container'><div class='row'>");

        for(i=0;i<1000;i++){
            if(arrayMovies[i].isEmpty==1){
                fprintf(f,"<!-- Repetir esto para cada pelicula --><article class='col-md-4 article-intro'><a href='#'><img class='img-responsive img-rounded' src='%s' alt=''></a><h3><a href='#'>%s</a></h3><ul><li>G&eacutenero:%s</li><li>Puntaje:%d</li><li>Duraci&oacuten:%d:%d</li></ul><p>%s</p></article><!-- Repetir esto para cada pelicula -->",arrayMovies[i].linkImagen,arrayMovies[i].titulo,arrayMovies[i].genero,arrayMovies[i].puntaje,arrayMovies[i].duracion.horas,arrayMovies[i].duracion.minutos,arrayMovies[i].descripcion);
            }
        }
        fprintf(f,"</div><!-- /.row --></div><!-- /.container --><!-- jQuery --><script src='js/jquery-1.11.3.min.js'></script><!-- Bootstrap Core JavaScript --><script src='js/bootstrap.min.js'></script><!-- IE10 viewport bug workaround --><script src='js/ie10-viewport-bug-workaround.js'></script><!-- Placeholder Images --><script src='js/holder.min.js'></script></body></html>");
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
    char titulo [50], descripcion[50],linkImagen[500], genero[50];
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
                            while(getAllString(linkImagen,"* Ingrese LinkImagen:\n  ","Error, el largo maximo es 500 caracteres. Reingrese\n", 0, 500));
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
