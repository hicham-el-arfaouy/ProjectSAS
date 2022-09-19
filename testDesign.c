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

void main(){
    // FILE* fichier = NULL;

    // fichier = fopen("test.txt", "a+");
    // for(int i = 0; i < lentghArray; i++){
    //     if (fichier != NULL)
    //     {
    //         fprintf(fichier, "%d\t%s    \t\t%d\t%.2f\n", medicineArray[i].id, medicineArray[i].name, medicineArray[i].amount, medicineArray[i].price); 
    //     }
    // }
    
    // fclose(fichier); // On ferme le fichier qui a été ouvert

    FILE* fichierr = NULL;

    fichierr = fopen("test.txt", "w+");
    for(int i = 0; i < lentghArray; i++){
        if (fichierr != NULL){
            fprintf(fichierr, "%d\t%s    \t\t%d\t%.2f\n", medicineArray[i].id, medicineArray[i].name, medicineArray[i].amount, medicineArray[i].price); 
        }
    }
    
    fclose(fichierr); // On ferme le fichier qui a été ouvert   
}   