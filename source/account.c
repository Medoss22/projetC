#include <stdio.h>
#include <string.h>
#include "fonction.h"


// Fichier CSV pour stocker les comptes
#define ACCOUNT_FILE "data/accounts.csv"

// Fonction pour enregistrer un nouveau compte
void registerAccount() {
    Account account;

    printf("Numéro de compte : ");
    scanf("%s", account.account_number);

    printf("Nom : ");
    scanf("%s", account.last_name);

    printf("Prénom : ");
    scanf("%s", account.first_name);

    printf("Adresse : ");
    scanf(" %[^\n]", account.address);

    printf("Email : ");
    scanf("%s", account.email);

    printf("Téléphone : ");
    scanf("%s", account.phone);

    printf("Solde initial : ");
    scanf("%f", &account.balance);

    strcpy(account.status, "actif"); // Par défaut, le compte est actif

    // Sauvegarder le compte dans le fichier CSV
    saveAccountToCSV(&account, ACCOUNT_FILE);

    printf("Compte enregistré avec succès !\n");
}

// Fonction pour sauvegarder un compte dans le fichier CSV
void saveAccountToCSV(const Account *account, const char *filename) {
    FILE *file = fopen(filename, "a"); // Ouvre le fichier en mode ajout
    if (!file) {
        perror("Erreur lors de l'ouverture du fichier CSV");
        return;
    }

    fprintf(file, "%s,%s,%s,%s,%s,%s,%.2f,%s\n",
            account->account_number,
            account->last_name,
            account->first_name,
            account->address,
            account->email,
            account->phone,
            account->balance,
            account->status);

    fclose(file);
}

//affichier les listes de compte
void displayaccounts(  const char name_file[]){
    FILE*file=fopen(name_file,"r");
    if(file==NULL){
            printf("erreur:impossible d'ouvrir le fichier %s \n",name_file);
return ;} 
Account account;
printf("\n Liste des comptes enregistrés:\n");
printf("-------------------------------------------------------------------------------------------------------------------\n");
printf("Numéro de compte|Nom|Prénom|Solde|Email|Statut du compte\n");
printf("--------------------------------------------------------------------------------------------------------------------\n");
while(fscanf(file,"%d,%49[^,],%49[^,],%f,%49[^,],%9[^,]\n",&account.account_number,account.last_name,account.first_name,account.address,account.email
,account.phone,account.balance,account.status)==8){
    printf("%d|%s|%s|%8.3f|%s|%s\n",account.account_number,account.last_name,account.first_name,account.address,account.email,account.phone,account.balance,account.status);

    printf("--------------------------------------------------------------------------------------------------------------------\n");
}
fclose(file);
}



//fonction qui permete de modifier un compte client
void modifyAcc(int num_acc) 
{
    Account account;
    int a;
    if (num_acc == account.account_number)
    {
        printf("1: modifier l'adresse\n");
        printf("2: modifier l'email\n");
        printf("3: modifier le telephone\n");
        scanf("%d", &a);
        switch (a)
        {
        case 1:
            printf("entre le nouveau adresse: \n");
            scanf("%s", account.address);
            break;
        case 2:
            printf("entre le nouveau email: \n");
            scanf("%s", account.email);
            break;
        case 3:
            printf("entre le nouveau telephone: \n");
            scanf("%s", account.phone);
            break;
        default:
            printf("choix non valable");
            break;
        }
    }
    else
    {
        printf("compte inexistant");
    }  
}




//modifier le compte dans le fichier CSV
void modifyAccCSV(Account account[], char changement[], char filename[], int num_copmte[30])
{
    FILE *file = fopen(filename, "r"); // Ouvre le fichier en mode lecture
    if (file == NULL)
    {
        printf("Impossible d'ouvrir le fichier %s\n", filename);
        return;
    }
    FILE* file2 = fopen("temp.csv", "w"); // fichier temporaire pour stocker les modifications
    char ligne[300];
    while (fgets(ligne, sizeof(ligne), file))
    {
        char words[100];
        sscanf(ligne, "%[^,]", words); //extrait la ligne et on le compare avec la structure acc
        for (int i = 0; i < num_copmte; i++) 
        {
            if (strcmp(words, account->account_number) == 0) 
            {
                // Si le num compte correspond, écrivez le compte mis à jour dans le fichier temporaire
                fprintf(file2, "%s,%s,%s\n", account[i].account_number, account[i].last_name, account[i].balance);
                break;
            }
        }
    }
    fclose(file);
    fclose(file2);
}


//supprimer un compte 
void delete_client(char num, char File_name[]){
    Account account;
	int t=0;
	char ligne[taille_maximalle];
	FILE* fichier; 
	FILE* temp;
	
	fichier = fopen(File_name,"r");
	temp = fopen("temp.CSV","w");
	
	while(fgets(ligne,taille_maximalle,fichier )){
		sscanf(ligne,"%d",&num);
		if(strcmp(num,account.account_number!=0)){
		 fprintf(temp,"%d",ligne);}
		else
		t = 1;
	}
	fclose(fichier);	 fclose(temp);
	    if(t){
    	remove(File_name);
    	rename("temp.txt",File_name);
    	printf("le compte est supprime.\n");}
	    else 
	    printf("le compte n'existe pas :( !!!");  
} 