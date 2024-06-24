#ifndef ELEMENTTYPE_H
#define ELEMENTTYPE_H

#include "queue.h"

/** Definition of the element type stored in the list **/
typedef struct {
    char name[50];
    char brand[50];
    char model[50];
    char location[50];
    TQUEUE works;
} PRINTER;
///////////////////////////////////////////////////

#endif
