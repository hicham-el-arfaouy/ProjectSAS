#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h> 


// Structures Area
struct Medicine{
    int id;
    char name[20];
    int amount;
    float prix;
};


// Global Variables
int lentghArray = 7;
struct Medicine medicineArray[100] = {
        {11, "doliprane", 4, 25.99},
        {34, "parasitamol", 1, 20.99},
        {33, "aspro", 1, 20.99},
        {36, "aspirine", 2, 22.99},
        {45, "huawei", 6, 25.99},
        {5, "setamix", 4, 25.99},
        {2, "dwa rass", 0, 35.99},
    };


// Functions
void addProduct(){
    int numbers;
    printf("Please enter the numbers of products : ");
    scanf("%d", &numbers);
    for(int i = 0; i < numbers; i++){
        struct Medicine medicine;
        printf("Medicine id : ");
        scanf("%d", &medicine.id);
        printf("Medicine name : ");
        scanf("%s", &medicine.name);
        printf("Medicine amount : ");
        scanf("%d", &medicine.amount);
        printf("Medicine prix : ");
        scanf("%f", &medicine.prix);

        medicineArray[lentghArray] = medicine;
        ++lentghArray;
    }
}
int searchProduct(){
    int choiceSearchDelete;
    printf("Would you like to search with NAME or ID \n");
    printf("[1] ===>> Search  with Name \n");
    printf("[2] ===>> Search with ID \n");
    scanf("%d", &choiceSearchDelete);
    if(choiceSearchDelete == 1){
    char searchName[20];
    printf("Please enter the name of your medecine : ");
    scanf("%s", searchName);
    for(int i = 0; i < lentghArray; i++){
        if(strcmp(searchName, medicineArray[i].name) == 0){
            printf("\t The name of medecin product %s,\t ID ==>>   %d,\t Amount ==>> %d,\t Prix ==>> %.2f \n", medicineArray[i].name, medicineArray[i].id, medicineArray[i].amount, medicineArray[i].prix);
            return i;
        }
    }

    printf("Sorry! we dont have any medecine with this name \n");
    }else {
        int searchId;
        printf("Please enter ID of your medecine : ");
        scanf("%d", &searchId);
        for(int i = 0; i < lentghArray; i++){
        if(searchId == medicineArray[i].id){
            printf("\t The name of medecin product %s,\t ID ==>>   %d,\t Amount ==>> %d,\t Prix ==>> %.2f \n", medicineArray[i].name, medicineArray[i].id, medicineArray[i].amount, medicineArray[i].prix);
            return i;
        }
    }

    printf("Sorry! we dont have this medecine \n");
    }
    return -1;
}
void showProduct(){
    int sortAlphaPrix;
    struct Medicine help;

    printf("Would you like to sort with Alphabetical or Prix \n");
    printf("[1] ===>> Sort  with Alphabetical \n");
    printf("[2] ===>> Sort with Prix \n");
    scanf("%d", &sortAlphaPrix);

    if(sortAlphaPrix == 1){
        for(int i = 0; i < lentghArray; i++){
            for(int j = i + 1; j < lentghArray; j++){
                if(strcmp(medicineArray[i].name, medicineArray[j].name) > 0 ){
                    help = medicineArray[i];
                    medicineArray[i] = medicineArray[j];
                    medicineArray[j] = help;
                }
            }
        }
    }else{
        for(int i = 0; i < lentghArray; i++){
            for(int j = i + 1; j < lentghArray; j++){
                if(medicineArray[i].prix < medicineArray[j].prix){
                    help = medicineArray[i];
                    medicineArray[i] = medicineArray[j];
                    medicineArray[j] = help;
                }
            }
        }
    }
 
    printf("\t ----------\t----------\t----------\t----------\n");
    printf("\t|   name   |\t|    id    |\t|  amount  |\t|   prix   |\n");
    printf("\t ----------\t----------\t----------\t----------\n");

    for(int i = 0; i < lentghArray; i++){
        printf("\t%s           \t%d           \t%d         \t%.2f\n", medicineArray[i].name, medicineArray[i].id, medicineArray[i].amount, medicineArray[i].prix);
    }
}
void deleteProduct(){
    int i , index = searchProduct();
    if(index != -1){
        for(i = index; i < lentghArray; i++){
            medicineArray[i] = medicineArray[i + 1];
        }

        --lentghArray;
    }
}
void menu(){
    int choice;
    
    do{
        printf("\t -------------------------------------------------------\t\n");
        printf("\t|\t\t\tMENU\t\t\t\t|\n");
        printf("\t -------------------------------------------------------\t\n");
        printf("\t|\t{ 1 }\t:\tShow Medicines\t\t\t|\n");
        printf("\t|\t{ 2 }\t:\tAdd Medicines\t\t\t|\n");
        printf("\t|\t{ 3 }\t:\tSearch for Medicine\t\t|\n");
        printf("\t|\t{ 4 }\t:\tDelete Medicine\t\t\t|\n");
        printf("\t|\t{ 0 }\t:\tExit\t\t\t\t|\n");
        printf("\t -------------------------------------------------------\t\n");
        printf("Please enter your choice : ");
        scanf("%d", &choice);
        system("cls");
        switch(choice){
            case 0: break;
            case 1: showProduct(); break;
            case 2: addProduct(); break;
            case 3: searchProduct(); break;
            case 4: deleteProduct(); break;
            default : printf("\n\t\t===> PLEASE ENTER VALID NUMBER!!! <===\n\n");
        }
    }while(choice != 0);
}


void main(){

    menu();
}
