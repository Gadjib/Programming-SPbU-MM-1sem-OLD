#include <stdio.h>

void insertSort(int array[], int len)
{
    int element, location;
    for (int i = 1; i < len; i++)
    {
        element = array[i];
        location = i - 1;
        while (location >= 0 && array[location] > element)
        {
            array[location + 1] = array[location];
            location = location - 1;
        }
        array[location + 1] = element;
    }
}

void printIntArray(int array[], int len)
{
    if (len == 0)
    {
        printf("[]");
    }
    else 
    {
        printf("[");
        for (int i = 0; i < len - 1; i++)
        {
            printf("%d, ", array[i]);
        }
        printf("%d]\n", array[len-1]);
    }
}

int main()
{
    int array[] = {4,1,8,5};
    insertSort(array, 4);
    printIntArray(array, 4);
}