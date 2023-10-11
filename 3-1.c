#include <stdio.h>

void swapp(int* a, int* b){
	*a = *a ^ *b;
	*b = *a ^ *b;
	*a = *a ^ *b;
}

// Реализация сортировки вставками
void insertSort(int array[], int len)
{
    if (len == 0)
    {
        return;
    }
    
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

    return index;
}

// Сама функция qSort
void quickSort(int array[], int start, int end)
{
    if (start >= end)
    {
        return;
    }

    int pivot = partition(array, start, end);
    quickSort(array, start, pivot - 1);
    quickSort(array, pivot + 1, end);
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

void mainSort(int array[], int len)
{
    if (len < 10)
    {
        insertSort(array, len);
    }
    else
    {
        quickSort(array, 0, len - 1);
    }
}

int main()
{
    int array1[] = {4,1,8,5};
    int array2[] = {0};
    int array3[] = {34, 2452, 143, 34, 134, 566, 3, 100, 1234, 1234, 34, 565, 544};

    mainSort(array1, 4);
    mainSort(array2, 1);
    mainSort(array3, 13);

    printIntArray(array1, 4);
    printIntArray(array2, 1);
    printIntArray(array3, 13);
}