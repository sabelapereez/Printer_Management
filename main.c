#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cola.h"
#include "lista.h"
#include "impresoras.h"

int main(int argc, char** argv){
    FILE *ListaImpresoras;
    TLISTA Impresoras;
    TIPOELEMENTOLISTA elem;
    char bin[200], opcion;

    //Introducción de parámetros
    if(argc != 2){
        perror("Error en los parámetros introducidos.");
        exit(1);
    }

    //Apertura archivo
    if ((ListaImpresoras = fopen(argv[1], "r")) == NULL){
        perror("Error en la lectura del archivo.");
        exit(2);
    }

    //Creación de la lista e inserción de los elementos
    crearLista(&Impresoras);
    TPOSICION actual = primeroLista(Impresoras);
    fseek(ListaImpresoras, 0, SEEK_SET);
    while(fgets(bin, 200, ListaImpresoras) != NULL){
        sscanf(bin, "%s %s %s %s", elem.nombre, elem.marca, elem.modelo, elem.ubicacion);
        crearCola(&elem.trabajos);
        insertarElementoLista(&Impresoras, actual, elem);
        actual = siguienteLista(Impresoras, actual);
    }
    fclose(ListaImpresoras); 
    imprimirlista(Impresoras);

    do{
        printf("~~~~~~~~~~~~~~~~\n"); 
        printf("a) Eliminar impresora\n"); 
        printf("b) Añadir impresora\n");
        printf("c) Enviar traballo\n");
        printf("d) Listado traballos pendentes\n");
        printf("e) Imprimir traballo\n");
        printf("f) Buscar impresora\n"); 
        printf("s) Salir\n"); 
        printf("~~~~~~~~~~~~~~~~\n");
        printf("Opcion: ");
        scanf(" %c", &opcion);
        switch (opcion){
            case 'a': 
            case 'A':
                eliminarelemento(Impresoras);
                imprimirlista(Impresoras);
                break;
            case 'b':
            case 'B':
                nuevoelemento(Impresoras);
                imprimirlista(Impresoras);
                break;
            case 'c':
            case 'C':
                añadirtrabajo(Impresoras);
                break;
            case 'd':
            case 'D':
                trabajospendientes(Impresoras);
                break;
            case 'e':
            case 'E':
                imprimirtrabajo(Impresoras);
                break;
            case 'f':
            case 'F':
                impresoraspocacarga(Impresoras);
                break;
            case 's': 
            case 'S':
                //Apertura del archivo
                if ((ListaImpresoras = fopen(argv[1], "w")) == NULL){
                    perror("Error en la lectura del archivo.");
                    exit(2);
                }
                //Actualización del archivo con los elementos de la lista
                actual = primeroLista(Impresoras);
                fseek(ListaImpresoras, 0, SEEK_SET);
                while(actual != finLista(Impresoras)){
                    recuperarElementoLista(Impresoras, actual, &elem);
                    fprintf(ListaImpresoras, "%s %s %s %s\n", elem.nombre, elem.marca, elem.modelo, elem.ubicacion);
                    actual = siguienteLista(Impresoras, actual);
                }
                fclose(ListaImpresoras); 
                printf("Lista actualizada\n"),
                destruirLista(&Impresoras);
                printf("Fin del programa.\n");
                break;
            default:
                printf("No se incluye esa opción.\n");
                break;
        }
    } while (opcion != 's' && opcion != 'S');
    return(EXIT_SUCCESS);
}
