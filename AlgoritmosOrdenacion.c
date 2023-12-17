#include <stdio.h>

void BubbleSort(int array[], int arraySize);
void SelectionSort(int array[], int arraySize);
void InsertionSort(int array[], int arraySize);

int BusquedaBinaria(int array[], int numeroABuscar, int inicio, int final);

void VisualizarArray(int array[], int arraySize);

int main()
{
    int arrayDesordenado[15] = {12, 5, -2, 10, 1, 0, 13, 14, 27, 90, 19, 34, 56, -10, 7};
    int numeroBusqueda;
    int posicion;

    // Insertionsort
    printf("Ordenación por Insertionsort: \n\n");
    InsertionSort(arrayDesordenado, 15);
    VisualizarArray(arrayDesordenado, 15);
    // Selectionsort
    printf("\n\nOrdenación por Selectionsort: \n\n");
    SelectionSort(arrayDesordenado, 15);
    VisualizarArray(arrayDesordenado, 15);
    // BubbleSort
    printf("\n\nOrdenación por Bubblesort: \n\n");
    BubbleSort(arrayDesordenado, 15);
    VisualizarArray(arrayDesordenado, 15);

    // Se pregunta el número a buscar
    printf("\n\nIntroduzca el número a buscar: ");
    scanf("%d", &numeroBusqueda);
    posicion = BusquedaBinaria(arrayDesordenado, numeroBusqueda, 0, 14);
    if (posicion == -1)
    {
        printf("El elemento no se encuentra en el array.");
    }
    else
    {
        printf("El elemento %d se encuentra en la posicion %d", numeroBusqueda, posicion);
    }
    scanf("%d");
    return 0;
}

int BusquedaBinaria(int array[], int numeroABuscar, int inicio, int final)
{
    int posicion = (inicio + final) / 2;

    // Casos base (Cuando se sale de la recursividad)
    if (array[posicion] == numeroABuscar)
    {
        return posicion + 1;
    }
    if (inicio > final)
    {
        return -1;
    }
    // Casos Generales (Cuando se aplica la recursividad)
    if (numeroABuscar > array[posicion])
    {
        // Si es mayor, busca del centro del array hacia la derecha
        return BusquedaBinaria(array, numeroABuscar, posicion + 1, final);
    }
    else if (numeroABuscar < array[posicion])
    {
        // Si es menor, busca desde el centro del array hacia la izquierda
        return BusquedaBinaria(array, numeroABuscar, inicio, posicion - 1);
    }
}

void BubbleSort(int array[], int arraySize)
{
    int aux;
    for (int i = 0; i < arraySize; i++)
    {
        for (int j = 0; j < arraySize - i - 1; j++)
        {
            if (array[j] > array[j + 1])
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
            if (array[j] < array[min])
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
            if (array[i] < array[j])
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