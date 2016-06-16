/*
    utest example : Unit test examples.
    Copyright (C) <2016>  <Mauricio Davila>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ELEMENTS 5

#define ELEMENT 1000

#include "../inc/ArrayList.h"
#include "../inc/Employee.h"
#include "../inc/peliculas.h"
#include "../inc/funciones.h"


void printArrayListMovie(ArrayList* lista)
{
  int i=0;
  for(i=0;i<lista->len(lista);i++)
  {
      EMovie* pAux = lista->get(lista,i);
      printf("%d) ",i);
      printMovie(pAux);
  }
}

int run(void);
int run2(void);

int main(void)
{
    run();

     //   run2();

    return 0;
}

int run(void){
    char seguir='s';
    //char titulo[50];
    int opcion=0;
    ArrayList* lista = al_newArrayList();
    while(seguir=='s')
    {
        printMenu();

        if(getInt(&opcion,"","\nERROR, ingrese una opcion valida.\n\n",0,9)==-1){
            opcion=-1;
        }

        switch(opcion)
        {
            case 1:
                    lista->add(lista,newMovie());
                break;
            case 2:
                    //while(getAlNumPunctSpace(titulo,"* Ingrese Titulo:\n  ","Error, el largo maximo es 50 caracteres. Reingrese\n", 0, 50));
                    //EMovie* movie = getMovieByTitulo(lista,titulo);
                    //int index = lista->indexOf(lista,movie);
                    //printf("\n indice:%d\n",index);
                    //system("pause");
                    //lista->remove(lista,2);
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                    system("pause");
                break;
            case 6:
                    printArrayListMovie(lista);
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




