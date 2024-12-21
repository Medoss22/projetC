#include <stdio.h>
#include <string.h>
#include "fonction.h"

void transfert(Account *account1, Account *account2, char file_name[])  
{
    float ST;
    printf("Donner le montant %f a deposer dans le compte de numero %d: ", ST, account2->account_number); //ST c'est solde a transferer, account1 c'est source
    scanf("%f",&ST);
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
        return;
    }
    fprintf(f, "Transfert de %.2f du compte %s vers le compte %s est effectuer.\n", ST, account1->account_number, account2->account_number);
    fclose(f);
}

// effectuer un dépôt
void makeDeposit(Account account, char file_name[]) {
    float montant;
    printf("Donner le montant %f a deposer dans votre compte de numero %d: ", montant, account.account_number);
    scanf("%f",&montant);

    if (montant > 0) {
        account.balance += montant;
        printf("depot de %.3f effectué avec succès :) pour le compte %d !!\n", montant,account.account_number);
        printf("Nouveau solde : %.3f\n", account.balance);
    } else {
        printf("Le montant du dépôt doit être positif :( .\n");
    }
    FILE* f = fopen(file_name, "a");
    if (f == NULL)
    {
        printf("Impossible d'ouvrir le fichier\n");
        return;
    }
    fprintf(f, "depot de %.3f pour le compte %d est effectuer.\n", montant,account.account_number);
    fclose(f);
}

