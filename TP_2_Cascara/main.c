#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include <conio.h> //windows
#define CANT_MAX_PERSONAS 20

int main()
{
    char seguir='s';
    int opcion=0;
    int i;
    int indiceEspacioLibre;
    int cont=0;
    EPersona lista[CANT_MAX_PERSONAS];
    inicializarLista(lista);

    while(seguir=='s')
    {

        opcion=menu();

        switch(opcion)
        {
            case 1:
                indiceEspacioLibre=obtenerEspacioLibre(lista);
                if(indiceEspacioLibre==-1){
                    printf("ERROR. No hay espacio disponible.");
                    getch();
                }else{
                    doAltaPersona(lista,indiceEspacioLibre);
                }
                break;
            case 2:
                    borrarPersona(lista);
                getch();
                break;
            case 3:
                    system("cls");
                    printf("*******************************************\n");
                    printf("*           Nomina de Personal            *\n");
                    printf("*-----------------------------------------*\n");
                    printf(" |Apellido y Nombre\tEdad\tDNI      |      \n");
                    printf(" ----------------------------------------- \n");
                    ordenarPorNombre(lista);
                    for(i=0;i<CANT_MAX_PERSONAS;i++){
                        if(lista[i].estado!=-1){
                            cont++;
                            printf("%d %s \t%d \t%d\n",cont,lista[i].nombre,lista[i].edad,lista[i].dni);

                        }
                    }
                    printf("*-----------------------------------------*\n");
                    printf("%d - resultados mostrandose...\n",cont);
                    printf("*-----------------------------------------*\n");
                    if(cont==0){
                        printf("-No hay resultados para mostrar.");
                    }
                cont=0;
                getch();
                break;
            case 4:
                graficoEdades(lista);
                getch();
                break;
            case 5:
                printf("ERROR. No eligio una opcion valida.\n");
                getch();
                break;
            case 0:
                seguir = 'n';
                break;
        }
    }

    return 0;
}
