#include <stdio.h>
#include <stdlib.h>
#include "account.h"

void showMenu() {
    printf("\n=== Menu de gestion bancaire ===\n");
    printf("1. Ajouter un compte\n");
    printf("2. Modifier un compte\n");
    printf("3. Supprimer un compte\n");
    printf("Votre choix : ");
}

int main() {
    int choix;
    char account_number[20];
    float amount;

    do {
        showMenu();
        scanf("%d", &choix);

        switch (choix) {
        case 1:
            registerAccount();
            break;
        case 2:
            int num_acc;
            printf("Entrez le numéro de compte: ");
            scanf("%d", &num_acc);
            modifyAcc(num_acc);
            break;
        default:
            printf("Choix invalide, veuillez réessayer.\n");
        }
    } while (1);

    return 0;
}
