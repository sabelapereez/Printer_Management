#include <stdlib.h>
#include <stdio.h>

/** Defining the type of element stored in the queue **/
typedef int QUEUEELEMENTTYPE;

/** Queue node **/
typedef struct QueueNode {
    QUEUEELEMENTTYPE data;
    struct QueueNode *next;
} STQUEUENODE;

/** Queue structure **/
typedef struct {
    STQUEUENODE *start;
    STQUEUENODE *end;
} STQUEUE;
typedef STQUEUE *TQUEUE;

/**
 * Reserves memory for a data queue with type [QUEUEELEMENTTYPE].
 *
 * @param q pointer to the queue to create.
 */
void createQueue(TQUEUE *q) {
    *q = (TQUEUE) malloc(sizeof(STQUEUE));
    (*q)->end = NULL;
    (*q)->start = NULL;
}

/**
 * Checks if queue [q] is empty.
 * 
 * @param q queue to chech if it is empty.
 * @return 1 if the queue is empty, 0 otherwise.
 */
int isEmptyQueue(TQUEUE q) {
    return (q->end == NULL) && (q->start == NULL);
}

/**
 * Conaults the first element of the queue [q], if any, and stores it in [e], without removing it from the queue.
 *
 * @param q queue from which to extract the first element.
 * @param e variable where to store the first element of the queue.
 */
void FirstItemQueue(TQUEUE q, QUEUEELEMENTTYPE *e) {
    if (isEmptyQueue(q)) {
        printf("\nError, queue has no elements\n");
    } else {
        *e = (q->start)->data;
    }
}

/**
 * Destroys (frees reserved memory) the first element in the queue.
 *
 * @param q queue from which to destroy the first element.
 */
void deleteQueueElement(TQUEUE *q) {
    STQUEUENODE *aux;
    if (isEmptyQueue(q)) {
        printf("\nError, queue has no elements\n");
    } else {
        aux = (*q)->start;
        (*q)->start = aux->next;
        if ((*q)->start == NULL) {
            (*q)->end = NULL;
        }
        free(aux);
    }
}

/**
 * Adds element [e] to queue [q].
 *
 * @param q queue to which to add the element.
 * @param e element to add.
 */
void addQueueElement(TQUEUE *q, QUEUEELEMENTTYPE e) {
    STQUEUENODE *aux;

    aux = (STQUEUENODE *) malloc(sizeof(STQUEUENODE));
    aux->data = e;
    aux->next = NULL;

    if (isEmptyQueue(*q)) {
        (*q)->start = aux;
    } else {
        (*q)->end->next = aux;
    }
    (*q)->end = aux;
}

/**
 * Destroys (frees reserved memory) the queue [q] and all the elements it stores.
 *
 * @param q queue to destroy.
 */
void destroyQueue(TQUEUE *q) {
    while (!isEmptyQueue(*q)) {
        deleteQueueElement(q); 
    }
    free(*q);
}

/**
 * Returns the number of elements in the queue
 *
 * @param q queue from which to count the elements.
 */
int QueueLength(TQUEUE c){
    TQUEUE aux;
    QUEUEELEMENTTYPE b;
    int i = 0;
    createQueue(&aux);
    if(isEmptyQueue(c) == 1){
        return 0;
    }
    while(isEmptyQueue(c) == 0){
        FirstItemQueue(c, &b);
        addQueueElement(&aux, b);
        deleteQueueElement(&c);
        i++;
    }
    while(isEmptyQueue(aux) == 0){
        FirstItemQueue(aux, &b);
        addQueueElement(&c, b);
        deleteQueueElement(&aux);
    }
    destroyQueue(&aux);
    return i;
}
