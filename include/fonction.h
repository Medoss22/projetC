#ifndef ACCOUNT_H
#define ACCOUNT_H
#define taille_maximalle 1000


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
void makeDeposit(Account account, char file_name[]);
void transfert(Account *account1, Account *account2, char file_name[]);
void trier_compte(char *File_name);

#endif
