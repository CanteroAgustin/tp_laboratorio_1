#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED



void sumar(float operando1, float operando2, int flagIngresoOperando1, int flagIngresoOperando2){
    float suma=0;
    if (flagIngresoOperando1 == 1 && flagIngresoOperando2 == 1){
        suma=operando1+operando2;
         printf("El resultado de la suma es: %.2f \n",suma);
    }else{
        printf("Error, no se puede realizar la operacion. Debe ingresar ambos operandos \n");
    }

}

void restar(float operando1, float operando2, int flagIngresoOperando1, int flagIngresoOperando2){
    float resta;
    if (flagIngresoOperando1 == 1 && flagIngresoOperando2 == 1){
        resta=operando1-operando2;
        printf("El resultado de la resta es: %.2f\n",resta);
    }else{
        printf("Error, no se puede realizar la operacion. Debe ingresar ambos operandos \n");
    }
}

void multiplicar(float operando1, float operando2, int flagIngresoOperando1, int flagIngresoOperando2){

    float multiplicacion;

    if (flagIngresoOperando1 == 1 && flagIngresoOperando2 == 1){
        multiplicacion=operando1*operando2;
        printf("El resultado de la multiplicacion es: %.2f\n",multiplicacion);
    }else{
        printf("Error, no se puede realizar la operacion. Debe ingresar ambos operandos \n");
    }
}

void dividir(float operando1, float operando2, int flagIngresoOperando1, int flagIngresoOperando2){

    float division;

    if (flagIngresoOperando1 == 1 && flagIngresoOperando2 == 1){
        if(operando2==0){
            printf("Error, la division por 0 no esta definida\n");
        }else{
            division=operando1/operando2;
            printf("El resultado de la division es: %.2f\n",division);
        }
    }else{
        printf("Error, no se puede realizar la operacion. Debe ingresar ambos operandos \n");
    }
}

void calcularFactorial(int operando1, int flagIngresoOperando1){

    long int factor=1;

    if (flagIngresoOperando1 == 1){
        if (operando1 <= 0){
            printf("Solo se puede calcular falctorial de un entero positivo\n");
        }else{
            while (operando1 > 0)
                {
                    factor = operando1 * factor;
                    operando1--;
                }
        printf("El factorial de (A) es: %ld\n", factor);
        }
    }else{
        printf("Error, no se puede realizar la operacion. Debe ingresar el primer operando \n");
    }
}

int imprimirMenu(float operando1, float operando2){

    int opcion=0;

    do{
        printf("*************************************************\n");
        printf("Ingrese una opcion (1-9):\n");
        printf("1- Ingresar 1er operando (A=%.2f)\n",operando1);
        printf("2- Ingresar 2do operando (B=%.2f)\n",operando2);
        printf("3- Calcular la suma (A+B)\n");
        printf("4- Calcular la resta (A-B)\n");
        printf("5- Calcular la division (A/B)\n");
        printf("6- Calcular la multiplicacion (A*B)\n");
        printf("7- Calcular el factorial (A!)\n");
        printf("8- Calcular todas las operacione\n");
        printf("9- Salir\n");

        setbuf(stdin, NULL);
    }
    while(scanf("%d", &opcion)!= 1);

    return opcion;
}
#endif // FUNCIONES_H_INCLUDED
