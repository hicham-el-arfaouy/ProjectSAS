#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


struct Medicine{
    int id;
    char name[20];
    int amount;
    float price;
};


// Global Variables
int lentghArray = 8;
struct Medicine medicineArray[100] = {
        {11, "doliprane", 4, 25.99},
        {34, "parasitamol", 1, 20.99},
        {33, "aspro", 1, 20.99},
        {36, "aspirine", 2, 22.99},
        {45, "huawei", 6, 25.99},
        {5, "setamix", 4, 25.99},
        {2, "dwa rass", 0, 35.99},
        {2, "12345678901", 0, 35.99},
    };

void toUpperCase(char string[20]){
    for(int i = 0; i < strlen(string); i++){
        string[i] = toupper(string[i]);
    }
}

void main(){


    char choice[20];
    int choicee;
    
    do{
        printf("\t -------------------------------------------------------\t\n");
        printf("\t|\t\t\tMENU\t\t\t\t|\n");
        printf("\t -------------------------------------------------------\t\n");
        printf("\t|\t{ 1 }\t:\tShow Medicines\t\t\t|\n");
        printf("\t|\t{ 2 }\t:\tAdd Medicines\t\t\t|\n");
        printf("\t|\t{ 3 }\t:\tUpdate a Medicine\t\t|\n");
        printf("\t|\t{ 4 }\t:\tSearch for a Medicine\t\t|\n");
        printf("\t|\t{ 5 }\t:\tDelete a Medicine\t\t|\n");
        printf("\t|\t{ 6 }\t:\tBuy a Medicine\t\t\t|\n");
        printf("\t|\t{ 7 }\t:\tDashboard\t\t\t|\n");
        printf("\t|\t{ 0 }\t:\tExit\t\t\t\t|\n");
        printf("\t -------------------------------------------------------\t\n");
        printf("Please enter your choice : ");
        scanf("%s", &choice);
        choicee = atoi(choice);
        printf("Please enter your choice : %d", choicee);
        switch(choicee){
            case 0: printf("0"); break;
            case 1: printf("0"); break;
            case 2: printf("0");  break;
            case 3: printf("0");  break;
            case 4: printf("0");  break;
            case 5: printf("0");  break;
            case 6: printf("0");  break;
            case 7: printf("0");  break;
            default : printf("\n\t\t===> PLEASE ENTER VALID CHOICE!!! <===\n\n");
        }
    }while(choicee != 0);





    // printf("\t -------------------------------------------------------------------------------------------------------------------------------\n");
    // printf("\t|\tN\t|\tID\t|\tMedicine Name\t|\tAmount\t|\tPrice Total\t|\tTransaction Date\t|\n");
    // printf("\t ---------------------------------------------------------------------------------------------------------------------------------------\n");

    // for(int i = 0; i < lentghArray; i++){
        
    //             printf("\t|\t%d\t|\t%d\t|\t%s    \t|\t%d\t|\t%.2f   DH\t|\t%s    \t\t|\n", i + 1, medicineArray[i].id, medicineArray[i].name, medicineArray[i].amount, medicineArray[i].price);
            
        
    // }

    // printf("\t ---------------------------------------------------------------------------------------------------------------------------------------\n\n\n");

    // char s[20];
    // scanf("%s", s);
    // toUpperCase(s);
    // printf("%s", s);




    // float moyen = totalProducts != 0 ? ((float)totalPrix / (float)totalProducts) : 0;
    // printf("\t -------------------------------------------------------------------------------------------------------------------------------\n");
    // printf("\t|\tSum Medicine Sold\t|\tMoyen Medicine Sold\t|\tMax Medicine Sold\t|\tMin Medicine Sold\t|\n");
    // printf("\t -------------------------------------------------------------------------------------------------------------------------------\n");
    // printf("\t|\t%.2f   DH\t\t|\t%.2f   DH\t\t|\t%.2f   DH\t\t|\t%.2f   DH\t\t|\n", 33, 33, 33, 22);
    // printf("\t ---------------------------------------------------------------|\t%s        \t\t|\t%s\t\t|\n", "", "");
    // printf("\t                                                                 ---------------------------------------------------------------\n");
    // printf("------------ the sum price of all products : %d\n", 77);
    // printf("------------ the moyen price of all products : %.2f\n", 44);
    // printf("------------ the min of all products : %s\n", medicineArray[0].name);
    // printf("------------ the max of all products : %s\n", medicineArray[0].name);

    // printf("\t ----------\t----------\t----------\t----------\n");
    // printf("\t|   name   |\t|    id    |\t|  amount  |\t|   prix   |\t|   date   |\n");
    // printf("\t ----------\t----------\t----------\t----------\n");

    // for(int i = 0; i < lentghArrayTransaction; i++){
    //     printf("\t%s           \t%d           \t%d         \t%.2f           \t%s\n", transactionArray[i].nameProduct, transactionArray[i].idProduct, transactionArray[i].amountProductBuying, transactionArray[i].prixProductBuying, transactionArray[i].buyTime);
    // }







    // printf("\t -------------------------------------------------------\t\n");
    // printf("\t|\t\t\tMENU\t\t\t\t|\n");
    // printf("\t -------------------------------------------------------\t\n");
    // printf("\t|\t{1}\t:\tShow Medicines\t\t\t|\n");
    // printf("\t|\t{2}\t:\tAdd Medicines\t\t\t|\n");
    // printf("\t|\t{3}\t:\tSearch for Medicine\t\t|\n");
    // printf("\t|\t{4}\t:\tDelete Medicine\t\t\t|\n");
    // printf("\t|\t{0}\t:\tExit\t\t\t\t|\n");
    // printf("\t -------------------------------------------------------\t\n");
}