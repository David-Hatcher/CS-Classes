#include <stdio.h>

void selection_sort(int a[], int n);
int lineCounter(char const *fileName);
void arrayBuilder(char const *fileName, int *a);
void fileWriter(char const *fileName, int *a, int n);

int main()
{
    char *fileName = "numbers.txt";
    char *fileNameSorted = "sorted_numbers.txt";
    int lineCount = lineCounter(fileName);
    int numbers[lineCount];
    arrayBuilder(fileName,numbers);
    printf("%d Numbers total\n",lineCount);
    selection_sort(numbers,lineCount);
    fileWriter(fileNameSorted,numbers,lineCount);


    return 0;
}
int lineCounter(char const *fileName){
    int number, lineCount = 0;
    FILE *fp = fopen(fileName,"r");
    if(fp == NULL){
        printf("Error reading file");
        return 1;
    }
    while(!feof(fp) && !ferror(fp)){
        if(fscanf(fp,"%d",&number) == 1){
            lineCount++;
        }
    }
    return lineCount;
}

void arrayBuilder(char const *fileName, int *a){
    int *p = a;
    FILE *fp = fopen(fileName,"r");
    if(fp == NULL){
        printf("Error reading file");
        return;
    }
    while(!feof(fp) && !ferror(fp)){
        fscanf(fp,"%d",p++);
    }
}
void fileWriter(char const *fileName, int *a,int n){
    int *p;
    FILE *fp = fopen(fileName,"w");
    if(fp == NULL){
        printf("Error reading file");
        return;
    }
    for(p = a;p < a + n; p++){
        fprintf(fp,"%d\n",*p);
    }    
}
void selection_sort(int a[], int n)
{
  int i, largest = 0, temp;

  if (n == 1)
    return;

  for (i = 1; i < n; i++)
    if (a[i] > a[largest])
      largest = i;

  if (largest < n - 1) {
    temp = a[n-1];
    a[n-1] = a[largest];
    a[largest] = temp;
  }

  selection_sort(a, n - 1);
}