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
int beans = 15, water = 500, milk = 500, syrup = 100;

void display_main_menu();
void order_coffee(); 

int main() {
    int choice;
    
    while (1) {
        display_main_menu();
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                order_coffee();
                break;
            case 2:
                printf("Admin mode (to be implemented).\n");
                break;
            case 3:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid option. Try again.\n");
        }
    }
    return 0;
}

void display_main_menu() {
    printf("\nCoffee Machine Startup Menu:\n");
    printf("1. Order Coffee\n");
    printf("2. Admin Mode\n");
    printf("3. Exit\n");
    printf("Select an option: ");
}

void order_coffee() {
    int coffee_choice;

    printf("\nAvailable Coffee Types:\n");
    printf("1. Espresso - %.2f AED\n", ESPRESSO_PRICE);
    printf("2. Cappuccino - %.2f AED\n", CAPPUCCINO_PRICE);
    printf("3. Mocha - %.2f AED\n", MOCHA_PRICE);
    printf("0. Back to Main Menu\n");
    printf("Select a coffee type: ");
    
    scanf("%d", &coffee_choice);
    
    if (coffee_choice == 1) {
        if (beans >= ESPRESSO_BEANS && water >= ESPRESSO_WATER) {
            beans -= ESPRESSO_BEANS;
            water -= ESPRESSO_WATER;
            printf("Espresso made! Remaining beans: %d g, water: %d ml\n", beans, water);
        } else {
            printf("Not enough ingredients to make Espresso.\n");
        }
    } else if (coffee_choice == 2) {
        if (beans >= CAPPUCCINO_BEANS && water >= CAPPUCCINO_WATER && milk >= CAPPUCCINO_MILK) {
            beans -= CAPPUCCINO_BEANS;
            water -= CAPPUCCINO_WATER;
            milk -= CAPPUCCINO_MILK;
            printf("Cappuccino made! Remaining beans: %d g, water: %d ml, milk: %d ml\n", beans, water, milk);
        } else {
            printf("Not enough ingredients to make Cappuccino.\n");
        }
    } else if (coffee_choice == 3) {
        if (beans >= MOCHA_BEANS && water >= MOCHA_WATER && milk >= MOCHA_MILK && syrup >= MOCHA_SYRUP) {
            beans -= MOCHA_BEANS;
            water -= MOCHA_WATER;
            milk -= MOCHA_MILK;
            syrup -= MOCHA_SYRUP;
            printf("Mocha made! Remaining beans: %d g, water: %d ml, milk: %d ml, syrup: %d ml\n", beans, water, milk, syrup);
        } else {
            printf("Not enough ingredients to make Mocha.\n");
        }
    } else if (coffee_choice == 0) {
        printf("Returning to main menu...\n");
    } else {
        printf("Invalid selection, returning to main menu...\n");
    }
}
