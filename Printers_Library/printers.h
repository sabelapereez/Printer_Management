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

//Añade un trabajo a la cola de impresión 
void añadirtrabajo(TLISTA l);

//Imprime los trabajos de la cola de impresión 
void trabajospendientes(TLISTA l);

//Elimina el trabajo de la cola que entró antes
void imprimirtrabajo(TLISTA l);

//Busca las impresoras con menos trabajos en la cola de impresión 
void impresoraspocacarga(TLISTA l);

#endif
