#include <stdio.h>
#include <string.h>
#define NUM_CHARS 30

struct magformer{
    char shape[NUM_CHARS + 1];
    char color[NUM_CHARS +1];
    int quantity;
};

int magformerCompare(struct magformer m1, struct magformer m2);

int main(){
    //Structs
    //like and object but only with data no methods
    //

    struct magformer m1 ={"square","pink",5};
    printf("%s %s %d\n",m1.shape,m1.color,m1.quantity);

    struct magformer m2;
    printf("Enter Quanity ");
    scanf("%d",&m2.quantity);
    printf("Enter Shape ");
    scanf("%s",m2.shape);
    strcpy(m2.color,"green");

    printf("%s %s %d\n",m2.shape,m2.color,m2.quantity);
    //operations on structures
    //part1 = part2
    //copies all data from part2 onto part1
    //comparison not defined
    //must use comparsion operators for numeric data
    //and strcmp for strings, in new method

    int sameBool = magformerCompare(m1,m2);

    char string[] = (sameBool == 1) ? "They're the same" : "They're not the same!"; 

    m1 = m2;

    //printf("\nafter copying, m1: %s %s %d\n",m1.shape,m1.color,m1.quantity);
    if(magformerCompare(m1,m2) == 1){
        printf("They're the same magformer!");
    }else{
        printf("They're not the same magformer");
    }

}

int magformerCompare(struct magformer m1, struct magformer m2){
    if(strcmp(m1.color,m2.color) == 0 && strcmp(m1.shape,m2.shape) == 0){
        return 1;
    }
    return 0;
}