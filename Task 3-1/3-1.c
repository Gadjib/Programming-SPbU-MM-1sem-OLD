#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

void swapp(int* a, int* b)
{
	*a = *a ^ *b;
	*b = *a ^ *b;
	*a = *a ^ *b;
}

// Функция, которая печатает интовый массив
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

// Реализация сортировки вставками
void insertSort(int array[], int start, int end)
{
    if (start >= end)
    {
        return;
    }
    
    int element, location;

    for (int i = start; i < end; i++)
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

// Функция, разделяющая массив относительно точки опоры
int partition(int array[], int start, int end)
{
    int pivot = array[end];
    int index = start;

    for (int i = start; i < end; i++)
    {   
        if (array[i] <= pivot)
        {
            swapp(&array[i], &array[index]);
            index++;
        }
    }
    
    swapp (&array[index], &array[end]);
    printIntArray(array, (end - start));
    return index;
}

// Сама функция qSort
void quickSort(int array[], int start, int end)
{
    if (start >= end)
    {
        return;
    }

    if (end - start < 10)
    {
        insertSort(array, start, end);
        printIntArray(array, end - start);
    }
    else
    {
        int pivot = partition(array, start, end);
        quickSort(array, start, pivot - 1);
        quickSort(array, pivot + 1, end);
        printIntArray(array, end - start);
    }
}



bool arraysEqual(int array1[], int array2[], int len)
{
    bool result = true;

    for (int i = 0; i < len; i++)
    {
        if (! (array1[i] == array2 [i]))
        {
            result = false;
        }
    }

    return result;
}

int main()
{
    int array1[] = {4, 1, 8, 5};
    int array1Sorted[] = {1, 4, 5, 6};
    
    int array2[] = {0};
    int array2Sorted[] = {0};
    
    int array3[] = {34, 2452, 143, 34, 134, 566, 3, 100, 1234, 1234, 34, 565, 544};
    //int array3Sorted[] = {3, }

    quickSort(array1, 0, 4);
    quickSort(array2, 0, 1);
    quickSort(array3, 0, 13);
    
    printIntArray(array1, 4);
    printIntArray(array2, 1);
    printIntArray(array3, 13);

    //if (!(arraysEqual(array1, {1, 4, 5, 8}, 4) && )
}