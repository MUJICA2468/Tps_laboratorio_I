#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
typedef struct {

    char nombre[50];
    int edad;
    //------------
    int estado;
    int dni;

}EPersona;

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
int GetInt(char* mensaje,char* mensajeError,int reIntentos,int minimo,int maximo,int* resultado);

/** \brief valida numeros enteros
 *
 * \param str char*
 * \return int Retorna un valor que valida el if
 *
 */
int esEntero(char *str);
/** \brief Realiza la apertura de espacios dentro del array
 *
 * \param lista EPersona* se llama a la estructura
 * \param cant int limite del array
 * \return int retorna los espacios libre de la array
 *
 */
int epersona_init(EPersona* lista, int cant);

/** \brief Se obtiene el espacio libre dentro del array
 *
 * \param lista EPersona* se llama a la estructura
 * \param cant int limite del array
 * \return int retorna los espacios libre de la array
 *
 */
int obtenerEspacioLibre(EPersona* lista, int cant);

/** \brief Busca el la array en busca de un espacio ocupado por el dni
 *
 * \param lista EPersona* se llama a la estructura
 * \param cant int limite del array
 * \param dni int Identificador de la persona
 * \return int retorna el dni a buscar
 *
 */
int buscarPorDni(EPersona* lista, int cant,int dni);
/** \brief Valida el ingreso de strings
 *
 * \param mensaje[] char se introduce un mensaje
 * \param imput[] char se introduce el dato
 * \return int retorna un valor que valida
 *
 */
int getString(char mensaje[], char imput[]);
/** \brief Valida la letras mayusculas y las minusculas
 *
 * \param str[] char
 * \return int retorna un valor que valida
 *
 */
int esSoloLetras(char str[]);
/** \brief Se puede introducir cadenas de caracteres
 *
 * \param mensaje[] char mensaje para indicar  que colocar
 * \param cant int limite del array
 * \param imput[] char se coloca la array para guardar los datos cargador
 * \return int
 *
 */
int getStringLetras(char mensaje[], int cant, char imput[]);
//----------------------------------------------------------------
/** \brief Carga los datos de una persona
 *
 * \param lista EPersona* llama a la estructura
 * \param cant int limite del array
 * \return int retorna un valor negativo
 *
 */
int epersona_agregarPersona(EPersona* lista, int cant);
/** \brief Imprime los datos cargados
 *
 * \param lista EPersona*  llama a la estructura
 * \param cant int limite del array
 * \return int retorna un valor negativo
 *
 */
int epersona_imprimir(EPersona* lista, int cant);
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
int epersona_borrarPersona(EPersona* lista, int cant, int dni);
/** \brief Ordena alfabeticamente los nombres
 *
 * \param lista EPersona* llama a la estructura
 * \param cant int limite del array
 * \param orden int ordena
 * \return int retorna un valor negativo
 *
 */
int epersona_ordenar(EPersona* lista,int cant, int orden);
/** \brief Muestra un grafico con cantidad de personas dependiendo de la edad
 *
 * \param lista EPersona* llama a la estructura
 * \param cant int limite del array
 * \return int retorna un valor negativo
 *
 */
int epersona_mostrarOrdenarEdad(EPersona* lista, int cant);
#endif // FUNCIONES_H_INCLUDED
