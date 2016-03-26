#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"


int main()
{
    char seguir='s';
    int opcion=0;
    float operando1=0; float operando2=0;
    while(seguir=='s')
    {
        do{
        printf("-------------------------------------------------------------\n");
        printf("1- Ingresar 1er operando (A=%.2f)\n",operando1);
        printf("2- Ingresar 2do operando (B=%.2f)\n",operando2);
        printf("3- Calcular la suma (A+B)\n");
        printf("4- Calcular la resta (A-B)\n");
        printf("5- Calcular la division (A/B)\n");
        printf("6- Calcular la multiplicacion (A*B)\n");
        printf("7- Calcular el factorial (A!)\n");
        printf("8- Calcular todas las operaciones\n");
        printf("9- Salir\n");
        printf("-------------------------------------------------------------\n");
        setbuf(stdin, NULL);
        }
        while(scanf("%d", &opcion)!= 1);


        switch(opcion)
        {
            case 1:
                    do{
                    printf("Ingrese el primer numero \n");
                    setbuf(stdin, NULL);
                    }
                    while(scanf("%f", &operando1)!= 1);
                break;
            case 2:
                    do{
                    printf("Ingrese el segundo numero \n");
                    setbuf(stdin, NULL);
                    }
                    while(scanf("%f", &operando2)!= 1);
                break;
            case 3:
                    printf("-------------------------------------------------------------\n");
                    sumar(operando1,operando2);
                    printf("-------------------------------------------------------------\n");
                break;
            case 4:
                    printf("-------------------------------------------------------------\n");
                    restar(operando1,operando2);
                    printf("-------------------------------------------------------------\n");
                break;
            case 5:
                    printf("-------------------------------------------------------------\n");
                    dividir(operando1,operando2);
                    printf("-------------------------------------------------------------\n");
                break;
            case 6:
                    printf("-------------------------------------------------------------\n");
                    multiplicar(operando1,operando2);
                    printf("-------------------------------------------------------------\n");
                break;
            case 7:
                    printf("-------------------------------------------------------------\n");
                    calcularFactorial(operando1);
                    printf("-------------------------------------------------------------\n");
                break;
            case 8:
                    printf("-------------------------------------------------------------\n");
                    sumar(operando1,operando2);
                    restar(operando1,operando2);
                    dividir(operando1,operando2);
                    multiplicar(operando1,operando2);
                    calcularFactorial(operando1);
                    printf("-------------------------------------------------------------\n");
                break;
            case 9:
                seguir = 'n';
                break;
            default:
                    printf("Ingrese una opcion valida 1-9\n");
                break;
        }


    }
    return 0;
}
