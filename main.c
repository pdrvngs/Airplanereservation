#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ROWS 32
#define COLS 6

// Global Variables
char flightid[10];
char flightseats[6][32];

void clearscreen()
{
    system("@cls||clear");
}


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
                if(choice != 3) {
                    printf("Oops, that's not a valid choice!\n");
                    fflush(stdin);
                }
        }
    }
    return 0;
}

void flightidchecker(){
    printf("Welcome! Please enter your flight code: ");
    fgets(flightid, 10, stdin);
    unsigned int num = strlen(flightid);
    while(num != 6){
        fflush(stdin);
        printf("No es un vuelo valido, porfavor intente de nuevo: ");
        fgets(flightid, 10, stdin);
        num = strlen(flightid);
    }
    clearscreen();
}

void initializer(){
    for(int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            flightseats[i][j] = 0;
        }
    }

}

int main() {

    // initialize seat reservation with 0's
    initializer();
    // Checks flight number
    flightidchecker();
    // provides menu function
    menu();

    fflush(stdin);
    char input[2];
    fgets(input, 3, stdin);
    printf("%d ", input[0] - 65);
    printf("%d ", input[1] - 49);

    printf("\n%c %c", input[0], input[1]);


    return 0;
}
