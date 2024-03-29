#include <stdio.h>
#include <stdlib.h>

// An utilitarian function to swap the values.
void swap(int* a, int* b)
{
    int aux = *a;
    *a = *b;
    *b = aux;
}

// It's make the partition necessary to the algorithm.
int partition(int arr[], int l, int r)
{
    int pivot = arr[r];
    int j, i = l - 1;

    for (j = l; j <= r - 1; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i + 1], &arr[r]);
    return i + 1;
}

// The quickSort algorithm.
void quickSort(int arr[], int l, int r)
{
    if (l < r)
    {
        int pivot = partition(arr, l, r);

        quickSort(arr, l, pivot - 1);
        quickSort(arr, pivot + 1, r);
    }
}

// A utility function for applying the quick sort algorithm
// in a specified input file.
// inPath -> Path to the input file.
// outPath -> path to output file.
void applyQuickSort(char inPath[], char outPath[])
{
    FILE *ip, *op;

    if((ip = fopen(inPath, "r")) == NULL)
    {
        printf("Cannot open input file: %s\n", inPath);
        exit(0);
    }       

    if((op = fopen(outPath, "w")) == NULL)
    {
        printf("Cannot open output file: %s\n", outPath);
        exit(0);
    }

    int inputArrayLenght;
    fscanf(ip, "%d", &inputArrayLenght);

    int arr[inputArrayLenght], i;

    for(i = 0; i < inputArrayLenght; i++)
    {
        fscanf(ip, "%d", &arr[i]);
    }

    quickSort(arr, 0, inputArrayLenght - 1);

    for(i = 0; i < inputArrayLenght; i++)
    {
        fprintf(op, "%d\n", arr[i]);
    }

    fclose(ip);
    fclose(op);
}

int main(int argc, int *argv[])
{
    applyQuickSort((char*) argv[1], (char*) argv[2]);

    return 0;
}