#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct {

    char nombre[50];
    int edad;
    int estado;
    int dni;

}EPersona;

/**
 * \brief Muestra el menu principal y llama a la funcion capturarOpcionElegida().
 * @param void.
 * @return la opcion ingresada por el usuario validada.
 */
int menu(void);

/**
 * \brief captura la opcion ingresada por el usuario y llama a la funcion validarOpcionElegida.
 * \param void.
 * \return la opcion ingresada por el usuario validada.
 */
int capturarOpcionElegida();

/**
 * \brief valida la Opcion que recibe por parametros.
 * \param recibe la opcion ingresada por el usuario.
 * \return 0 si la opcion es valida y -1 si es invalida.
 */
int validarOpcionElegida(int opcionAValidar);

/** \brief Carga el valor -1 en el elemento isEmpty de todos los items del array
 * \param Recibe un array del tipo EPersona.
 * \return no hay retorno.
 */
void inicializarLista(EPersona lista[]);

/**
 * \brief Obtiene el primer indice libre del array.
 * \param lista el array se pasa como parametro.
 * \return el primer indice disponible
 */
int obtenerEspacioLibre(EPersona lista[]);

/**
 * \brief Obtiene el indice que coincide con el dni pasado por parametro.
 * \param lista el array se pasa como parametro.
 * \param dni el dni a ser buscado en el array.
 * \return el indice en donde se encuentra el elemento que coincide con el parametro dni
 */
int buscarPorDni(EPersona lista[], int dni);

/** \brief Carga una persona en el primer espacio libre del array
 *
 * \param lista. el array a ser cargado
 * \param dni. el dni para usar como filtro
 * \return no hay retorno.
 *
 */
void doAltaPersona(EPersona lista[],int indiceEspacioLibre);

/** \brief valida el nombre ingresado por el usuario
 *
 * \param lista el array cuyo elemento sera validado
 * \param indice el indice del elemento del array
 * \return
 *
 */
int validarNombre(EPersona lista[],int indiceEspacioLibre);

/** \brief valida la edad ingresada por el usuario
 *
 * \param lista el array cuyo elemento sera validado
 * \param indice el indice del elemento del array
 * \return 0 si la edad es valida y -1 si es invalida.
 *
 */
int validarEdad(EPersona lista[],int indiceEspacioLibre);

/** \brief valida el dni ingresado por el usuario
 *
 * \param dni a ser validado
 *
 * \return dni si es valido y -1 si es invalido.
 */
int validarDni(int dni);

/** \brief recibe el array y lo ordena alfabeticamente por nombre
 *
 * \param lista. el array a ordenar
 *
 * \return no hay retorno
 */
void ordenarPorNombre(EPersona lista[]);

/** \brief imprime un grafico de barras de acuerdo a un criterio
 *
 * \param lista. el array
 *
 * \return no hay retorno
 */
void graficoEdades(EPersona lista[]);

/** \brief Borrado logico de una persona
 *
 * \param lista. el array
 *
 * \return no hay retorno
 */
void borrarPersona (EPersona lista[]);
#endif // FUNCIONES_H_INCLUDED
