#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define NAME_LEN 100
#define MAX_QUANTITY 100
#define MAX_TO_WRITE 5

/*David Hatcher
Project 7

This program will take the products from fruits_vegetables.txt and put them into an array of product structs
then sort those by the quantity value of each. After sorted it will create a file named top5.txt and
in that file write the top of products by quantity
*/
//this is the product struct with name price and quantity
struct product{
    char name[NAME_LEN + 1];
    double price;
    double quantity;
};

int readFile(struct product products[], char fileName[]);
int writeFile(struct product products[],char fileName[],int numToPrint);
int productsCompare(const void* a, const void* b);


/*main function initializes an array of products, then creates strings of the file name
to read and the file name to write, after that it calls the readFile function, then
sortProducts function, the writeFile function
*/
int main(){
    struct product products[MAX_QUANTITY];
    char fileName[30] = "fruits_vegetables.txt";
    char fileWriteName[30] = "top5.txt";
    int numValues = readFile(products,fileName);
    qsort(products,numValues,sizeof(struct product),productsCompare);
    writeFile(products,fileWriteName,MAX_TO_WRITE);
    return 0;
}

/*readFile function takes an array of products and a file name string
it willthen read from that file and creates a product of each line in that
file. It then returns the number of products it found
*/
int readFile(struct product products[], char fileName[]){
    int i = 0;
    FILE *fp = fopen(fileName,"r");
    if(fp ==  NULL){
        printf("Error reading %s", fileName);
        return 0;
    }
    while(!feof(fp) && !ferror(fp) && i < MAX_QUANTITY){
        fscanf(fp,"%s %lf %lf",products[i].name,&products[i].price,&products[i].quantity);
        i++;
    }
    return i-1;
}

/*writeFile function takes an array of products, a file name string, and an integer
which is the max number of values to write to the file. It creates a file with the same
name as the file name string, then it will write the first 5 products in the products array
*/
int writeFile(struct product products[],char fileName[],int numToPrint){
    FILE *fp = fopen(fileName,"w");
    int i;
    if(fp == NULL){
        printf("Error writing %s", fileName);
        return 0;
    }
    for(i = 0; i < numToPrint; i++){
        fprintf(fp,"%s\t\t\t%.2lf\t%.2lf\n",products[i].name,products[i].price,products[i].quantity);
    }
    return 1;
}
/*function sortProducts takes an array of products, an integer 0 first, and an integer
which is the max quantity of items in the products array. it then takes the value of 
products[n] and assigns it to currentMax, then it will look through the array and find
the product with the highest quantity and assign it to currentMax, once it has checked
all slots from products[n] -> products[maxQuantity] it swaps the product at index n
with the product currentMax and as long as n is not <= MAX_QUANTITY it will recursively call
itself again. Modification of selection sort algorithm to order array from largest to smallest
*/

int productsCompare(const void* a, const void* b){
    if(((struct product *)a)->quantity > ((struct product *)b)->quantity){
        return -1;
    }else if(((struct product *)a)->quantity == ((struct product *)b)->quantity){
        return 0;
    }else{
        return 1;
    }
}
