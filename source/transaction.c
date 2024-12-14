#include <stdio.h>
#include <string.h>
#include "account.h"

float transfert(Account *account1, Account *account2, float ST, char file_name[])  //ST c'est solde a transferer, account1 c'est source
{
    if (account1->balance > ST && ST > 0)
    {
        account1->balance = account1->balance - ST; //Retirer de l'argent du account1
        account2->balance = account2->balance + ST; //Ajouter de l'argent sur le account2
        printf("Transfert réussi de %.2f du compte %s vers le compte %s.\n",
        ST, account1->account_number, account2->account_number);
    }
    else
    {
        printf("Solde insuffisant\n");
    }
    FILE* f = fopen(file_name, "a");
    if (f == NULL)
    {
        printf("Impossible d'ouvrir le fichier\n");
        return 0;
    }
    fprintf(f, "Transfert de %.2f du compte %s vers le compte %s est effectuer.\n", ST, account1->account_number, account2->account_number);
    fclose(f);
    return 0;
}