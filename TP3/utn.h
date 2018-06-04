#ifndef UTN_H_INCLUDED
#define UTN_H_INCLUDED



#endif // UTN_H_INCLUDED
int getIntA(char* mensaje, char* mensajeError, int contadorIntentos, int numeroMax, int numeroMin, int* resultado);
int getIntB(char* mensaje,char* mensajeError,int reIntentos,int minimo,int maximo,int* resultado);
int getFloatA(char* mensaje,char* mensajeError,float reIntentos,float minimo,float maximo,float* resultado);
int getInt(char* mensaje);
float getFloatB(char* mensaje);
char getChar(char* mensaje);
char getNumeroAleatorio(int desde , int hasta, int iniciar);
int getString(char mensaje[],char input[]);
int getStringLetras(char mensaje[],char input[]);
int getStringNumeros(char mensaje[],char input[]);
int getStringNumerosFlotantes(char mensaje[],char input[]);
int getValidString(char requestMessage[],char errorMessage[], char errorMessageLenght[],char input[], int maxLenght,int attemps);
int getValidInt(char requestMessage[],char errorMessage[], int* input,int lowLimit, int hiLimit,int attemps);
int getValidFloat(char requestMessage[],char errorMessage[], float* input,float lowLimit, float hiLimit,int attemps);
int getValidCuit(char requestMessage[],char errorMessage[], char errorMessageLenght[],char input[],int minLength, int maxLenght,int attemps);
int getValidUrl(char *requestMessage,char *errorMessage, char *errorMessageLenght,char *input, int maxLenght,int attemps);

int suma(int numeroUno, int numeroDos);
int resta(int numeroUno, int numeroDos);
int dividir(int numeroUno, int numeroDos);
int multiplicacion(int numeroUno, int numeroDos);
float calculo(int numeroUno, int numeroDos, char operacion);

int esEntero(char *str);
float esFlotante(char* mensaje);
int esNumerico(char *str) ;
int esTelefono(char *str);
int esAlfaNumerico(char *str);
int esSoloLetras(char *str);
int esNumericoFlotante(char str[]);
int esDNI(char *str);
int pedirDNI(char *str, char *mensaje, char *error, int intentos);

int isValidUrl(char *url);

void clearStdin(void);
void pause(void);
void clearScreen(void);
