#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct {

    char nombre[50];
    int edad;
    int estado;
    int dni;

}ePersona;

#endif // FUNCIONES_H_INCLUDED
/**
 * Inicializa todos las posiciones del array en -1
 * @param ePersona[] el array que pasa como parametro
 * @param limite int la cantidad de posiciones que se va a utilizar
 * @return void No devuelvo nada
 */
void ePer_init(ePersona listaPersonas[],int limite);

/**
 * Obtiene el primer indice libre del array.
 * @param lista el array se pasa como parametro.
 * @return el primer indice disponible
 */
int ePer_obtenerEspacioLibre(ePersona listaPersonas[],int limite);

/**
 * Ordena cada nombre con sus elementos en orden alfabetico
 * \param lista[] ePersona el array que se pasa como parametro
 * \param limite int la cantidad de posiciones que se va a utilizar
 * \return void No devuelvo nada
 */
void ePer_Ordenamiento(ePersona lista[],int limite);

/**
 * Muestro el nombre, edad, dni segun la posicion de array que se haya dado a la funcion
 * \param parametro ePersona el array que se pasa como parametro
 * \return void No devuelvo nada, solo muestro
 */
void ePer_mostrarUno(ePersona parametro);

/**
 * Muestro un listado con los nombre, edades y dni ingresados
 * @param listaPersonas[] ePersona el array que pasa como parametro
 * @param limite int la cantidad de posiciones que se va a utilizar
 * @return void No devuelvo nada..
 */
void ePer_mostrarListado(ePersona listaPersonas[] ,int limite);

/**
 * Obtiene el indice que coincide con el dni pasado por parametro.
 * @param lista el array se pasa como parametro.
 * @param dni el dni a ser buscado en el array.
 * @return el indice en donde se encuentra el elemento que coincide con el parametro dni
 */
int ePer_buscarPorDni(ePersona listaPersonas[], int dni,int limite);

/**
 * Agrego a un usuario. Con dni y edad incluido.
 * @param listaPersonas[] ePersona el array que pasa como parametro
 * @param limite int la cantidad de posiciones que se va a utilizar
 * @return void No devuelvo nada.
 */
void ePer_alta(ePersona listaPersonas[] ,int limite);

/**
 *  Doy de baja (o borro) la informacion de una persona segun el dni que haya ingresado el usuario
 * \param listaPersonas[] ePersona el array que se pasa como parametro
 * \param limite int la cantidad de posiciones que pasa como parametro
 * \return void No devuelvo ninguna informacion, una ves dado de baja muestro si se ha borrado la persona de la lista
 */
void ePer_baja(ePersona listaPersonas[] ,int limite);

/**
 * Muestro el grafico de las edades segun si es menor a 18 o esta entre 19 a 35 o si es mayor de 35
 * \param listaPersonas[] ePersona  el array que se pasa como parametro
 * \param limite int la cantidad de posiciones que pasa como parametro
 * \return void No devuelvo nada.
 */
void ePer_MostrarGraficoEdades(ePersona listaPersonas[], int limite);

/**
 * Esta funcion es llamada por la anterior para clasificar la edad de cada persona
 * \param listaPersonas[] ePersona el array que se pasa como parametro
 * \param limite int la cantidad de posiciones que se pasa como parametro
 * \return void Solo muestra el grafico junto con la anterior funcion.
 */
void ePer_GraficoEdades(ePersona listaPersonas[], int limite);

