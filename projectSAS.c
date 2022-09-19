#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h> 


// Structures Area
struct Medicine{
    int id;
    char name[20];
    int amount;
    float price;
};


// Global Variables
float totalPrice = 0, totalProducts = 0;
int max = -1, min = -1;
int lentghArray = 7;
struct Medicine medicineArray[100] = {
        {11, "doliprane", 4, 25.99},
        {34, "parasitamol", 1, 20.99},
        {33, "aspro", 1, 20.99},
        {36, "aspirine", 2, 22.99},
        {45, "huawei", 6, 25.99},
        {5, "setamix", 4, 25.99},
        {2, "dwa rass", 0, 3335.99},
};


// Functions
void sortByAlphabet(){
    struct Medicine help;

    for(int i = 0; i < lentghArray; i++){
        for(int j = i + 1; j < lentghArray; j++){
            if(strcmp(medicineArray[i].name, medicineArray[j].name) > 0 ){
                help = medicineArray[i];
                medicineArray[i] = medicineArray[j];
                medicineArray[j] = help;
            }
        }
    }
}

void sortByPrice(){
    struct Medicine help;

    for(int i = 0; i < lentghArray; i++){
        for(int j = i + 1; j < lentghArray; j++){
            if(medicineArray[i].price < medicineArray[j].price){
                help = medicineArray[i];
                medicineArray[i] = medicineArray[j];
                medicineArray[j] = help;
            }
        }
    }
}

void showSingleMedicine(struct Medicine medicine){
    printf("\t -----------------------------------------------------------------------------------------------\n");
    printf("\t|\tMedicine ID\t|\tMedicine Name\t|\tMedicine Amount\t|\tMedicine Price\t|\n");
    printf("\t -----------------------------------------------------------------------------------------------\n");
    printf("\t|\t%d\t\t|\t%s    \t|\t%d\t\t|\t%.2f   DH\t|\n", medicine.id, medicine.name, medicine.amount, medicine.price);
    printf("\t -----------------------------------------------------------------------------------------------\n\n\n\n");
}

void showListMedicines(bool fromUpdate){
    printf("\t -----------------------------------------------------------------------------------------------\n");
    printf("\t|\tMedicine ID\t|\tMedicine Name\t|\tMedicine Amount\t|\tMedicine Price\t|\n");
    printf("\t -----------------------------------------------------------------------------------------------\n");

    for(int i = 0; i < lentghArray; i++){
        if(fromUpdate){
            if(medicineArray[i].amount < 3){
                printf("\t|\t%d\t\t|\t%s    \t|\t%d\t\t|\t%.2f   DH\t|\n", medicineArray[i].id, medicineArray[i].name, medicineArray[i].amount, medicineArray[i].price);
            }
        }else{
            if(medicineArray[i].amount != 0){
                printf("\t|\t%d\t\t|\t%s    \t|\t%d\t\t|\t%.2f   DH\t|\n", medicineArray[i].id, medicineArray[i].name, medicineArray[i].amount, medicineArray[i].price);
            }
        }
    }

    printf("\t -----------------------------------------------------------------------------------------------\n\n\n\n");
}

int showMedicines(){
    int sortChoice;

    do{
        printf("[1] ===> Sort with Alphabet \n");
        printf("[2] ===> Sort with Price \n");
        printf("[0] ===> Return to Menu \n");
        printf("Would you like to sort with Alphabet or Price : ");
        scanf("%d", &sortChoice);
        system("cls");
        switch(sortChoice){
            case 0: return 0;
            case 1: sortByAlphabet(); break;
            case 2: sortByPrice(); break;
            default : printf("\n\t\t===> PLEASE ENTER VALID CHOICE!!! <===\n\n");
        }
    }while(sortChoice < 0 || sortChoice > 2);
 
    showListMedicines(false);
}

int addMedicine(){
    int numbers;
    printf("[0] ===> Return to Menu \n");
    printf("How many medicine do you want add : ");
    scanf("%d", &numbers);
    if(numbers <= 0){
        system("cls");
        return 0;
    }
    for(int i = 0; i < numbers; i++){
        struct Medicine medicine;
        printf("--------------[ %d ]--------------\n", i + 1);
        printf("Medicine ID : ");
        scanf("%d", &medicine.id);
        printf("Medicine Name : ");
        scanf("%s", &medicine.name);
        printf("Medicine Amount : ");
        scanf("%d", &medicine.amount);
        printf("Medicine Price : ");
        scanf("%f", &medicine.price);

        medicineArray[lentghArray] = medicine;
        ++lentghArray;
    }

    showListMedicines(false);
}

int isExistById(int id){
    for(int i = 0; i < lentghArray; i++){
        if(id == medicineArray[i].id){
            showSingleMedicine(medicineArray[i]);
            return i;
        }
    }

    return -1;
}

int isExistByName(char name[20]){
    for(int i = 0; i < lentghArray; i++){
        if(strcmp(name, medicineArray[i].name) == 0){
            showSingleMedicine(medicineArray[i]);
            return i;
        }
    }

    return -1;
}

void searchMedicine(){
    int searchChoice;
    int index;
    char searchName[20];
    int searchId;

    do{
        printf("[1] ===> Search with Name \n");
        printf("[2] ===> Search with ID \n");
        printf("[0] ===> Return to Menu \n");
        printf("Would you like to search with NAME or ID : ");
        scanf("%d", &searchChoice);
        system("cls");
        switch(searchChoice){
            case 0: break;
            case 1: 
                printf("Enter the Name of medicine you want : ");
                scanf("%s", &searchName);
                index = isExistByName(searchName);
                break;
            case 2: 
                printf("Enter the ID of medicine you want : ");
                scanf("%d", &searchId);
                index = isExistById(searchId);
                break;
            default : printf("\n\t\t===> PLEASE ENTER VALID CHOICE!!! <===\n\n");
        }
        if(index == -1){
            printf("\t -----------------------------------------------------------------------------------------------\n");
            printf("\t\t\t\t\tSorry! We don't have this Medicine.\t\t\t\t\t\n");
            printf("\t -----------------------------------------------------------------------------------------------\n\n\n\n");
        }
    }while(searchChoice < 0 || searchChoice > 2);
}

int deleteMedicine(){
    int deleteId, index;

    showListMedicines(false);

    printf("[0] ===> Return to Menu \n");
    printf("Enter the ID of medicine you want Delete : ");
    scanf("%d", &deleteId);

    if(deleteId == 0){
        return 0;
    }

    index = isExistById(deleteId);

    if(index != -1){
        for(int i = index; i < lentghArray; i++){
            medicineArray[i] = medicineArray[i + 1];
        }
        --lentghArray;
    }else{
        printf("\t -----------------------------------------------------------------------------------------------\n");
        printf("\t\t\t\t\tSorry! We don't have this Medicine.\t\t\t\t\t\n");
        printf("\t -----------------------------------------------------------------------------------------------\n\n\n\n");
    }
}

int updateMedicine(){
    int updateId, updateAmount, index;

    showListMedicines(true);

    printf("[0] ===> Return to Menu \n");
    printf("Enter the ID of medicine you want Update : ");
    scanf("%d", &updateId);

    if(updateId == 0){
        return 0;
    }

    index = isExistById(updateId);

    if(index != -1){
        printf("Enter the amount you want add : ");
        scanf("%d", &updateAmount);
        if(updateAmount > 0){
            medicineArray[index].amount += updateAmount;
        }else{
            printf("\t -----------------------------------------------------------------------------------------------\n");
            printf("\t\t\t\t\tDon't Play with Me !!!.\t\t\t\t\t\n");
            printf("\t -----------------------------------------------------------------------------------------------\n\n\n\n");
        }
    }else{
        printf("\t -----------------------------------------------------------------------------------------------\n");
        printf("\t\t\t\t\tSorry! We don't have this Medicine.\t\t\t\t\t\n");
        printf("\t -----------------------------------------------------------------------------------------------\n\n\n\n");
    }
}
int buyMedicine(){
    int buyId, buyAmount, index;

    showListMedicines(false);

    printf("[0] ===> Return to Menu \n");
    printf("Enter the ID of medicine you want Buy : ");
    scanf("%d", &buyId);

    if(buyId == 0){
        return 0;
    }

    index = isExistById(buyId);

    if(index != -1){
        printf("Enter the amount you want Buy : ");
        scanf("%d", &buyAmount);
        if(buyAmount > medicineArray[index].amount || buyAmount < 1){
            printf("\t -----------------------------------------------------------------------------------------------\n");
            printf("\t\t\t\t\tSorry! We don't have that amount of this Medicine.\t\t\t\t\t\n");
            printf("\t -----------------------------------------------------------------------------------------------\n\n\n\n");
        }else{
            if(totalProducts == 0){
                min = index;
                max = index;
            }else{
                if(medicineArray[min].price > medicineArray[index].price){
                    min = index;
                }
                if(medicineArray[max].price < medicineArray[index].price){
                    max = index;
                }
            }
            totalPrice += (medicineArray[index].price * buyAmount);
            totalProducts += buyAmount;
            medicineArray[index].amount -= buyAmount;
            system("cls");
        }
    }else{
        printf("\t -----------------------------------------------------------------------------------------------\n");
        printf("\t\t\t\t\tSorry! We don't have this Medicine.\t\t\t\t\t\n");
        printf("\t -----------------------------------------------------------------------------------------------\n\n\n\n");
    }
}

void dashboard(){
    float moyen = totalProducts != 0 ? (totalPrice / totalProducts) : 0;

    printf("\t -------------------------------------------------------------------------------------------------------------------------------\n");
    printf("\t|\tSum Medicine Sold\t|\tMoyen Medicine Sold\t|\tMax Medicine Sold\t|\tMin Medicine Sold\t|\n");
    printf("\t -------------------------------------------------------------------------------------------------------------------------------\n");
    printf("\t|\t%.2f   DH\t\t|\t%.2f   DH\t\t|\t%.2f   DH\t\t|\t%.2f   DH\t\t|\n", totalPrice, moyen, medicineArray[max].price, medicineArray[min].price);
    printf("\t ---------------------------------------------------------------|\t%s\t\t|\t%s\t\t|\n", medicineArray[max].name, medicineArray[min].name);
    printf("\t                                                                 ---------------------------------------------------------------\n\n\n");
}

void menu(){
    int choice;
    
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
        scanf("%d", &choice);
        system("cls");
        switch(choice){
            case 0: break;
            case 1: showMedicines(); break;
            case 2: addMedicine(); break;
            case 3: updateMedicine(); break;
            case 4: searchMedicine(); break;
            case 5: deleteMedicine(); break;
            case 6: buyMedicine(); break;
            case 7: dashboard(); break;
            default : printf("\n\t\t===> PLEASE ENTER VALID CHOICE!!! <===\n\n");
        }
    }while(choice != 0);
}

void main(){
    menu();
}
