#include "funciones.h"
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define CANT_MAX_PERSONAS 20
#include <string.h>

int menu(void){

    int opcion;

    system("cls");
    printf("*******************************************\n");
    printf("*            MENU ABM                     *\n");
    printf("*******************************************\n");
    printf("* 1-Agregar persona.                      *\n");
    printf("* 2-Borrar persona.                       *\n");
    printf("* 3-Imprimir lista ordenada por  nombre.  *\n");
    printf("* 4-Imprimir grafico de edades.           *\n");
    printf("*-----------------------------------------*\n");
    printf("* 0-Salir.                                *\n");
    printf("*******************************************\n");


    opcion=capturarOpcionElegida();



    return opcion;
}

int capturarOpcionElegida(){
    int opcionElegida;
    fflush(stdin);
    scanf("%d",&opcionElegida);

    if(validarOpcionElegida(opcionElegida)==-1){
        opcionElegida=5;
    }

    return opcionElegida;

}

int validarOpcionElegida(int opcionAValidar){
    int esValido;
    if(opcionAValidar>-1 && opcionAValidar<5){
        esValido=0;
    }else{
        esValido=-1;
    }

    return esValido;
}

void inicializarLista(EPersona lista[]){
    int i;
    for(i=0;i<CANT_MAX_PERSONAS;i++){
        lista[i].estado=-1;
    }
}

int obtenerEspacioLibre(EPersona lista[]){
    int i;
    int espacioLibre=-1;
    for(i=0;i<CANT_MAX_PERSONAS;i++){
        if(lista[i].estado==-1){
            espacioLibre=i;
            break;
        }
    }
    return espacioLibre;
}

int buscarPorDni(EPersona lista[], int dni){
    int i;
    int retorno;
    for(i=0;i<CANT_MAX_PERSONAS;i++){
        if(lista[i].dni==dni && lista[i].estado==0){
            retorno=i;
            break;
        }else{
            retorno=-1;
        }
    }

    return retorno;
}

void doAltaPersona(EPersona lista[],int indiceEspacioLibre){

    int dni;
    int dniValido=-1;
    char nombre[20];
    char apellido[20];
    system("cls");

    printf("*******************************************\n");
    printf("*               Alta Persona              *\n");
    printf("*-----------------------------------------*\n");

    printf("*Ingrese DNI (8 digitos sin puntos):      *\n");
    scanf("%d",&dni);

    while(dniValido==-1){
        dniValido=validarDni(dni);
    }

    dni=dniValido;

    if(buscarPorDni(lista,dni)==-1){
        lista[indiceEspacioLibre].dni=dni;

        printf("*-----------------------------------------*\n");
        printf("*Ingrese Nombre:                          *\n");
        fflush(stdin);
        gets(nombre);
        if(strlen(nombre)<10){
        }else{
            printf("ERROR.El nombre solo puede contener hasta 10 letras).\n");
            fflush(stdin);
            gets(nombre);
        }

        strlwr(nombre);
        nombre[0]=toupper(nombre[0]);

        printf("*Ingrese Apellido:                        *\n");
        fflush(stdin);
        gets(apellido);
        if(strlen(apellido)<10){
        }else{
            printf("ERROR.El apellido solo puede contener hasta 10 letras).\n");
            fflush(stdin);
            gets(apellido);
        }
        strlwr(apellido);
        apellido[0]=toupper(apellido[0]);

        strcat(lista[indiceEspacioLibre].nombre,apellido);
        strcat(lista[indiceEspacioLibre].nombre," ");
        strcat(lista[indiceEspacioLibre].nombre,nombre);

        while(validarNombre(lista,indiceEspacioLibre)==-1);

        printf("*-----------------------------------------*\n");
        printf("*Ingrese Edad:                            *\n");
        scanf("%d",&lista[indiceEspacioLibre].edad);
        while(validarEdad(lista,indiceEspacioLibre)==-1);
        lista[indiceEspacioLibre].estado=0;
    }else{
        printf("ERROR.El dni ingresado ya existe.\n");
    }

        printf("*-----------------------------------------*\n");

    getch();

}

int validarNombre(EPersona lista[],int indiceEspacioLibre){

    int retorno;
    if(strlen(lista[indiceEspacioLibre].nombre)>49)
        {
            printf("ERROR. El nombre ingresado es demasiado largo. Reingrese.\n");
            fflush(stdin);
            gets(lista[indiceEspacioLibre].nombre);
            retorno=-1;
        }else{
            retorno=0;
        }
        return retorno;
}

int validarEdad(EPersona lista[],int indiceEspacioLibre){
    int esValido;
    int edadIngresada=lista[indiceEspacioLibre].edad;
    if(edadIngresada>0 && edadIngresada<100){
        esValido=0;
    }else{
        printf("ERROR. La edad ingresada no es valida. Reingrese (1-99).\n");
        fflush(stdin);
        scanf("%d",&lista[indiceEspacioLibre].edad);
        esValido=-1;
    }

    return esValido;
}

int validarDni(int dni){

char cDni[9];
int dniValido;

sprintf(cDni, "%d", dni);

    if(strlen(cDni)==8){
        dniValido=dni;
    }else{
        printf("ERROR. Debe ingresar el numero de DNI completo (8 digitos sin puntos).\n");
        fflush(stdin);
        dniValido=-1;
        scanf("%d",&dni);
        dniValido=validarDni(dni);
    }

return dniValido;
}

void ordenarPorNombre(EPersona lista[])
{
    EPersona temp;
	int i, j;

        for(i=0; i<CANT_MAX_PERSONAS-1; i++){
            for(j=i+1; j<CANT_MAX_PERSONAS; j++){
                if(strcmp(lista[i].nombre, lista[j].nombre) > 0){
                       temp=lista[i];
                       lista[i]=lista[j];
                       lista[j]=temp;

                }
            }
        }
}

void graficoEdades(EPersona* lista){

    int contMayor=0;
    int contMenores18=0;
    int contDe19a35=0;
    int contMayoresDe35=0;
    int i;
    int flag=0;

    for (i=0;i<CANT_MAX_PERSONAS;i++){
        if(lista[i].estado!=-1){
            if(lista[i].edad<18){
                contMenores18++;
            }else if(lista[i].edad>18&&lista[i].edad<35){
                contDe19a35++;
            }else {
                contMayoresDe35++;
            }
        }
    }

    if(contMenores18>contDe19a35&&contMenores18>contMayoresDe35){
        contMayor=contMenores18;
    }else if(contDe19a35>contMenores18&&contDe19a35>contMayoresDe35){
        contMayor=contDe19a35;
    }else{
        contMayor=contMayoresDe35;
    }

    for(i=contMayor; i>0; i--){
        if(i<= contMenores18){
            printf("*");
        }
        if(i<= contDe19a35){
            flag=1;
            printf("\t*");
        }
        if(i<= contMayoresDe35){
            if(flag==0)
                printf("\t\t*");
            if(flag==1)
                printf("\t*");
        }
        printf("\n");
    }
    printf("*--------------------*");
    printf("\n <18 | 19-35 | >35");

}

void borrarPersona (EPersona lista[]){
    int dni;
    int dniValido=-1;
    int indiceEncontrado;
    system("cls");

    printf("*******************************************\n");
    printf("*               Borrar Persona            *\n");
    printf("*-----------------------------------------*\n");

    printf("*Ingrese DNI (8 digitos sin puntos):      *\n");
    scanf("%d",&dni);

    while(dniValido==-1){
        dniValido=validarDni(dni);
    }

    dni=dniValido;

    indiceEncontrado=buscarPorDni(lista,dni);
    if(indiceEncontrado==-1){
        printf("ERROR. El dni ingresado no esta en la nomina.");
    }else{
        lista[indiceEncontrado].estado=-1;
    }
}
