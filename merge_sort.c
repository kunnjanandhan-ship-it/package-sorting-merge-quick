#include <stdio.h>

struct Package
{
    int id;
    int weight;
    int position;
};

void merge(struct Package a[], int lb, int mid, int ub)
{
    struct Package temp[20];

    int i = lb;
    int j = mid + 1;
    int k = lb;

    while (i <= mid && j <= ub)
    {
        if (a[i].weight <= a[j].weight)
        {
            temp[k] = a[i];
            i++;
        }
        else
        {
            temp[k] = a[j];
            j++;
        }

        k++;
    }

    while (i <= mid)
    {
        temp[k] = a[i];
        i++;
        k++;
    }

    while (j <= ub)
    {
        temp[k] = a[j];
        j++;
        k++;
    }

    for (i = lb; i <= ub; i++)
    {
        a[i] = temp[i];
    }
}

void mergeSort(struct Package a[], int lb, int ub)
{
    if (lb < ub)
    {
        int mid = (lb + ub) / 2;

        mergeSort(a, lb, mid);
        mergeSort(a, mid + 1, ub);

        merge(a, lb, mid, ub);
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

    mergeSort(a, 0, n - 1);

    printf("\nAfter Merge Sort:\n");
    display(a, n);

    return 0;
}
