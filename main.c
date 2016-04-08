#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int imprimirMenu(float operando1, float operando2);
void sumar(float operando1, float operando2, int flagIngresoOperando1, int flagIngresoOperando2);
void restar(float operando1, float operando2, int flagIngresoOperando1, int flagIngresoOperando2);
void multiplicar(float operando1, float operando2, int flagIngresoOperando1, int flagIngresoOperando2);
void dividir(float operando1, float operando2, int flagIngresoOperando1, int flagIngresoOperando2);
void calcularFactorial(int operando1, int flagIngresoOperando1);

int main()
{
    char seguir='s';
    float operando1=0;
    float operando2=0;
    int flagIngresoOperando1=0;
    int flagIngresoOperando2=0;

    while(seguir=='s')
    {
        switch(imprimirMenu(operando1, operando2))
        {
            case 1:
                    do{
                        printf("*************************************************\n");
                        printf("Ingrese el primer numero \n");
                        setbuf(stdin, NULL);
                    }
                    while(scanf("%f", &operando1)!= 1);
                    flagIngresoOperando1=1;
                break;
            case 2:
                    do{
                        printf("*************************************************\n");
                        printf("Ingrese el segundo numero \n");
                        setbuf(stdin, NULL);
                    }
                    while(scanf("%f", &operando2)!= 1);
                    flagIngresoOperando2=1;
                break;
            case 3:
                    printf("*************************************************\n");
                    sumar(operando1,operando2,flagIngresoOperando1,flagIngresoOperando2);
                    printf("*************************************************\n");
                break;
            case 4:
                    printf("*************************************************\n");
                    restar(operando1, operando2, flagIngresoOperando1, flagIngresoOperando2);
                    printf("*************************************************\n");
                break;
            case 5:
                    printf("*************************************************\n");
                    dividir(operando1,operando2, flagIngresoOperando1, flagIngresoOperando2);
                    printf("*************************************************\n");
                break;
            case 6:
                    printf("*************************************************\n");
                    multiplicar(operando1,operando2, flagIngresoOperando1, flagIngresoOperando2);
                    printf("*************************************************\n");
                break;
            case 7:
                    printf("*************************************************\n");
                    operando1 = (int) operando1;
                    calcularFactorial(operando1, flagIngresoOperando1);
                    printf("*************************************************\n");
                break;
            case 8:
                    printf("*************************************************\n");
                    sumar(operando1,operando2, flagIngresoOperando1, flagIngresoOperando2);
                    restar(operando1,operando2, flagIngresoOperando1, flagIngresoOperando2);
                    multiplicar(operando1,operando2, flagIngresoOperando1, flagIngresoOperando2);
                    dividir(operando1,operando2, flagIngresoOperando1, flagIngresoOperando2);
                    operando1 = (int) operando1;
                    calcularFactorial(operando1, flagIngresoOperando1);
                    printf("*************************************************\n");
                break;
            case 9:
                seguir = 'n';
                break;
            default:
                    printf("*************************************************\n");
                    printf("Ingrese una opcion valida (1-9)\n");
                    printf("*************************************************\n");
                break;
        }
    }
    return 0;
}
