#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
#include "elementtype.h"

/**Definition structure [LISTELEMENTTYPE]*/
typedef PRINTER LISTELEMENTTYPE;

/** Structure for a list node **/
typedef struct ListNode {
    LISTELEMENTTYPE element;
    struct ListNode *next;
} STLISTNODE;
typedef STLISTNODE *TPOSITION;

/** List structure **/
typedef struct {
    TPOSITION start;
    int length;
    TPOSITION end;
} STLIST;
typedef STLIST *TLIST;

/**
 * Reserves memory for a list of data with type [LISTELEMENTTYPE].
 *
 * @param q pointer to the list to create.
 */
void createList(TLIST *l) {
    *l = (TLIST) malloc(sizeof(STLIST));
    (*l)->start = (TPOSITION) malloc(sizeof(STLISTNODE));
    (*l)->start->next = NULL;
    (*l)->end = (*l)->start;
    (*l)->length = 0;
}

/**
 * Destroys (frees reserved memory) the list [l] and all the elements it stores.
 *
 * @param l pointer to the list to destroy.
 */
void destroyList(TLIST *l) {
    (*l)->end = (*l)->start;
    while ((*l)->end->next != NULL) {
        (*l)->end = (*l)->end->next;
        destroyQueue(&((*l)->end)->element.works);
        free((*l)->start);
        (*l)->start = (*l)->end;
    }
    free(*l);
}

/**
 * Checks if list [l] is empty.
 *
 * @param l list to check if it is empty.
 * @return 1 if the list is empty, 0 otherwise.
 */
int isEmptyList(TLIST l) {
    return (l->length == 0);
}

/**
 * Consults the first element of the list [l], and returns it.
 *
 * @param l list from which to recover the first position.
 * @return the first position [TPOSITION] of the list [l].
 */
TPOSITION firstList(TLIST l) {
    return l->start;
}

/**
 * Consults the last element of the list [l], and returns it.
 *
 * @param l list from which to recover the last position.
 * @return the last position [TPOSITION] of the list [l].
 */
TPOSITION endList(TLIST l) {
    return l->end;
}

/**
 * Returns the position next to [p] in list [l].
 *
 * @param l list from which the next position will be searched.
 * @param p reference position to return the next one.
 * @return the position following [p].
 */
TPOSITION nextList(TLIST l, TPOSITION p) {
    return p->next;
}

/**
 * Returns the element stored at position [p] passed by argument.
 *
 * @param l list from which to retrieve the element.
 * @param p position from which to retrieve the element.
 * @param e pointer to the variable in which to store the retrieved element.
 */
void retrieveListItem(TLIST l, TPOSITION p, LISTELEMENTTYPE *e){
    *e = p->next->element;
}

/**
 * Consults the length of the list [l].
 *
 * @param l list of which to consult the length.
 * @return integer with the value of the length of the list.
 */
int lengthList(TLIST l) {
    return l->length;
}

/**
 * Inserts the element [e] in the position following position [p] of the list [l].
 *
 * @param l pointer to the list into which the element is inserted.
 * @param p position after which the element will be inserted.
 * @param e element to insert.
 */
void insertListElement(TLIST *l, TPOSITION p, LISTELEMENTTYPE e){
    TPOSITION q = p->next;
    p->next = (STLISTNODE *) malloc(sizeof(STLISTNODE));
    p->next->element = e;
    p->next->next = q;
    if (q == NULL) {
        (*l)->end = p->next;
    }
    (*l)->length++;
}

/**
 * Deletes the element at position [p] from list [l].
 *
 * @param l pointer to the list from which the element will be deleted.
 * @param p position of the element to be deleted.
 */
void deleteListElement(TLIST *l, TPOSITION p){
    TPOSITION q;

    q = p->next;
    p->next = q->next;
    if (p->next == NULL) {
        (*l)->end = p;
    }
    free(q);
    (*l)->length--;
}

/**
 * Modifies the value of the element stored at position [p] by saving the new element [e].
 *
 * @param l pointer to the list from which the element will be modified.
 * @param p position of the value to be modified.
 * @param e new value to save in position [p].
 */
void modifyItemList(TLIST *l, TPOSITION p, LISTELEMENTTYPE e){
    p->next->element = e;
}
