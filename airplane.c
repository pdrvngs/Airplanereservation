#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// MACROS
#define ROWS 32
#define COLS 6

// Function prototypes
void clearscreen(void); // Clears screen
int menu(void); // Provides menu options and checks input
void flightidchecker(void); // checks flight id for correct # of digits
void initializer(void); // Initializes flight seat array
int getrownumber(void); // gets row number based on input [letter-num-num or letter-num]
int getcolnumber(void); // gets col number based on the first value of input
void reservation(void); // assigns reservation to seat number given, runs check for reserved seats
void available(void); // displays the seat chart with available seats.


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


int getcolnumber(){
    fflush(stdin);

    char* pinput = input;
    int column;


    column = pinput[0] - 65;
    return column;

}

// is missing the type menu to return to menu from FASE II
void reservation() {
    fflush(stdin);
    int reservado = 0;
    int row;
    int col;
    char nothing[3];
    char* pinput = input;

    // Asks for seat number
    printf("Que asiento desea reservar? \n");
    fgets(pinput, 5, stdin);
    col = getcolnumber();
    printf("\n");
    row = getrownumber();

    while(reservado != 1) {
        if(flightseats[row][col] == 'X'){
            printf("Este asiento ya esta reservado, porfavor ingrese otro asiento: ");
            fgets(pinput, 5, stdin);
            col = getcolnumber();
            printf("\n");
            row = getrownumber();
        }
        else {
            printf("Felicitaciones! Reservo el asiento: "); fputs(pinput, stdout);
            flightseats[row][col] = 'X';
            reservado = 1;
        }
    }
    fflush(stdin);
    fgets(nothing, 3, stdin);
}

void available(){
    fflush(stdin);
    char nothing[3];
    printf("   | A | B | C | D | E | F |\n");
    printf("   -------------------------\n");
    for(int i = 0; i < ROWS; i++) {
        if(i > 8) {
            printf(" %d", i+1);
        } else {
            printf(" %d ", i+1);
        }
        for (int j = 0; j < COLS; j++) {
            printf("| %c ",flightseats[i][j]);
        }
        printf("|\n");
    }
    fflush(stdin);
    printf("Presione ENTER para regresar al menu principal\n");
    fgets(nothing, 3, stdin);
}

int main() {
    fflush(stdin);
    clearscreen();
    int choice = 0;

    // initialize seat reservation with 0's
    initializer();

    // Checks flight number
    flightidchecker();

    // menu function
    while(choice != 3){
        choice = menu();
        if(choice == 1){
            // calls reservation process
            reservation();
        }
        else if(choice == 2){
            // gets available seats
            available();
        }

    }

}