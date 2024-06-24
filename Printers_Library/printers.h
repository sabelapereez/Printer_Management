#ifndef PRINTERS_H
#define PRINTERS_H

//Searchs for a printer in the list (returns TPOSITION of the item)
TPOSITION searchprinter(TLIST l, char* printer);

//Prints list
void printlist(TLIST l);

//Deletes list element
void deleteelement(TLIST l);

//Inserts an element into the list
void newelement(TLIST l);

//Prints the elements in the print queue
void printqueue(TQUEUE c);

//Adds a job into the print queue
void addjob(TLIST l);

//Prints the jobs from the print queue
void pendingjobs(TLIST l);

//Deletes a job from the queue
void printjob(TLIST l);

//Find the printers with the fewest jobs in the print queue
void printerslowload(TLIST l);

#endif
