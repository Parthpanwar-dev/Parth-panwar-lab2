#include <stdio.h>
#include <stdlib.h>
#define ESPRESSO_BEANS 8
#define ESPRESSO_WATER 30
#define ESPRESSO_PRICE 3.5
#define CAPPUCCINO_BEANS 8
#define CAPPUCCINO_WATER 30
#define CAPPUCCINO_MILK 70
#define CAPPUCCINO_PRICE 4.5
#define MOCHA_BEANS 8
#define MOCHA_WATER 39
#define MOCHA_MILK 160
#define MOCHA_SYRUP 30
#define MOCHA_PRICE 5.5

// Ingredient quantities in the machine
int beans = 100, water = 500, milk = 500, syrup = 100;

void display_menu();

int main() {
    int choice;
    
    while (1) {
        display_menu();
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Order coffee (to be implemented).\n");
                break;
            case 2:
                printf("Admin mode (to be implemented).\n");
                break;
            case 3:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid option try again...\n");
        }
    }
    return 0;
}

void display_menu() {
    printf("\nCoffee Machine Menu:\n");
    printf("1. Order Coffee\n");
    printf("2. Admin Mode\n");
    printf("3. Exit\n");
    printf("Select an option: ");
}
