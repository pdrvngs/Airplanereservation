#include <stdio.h>

// Global Variables
char flightid[6];


int menu(){
    fflush(stdin);
    int choice = 0;
    printf("VUELO: "); fputs(flightid, stdout); printf("\n");
    printf("1. Reservar Asiento\n2. Disponibilidad de Asientos\n3. Salir \n");
    while(choice != 3){
        printf("Ingrese su eleccion: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("Eligio 1");
                return 1;
            case 2:
                printf("Eligio 2");
                return 2;

            default:
                printf("Oops, that's not a valid choice!\n");
                fflush(stdin);
        }
    }
    return 0;
}

int main() {
    printf("Welcome! Please enter your flight code: ");
    fgets(flightid, 6, stdin);
    menu();
    return 0;
}
