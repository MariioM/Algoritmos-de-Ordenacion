#include <stdio.h>

void BubbleSort(int array[], int arraySize);
void SelectionSort(int array[], int arraySize);
void InsertionSort(int array[], int arraySize);

void VisualizarArray(int array[], int arraySize);

int main()
{
    int arrayDesordenado[15] = {12, 5, -2, 10, 1, 0, 13, 14, 27, 90, 19, 34, 56, -10};

    // BubbleSort
    printf("Ordenación por Bubblesort: \n\n");
    BubbleSort(arrayDesordenado, 15);
    VisualizarArray(arrayDesordenado, 15);
    // Selectionsort
    printf("\n\nOrdenación por Selectionsort: \n\n");
    SelectionSort(arrayDesordenado, 15);
    VisualizarArray(arrayDesordenado, 15);
    // Insetionsort
    printf("\n\nOrdenación por Insertionsort: \n\n");
    InsertionSort(arrayDesordenado, 15);
    VisualizarArray(arrayDesordenado, 15);
    scanf("%d");
}

void BubbleSort(int array[], int arraySize)
{
    int aux;
    for (int i = 0; i < arraySize; i++)
    {
        for (int j = 0; j < arraySize - i - 1; j++)
        {
            if (array[j] < array[j + 1])
            {
                aux = array[j];
                array[j] = array[j + 1];
                array[j + 1] = aux;
            }
        }
    }
}

void SelectionSort(int array[], int arraySize)
{
    int min, aux;
    for (int i = 0; i < arraySize; i++)
    {
        min = i;
        for (int j = i + 1; j < arraySize; j++)
        {
            if (array[j] > array[min])
            {
                min = j;
            }
        }
        aux = array[i];
        array[i] = array[min];
        array[min] = aux;
    }
}

void InsertionSort(int array[], int arraySize)
{
    int aux;
    for (int i = 1; i < arraySize; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (array[i] > array[j])
            {
                aux = array[i];
                array[i] = array[j];
                array[j] = aux;
            }
        }
    }
}

void VisualizarArray(int array[], int arraySize)
{
    for (int i = 0; i < arraySize; i++)
    {
        if (i == 0)
        {
            printf("{%d", array[i]);
        }
        else if (i == arraySize - 1)
        {
            printf(", %d}", array[i]);
        }
        else
        {
            printf(", %d", array[i]);
        }
    }
}