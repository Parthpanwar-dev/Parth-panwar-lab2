#include <stdio.h>

int main() {
    int balance = 1000;
    int transactions[] = {200, -150, -500, -400, -50, -200, 300};  
    int tobeprocessed[10];  
    int tbp_count = 0;  

    for (int i = 0; i < 7; i++) {  
        int transaction = transactions[i];
         
        
        if (balance == 0) {
            printf("Balance is zero; no further transactions will be processed.\n");
            tobeprocessed[tbp_count++] = transaction;
            break;
        }

        
        if (transaction > 0) {
            balance += transaction;  
        } else if (balance + transaction >= 0) {
            balance += transaction;  
        } else {
            printf("Invalid transaction of %d; insufficient funds.\n", transaction);
            tobeprocessed[tbp_count++] = transaction;  
        }
    }

    
    printf("Final Balance: %d AED\n", balance);
    printf("Unprocessed Transactions: ");
    for (int i = 0; i < tbp_count; i++) {
        printf("%d ", tobeprocessed[i]);
    }
    printf("\n");

    return 0;
}
