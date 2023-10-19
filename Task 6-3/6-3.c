#include <stdio.h>

int min(int a, int b)
{
    if (a < b)
    {
        return a;
    }
    else
    {
        return b;
    }
}

void printIntArray(int array[], int len)
{
    if (len == 0)
    {
        printf("{}\n");
    }
    else 
    {
        printf("{");
        for (int i = 0; i < len - 1; i++)
        {
            printf("%d, ", array[i]);
        }
        printf("%d}\n", array[len - 1]);
    }
}

void merge(int array[], int left, int mid, int right)
{
    int i1 = 0;
    int i2 = 0;
    
    int result[right-left];

    while (left + i1 < mid && mid + i2 < right)
    {
        if (array[left + i1] < array[mid + i2])
        {
            result[i1 + i2] = array[left + i1];
            i1++;
        } 
        else
        {
            result[i1 + i2] = array[mid + i2];
            i2++;
        }
    }

    while (left + i1 < mid)
    {
        result[i1 + i2] = array[left + i1];
        i1++;
    }

    while (mid + i2 < right)
    {
        result[i1 + i2] = array[mid + i2];
        i2++;
    }

    for (int i = 0; i < i1 + i2; i++)
    {
        array[left + i] = result[i];
    }
}

void mergeSort(int array[], int len)
{
    for (int i = 1; i <= len; i = i * 2)
    {
        for (int j = 0; j <= len - 1; j = j + (2 * i))
        {
            merge(array, j, j + 1, min((j + 2 * i), len));
        }
    }
}

void mergeSortRec(int array[], int left, int right)
{
    if (left + 1 >= right)
    {
        return;
    }
    
    int mid;

    mid = (left + right) / 2;
    mergeSortRec(array, left, mid);
    //printIntArray(array, 4);

    mergeSortRec(array, mid, right);
    //printIntArray(array, 4);
    merge(array, left, mid, right);
}

int main()
{
    int array[] = {8, 4, 1, 3, 45, 2};

    mergeSortRec(array, 0, 6);

    printIntArray(array, 6);
}