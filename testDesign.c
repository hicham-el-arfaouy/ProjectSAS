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

void hy(struct Medicine * tab){
    printf("%d", (tab + 0)->id);
    scanf("%d", &(tab + 0)->id);
    printf("%d", (tab + 0)->id);
}


void main(){
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
    hy(medicineArray);
}   