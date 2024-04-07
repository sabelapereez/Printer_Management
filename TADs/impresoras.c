#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"
#include "cola.h"
#include "tipoelemento.h"

//Busqueda de una impresora en la lista (devuelve  TPOSICIÓN del elemento)
TPOSICION buscarelemento(TLISTA l, char* impresora){
    TIPOELEMENTOLISTA a;
    TPOSICION actual = primeroLista(l);
    while (actual != finLista(l)){
        recuperarElementoLista(l, actual, &a);
        if (strcmp(a.nombre, impresora) == 0){
            return actual;
        }
        actual = siguienteLista(l, actual);
    }
    return NULL;
}

//Impresión de la lista
void imprimirlista(TLISTA l){
    TIPOELEMENTOLISTA a;
    TPOSICION actual = primeroLista(l);
    printf("\nLista Impresoras:\n");
    while (actual != finLista(l)){
        recuperarElementoLista(l, actual, &a);
        printf("%s %s %s %s\n", a.nombre, a.marca, a.modelo, a.ubicacion);
        actual = siguienteLista(l, actual);
    }
}

//Eliminar elemento de la lista
void eliminarelemento(TLISTA l){
    char impresora[50];
    TPOSICION eliminar = NULL;
    printf("Introduzca el nombre de la impresora a eliminar: ");
    scanf("%s", impresora);
    eliminar = buscarelemento(l, impresora);
    if (eliminar == NULL){
        printf("No se ha encontrado esa impresora en la lista.\n");
    }
    else {
        suprimirElementoLista(&l, eliminar);
        printf("Se ha eliminado la impresora %s.\n", impresora);
    }
}

//Inserta elemento en la lista
void nuevoelemento(TLISTA l){
    TIPOELEMENTOLISTA a;
    printf("Introduzca o nome da impresora: ");
    scanf("%s", a.nombre);
    printf("Introduzca a marca da impresora: ");
    scanf("%s", a.marca);
    printf("Introduzca o modelo da impresora: ");
    scanf("%s", a.modelo);
    printf("Introduzca a ubicación da impresora: ");
    scanf("%s", a.ubicacion);
    crearCola(&a.trabajos);
    insertarElementoLista(&l, finLista(l), a);
    printf("Se ha insertado la impresora %s", a.nombre);
}

//Imprime los elementos en la cola de impresión
void imprimircola(TCOLA c){
    TCOLA aux;
    TIPOELEMENTOCOLA b;
    crearCola(&aux);
    printf("Lista de impresión:\n");
    if(esColaVacia(c) == 1){
        printf("No hay elementos\n");
    }
    while(esColaVacia(c) == 0){
        consultarPrimerElementoCola(c, &b);
        printf("%i\n", b);
        anadirElementoCola(&aux, b);
        suprimirElementoCola(&c);
    }
    while(esColaVacia(aux) == 0){
        consultarPrimerElementoCola(aux, &b);
        anadirElementoCola(&c, b);
        suprimirElementoCola(&aux);
    }
    destruirCola(&aux);
}

//Añade un trabajo a la cola de impresión 
void añadirtrabajo(TLISTA l){
    char impresora[50];
    TIPOELEMENTOCOLA ide;
    TIPOELEMENTOLISTA a;
    TPOSICION añadir = NULL;
    printf("Introduzca la impresora a la que mandar el trabajo: ");
    scanf("%s", impresora);
    añadir = buscarelemento(l, impresora);
    if (añadir == NULL){
        printf("No se ha encontrado esa impresora en la lista.\n");
    }
    else {
        printf("Introduzca el identificador del trabajo: ");
        scanf("%i", &ide);
        recuperarElementoLista(l, añadir, &a); 
        anadirElementoCola(&a.trabajos, ide); 
        printf("Se ha añadido el trabajo a la impresora %s.\n", impresora);
    }
}

//Imprime los trabajos de la cola de impresión 
void trabajospendientes(TLISTA l){
    char impresora[50];
    TPOSICION añadir = NULL;
    printf("Introduzca la impresora de la que ver los trabajos: ");
    scanf("%s", impresora);
    añadir = buscarelemento(l, impresora);
    if (añadir == NULL){
        printf("No se ha encontrado esa impresora en la lista.\n");
    }
    else {
        TIPOELEMENTOLISTA a;
        recuperarElementoLista(l, añadir, &a);
        imprimircola(a.trabajos);
    }
}

//Elimina el trabajo de la cola que entró antes
void imprimirtrabajo(TLISTA l){
    char impresora[50];
    TPOSICION añadir = NULL;
    printf("Introduzca la impresora de la que imprimir el trabajo: ");
    scanf("%s", impresora);
    añadir = buscarelemento(l, impresora);
    if (añadir == NULL){
        printf("No se ha encontrado esa impresora en la lista.\n");
    }
    else{
        TIPOELEMENTOLISTA a;
        TIPOELEMENTOCOLA c;
        recuperarElementoLista(l, añadir, &a);
        imprimircola(a.trabajos);
        if(esColaVacia(a.trabajos) == 0){
            consultarPrimerElementoCola(a.trabajos, &c);
            suprimirElementoCola(&a.trabajos);
            printf("Se ha impreso el trabajo %i.\n", c);
        }
    }
}

//Busca las impresoras con menos trabajos en la cola de impresión 
void impresoraspocacarga(TLISTA l){
    TIPOELEMENTOLISTA a;
    TPOSICION actual = primeroLista(l);
    int i, m = -1;
    recuperarElementoLista(l, actual, &a);
    m = tamañocola(a.trabajos);
    while (actual != finLista(l)){
        recuperarElementoLista(l, actual, &a);
        i = tamañocola(a.trabajos);
        if(i < m){
            m = i;
        }
        actual = siguienteLista(l, actual);
    }
    actual = primeroLista(l);
    while (actual != finLista(l)){
        recuperarElementoLista(l, actual, &a);
        i = tamañocola(a.trabajos);
        if(i == m){
            printf("%s\n", a.nombre);
        }
        actual = siguienteLista(l, actual);
    }
}
