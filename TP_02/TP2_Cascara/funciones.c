#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "funciones.h"

#define OCUPADO 0
#define LIBRE 1
/** \brief Se pueden ingresar numeros enteros
 *
 * \param mensaje char* Es el mensaje que se muestra para pedir el ingreso de datos
 * \param mensajeError char* Es el mensaje que se muestra si los datos son invalidos
 * \param reIntentos int Cantidad de intentos de ingreso
 * \param minimo int cantidad de numeros minima
 * \param maximo int cantidad de numeros maxima
 * \param resultado int* la variavle que se pretende validar para la carga de datos
 * \return int retorno de los ingresado
 *
 */
int GetInt(char* mensaje,char* mensajeError,int reIntentos,int minimo,int maximo,int* resultado)
{
    int retorno = -1;
    char buffer[4096];
    long auxiliarLong;
    do
    {
        printf("%s",mensaje);
        scanf("%4095s", buffer);
        if(esEntero(buffer) == 1)
        {
            auxiliarLong = atol(buffer);
            if(auxiliarLong >= minimo && auxiliarLong <= maximo)
            {
                *resultado = (int)auxiliarLong;
                retorno = 0;
                break;
            }
        }
        printf("%s",mensajeError);
        reIntentos--;
    }while(reIntentos >= 0);
    return retorno;
}
/** \brief valida numeros enteros
 *
 * \param str char*
 * \return int Retorna un valor que valida el if
 *
 */
int esEntero(char *str)
{
    int i;
    for(i=0;str[i] != '\0';i++)
    {
        if(str[i] > '9' || str[i] < '0')
            return 0;
    }
    return 1;
}
/** \brief Realiza la apertura de espacios dentro del array
 *
 * \param lista EPersona* se llama a la estructura
 * \param cant int limite del array
 * \return int retorna los espacios libre de la array
 *
 */
int epersona_init(EPersona* lista, int cant)
{
    int retorno = -1;
    int i;
    if(cant > 0 && lista != NULL)
    {
        for(i=0;i<cant;i++)
        {
            lista[i].estado = LIBRE;
            retorno = 0;
        }
    }
    return retorno;
}
/** \brief Se obtiene el espacio libre dentro del array
 *
 * \param lista EPersona* se llama a la estructura
 * \param cant int limite del array
 * \return int retorna los espacios libre de la array
 *
 */
int obtenerEspacioLibre(EPersona* lista, int cant)
{
    int retorno = -1;
    int i;
    if(cant > 0 && lista != NULL)
    {
        for(i=0;i<cant;i++)
        {
            if(lista[i].estado == LIBRE)
            {
                retorno= i;
                break;
            }
        }
    }
    return retorno;
}
/** \brief Busca el la array en busca de un espacio ocupado por el dni
 *
 * \param lista EPersona* se llama a la estructura
 * \param cant int limite del array
 * \param dni int Identificador de la persona
 * \return int retorna el dni a buscar
 *
 */
int buscarPorDni(EPersona* lista, int cant, int dni)
{
    int retorno = -1;
    int i;
    if(cant > 0 && lista != NULL)
    {
        for(i=0;i<cant;i++)
        {
            if(lista[i].estado == OCUPADO && lista[i].dni == dni)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}
/** \brief Valida el ingreso de strings
 *
 * \param mensaje[] char se introduce un mensaje
 * \param imput[] char se introduce el dato
 * \return int retorna un valor que valida
 *
 */
int getString(char mensaje[], char imput[])
{
    printf("%s", mensaje);
    scanf("%s", imput);
    return 0;
}
/** \brief Valida la letras mayusculas y las minusculas
 *
 * \param str[] char
 * \return int retorna un valor que valida
 *
 */
int esSoloLetras(char str[])
{
    int i=0;
    while(str[i] != '\0')
    {
        if((str[i] != ' ')&&(str[i] < 'a' || str[i] > 'z')&&(str[i] < 'A' || str[i] > 'Z'))
         return 1;
        i++;
    }
    return 0;
}
/** \brief Se puede introducir cadenas de caracteres
 *
 * \param mensaje[] char mensaje para indicar  que colocar
 * \param cant int limite del array
 * \param imput[] char se coloca la array para guardar los datos cargador
 * \return int
 *
 */
int getStringLetras(char mensaje[], int cant, char imput[])
{
    int retorno = -1;
    char aux[cant];
    getString(mensaje, aux);
    if(esSoloLetras(aux)==0)
    {
        strcpy(imput, aux);
        retorno = 0;
    }
    return retorno;
}
/** \brief Carga los datos de una persona
 *
 * \param lista EPersona* llama a la estructura
 * \param cant int limite del array
 * \return int retorna un valor negativo
 *
 */
int epersona_agregarPersona(EPersona* lista, int cant)
{
    int retorno = -1;
    int indice;
    if(cant > 0 && lista != NULL)
    {
        indice = obtenerEspacioLibre(lista, cant);
        if(indice >= 0)
        {
            if(lista[indice].estado == LIBRE)
            {
                printf("\nAGREGAR: \n");
                //getStringLetras("\nIngrese nombre: \n",50, lista[indice].nombre);
                GetInt("\nIngrese edad: \n", "\nEDAD invalida \n", 1, 1, 100, &lista[indice].edad);
                //GetInt("\nIngrese DNI: \n", "\nDNI invalido \n", 1, 1, 45000000, &lista[indice].dni);
                lista[indice].estado = OCUPADO;
                return 0;
            }
        }else{
                printf("\nSIN ESPACIO \n");
        }
    }
    return retorno;
}
/** \brief Imprime los datos cargados
 *
 * \param lista EPersona*  llama a la estructura
 * \param cant int limite del array
 * \return int retorna un valor negativo
 *
 */
int epersona_imprimir(EPersona* lista, int cant)
{
    int retorno = -1;
    int i;
    if(cant > 0 && lista != NULL)
    {
        printf("\n%5s %25s %16s \n","NOMBRE:","EDAD:","DNI:");
        for(i=0;i<cant;i++)
        {
            if(lista[i].estado == OCUPADO)
            {
                printf("\n%5s  %23d  %16d \n", lista[i].nombre, lista[i].edad, lista[i].dni);
                retorno = 0;
            }
        }
    }
    return retorno;
}
/** \brief Da de baja el dni de una persona, por lo tanto lo borra
 *
 * \param variable para cargar la llamada a la funcion de busqueda del dni
 * \param
 * \return retorno 0
 *
 */
/** \brief
 *
 * \param lista EPersona* llama a la estructura
 * \param cant int  limite del array
 * \param dni int para escribir el dni y darlo de baja
 * \return int retorna un valor negativo
 *
 */
int epersona_borrarPersona(EPersona* lista, int cant, int dni)
{
    int retorno = -1;
    int indice;
    if(cant > 0 && lista != NULL)
    {
        indice = buscarPorDni(lista, cant, dni);
        if(indice >= 0)
        {
            lista[indice].estado = LIBRE;
            retorno = 0;
        }else{
            printf("\nDNI inexistente \n");
        }
    }
    return retorno;
}
/** \brief Ordena alfabeticamente los nombres
 *
 * \param lista EPersona* llama a la estructura
 * \param cant int limite del array
 * \param orden int ordena
 * \return int retorna un valor negativo
 *
 */
int epersona_ordenar(EPersona* lista, int cant, int orden)
{
    EPersona aux;
    int retorno = -1;
    int i;
    int flagSwap = 0;
    if(cant > 0 && lista != NULL)
    {
        do{
            flagSwap = 0;
            for(i=0;i<cant-1;i++)
            {
                if(lista[i].estado == OCUPADO && lista[i+1].estado == OCUPADO)
                {
                    if((strcmp(lista[i].nombre, lista[i+1].nombre)>0  && !orden) ||(strcmp(lista[i].nombre, lista[i+1].nombre)<0  && orden))
                    {
                        aux = lista[i];
                        lista[i] = lista[i+1];
                        lista[i+1] = aux;
                        flagSwap = 1;
                    }
                }
            }
        }while(flagSwap);
    }

    return retorno;
}
/** \brief Muestra un grafico con cantidad de personas dependiendo de la edad
 *
 * \param lista EPersona* llama a la estructura
 * \param cant int limite del array
 * \return int retorna un valor negativo
 *
 */
int epersona_mostrarOrdenarEdad(EPersona* lista, int cant)
{
    int retorno = -1;
    int i;
    int contA = 0;
    int contB = 0;
    int contC = 0;
    int edad;
    int flag=0;
    if(cant > 0 && lista != NULL)
    {
        for(i=0;i<cant;i++)
        {
            if(lista[i].estado == OCUPADO)
            {
                edad = lista[i].edad;
                if(edad < 18)
                {
                    contA++;
                }else if(edad >= 19 && edad <= 35){
                    contB++;
                }else if(edad > 35){
                    contC++;
                }
                do{
                    if((contA == contB)&&(contA == contC)&&(contB==contC))
                    {
                    printf("-*---  *  ---*-\n");

                    }else if(contC > contA&&contC > contB){
                        printf("- ---    ---*-\n");
                        }else if(contB > contA&&contB > contC){
                        contB--;
                        printf("- ---  * --- -\n");
                        }else if((contB&&contC)< contA){
                        contA--;
                        printf("-*---    --- -\n");
                        }else if((contA > contC)&&(contB > contC)&&(contB == contA)){
                        printf("-*---  * --- -\n");
                        }else if((contB > contA)&&(contC > contA)&&(contB == contC)){
                        printf("- ---  * ---*-\n");
                        }
                        if((contA > contB)&&(contC > contB)&&(contA == contC)){
                        printf("-*---    ---*-\n");
                        }

                }while(flag);
            }
        }
        printf("<18---19-35--->35\n");
        printf("\nContador : %d %d %d", contA, contB, contC);
    }
    return retorno;
}
