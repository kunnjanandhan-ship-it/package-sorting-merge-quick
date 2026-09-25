#include <stdio.h>

struct Package
{
    int id;
    int weight;
    int position;
};

int partition(struct Package a[], int low, int high)
{
    int pivot = a[high].weight;
    int i = low - 1;
    int j;

    struct Package temp;

    for (j = low; j < high; j++)
    {
        if (a[j].weight <= pivot)
        {
            i++;

            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }

    temp = a[i + 1];
    a[i + 1] = a[high];
    a[high] = temp;

    return i + 1;
}

void quickSort(struct Package a[], int low, int high)
{
    if (low < high)
    {
        int p = partition(a, low, high);

        quickSort(a, low, p - 1);
        quickSort(a, p + 1, high);
    }
}

void display(struct Package a[], int n)
{
    int i;

    for (i = 0; i < n; i++)
    {
        printf("P%d(%d) ", a[i].id, a[i].weight);
    }

    printf("\n");
}

int main()
{
    struct Package a[8] =
    {
        {1, 20, 1},
        {2, 15, 2},
        {3, 20, 3},
        {4, 10, 4},
        {5, 15, 5},
        {6, 20, 6},
        {7, 25, 7},
        {8, 10, 8}
    };

    int n = 8;

    printf("Original packages:\n");
    display(a, n);

    quickSort(a, 0, n - 1);

    printf("\nAfter Quick Sort:\n");
    display(a, n);

    return 0;
}
