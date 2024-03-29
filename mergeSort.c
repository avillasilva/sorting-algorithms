#include <stdio.h>
#include <stdlib.h>

// A utilitarian function to print the elements of an array.
void printArray(int arr[], int n)
{
    int i;
    for(i = 0; i < n; i++)
        printf("%d ", arr[i]);
    
    printf("\n");
}

// The merge function to merge the halves.
void merge(int arr[], int left, int middle, int right)
{
    int i, j, k;
    int nl = middle - left + 1;
    int nr = right - middle;

    int l[nl];
    int r[nr];

    for (i = 0, j = left; j < middle + 1; i++, j++)
        l[i] = arr[j];

    for (i = 0, j = middle + 1; j <= right; i++, j++)
        r[i] = arr[j];

    for (i = 0, j = 0, k = left; i < nl && j < nr; k++)
    {
        if (l[i] <= r[j])
        {
            arr[k] = l[i];
            i++;
        }

        else
        {
            arr[k] = r[j];
            j++;
        }
    }

    while (i < nl)
    {
        arr[k] = l[i];
        i++;
        k++;
    }

    while (j < nr)
    {
        arr[k] = r[j];
        j++;
        k++;
    }
}

// The merge sort algorithm.
void mergeSort(int arr[], int left, int right)
{
    if (right > left)
    {
        int middle = (right + left) / 2;
        mergeSort(arr, left, middle);
        mergeSort(arr, middle + 1, right);
        merge(arr, left, middle, right);
    }
}

// A utility function for applying the quick sort algorithm
// in a specified input file.
// inPath -> Path to the input file.
// outPath -> path to output file.
void applyMergeSort(char inPath[], char outPath[])
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

    mergeSort(arr, 0, inputArrayLenght - 1);

    for(i = 0; i < inputArrayLenght; i++)
    {
        fprintf(op, "%d\n", arr[i]);
    }

    fclose(ip);
    fclose(op);
}

int main(int argc, int *argv[])
{
    applyMergeSort((char*) argv[1], (char*) argv[2]);

    return 0;
}