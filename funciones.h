#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#include <math.h>


/**
 * \brief Recibe dos numeros, los suma e imprime el resultado por pantalla
 * \param operando1, operando 2 numeros a sumar
 *
 */
void sumar(float operando1, float operando2){
    float suma = 0;
    suma=operando1+operando2;
    printf("El resultado de la suma (A+B) es: %.2f\n",suma);
}

/**
 * \brief Recibe dos numeros, los resta e imprime el resultado por pantalla
 * \param operando1, operando 2 numeros a restar
 *
 */
void restar(float operando1, float operando2){
    float resta;
    resta=operando1-operando2;
    printf("El resultado de la resta (A-B) es: %.2f\n",resta);
}

/**
 * \brief Recibe dos numeros, los multiplica e imprime el resultado por pantalla
 * \param operando1, operando 2 numeros a multiplicar
 *
 */
void multiplicar(float operando1, float operando2){
    float multiplicacion;
    multiplicacion=operando1*operando2;
    printf("El resultado de la multiplicacion (A*B) es: %.2f\n",multiplicacion);
}

/**
 * \brief Recibe dos numeros, los divide e imprime el resultado por pantalla
 * \param operando1, operando 2 numeros a dividir
 *
 */
void dividir(float operando1, float operando2){
    float division;
    if (operando2 == 0){
        printf("No se puede dividir por 0\n");


    }else{
    division=operando1/operando2;
    printf("El resultado de la division (A/B) es: %.2f\n",division);
    }

}

/**
 * \brief Recibe un numero, calcula el factorial e imprime el resultado por pantalla
 * \param operando1, numero sobre el que se calculara el factorial
 *
 */
void calcularFactorial(float operando1){
    int factor=1;
    int auxiliar = 0;
    auxiliar = (int) operando1;
    if (operando1 <= 0){
        printf("Solo se puede calcular falctorial de un entero positivo\n");


    }else{
        while (auxiliar > 0)
            {


                factor = auxiliar * factor;
                auxiliar--;
            }
            printf("El factorial de (A) es: %d\n", factor);
    }

}

#endif // FUNCIONES_H_INCLUDED
