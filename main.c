#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ROWS 32
#define COLS 6

// Global Variables
char flightid[10];
char flightseats[32][6];
char input[5];


void clearscreen()
{
    system("@cls||clear");
}


int menu(){
    clearscreen();
    fflush(stdin);
    int choice = 0;
    printf("VUELO: "); fputs(flightid, stdout); printf("\n");
    printf("1. Reservar Asiento\n2. Disponibilidad de Asientos\n3. Salir \n");
    while(choice != 3){
        printf("Ingrese su eleccion: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                return 1;
            case 2:
                return 2;

            default:
                if(choice != 3) {
                    printf("Oops, that's not a valid choice!\n");
                    fflush(stdin);
                }
        }
    }
    return 3;
}


void flightidchecker(){
    fflush(stdin);

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
    fflush(stdin);

    for(int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            flightseats[i][j] = '0';
        }
    }

}


int getrownumber(){
    fflush(stdin);

    char* pinput = input;
    int int1;
    int int2;
    int row;


    unsigned int length = strlen(pinput);

    if(length == 4){

        int1 = (pinput[1]-48)*10;
        int2 = (pinput[2] - 48);
        row = int1 + int2;
        return row - 1;

    } else if(length == 3){
        int1 = (pinput[1] - 48);
        return int1 - 1;
    }
    return 0;
}


int getcolumnnumber(){
    fflush(stdin);

    char* pinput = input;
    int column;


    column = pinput[0] - 65;
    return column;

}


void reservation() {
    fflush(stdin);

    int row;
    int col;
    char nothing[3];
    char* pinput = input;

    // Asks for seat number
    printf("Que asiento desea reservar? \n");
    fgets(pinput, 5, stdin);

    col = getcolumnnumber();
    printf("\n");
    row = getrownumber();

    flightseats[row][col] = 'X';

    fgets(nothing, 3, stdin);
}

void available(){
    fflush(stdin);
    char nothing[3];

    for(int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%c ",flightseats[i][j]);
        }
        printf("\n");
    }
    fflush(stdin);
    fgets(nothing, 3, stdin);
}

int main() {
    fflush(stdin);
    int choice = 0;

    // initialize seat reservation with 0's
    initializer();
    // Checks flight number
    flightidchecker();
    // menu function
    while(choice != 3){
        choice = menu();
        if(choice == 1){
            reservation();
        }
        else if(choice == 2){
            available();
        }

    }

}