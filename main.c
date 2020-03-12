#include <stdio.h>

// Global Variables
char flightid;


int menu(){
    int choice = 0;
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

        }
    }
}

int main() {
    menu();
    return 0;
}
