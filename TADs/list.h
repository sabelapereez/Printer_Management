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
 * Reserves memory for a list of data with type [LISTELEMENTTYPE].
 *
 * @param q pointer to the list to create.
 */
void createList(TLIST *l);

/**
 * Destroys (frees reserved memory) the list [l] and all the elements it stores.
 *
 * @param l pointer to the list to destroy.
 */
void destroyList(TLIST *l);

/**
 * Checks if list [l] is empty.
 *
 * @param l list to check if it is empty.
 * @return 1 if the list is empty, 0 otherwise.
 */
int isEmptyList(TLIST l);

/**
 * Consults the first element of the list [l], and returns it.
 *
 * @param l list from which to recover the first position.
 * @return the first position [TPOSITION] of the list [l].
 */
TPOSITION firstList(TLIST l);

/**
 * Consults the last element of the list [l], and returns it.
 *
 * @param l list from which to recover the last position.
 * @return the last position [TPOSITION] of the list [l].
 */
TPOSITION endList(TLIST l);

/**
 * Returns the position next to [p] in list [l].
 *
 * @param l list from which the next position will be searched.
 * @param p reference position to return the next one.
 * @return the position following [p].
 */
TPOSITION nextList(TLIST l, TPOSITION p);

/**
 * Returns the element stored at position [p] passed by argument.
 *
 * @param l list from which to retrieve the element.
 * @param p position from which to retrieve the element.
 * @param e pointer to the variable in which to store the retrieved element.
 */
void retrieveListItem(TLIST l, TPOSITION p, LISTELEMENTTYPE *e);

/**
 * Consults the length of the list [l].
 *
 * @param l list of which to consult the length.
 * @return integer with the value of the length of the list.
 */
int lengthList(TLIST l);

/**
 * Inserts the element [e] in the position following position [p] of the list [l].
 *
 * @param l pointer to the list into which the element is inserted.
 * @param p position after which the element will be inserted.
 * @param e element to insert.
 */
void insertListElement(TLIST *l, TPOSITION p, LISTELEMENTTYPE e);

/**
 * Deletes the element at position [p] from list [l].
 *
 * @param l pointer to the list from which the element will be deleted.
 * @param p position of the element to be deleted.
 */
void deleteElementList(TLIST *l, TPOSITION p);

/**
 * Modifies the value of the element stored at position [p] by saving the new element [e].
 *
 * @param l pointer to the list from which the element will be modified.
 * @param p position of the value to be modified.
 * @param e new value to save in position [p].
 */
void modifyItemList(TLIST *l, TPOSITION p, LISTELEMENTTYPE e);

#endif
