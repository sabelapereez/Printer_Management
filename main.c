#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "queue.h"
#include "list.h"
#include "printers.h"

int main(int argc, char** argv){
    FILE *PrintersList;
    TLIST Printers;
    LISTELEMENTTYPE elem;
    char bin[200], option;

    //Prameter introduction
    if(argc != 2){
        perror("Error in the entered parameters.");
        exit(1);
    }

    //File opening
    if ((PrintersList = fopen(argv[1], "r")) == NULL){
        perror("File reading error.");
        exit(2);
    }

    //List creation and insertion of the elements.
    createList(&Printers);
    TPOSITION actual = firstList(Printers);
    fseek(PrintersList, 0, SEEK_SET);
    while(fgets(bin, 200, PrintersList) != NULL){
        sscanf(bin, "%s %s %s %s", elem.name, elem.brand, elem.model, elem.location);
        createQueue(&elem.works);
        insertListElement(&Printers, actual, elem);
        actual = nextList(Printers, actual);
    }
    fclose(PrintersList); 
    printlist(Printers);

    do{
        printf("\nMenu\n");
        printf("~~~~~~~~~~~~~~~~\n"); 
        printf("a) Delete printer\n"); 
        printf("b) Add printer\n");
        printf("c) Send work\n");
        printf("d) Pending jobs list\n");
        printf("e) Print work\n");
        printf("f) Find printer\n"); 
        printf("g) Print list\n");
        printf("s) Exit\n"); 
        printf("~~~~~~~~~~~~~~~~\n");
        printf("Option: ");
        scanf(" %c", &option);
        switch (option){
            case 'a': 
            case 'A':
                deleteelement(Printers);
                printlist(Printers);
                break;
            case 'b':
            case 'B':
                newelement(Printers);
                printlist(Printers);
                break;
            case 'c':
            case 'C':
                addjob(Printers);
                break;
            case 'd':
            case 'D':
                pendingjobs(Printers);
                break;
            case 'e':
            case 'E':
                printjob(Printers);
                break;
            case 'f':
            case 'F':
                printerslowload(Printers);
                break;
            case 'g':
            case 'G':
                printlist(Printers);
                break;
            case 's': 
            case 'S':
                //File opening
                if ((PrintersList = fopen(argv[1], "w")) == NULL){
                    perror("File reading error.");
                    exit(2);
                }
                //File updating with the list elements
                actual = firstList(Printers);
                fseek(PrintersList, 0, SEEK_SET); 
                while(actual != endList(Printers)){
                    retrieveListItem(Printers, actual, &elem);
                    fprintf(PrintersList, "%s %s %s %s\n", elem.name, elem.brand, elem.model, elem.location);
                    actual = nextList(Printers, actual);
                }
                fclose(PrintersList); 
                printf("Updated list.\n");
                destroyList(&Printers);
                printf("Exiting...\n");
                break;
            default:
                printf("Wrong option.\n");
                break;
        }
    } while (option != 's' && option != 'S');
    return(EXIT_SUCCESS);
}
