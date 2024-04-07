#ifndef IMPRESORAS_H
#define IMPRESORAS_H

//Busqueda de una impresora en la lista (devuelve  TPOSICIÓN del elemento)
TPOSICION buscarelemento(TLISTA l, char* impresora);

//Impresión de la lista
void imprimirlista(TLISTA l);

//Eliminar elemento de la lista
void eliminarelemento(TLISTA l);

//Inserta elemento en la lista
void nuevoelemento(TLISTA l);

//Imprime los elementos en la cola de impresión
void imprimircola(TCOLA c);

//Añade un trabajo a la cola de impresión 
void añadirtrabajo(TLISTA l);

//Imprime los trabajos de la cola de impresión 
void trabajospendientes(TLISTA l);

//Elimina el trabajo de la cola que entró antes
void imprimirtrabajo(TLISTA l);

//Busca las impresoras con menos trabajos en la cola de impresión 
void impresoraspocacarga(TLISTA l);

#endif
