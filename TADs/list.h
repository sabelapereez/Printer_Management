#ifndef LIST_H
#define LIST_H

#include "elementtype.h"

/**Definition structure [LISTELEMENTTYPE]*/
typedef PRINTER LISTELEMENTTYPE;

/** Structure for a list node **/
typedef void *TPOSITION;

/** List structure **/
typedef void *TLIST;

/**
 * Reserva memoria para una lista de datos con el tipo [LISTELEMENTTYPE].
 *
 * @param q puntero a la lista a crear.
 */
void crearLista(TLIST *l);

/**
 * Destruye (libera la memoria reservada) la lista [l] y todos los elementos que almacena.
 *
 * @param l puntero a la lista a destruir.
 */
void destruirLista(TLIST *l);

/**
 * Comprueba si la lista [l] esta vacia.
 *
 * @param l lista a comprobar si esta vacia.
 * @return 1 si la lista esta vacia, 0 en otro caso.
 */
int esListaVacia(TLIST l);

/**
 * Recupera la primera posicion de la lista.
 *
 * @param l lista de la cual recuperar la primera posicion.
 * @return la primera posicion tipo [TPOSICION] de la lista [l].
 */
TPOSITION primeroLista(TLIST l);

/**
 * Recupera la posicion del fin de la lista.
 *
 * @param l lista de la cual recuperar su final.
 * @return la posicion del fin tipo [TPOSICION] de la lista [l].
 */
TPOSITION finLista(TLIST l);

/**
 * Devuelve la posicion siguiente a [p] en la lista [l].
 *
 * @param l lista en la cual se va a buscar la siguiente posicion.
 * @param p posicion referencia para devolver la siguiente.
 * @return la posicion siguiente a [p].
 */
TPOSITION siguienteLista(TLIST l, TPOSITION p);

/**
 * Recupera el elemento almacenado en la posicion [p] pasada por argumento.
 *
 * @param l lista de la cual recuperar el elemento.
 * @param p posicion de la cual recuperar el elemento.
 * @param e puntero a la variable en la cual almacenar el elemento recuperado.
 */
void recuperarElementoLista(TLIST l, TPOSITION p, LISTELEMENTTYPE *e);

/**
 * Consulta la longitud de la lista [l].
 *
 * @param l lista de la cual consultar la longitud.
 * @return entero con el valor de la longitud de la lista.
 */
int longitudLista(TLIST l);

/**
 * Inserta el elemento [e] en la posicion siguiente a la posicion [p] de la lista [l].
 *
 * @param l puntero a la lista en la cual se va a insertar el elemento.
 * @param p posicion despues de la cual se insertara el elemento.
 * @param e elemento a insertar.
 */
void insertarElementoLista(TLIST *l, TPOSITION p, LISTELEMENTTYPE e);

/**
 * Suprime el elemento en posicion [p] de la lista [l].
 *
 * @param l puntero a la lista de la que se suprimira el elemento.
 * @param p posicion del elemento a suprimir.
 */
void suprimirElementoLista(TLIST *l, TPOSITION p);

/**
 * Modifica el valor del elemento almacenado en la posicion [p] guardando el nuevo elemento [e].
 *
 * @param l puntero a la lista de la cual se va a modificar el elemento.
 * @param p posicion del valor que se va a modificar.
 * @param e nuevo valor a guardar en la posicion [p].
 */
void modificarElementoLista(TLIST *l, TPOSITION p, LISTELEMENTTYPE e);

#endif
