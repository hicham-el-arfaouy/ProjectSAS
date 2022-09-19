#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>


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
    {2, "dwa:R_ass", 0, 35.99},
    {2, "12345678901", 0, 35.99},
};

char * date(char * n){
    char * name = n;
    
    name[0] = 'v';

    return name;
}

void main(){
    // char time[50];
    // time_t  t = time(NULL);
    // strcpy(name, ctime(&t));
    // name[3] = '_';
    // name[7] = '_';
    // name[10] = '_';
    // name[19] = '_';
    // printf("%s", time);
    struct Medicine medicine;


    // FILE* fichierr = NULL;

    // fichierr = fopen("test.txt", "w+");
    // for(int i = 0; i < lentghArray; i++){
    //     if (fichierr != NULL){
    //         fprintf(fichierr, "%d\t%s\t\t\t%d\t%.2f\n", medicineArray[i].id, medicineArray[i].name, medicineArray[i].amount, medicineArray[i].price); 
    //     }
    // }
    
    // fclose(fichierr); // On ferme le fichier qui a été ouvert   

    FILE* fichier = NULL;

    fichier = fopen("test.txt", "r");
 
    
        if (fichier != NULL)
        {
            while(fscanf(fichier, "%d\t%s\t\t\t%d\t%f", &medicine.id, &medicine.name, &medicine.amount, &medicine.price) != -1)
                printf("%d--%s--%d--%.2f\n", medicine.id, medicine.name, medicine.amount, medicine.price); 
            
        }
    
    
    fclose(fichier); // On ferme le fichier qui a été ouvert
}   