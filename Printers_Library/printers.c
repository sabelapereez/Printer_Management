#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"
#include "queue.h"
#include "elementtype.h"

//Searchs for a printer in the list (returns TPOSITION of the item)
TPOSITION searchprinter(TLIST l, char* printer){
    LISTELEMENTTYPE a;
    TPOSITION actual = firstList(l);
    while (actual != endList(l)){
        retrieveListItem(l, actual, &a);
        if (strcmp(a.name, printer) == 0){
            return actual;
        }
        actual = nextList(l, actual);
    }
    return NULL;
}

//Prints list
void printlist(TLIST l){
    LISTELEMENTTYPE a;
    TPOSITION actual = firstList(l);
    printf("\nPrinters List:\n");
    while (actual != endList(l)){
        retrieveListItem(l, actual, &a);
        printf("%s %s %s %s\n", a.name, a.brand, a.model, a.location);
        actual = nextList(l, actual);
    }
}

//Deletes list element
void deleteelement(TLIST l){
    char printer[50];
    TPOSITION delete = NULL;
    printf("Enter the name of the printer to delete: ");
    scanf("%s", printer);
    delete = searchprinter(l, printer);
    if (delete == NULL){
        printf("That printer was not found in the list.\n");
    }
    else {
        deleteListElement(&l, delete);
        printf("The printer %s has been deleted.\n", printer);
    }
}

//Inserts an element into the list
void newelement(TLIST l){
    LISTELEMENTTYPE a;
    printf("Enter the name of the printer: ");
    scanf("%s", a.name);
    printf("Enter the brand of the printer: ");
    scanf("%s", a.brand);
    printf("Enter the model of the printer: ");
    scanf("%s", a.model);
    printf("Enter the location of the printer: ");
    scanf("%s", a.location);
    createQueue(&a.works);
    insertListElement(&l, endList(l), a);
    printf("The printer %s has been created", a.name);
}

//Prints the elements in the print queue
void printqueue(TQUEUE c){
    TQUEUE aux;
    QUEUEELEMENTTYPE b;
    createQueue(&aux);
    printf("Print Queue List:\n");
    if(isEmptyQueue(c) == 1){
        printf("No elements\n");
    }
    while(isEmptyQueue(c) == 0){
        FirstItemQueue(c, &b);
        printf("%i\n", b);
        addQueueElement(&aux, b);
        deleteQueueElement(&c);
    }
    while(isEmptyQueue(aux) == 0){
        FirstItemQueue(aux, &b);
        addQueueElement(&c, b);
        deleteQueueElement(&aux);
    }
    destroyQueue(&aux);
}

//Añade un trabajo a la cola de impresión 
void añadirtrabajo(TLIST l){
    char printer[50];
    QUEUEELEMENTTYPE ide;
    LISTELEMENTTYPE a;
    TPOSITION añadir = NULL;
    printf("Introduzca la printer a la que mandar el trabajo: ");
    scanf("%s", printer);
    añadir = searchprinter(l, printer);
    if (añadir == NULL){
        printf("No se ha encontrado esa printer en la lista.\n");
    }
    else {
        printf("Introduzca el identificador del trabajo: ");
        scanf("%i", &ide);
        retrieveListItem(l, añadir, &a); 
        addQueueElement(&a.trabajos, ide); 
        printf("Se ha añadido el trabajo a la printer %s.\n", printer);
    }
}

//Imprime los trabajos de la cola de impresión 
void trabajospendientes(TLIST l){
    char printer[50];
    TPOSITION añadir = NULL;
    printf("Introduzca la printer de la que ver los trabajos: ");
    scanf("%s", printer);
    añadir = searchprinter(l, printer);
    if (añadir == NULL){
        printf("No se ha encontrado esa printer en la lista.\n");
    }
    else {
        LISTELEMENTTYPE a;
        retrieveListItem(l, añadir, &a);
        imprimircola(a.trabajos);
    }
}

//Elimina el trabajo de la cola que entró antes
void imprimirtrabajo(TLIST l){
    char printer[50];
    TPOSITION añadir = NULL;
    printf("Introduzca la printer de la que imprimir el trabajo: ");
    scanf("%s", printer);
    añadir = searchprinter(l, printer);
    if (añadir == NULL){
        printf("No se ha encontrado esa printer en la lista.\n");
    }
    else{
        LISTELEMENTTYPE a;
        QUEUEELEMENTTYPE c;
        retrieveListItem(l, añadir, &a);
        imprimircola(a.trabajos);
        if(isEmptyQueue(a.trabajos) == 0){
            FirstItemQueue(a.trabajos, &c);
            deleteQueueElement(&a.trabajos);
            printf("Se ha impreso el trabajo %i.\n", c);
        }
    }
}

//Busca las printers con menos trabajos en la cola de impresión 
void printerspocacarga(TLIST l){
    LISTELEMENTTYPE a;
    TPOSITION actual = firstList(l);
    int i, m = -1;
    retrieveListIte(l, actual, &a);
    m = tamañocola(a.trabajos);
    while (actual != endList(l)){
        retrieveListItem(l, actual, &a);
        i = tamañocola(a.trabajos);
        if(i < m){
            m = i;
        }
        actual = nextList(l, actual);
    }
    actual = firstList(l);
    while (actual != endList(l)){
        retrieveListItem(l, actual, &a);
        i = tamañocola(a.trabajos);
        if(i == m){
            printf("%s\n", a.name);
        }
        actual = nextList(l, actual);
    }
}
