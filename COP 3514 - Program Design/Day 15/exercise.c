#include <stdio.h>
#include <string.h>

struct color{
    int red;
    int blue;
    int green;
};

struct color makeColor(int red, int blue, int green);
struct color brighter(struct color c);

int main(){

    struct color magenta = {255,0,255};
    printf("Magenta   -   Red : %d, Blue : %d, Green: %d\n",magenta.red,magenta.blue,magenta.green);

    struct color color2;
    printf("Enter 3 numbers to represent your color, with spaces between (ie Red Blue Green):\n");
    scanf("%d %d %d",&color2.red,&color2.blue,&color2.green);
    printf("Your Color   -   Red : %d, Blue : %d, Green: %d\n",color2.red,color2.blue,color2.green);

    struct color gold = makeColor(255,215,0);
    printf("Gold   -   Red : %d, Blue : %d, Green: %d\n",gold.red,gold.blue,gold.green);

    struct color brighterGold = brighter(gold);
    printf("Brighter Gold   -   Red : %d, Blue : %d, Green: %d\n",brighterGold.red,brighterGold.blue,brighterGold.green);

    return 0;
}

struct color makeColor(int red, int blue, int green){
    int colors[3] ={red,blue,green}, i;
    for(i = 0; i < 3; i++){
        colors[i] = colors[i] > 255 ? 255 : colors[i];
        colors[i] = colors[i] < 0 ? 0 : colors[i];
    }
    struct color newColor = {colors[0],colors[1],colors[2]};
    return newColor;
}

struct color brighter(struct color c){
    int colors[3] = {c.red,c.blue,c.green},i;
    double brightVal = 0.7;
    for(i = 0; i < 3; i++){
        colors[i] = colors[1] == 0 ? 3 : colors[i];
        colors[i] = colors[i]/brightVal;
        colors[i] = colors[i] > 255 ? 255 : colors[i];
    }
    struct color brighterColor = {colors[0],colors[1],colors[2]};
    return brighterColor;
}
