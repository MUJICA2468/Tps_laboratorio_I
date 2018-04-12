

/** \brief
 *
 * \param numeroUno float se guarda el primer n�mero flotante para la operaci�n
 * \param numeroDos float se guarda el segundo n�mero flotante para la operaci�n
 * \return float devuelve el resultado de la operaci�n
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
 * \param numeroUno float se guarda el primer n�mero flotante para la operaci�n
 * \param numeroDos float se guarda el segundo n�mero flotante para la operaci�n
 * \return int retorna el resultado de la operaci�n
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
 * \param numeroUno float se guarda el primer n�mero flotante para la operaci�n
 * \param numeroDos float se guarda el segundo n�mero flotante para la operaci�n
 * \return int devuelve el resultado de la operaci�n
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
 * \param numeroUno float se guarda el primer n�mero flotante para la operaci�n
 * \param numeroDos float se guarda el segundo n�mero flotante para la operaci�n
 * \return float retorna el resultado de la operaci�n
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
 * \param numeroUno int guarda el primmer numero para sacar el factorial de �ste
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

