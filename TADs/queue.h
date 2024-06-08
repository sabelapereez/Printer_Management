#ifndef QUEUE_H
#define QUEUE_H

/** Defining the type of element stored in the queue **/
typedef int QUEUEELEMENTTYPE;


/** Queue structure **/
typedef void *TQUEUE;

/**
 * Reserves memory for a data queue with type [QUEUEELEMENTTYPE].
 *
 * @param q pointer to the queue to create.
 */
void createQueue(TQUEUE *q);

/**
 * Checks if queue [q] is empty.
 * 
 * @param q queue to chech if it is empty.
 * @return 1 if the queue is empty, 0 otherwise.
 */
int isEmptyQueue(TQUEUE q);

/**
 * Consults the first element of the queue [q], if any, and stores it in [e], without removing it from the queue.
 *
 * @param q queue from which to extract the first element.
 * @param e variable where to store the first element of the queue.
 */
void FirstItemQueue(TQUEUE q, QUEUEELEMENTTYPE *e);

/**
 * Destroys (frees reserved memory) the first element in the queue.
 *
 * @param q queue from which to destroy the first element.
 */
void deleteQueueElement(TQUEUE *q);

/**
 * Adds element [e] to queue [q].
 *
 * @param q queue to which to add the element.
 * @param e element to add.
 */
void addQueueElement(TQUEUE *q, QUEUEELEMENTTYPE e);

/**
 * Destroys (frees reserved memory) the queue [q] and all the elements it stores.
 *
 * @param q queue to destroy.
 */
void destroyQueue(TQUEUE *q);

/**
 * Returns the number of elements in the queue
 *
 * @param q queue from which to count the elements.
 */
int QueueLength(TQUEUE c);

#endif 

