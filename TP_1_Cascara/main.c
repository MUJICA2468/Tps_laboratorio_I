#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"


int main()
{
    int primerOperando = 0, segundoOperando = 0;

    int resultadoFactorial;
    float resultadoSuma = 0;
    float resultadoResta = 0;
    float resultadoDividir = 0;
    float resultadoMultiplicar = 0;

    char seguir='s';
    int opcion=0;


    while(seguir=='s')
    {
        printf("\n 1- Ingresar 1er operando (A=%d)\n", primerOperando);
        printf(" 2- Ingresar 2do operando (B=%d)\n", segundoOperando);
        printf(" 3- Calcular la suma (A+B)\n");
        printf(" 4- Calcular la resta (A-B)\n");
        printf(" 5- Calcular la division (A/B)\n");
        printf(" 6- Calcular la multiplicacion (A*B)\n");
        printf(" 7- Calcular el factorial (A!)\n");
        printf(" 8- Calcular todas las operaciones\n");
        printf(" 9- Salir\n");
        scanf("%d",&opcion);

        fflush(stdin);

        switch(opcion)
        {
            case 1:
                printf("Ingrese el primer operando \n");
                scanf("%d", &primerOperando);
                break;
            case 2:
                printf("Ingrese el segundo operando \n");
                scanf("%d", &segundoOperando);
                break;
            case 3:
                resultadoSuma = sumar(primerOperando, segundoOperando);
                printf("\n EL RESULTADO de (%d + %d) ES : %f \n\n",  primerOperando, segundoOperando, resultadoSuma);
                break;
            case 4:
                resultadoResta = restar(primerOperando, segundoOperando);
                printf("\n EL RESULTADO de (%d - %d) ES : %f \n\n",  primerOperando, segundoOperando, resultadoResta);
                break;
            case 5:
                resultadoDividir = dividir(primerOperando, segundoOperando);
                printf("\n EL RESULTADO de (%d / %d) ES : %f \n\n",  primerOperando, segundoOperando, resultadoDividir);
                break;
            case 6:
                resultadoMultiplicar = multiplicar(primerOperando, segundoOperando);
                printf("\n EL RESULTADO de (%d * %d) ES : %f \n", primerOperando, segundoOperando, resultadoMultiplicar);
                break;
            case 7:
                resultadoFactorial = factorial(primerOperando);
                printf("\n EL factorial de (%d) es : %d \n", primerOperando, resultadoFactorial);
                break;
            case 8:
                resultadoSuma = sumar(primerOperando, segundoOperando);
                printf("\n El resultado de la SUMA de (%d + %d) es : %f \n", primerOperando, segundoOperando, resultadoSuma);

                resultadoResta = restar(primerOperando, segundoOperando);
                printf("\n El resultado de la RESTA de (%d - %d) es : %f \n", primerOperando, segundoOperando, resultadoResta);

                resultadoDividir = dividir(primerOperando, segundoOperando);
                printf("\n El resultado de la DIVISION de (%d / %d) es : %f \n", primerOperando, segundoOperando, resultadoDividir);

                resultadoMultiplicar = multiplicar(primerOperando, segundoOperando);
                printf("\n El resultado de la MULTIPLICACION de (%d * %d) es : %f \n", primerOperando, segundoOperando, resultadoMultiplicar);
                break;
            case 9:
                seguir = 'n';
                break;
            default:
                printf("\n INCORRECTO, inserte opciones validas \n");
                break;
            }
    }
    return 0;

}


