#ifndef TIPOELEMENTO_H
#define TIPOELEMENTO_H

#include "cola.h"

/** Definicion del tipo de elemento almacenado en la lista **/
typedef struct {
    char nombre[50];
    char marca[50];
    char modelo[50];
    char ubicacion[50];
    TCOLA trabajos;
} IMPRESORA;
///////////////////////////////////////////////////

#endif
