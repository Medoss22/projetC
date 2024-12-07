#ifndef ACCOUNT_H
#define ACCOUNT_H

typedef struct {
    int account_number;
    char first_name[50];
    char last_name[50];
    char address[100];
    char email[50];
    char phone[15];
    float balance;
    char status[10];  // "actif" ou "inactif"
} Account;

// Fonctions liées à la gestion des comptes
void registerAccount();
void displayAccounts();
void saveAccountToCSV(const Account *account, const char *filename);
void modifyAcc(Account account[]);
void modifyAccCSV(Account account[], char changement[], char filename[], int num_copmte[30]);
void delete_client(Account account[],char num,char File_name[]);

#endif
