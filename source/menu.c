#include <stdio.h>
#include <string.h>
#include "account.h"

//fair rechercher un compte par le nom et Id dans un fichier CSV
void recherche()
{
    FILE *fichier;
    char ligne[100];
    char nom[50];
    int Id;
    int trouve = 0;
    fichier = fopen("compte.csv", "r");
    if (fichier == NULL)
    {
        printf("Impossible d'ouvrir le fichier.\n");
        return;
    }
    printf("Entrez le nom du compte à rechercher : ");
    scanf("%s", nom);
    printf("Entrez l'ID du compte à rechercher : ");
    scanf("%d", &Id);
    while (fgets(ligne, sizeof(ligne), fichier) != NULL)
    {
        
    }
}

/*
//rechercher un compte par le nome ou Id
void recherche(Account *account)
{
    int choix, Id;
    char nom[50];
    printf("Voulez-vous rechercher par le nom ou l'Id ?\n");
    printf("1. Par le nom\n");
    printf("2. Par l'ID\n");
    scanf("%d", &choix);
    switch (choix)
    {
    case 1:
        printf("Entrez le nom du compte à rechercher : ");
        scanf("%s", nom);
        for (int i = 0; i < 10; i++)
        {
            if (strcmp(account[i].last_name, nom) == 0)
            {
                printf("le compte existe.");
            }
            else
            {
                printf("le compte n'existe pas.");
            }
        }
        break;
        case 2:
        printf("Entrez l'ID du compte à rechercher : ");
        scanf("%d", &Id);
        for (int i = 0; i < 10; i++)
        {
            if (account[i].id == account[0].id)
            {
                printf("le compte existe.");
            }
            else
            {
                printf("le compte n'existe pas.");
            }
        }
        break;
    default:
    printf("Choix invalide, veuillez réessayer.\n");
        break;
    }
}
*/