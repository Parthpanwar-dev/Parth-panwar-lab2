#include <stdio.h>
#include <stdlib.h>
#include <time.h> 

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

#define ADMIN_PASSWORD 8560390  // Admin password

// Ingredient quantities in the machine
int beans = 100, water = 500, milk = 500, syrup = 100;
double total_sales = 0.0;  // Track total sales

void display_main_menu();
void order_coffee();
int check_ingredients(int coffee_choice);
double process_payment(double price);
void admin_login();
void view_ingredients();
void replenish_ingredients();
void view_total_sales();

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
                admin_login();
                break;
            case 3:
                printf("Thank you for choosing us!! \n");
                exit(0);
            default:
                printf("Invalid option. Try again.\n");
        }
    }
    return 0;
}

// Main Menu Display
void display_main_menu() {
    printf("\n%-12s\n", "Coffee Machine Menu:");
    printf("%-12s%-12s\n", "Option", "Description");
    printf("%-12d%-12s\n", 1, "Order Coffee");
    printf("%-12d%-12s\n", 2, "Admin Mode");
    printf("%-12d%-12s\n", 3, "Exit");
    printf("Select an option: ");
}

// Coffee Order Function
void order_coffee() {
    int coffee_choice;

    // Display coffee types with prices
    printf("\n%-12s%-12s\n", "Coffee Type", "Price (AED)");
    printf("1. %-12s%-12.2f\n", "Espresso", ESPRESSO_PRICE);
    printf("2. %-12s%-12.2f\n", "Cappuccino", CAPPUCCINO_PRICE);
    printf("3. %-12s%-12.2f\n", "Mocha", MOCHA_PRICE);
    printf("0. %-12s\n", "Back to Main Menu");
    printf("Select your coffee: ");
    
    scanf("%d", &coffee_choice);

    if (coffee_choice == 0) {
        printf("Returning to main menu...\n");
        return;
    }

    // Check for sufficient ingredients
    if (check_ingredients(coffee_choice)) {
        double price = 0.0;
        switch (coffee_choice) {
            case 1:
                price = ESPRESSO_PRICE;
                printf("You selected %-12s%-12.2f AED\n", "Espresso", price);
                break;
            case 2:
                price = CAPPUCCINO_PRICE;
                printf("You selected %-12s%-12.2f AED\n", "Cappuccino", price);
                break;
            case 3:
                price = MOCHA_PRICE;
                printf("You selected %-12s%-12.2f AED\n", "Mocha", price);
                break;
            default:
                printf("Invalid selection, returning to main menu...\n");
                return;
        }

        // Process payment
        double paid = process_payment(price);

        if (paid >= price) {
            // Deduct ingredients based on coffee choice
            if (coffee_choice == 1) {
                beans -= ESPRESSO_BEANS;
                water -= ESPRESSO_WATER;
            } else if (coffee_choice == 2) {
                beans -= CAPPUCCINO_BEANS;
                water -= CAPPUCCINO_WATER;
                milk -= CAPPUCCINO_MILK;
            } else if (coffee_choice == 3) {
                beans -= MOCHA_BEANS;
                water -= MOCHA_WATER;
                milk -= MOCHA_MILK;
                syrup -= MOCHA_SYRUP;
            }

            total_sales += price;
            printf("%-12s\n", "Your coffee is ready! Enjoy!");
        }
    } else {
        printf("%-12s\n", "Insufficient ingredients for selected coffee.");
    }
}

// Check for sufficient ingredients
int check_ingredients(int coffee_choice) {
    if (coffee_choice == 1) {
        return (beans >= ESPRESSO_BEANS && water >= ESPRESSO_WATER);
    } else if (coffee_choice == 2) {
        return (beans >= CAPPUCCINO_BEANS && water >= CAPPUCCINO_WATER && milk >= CAPPUCCINO_MILK);
    } else if (coffee_choice == 3) {
        return (beans >= MOCHA_BEANS && water >= MOCHA_WATER && milk >= MOCHA_MILK && syrup >= MOCHA_SYRUP);
    }
    return 0;
}

// Process payment
double process_payment(double price) {
    double paid = 0.0, coin;

    printf("%-12s%-12.2f\n", "Total Price:", price);
    printf("%-12s\n", "Insert coins (1 AED or 0.5 AED)");

    while (paid < price) {
        printf("%-12s", "Insert coin: ");
        scanf("%lf", &coin);

        if (coin == 1.0 || coin == 0.5) {
            paid += coin;
            printf("%-12s%-12.2f\n", "Total Inserted:", paid);
        } else {
            printf("%-12s\n", "Invalid coin! Please insert 1 AED or 0.5 AED.");
        }
    }

    double change = paid - price;
    if (change > 0) {
        printf("%-12s%-12.2f\n", "Your change:", change);
    }
    return paid;
}

// Admin login
void admin_login() {
    int password;
    printf("%-12s", "Enter Admin Password: ");
    scanf("%d", &password);

    if (password == ADMIN_PASSWORD) {
        int admin_choice;
        printf("\n%-12s\n", "Admin Login Successful!");

        while (1) {
            printf("\n%-12s\n", "Admin Menu:");
            printf("%-12d%-12s\n", 1, "View Ingredients");
            printf("%-12d%-12s\n", 2, "Replenish Ingredients");
            printf("%-12d%-12s\n", 3, "View Total Sales");
            printf("%-12d%-12s\n", 0, "Exit Admin Mode");
            printf("%-12s", "Select an option: ");
            scanf("%d", &admin_choice);

            switch (admin_choice) {
                case 1:
                    view_ingredients();
                    break;
                case 2:
                    replenish_ingredients();  // Calls the random replenish function
                    break;
                case 3:
                    view_total_sales();
                    break;
                case 0:
                    printf("%-12s\n", "Exiting Admin Mode...");
                    return;
                default:
                    printf("%-12s\n", "Invalid option. Try again.");
            }
        }
    } else {
        printf("%-12s\n", "Incorrect Password. Returning to main menu.");
    }
}

// View ingredients
void view_ingredients() {
    printf("\n%-12s%-12d\n", "Beans:", beans);
    printf("%-12s%-12d\n", "Water:", water);
    printf("%-12s%-12d\n", "Milk:", milk);
    printf("%-12s%-12d\n", "Syrup:", syrup);
}

// Replenish ingredients (random reset)
void replenish_ingredients() {
    // Seed the random number generator
    srand(time(0));

    // Randomly reset ingredients to values within specific ranges
    beans = rand() % 51 + 100;        
    water = rand() % 301 + 500;      
    milk = rand() % 301 + 500;       
    syrup = rand() % 51 + 100;        

    printf("%-12s\n", "Ingredients have been randomly replenished!");
    printf("New ingredient levels:\n");
    printf("%-12s%-12d\n", "Beans:", beans);
    printf("%-12s%-12d\n", "Water:", water);
    printf("%-12s%-12d\n", "Milk:", milk);
    printf("%-12s%-12d\n", "Syrup:", syrup);
}

// View total sales and reset option
void view_total_sales() {
    printf("%-12s%-12.2f\n", "Total Sales:", total_sales);
    printf("Would you like to reset total sales to zero? (1 for Yes, 0 for No): ");
    int reset_choice;
    scanf("%d", &reset_choice);
    if (reset_choice == 1) {
        total_sales = 0.0;
        printf("Total sales have been reset to zero.\n");
    } else {
        printf("Total sales remain unchanged.\n");
    }
}