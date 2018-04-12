

/** \brief
 *
 * \param numeroUno float se guarda el primer número flotante para la operación
 * \param numeroDos float se guarda el segundo número flotante para la operación
 * \return float devuelve el resultado de la operación
 *
 */
float sumar(int numeroUno, int numeroDos)
{
    int aux = 0;
    float resultado;
    resultado = numeroUno + numeroDos;
    if(numeroUno < 0)
    {
        return aux = -1;
    }
    else{
        if(numeroDos < 0)
        {
            return aux = -1;
        }
    }
    return resultado;
}




/** \brief
 *
 * \param numeroUno float se guarda el primer número flotante para la operación
 * \param numeroDos float se guarda el segundo número flotante para la operación
 * \return int retorna el resultado de la operación
 *
 */
int restar(int numeroUno, int numeroDos)
{
    int aux = 0;
    float resultado;
    resultado = numeroUno - numeroDos;
    if(numeroUno < 0)
    {
        return aux = -1;
    }
    else{
        if(numeroDos < 0)
        {
            return aux = -1;
        }
    }
    return resultado;
}


/** \brief
 *
 * \param numeroUno float se guarda el primer número flotante para la operación
 * \param numeroDos float se guarda el segundo número flotante para la operación
 * \return int devuelve el resultado de la operación
 *
 */
int multiplicar(int numeroUno, int numeroDos)
{
    int aux = 0;
    float resultado;
    resultado = numeroUno * numeroDos;
    if(numeroUno < 0)
    {
        return aux = -1;
    }
    else{
        if(numeroDos < 0)
        {
            return aux = -1;
        }
    }
    return resultado;
}


/** \brief
 *
 * \param numeroUno float se guarda el primer número flotante para la operación
 * \param numeroDos float se guarda el segundo número flotante para la operación
 * \return float retorna el resultado de la operación
 *
 */
float dividir(float numeroUno, float numeroDos)
{
    int aux = 0;
    float resultado;

    resultado = numeroUno / numeroDos;

    if(numeroUno < 0)
    {
        return aux = -1;
    }
    else{
        if(numeroDos < 0)
        {
            return aux = -1;
        }
        else{
            if(numeroUno == 0)
            {
                return aux = 0;
            }
            else{
                if(numeroDos == 0)
                {
                    return aux = -1;
                }
            }
        }
    }
    return resultado;
}


/** \brief
 *
 * \param numeroUno int guarda el primmer numero para sacar el factorial de éste
 * \return int devuelve el factorial del primer numero que se introdusca
 *
 */
int factorial(int numeroUno)
{
    int factor = 1;
    int i;
    for(i=numeroUno; i >= 1; i --)
    {
        factor *= i;
    }

    return factor;
}

