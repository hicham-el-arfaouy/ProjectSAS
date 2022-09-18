#include <stdio.h>
struct Medicine{
    int id;
    char name[20];
    int amount;
    float prix;
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

void main(){


    printf("\t -----------------------------------------------------------------------------------------------\n");
    printf("\t|\tMedicine ID\t|\tMedicine Name\t\t|\tMedicine Amount\t|\tMedicine Prix\t|\n");
    printf("\t -----------------------------------------------------------------------------------------------\n");

    for(int i = 0; i < lentghArray; i++){
        printf("\t|\t%d\t\t|\t%s    \t\t|\t%d\t\t|\t%.2f\t\t|\n", medicineArray[i].id, medicineArray[i].name, medicineArray[i].amount, medicineArray[i].prix);
    }

    printf("\t -----------------------------------------------------------------------------------------------\n");








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