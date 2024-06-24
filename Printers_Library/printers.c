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
    printf("The printer %s has been created.\n", a.name);
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

//Adds a job into the print queue
void addjob(TLIST l){
    char printer[50];
    QUEUEELEMENTTYPE ide;
    LISTELEMENTTYPE a;
    TPOSITION add = NULL;
    printf("Enter the printer to send the job to: ");
    scanf("%s", printer);
    add = searchprinter(l, printer);
    if (add == NULL){
        printf("That printer was not found in the list.\n");
    }
    else {
        printf("Enter the job ID: ");
        scanf("%i", &ide);
        retrieveListItem(l, add, &a); 
        addQueueElement(&a.works, ide); 
        printf("The job has been added to the printer %s.\n", printer);
    }
}

//Prints the jobs from the print queue
void pendingjobs(TLIST l){
    char printer[50];
    TPOSITION add = NULL;
    printf("Enter the printer from which to see the works: ");
    scanf("%s", printer);
    add = searchprinter(l, printer);
    if (add == NULL){
        printf("That printer was not found in the list.\n");
    }
    else {
        LISTELEMENTTYPE a;
        retrieveListItem(l, add, &a);
        printqueue(a.works);
    }
}

//Deletes a job from the queue
void printjob(TLIST l){
    char printer[50];
    TPOSITION add = NULL;
    printf("Enter the printer from which to print the job: ");
    scanf("%s", printer);
    add = searchprinter(l, printer);
    if (add == NULL){
        printf("That printer was not found in the list.\n");
    }
    else{
        LISTELEMENTTYPE a;
        QUEUEELEMENTTYPE c;
        retrieveListItem(l, add, &a);
        printqueue(a.works);
        if(isEmptyQueue(a.works) == 0){
            FirstItemQueue(a.works, &c);
            deleteQueueElement(&a.works);
            printf("The job %i has been printed.\n", c);
        }
    }
}

//Find the printers with the fewest jobs in the print queue
void printerslowload(TLIST l){
    LISTELEMENTTYPE a;
    TPOSITION actual = firstList(l);
    int i, m = -1;
    retrieveListItem(l, actual, &a);
    m = QueueLength(a.works);
    while (actual != endList(l)){
        retrieveListItem(l, actual, &a);
        i = QueueLength(a.works);
        if(i < m){
            m = i;
        }
        actual = nextList(l, actual);
    }
    actual = firstList(l);
    while (actual != endList(l)){
        retrieveListItem(l, actual, &a);
        i = QueueLength(a.works);
        if(i == m){
            printf("%s\n", a.name);
        }
        actual = nextList(l, actual);
    }
}
