#include <stdio.h>

int search(int a[], int n, int value);
int delete (int a[], int n, int value);

int main()
{
    int n, i, deleteVal;
    printf("Enter the length of the array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements of the array: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("Enter the value for deleting: ");
    scanf("%d", &deleteVal);

    int newSize = delete (arr, n, deleteVal);

    printf("Output array: ");
    for (i = 0; i < newSize; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}

int search(int a[], int n, int value)
{
    int i;
    for (i = 0; i < n; i++)
    {
        if (a[i] == value)
        {
            return i;
        }
    }
    return -1;
}

int delete (int a[], int n, int value)
{
    int currentLocation = search(a, n, value);
    if (currentLocation == -1)
    {
        return n;
    }
    else
    {
        int i;
        for (i = currentLocation; i < n-1; i++)
        {
            a[i] = a[i + 1];
        }
        n = delete (a, n-1, value);
        return n;
    }
}
