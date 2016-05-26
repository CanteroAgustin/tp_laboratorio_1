#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "funciones.h"

/** \brief Imprime un menu de opciones predefinido.
 * \return void
 */
void printMenu(){
    system("cls");
    printf("*************************************\n");
    printf("*         CINEMA COMPANY.           *\n");
    printf("*-----------------------------------*\n");
    printf("*   Menu de gestion de peliculas.   *\n");
    printf("*-----------------------------------*\n");
    printf("* 1- Agregar Pelicula.              *\n");
    printf("* 2- Borrar pelicula.               *\n");
    printf("* 3- Modificar pelicula.            *\n");
    printf("* 4- Generar pagina web.            *\n");
    printf("* 5- Guardar datos.                 *\n");
    printf("* 6- Listar peliculas.              *\n");
    printf("* 0- Salir.                         *\n");
    printf("*************************************\n");
}

/** \brief Imprime un menu de opciones predefinido.
 * \return void
 */
void printSubMenuModificar(){
    system("cls");
    printf("*************************************\n");
    printf("*         CINEMA COMPANY.           *\n");
    printf("*-----------------------------------*\n");
    printf("*   Modificar pelicula.             *\n");
    printf("*-----------------------------------*\n");
    printf("* 1- Modificar titulo.              *\n");
    printf("* 2- Modificar genero.              *\n");
    printf("* 3- Modificar descripcion.         *\n");
    printf("* 4- Modificar duracion.            *\n");
    printf("* 5- Modificar puntaje.             *\n");
    printf("* 6- Modificar Link imagen.         *\n");
    printf("* 0- Salir.                         *\n");
    printf("*************************************\n");
}

/**
* \brief Solicita un número al usuario y lo valida
* \param input Se carga el numero ingresado
* \param message Es el mensaje a ser mostrado
* \param eMessage Es el mensaje a ser mostrado en caso de error
* \param lowLimit Limite inferior a validar
* \param hiLimit Limite superior a validar
* \return Si obtuvo el numero [0] si no [-1]
*
*/
int getInt(int* input,char message[],char eMessage[], int lowLimit, int hiLimit)
{
    int aux;
    int retorno;

    printf("%s",message);
    fflush(stdin);

    if(scanf("%d",&aux)!=1){
        printf("\nError, solo se puede ingresar digitos.Reingrese.\n\n");
        retorno = -1;
        system("pause");
    }else if(aux >=lowLimit && aux<=hiLimit){
            *input=aux;
            retorno = 0;
        }else{
            printf("%s",eMessage);
            system("pause");
            retorno = -1;
        }

    return retorno;
}

/**
* \brief Solicita una cadena de caracteres al usuario y la valida
* \param input Se carga el string ingresado
* \param message Es el mensaje a ser mostrado
* \param eMessage Es el mensaje a ser mostrado en caso de error
* \param lowLimit Longitud mínima de la cadena
* \param hiLimit Longitud máxima de la cadena
* \return Si obtuvo la cadena [0] si no [-1]
*
*/
int getString(char* input,char message[],char eMessage[], int lowLimit, int hiLimit)
{
    char aux[46034];
    int retorno;
    int i;
    int noEsNumero = 0;
    printf("%s",message);

    fflush(stdin);
    gets(aux);
    if(strlen(aux)>0){
        for (i=0;i<strlen(aux);i++){
            if(isdigit(aux[i])){
                printf("Error, debe ingresar solo letras. Reingrese.\n");
                retorno = -1;
                noEsNumero=0;
                system("pause");
                break;
            }else{
                noEsNumero=1;
            }
        }
    }else{
        retorno = -1;
        noEsNumero=0;
        printf("Error, Este campo no puede quedar vacio. Reingrese\n");
    }
    if(noEsNumero==1){
        if( strlen(aux)>=lowLimit && strlen(aux)<=hiLimit){
            strcpy(input,aux);
            retorno = 0;
        }else{
            printf("%s",eMessage);
            retorno = -1;
            system("pause");
        }
    }

    return retorno;
}

/**
* \brief Solicita una cadena de caracteres al usuario y la valida
* \param input Se carga el string ingresado
* \param message Es el mensaje a ser mostrado
* \param eMessage Es el mensaje a ser mostrado en caso de error
* \param lowLimit Longitud mínima de la cadena
* \param hiLimit Longitud máxima de la cadena
* \return Si obtuvo la cadena [0] si no [-1]
*
*/
int getAlNumPunctSpace(char* input,char message[],char eMessage[], int lowLimit, int hiLimit)
{
    char aux[46034];
    int retorno;
    int i;
    int noEsNumero = 0;
    printf("%s",message);

    fflush(stdin);
    gets(aux);
    if(strlen(aux)>0){
        for (i=0;i<strlen(aux);i++){
            if(!isalnum(aux[i]) && !ispunct(aux[i]) && !isspace(aux[i])){
                printf("Error, Ingreso un caracter erroneo. Reingrese.\n");
                retorno = -1;
                noEsNumero=0;
                system("pause");
                break;
            }else{
                noEsNumero=1;
            }
        }
    }else{
        retorno = -1;
        noEsNumero=0;
        printf("Error, Este campo no puede quedar vacio. Reingrese\n");
    }
    if(noEsNumero==1){
        if( strlen(aux)>=lowLimit && strlen(aux)<=hiLimit){
            strcpy(input,aux);
            retorno = 0;
        }else{
            printf("%s",eMessage);
            retorno = -1;
            system("pause");
        }
    }

    return retorno;
}

int getAllString(char* input,char message[],char eMessage[], int lowLimit, int hiLimit){
    char aux[46034];
    int retorno;
    printf("%s",message);
    fflush(stdin);
    gets(aux);
    if(!strlen(aux)>0){
        retorno = -1;
        printf("Error, Este campo no puede quedar vacio. Reingrese\n");
    }
    if( strlen(aux)>=lowLimit && strlen(aux)<=hiLimit){
        strcpy(input,aux);
        retorno = 0;
    }else{
        printf("%s",eMessage);
        retorno = -1;
        system("pause");
    }
    return retorno;
}
