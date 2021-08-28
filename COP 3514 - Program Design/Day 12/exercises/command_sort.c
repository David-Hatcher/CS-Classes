#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void selection_sort(int a[], int n);
int find_largest(int a[], int n);
void convert_array(int ints[], char *strs[], int n);

int main(int argc, char *argv[]){
    int arr[argc];
    int i;
    if(argc > 1){
        convert_array(arr,argv,argc);
        selection_sort(arr,argc-1);
        for(i = 0; i < argc - 1; i++){
            printf("%d ", arr[i]);
        }
    }else{
        printf("usage: a.exe followed by numbers for sorting\n");
    }
    return 0;
}

void convert_array(int ints[], char *strs[], int n){
    int i;
    for(i = 1;i < n; i++){
        ints[i-1] = atoi(strs[i]);
    }
}
void selection_sort(int a[], int n){
    int largest = 0, temp;
    if(n == 1){
        return;
    }
    
    largest = find_largest(a,n);

    if (largest < n - 1){
        temp = a[n-1];
        a[n-1] = a[largest];
        a[largest] = temp;
    }
    selection_sort(a,n-1);
}
int find_largest(int a[], int n){
    int largest_index = 0;
    int i;
    for(i = 1; i < n; i++){
        if(a[largest_index] < a[i])
        largest_index = i;
    }
    return largest_index;
}

