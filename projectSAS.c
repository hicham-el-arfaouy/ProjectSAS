#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h> 
#include <ctype.h>
#include <time.h>

// this line for define the length of all name in this project
#define LENGTH_NAME 50


/* Structures Area */
struct Medicine{
    int id;
    char name[LENGTH_NAME];
    int amount;
    float price;
};

struct Transaction{
    int idMedicine;
    char nameMedicine[LENGTH_NAME];
    int amountMedicineBuying;
    float unitPriceMedicine;
    float priceMedicineBuying;
    char buyTime[50];
    char timeToCompare[50];
};


/* Global Variables */
float totalPrice = 0, totalProducts = 0;
struct Transaction max;
struct Transaction min;
int lengthTransactionArray;
int lengthMedicineArray;


/* Files */
// this function to write the array medicines into file
void medicineArrayToFile(struct Medicine * medicineArray){
    FILE* file = NULL;

    file = fopen("Medicines.txt", "w");
    if (file != NULL){
        for(int i = 0; i < lengthMedicineArray; i++){
            fprintf(file, "%d\t%s\t\t\t%d\t%.2f\n", (medicineArray+i)->id, (medicineArray+i)->name, (medicineArray+i)->amount, (medicineArray+i)->price); 
        }
    }else{
        printf("\t -----------------------------------------------------------------------------------------------\n");
        printf("\t\t\t\t\tNo such file.\t\t\t\t\t\n");
        printf("\t -----------------------------------------------------------------------------------------------\n\n\n\n");
    }
    
    fclose(file); 
}
// this function to write the array transaction into file
void transactionArrayToFile(struct Transaction * transactionArray){
    FILE* file = NULL;

    file = fopen("Transactions.txt", "w");
    if (file != NULL){
        for(int i = 0; i < lengthTransactionArray; i++){
            fprintf(file, "%d\t%s\t\t%d\t%.2f\t%.2f\t%s %s\n", (transactionArray+i)->idMedicine, (transactionArray+i)->nameMedicine, (transactionArray+i)->amountMedicineBuying, (transactionArray+i)->unitPriceMedicine,(transactionArray+i)->priceMedicineBuying, (transactionArray+i)->timeToCompare, (transactionArray+i)->buyTime); 
        }
    }else{
        printf("\t -----------------------------------------------------------------------------------------------\n");
        printf("\t\t\t\t\tNo such file.\t\t\t\t\t\n");
        printf("\t -----------------------------------------------------------------------------------------------\n\n\n\n");
    }
    
    fclose(file); 
}
// this function to read the informations from file to array medicines
void readMedicineArray(struct Medicine * medicineArray){
    lengthMedicineArray = 0;
    FILE* file = NULL;

    file = fopen("Medicines.txt", "r");
    if (file != NULL){
        while(fscanf(file, "%d\t%s\t\t\t%d\t%f", &(medicineArray+lengthMedicineArray)->id, &(medicineArray+lengthMedicineArray)->name, &(medicineArray+lengthMedicineArray)->amount, &(medicineArray+lengthMedicineArray)->price) != -1){
            lengthMedicineArray++;
        }
    }else{
        printf("\t -----------------------------------------------------------------------------------------------\n");
        printf("\t\t\t\t\tNo such file.\t\t\t\t\t\n");
        printf("\t -----------------------------------------------------------------------------------------------\n\n\n\n");
    }
    
    fclose(file); 
}
// this function to read the informations from file to array transaction
void readTransactionArray(struct Transaction * transactionArray){
    lengthTransactionArray = 0;
    char date[50];

    struct tm * buyTime;
    time_t  t;
    time(&t);
    buyTime = localtime(&t);
    strftime(date, 80, "%x", buyTime);

    FILE* file = NULL;

    file = fopen("Transactions.txt", "r");
    if (file != NULL){
        while(fscanf(file, "%d\t%s\t\t%d\t%f\t%f\t%s %[^\n]", &(transactionArray+lengthTransactionArray)->idMedicine, &(transactionArray+lengthTransactionArray)->nameMedicine, &(transactionArray+lengthTransactionArray)->amountMedicineBuying, &(transactionArray+lengthTransactionArray)->unitPriceMedicine, &(transactionArray+lengthTransactionArray)->priceMedicineBuying, &(transactionArray+lengthTransactionArray)->timeToCompare, &(transactionArray+lengthTransactionArray)->buyTime) != -1){
            if(strcmp((transactionArray+lengthTransactionArray)->timeToCompare, date) == 0){
                if(max.unitPriceMedicine < (transactionArray+lengthTransactionArray)->unitPriceMedicine){
                    max = transactionArray[lengthTransactionArray];
                    if(lengthTransactionArray == 0){
                        min = transactionArray[lengthTransactionArray];
                    }
                }
                if(min.unitPriceMedicine > (transactionArray+lengthTransactionArray)->unitPriceMedicine){
                    min = transactionArray[lengthTransactionArray];
                }
                totalPrice += (transactionArray+lengthTransactionArray)->priceMedicineBuying;
                totalProducts += (transactionArray+lengthTransactionArray)->amountMedicineBuying;
                lengthTransactionArray++;
            }
        }
    }else{
        printf("\t -----------------------------------------------------------------------------------------------\n");
        printf("\t\t\t\t\tNo such file.\t\t\t\t\t\n");
        printf("\t -----------------------------------------------------------------------------------------------\n\n\n\n");
    }
    
    fclose(file); 
}


/* Functions */
// this function for sort the array medicines by alphabet
void sortByAlphabet(struct Medicine * medicineArray){
    struct Medicine help;

    for(int i = 0; i < lengthMedicineArray; i++){
        for(int j = i + 1; j < lengthMedicineArray; j++){
            if(strcmp((medicineArray+i)->name, medicineArray[j].name) > 0 ){
                help = medicineArray[i];
                medicineArray[i] = medicineArray[j];
                medicineArray[j] = help;
            }
        }
    }
}
// this function for sort the array medicines by price
void sortByPrice(struct Medicine * medicineArray){
    struct Medicine help;

    for(int i = 0; i < lengthMedicineArray; i++){
        for(int j = i + 1; j < lengthMedicineArray; j++){
            if((medicineArray+i)->price < medicineArray[j].price){
                help = medicineArray[i];
                medicineArray[i] = medicineArray[j];
                medicineArray[j] = help;
            }
        }
    }
}
// this function for uppercase a String, I use it for the name of medicine
void toUpperCase(char string[LENGTH_NAME]){
    for(int i = 0; i < strlen(string); i++){
        string[i] = toupper(string[i]);
    }
}
// this function for show single medicine, I use it for check is Exist & show it 
void showSingleMedicine(struct Medicine medicine){
    printf("\n\n\t -----------------------------------------------------------------------------------------------\n");
    printf("\t|\tMedicine ID\t|\tMedicine Name\t|\tMedicine Amount\t|\tMedicine Price\t|\n");
    printf("\t -----------------------------------------------------------------------------------------------\n");
    printf("\t|\t%d\t\t|\t%-10s\t|\t%d\t\t|\t%.2f   DH\t|\n", medicine.id, medicine.name, medicine.amount, medicine.price);
    printf("\t -----------------------------------------------------------------------------------------------\n\n\n\n");
}
// this function for show the list of all medicines
void showListMedicines(bool fromUpdate, struct Medicine * medicineArray){
    printf("\n\n\t -----------------------------------------------------------------------------------------------\n");
    printf("\t|\tMedicine ID\t|\tMedicine Name\t|\tMedicine Amount\t|\tMedicine Price\t|\n");
    printf("\t -----------------------------------------------------------------------------------------------\n");

    for(int i = 0; i < lengthMedicineArray; i++){
        if(fromUpdate){
            if((medicineArray+i)->amount < 3){
                printf("\t|\t%d\t\t|\t%-10s\t|\t%d\t\t|\t%.2f   DH\t|\n", (medicineArray+i)->id, (medicineArray+i)->name, (medicineArray+i)->amount, (medicineArray+i)->price);
            }
        }else{
            if((medicineArray+i)->amount != 0){
                printf("\t|\t%d\t\t|\t%-10s\t|\t%d\t\t|\t%.2f   DH\t|\n", (medicineArray+i)->id, (medicineArray+i)->name, (medicineArray+i)->amount, (medicineArray+i)->price);
            }
        }
    }

    printf("\t -----------------------------------------------------------------------------------------------\n\n\n\n");
}

int showMedicines(struct Medicine * medicineArray){
    int sortChoice;

    do{
        printf("\t[1] ===> Sort with Alphabet \n");
        printf("\t[2] ===> Sort with Price \n");
        printf("\t[0] ===> Return to Menu \n\n");
        printf("\tWould you like to sort with Alphabet or Price : ");
        scanf("%d", &sortChoice);
        system("cls");
        switch(sortChoice){
            case 0: return 0;
            case 1: sortByAlphabet(medicineArray); break;
            case 2: sortByPrice(medicineArray); break;
            default : printf("\n\t\t===> PLEASE ENTER VALID CHOICE!!! <===\n\n");
        }
    }while(sortChoice < 0 || sortChoice > 2);
 
    showListMedicines(false, medicineArray);
}
// this function for check a medicine is exist by id, return the index if exist or -1 if not
int isExistById(int id, struct Medicine * medicineArray){
    for(int i = 0; i < lengthMedicineArray; i++){
        if(id == (medicineArray+i)->id){
            showSingleMedicine(*(medicineArray+i));
            return i;
        }
    }

    return -1;
}
// this function for check a medicine is exist by name, return the index if exist or -1 if not
int isExistByName(char name[LENGTH_NAME], struct Medicine * medicineArray){
    toUpperCase(name);
    for(int i = 0; i < lengthMedicineArray; i++){
        if(strcmp(name, (medicineArray+i)->name) == 0){
            showSingleMedicine(*(medicineArray+i));
            return i;
        }
    }

    return -1;
}
// this function for add single or multiple medicines
int addMedicine(struct Medicine * medicineArray){
    int numbers;
    printf("\t[0] ===> Return to Menu \n\n");
    printf("\tHow many medicine do you want add : ");
    scanf("%d", &numbers);
    if(numbers <= 0){
        system("cls");
        return 0;
    }

    wrongId:

    for(int i = 0; i < numbers; i++){
        struct Medicine medicine;
        printf("\n\t--------------[ %d ]--------------\n", i + 1);
        printf("\tMedicine ID : ");
        scanf("%d", &medicine.id);

        if(isExistById(medicine.id, medicineArray) != -1){
            printf("\t -----------------------------------------------------------------------------------------------\n");
            printf("\t\t\t\t\tAlready Exist!!!.\t\t\t\t\t\n");
            printf("\t -----------------------------------------------------------------------------------------------\n\n\n\n");
            goto wrongId;
        }else{
            printf("\tMedicine Name : ");
            scanf("%s", &medicine.name);
            toUpperCase(medicine.name);
            printf("\tMedicine Amount : ");
            scanf("%d", &medicine.amount);
            printf("\tMedicine Price : ");
            scanf("%f", &medicine.price);
            medicine.price *= 1.15;

            medicineArray[lengthMedicineArray] = medicine;
            ++lengthMedicineArray;

            medicineArrayToFile(medicineArray);
            readMedicineArray(medicineArray);
        }
    }

    showListMedicines(false, medicineArray);
}

void searchMedicine(struct Medicine * medicineArray){
    int searchChoice;
    int index;
    char searchName[LENGTH_NAME];
    int searchId;

    do{
        printf("\t[1] ===> Search with Name \n");
        printf("\t[2] ===> Search with ID \n");
        printf("\t[0] ===> Return to Menu \n\n");
        printf("\tWould you like to search with NAME or ID : ");
        scanf("%d", &searchChoice);
        system("cls");
        switch(searchChoice){
            case 0: break;
            case 1: 
                printf("\tEnter the Name of medicine you want : ");
                scanf("%s", &searchName);
                index = isExistByName(searchName, medicineArray);
                break;
            case 2: 
                printf("\tEnter the ID of medicine you want : ");
                scanf("%d", &searchId);
                index = isExistById(searchId, medicineArray);
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
// this function for delete a medicine, i check if exist first & delete by the index
int deleteMedicine(struct Medicine * medicineArray){
    int deleteId, index;

    showListMedicines(false, medicineArray);

    printf("\t[0] ===> Return to Menu \n\n");
    printf("\tEnter the ID of medicine you want Delete : ");
    scanf("%d", &deleteId);

    if(deleteId == 0){
        return 0;
    }

    index = isExistById(deleteId, medicineArray);

    if(index != -1){
        for(int i = index; i < lengthMedicineArray; i++){
            medicineArray[i] = medicineArray[i + 1];
        }
        --lengthMedicineArray;

        medicineArrayToFile(medicineArray);
        readMedicineArray(medicineArray);

        showListMedicines(false, medicineArray);
    }else{
        printf("\t -----------------------------------------------------------------------------------------------\n");
        printf("\t\t\t\t\tSorry! We don't have this Medicine.\t\t\t\t\t\n");
        printf("\t -----------------------------------------------------------------------------------------------\n\n\n\n");
    }
}
// this function for update the medicines less than 3 in the amount
int updateMedicine(struct Medicine * medicineArray){
    int updateId, updateAmount, index;

    showListMedicines(true, medicineArray);

    printf("\t[0] ===> Return to Menu \n\n");
    printf("\tEnter the ID of medicine you want Update : ");
    scanf("%d", &updateId);

    if(updateId == 0){
        return 0;
    }

    index = isExistById(updateId, medicineArray);

    if(index != -1){
        printf("\tEnter the amount you want add : ");
        scanf("%d", &updateAmount);
        if(updateAmount > 0){
            medicineArray[index].amount += updateAmount;

            medicineArrayToFile(medicineArray);
            readMedicineArray(medicineArray);
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
// this function for buy a medicine & here save the transaction array
int buyMedicine(struct Transaction * transactionArray, struct Medicine * medicineArray){
    int buyId, buyAmount, index;
    char date[50];
    char dateForCompare[50];
    struct tm * buyTime;

    showListMedicines(false, medicineArray);

    printf("\t[0] ===> Return to Menu \n\n");
    printf("\tEnter the ID of medicine you want Buy : ");
    scanf("%d", &buyId);

    if(buyId == 0){
        return 0;
    }

    index = isExistById(buyId, medicineArray);

    if(index != -1){
        printf("\tEnter the amount you want Buy : ");
        scanf("%d", &buyAmount);
        if(buyAmount > medicineArray[index].amount || buyAmount < 1){
            printf("\t -----------------------------------------------------------------------------------------------\n");
            printf("\t\t\t\t\tSorry! We don't have that amount of this Medicine.\t\t\t\t\t\n");
            printf("\t -----------------------------------------------------------------------------------------------\n\n\n\n");
        }else{
            
            // increase the sum & total amount
            totalPrice += (medicineArray[index].price * buyAmount);
            totalProducts += buyAmount;
            // here decrease the amount after buying
            medicineArray[index].amount -= buyAmount;

            // Add to transaction Array
            struct Transaction transaction;
            transaction.idMedicine = medicineArray[index].id;
            strcpy(transaction.nameMedicine , medicineArray[index].name);
            transaction.amountMedicineBuying = buyAmount;
            transaction.unitPriceMedicine = medicineArray[index].price;
            transaction.priceMedicineBuying = (medicineArray[index].price * buyAmount);
            time_t  t = time(NULL);
            strcpy(date, ctime(&t));

            time(&t);
            buyTime = localtime(&t);
            strftime(dateForCompare, 80, "%x ", buyTime);

            strcpy(transaction.timeToCompare , dateForCompare);
            strcpy(transaction.buyTime , date);
            *(transactionArray+lengthTransactionArray) = transaction;

            lengthTransactionArray++;
            system("cls");

            // here sync with files
            medicineArrayToFile(medicineArray);
            transactionArrayToFile(transactionArray);
            readMedicineArray(medicineArray);
            readTransactionArray(transactionArray);
        }
    }else{
        printf("\t -----------------------------------------------------------------------------------------------\n");
        printf("\t\t\t\t\tSorry! We don't have this Medicine.\t\t\t\t\t\n");
        printf("\t -----------------------------------------------------------------------------------------------\n\n\n\n");
    }
}
// this function for show the statistics | total price | Moyen | max | min
void dashboard(struct Transaction * transactionArray, struct Medicine * medicineArray){
    float moyen = totalProducts != 0 ? (totalPrice / totalProducts) : 0;
    system("cls");
    printf("\n\t -------------------------------------------------------------------------------------------------------------------------------\n");
    printf("\t|\tSum Medicine Sold\t|\tMoyen Medicine Sold\t|\tMax Medicine Sold\t|\tMin Medicine Sold\t|\n");
    printf("\t -------------------------------------------------------------------------------------------------------------------------------\n");
    printf("\t|\t%.2f   DH\t\t|\t%.2f   DH\t\t|\t%.2f   DH\t\t|\t%.2f   DH\t\t|\n", totalPrice, moyen, max.unitPriceMedicine, min.unitPriceMedicine);
    printf("\t ---------------------------------------------------------------|\t%10s\t\t|\t%10s\t\t|\n", max.nameMedicine, min.nameMedicine);
    printf("\t                                                                 ---------------------------------------------------------------\n\n\n");

    printf("\n\t -------------------------------------------------------------------------------------------------------------------------------------------------------\n");
    printf("\t|\tN\t|\tID\t|\tMedicine Name\t|\tAmount\t|\tUnit Price\t|\tPrice Total\t|\tTransaction Date\t|\n");
    printf("\t -------------------------------------------------------------------------------------------------------------------------------------------------------\n");

    for(int i = 0; i < lengthTransactionArray; i++){
        printf("\t|\t%d\t|\t%d\t|\t%-10s\t|\t%d\t|\t%.2f   DH\t|\t%.2f   DH\t|  %s\n", i + 1, (transactionArray+i)->idMedicine, (transactionArray+i)->nameMedicine, (transactionArray+i)->amountMedicineBuying, (transactionArray+i)->unitPriceMedicine, (transactionArray+i)->priceMedicineBuying, (transactionArray+i)->buyTime);
    }

    printf("\t -------------------------------------------------------------------------------------------------------------------------------------------------------\n\n\n");
}

void menu(struct Transaction * transactionArray, struct Medicine * medicineArray){
    char choice[LENGTH_NAME];
    
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
        printf("\t -------------------------------------------------------\t\n\n");
        printf("\tPlease enter your choice : ");
        scanf("%s", &choice);
        system("cls");
        switch(atoi(choice)){
            case 0: break;
            case 1: showMedicines(medicineArray); break;
            case 2: addMedicine(medicineArray); break;
            case 3: updateMedicine(medicineArray); break;
            case 4: searchMedicine(medicineArray); break;
            case 5: deleteMedicine(medicineArray); break;
            case 6: buyMedicine(transactionArray, medicineArray); break;
            case 7: dashboard(transactionArray, medicineArray); break;
            default : printf("\n\t\t===> PLEASE ENTER VALID CHOICE!!! <===\n\n");
        }
    }while(atoi(choice) != 0);
}

void main(){
    struct Transaction transactionArray[100];
    struct Medicine medicineArray[100];
    printf("\n\n\n=========================> GESTION DE PHARMACIE <=========================\n\n\n\n");
    readMedicineArray(medicineArray);
    readTransactionArray(transactionArray);
    menu(transactionArray, medicineArray);
}
