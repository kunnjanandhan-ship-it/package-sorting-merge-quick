#include <stdio.h>

struct Package
{
    int id;
    int weight;
    int position;
};

/* Display packages */
void display(struct Package a[], int n)
{
    int i;

    for (i = 0; i < n; i++)
    {
        printf("P%d(%d) ", a[i].id, a[i].weight);
    }

    printf("\n");
}

/* ================= MERGE SORT ================= */

void merge(struct Package a[], int lb, int mid, int ub, int *count)
{
    struct Package temp[20];

    int i = lb;
    int j = mid + 1;
    int k = lb;

    while (i <= mid && j <= ub)
    {
        (*count)++;

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

void mergeSort(struct Package a[], int lb, int ub, int *count)
{
    int mid;

    if (lb < ub)
    {
        mid = (lb + ub) / 2;

        mergeSort(a, lb, mid, count);
        mergeSort(a, mid + 1, ub, count);

        merge(a, lb, mid, ub, count);
    }
}

/* ================= QUICK SORT ================= */

int partition(struct Package a[], int lb, int ub, int *count)
{
    int pivot = a[ub].weight;
    int i = lb - 1;
    int j;

    struct Package temp;

    for (j = lb; j < ub; j++)
    {
        (*count)++;

        if (a[j].weight <= pivot)
        {
            i++;

            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }

    temp = a[i + 1];
    a[i + 1] = a[ub];
    a[ub] = temp;

    return i + 1;
}

void quickSort(struct Package a[], int lb, int ub, int *count)
{
    int p;

    if (lb < ub)
    {
        p = partition(a, lb, ub, count);

        quickSort(a, lb, p - 1, count);
        quickSort(a, p + 1, ub, count);
    }
}

/* ============== STABLE QUICK SORT ============== */

int comesBefore(struct Package a, struct Package b, int *count)
{
    (*count)++;

    if (a.weight < b.weight)
    {
        return 1;
    }

    if (a.weight == b.weight)
    {
        (*count)++;

        if (a.position < b.position)
        {
            return 1;
        }
    }

    return 0;
}

int stablePartition(struct Package a[], int lb, int ub, int *count)
{
    struct Package pivot = a[ub];
    struct Package temp;

    int i = lb - 1;
    int j;

    for (j = lb; j < ub; j++)
    {
        if (comesBefore(a[j], pivot, count))
        {
            i++;

            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }

    temp = a[i + 1];
    a[i + 1] = a[ub];
    a[ub] = temp;

    return i + 1;
}

void stableQuickSort(struct Package a[], int lb, int ub, int *count)
{
    int p;

    if (lb < ub)
    {
        p = stablePartition(a, lb, ub, count);

        stableQuickSort(a, lb, p - 1, count);
        stableQuickSort(a, p + 1, ub, count);
    }
}

/* ================= MAIN ================= */

int main()
{
    struct Package original[8] =
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

    struct Package a[8];

    int i;
    int mergeCount = 0;
    int quickCount = 0;
    int stableQuickCount = 0;

    /* Original packages */

    printf("Original Packages:\n");
    display(original, 8);

    /* -------- Merge Sort -------- */

    for (i = 0; i < 8; i++)
    {
        a[i] = original[i];
    }

    mergeSort(a, 0, 7, &mergeCount);

    printf("\nAfter Merge Sort:\n");
    display(a, 8);

    printf("Merge Sort Comparisons = %d\n", mergeCount);

    /* -------- Quick Sort -------- */

    for (i = 0; i < 8; i++)
    {
        a[i] = original[i];
    }

    quickSort(a, 0, 7, &quickCount);

    printf("\nAfter Quick Sort:\n");
    display(a, 8);

    printf("Quick Sort Comparisons = %d\n", quickCount);

    /* -------- Stable Quick Sort -------- */

    for (i = 0; i < 8; i++)
    {
        a[i] = original[i];
    }

    stableQuickSort(a, 0, 7, &stableQuickCount);

    printf("\nAfter Stable Quick Sort:\n");
    display(a, 8);

    printf("Stable Quick Sort Comparisons = %d\n",
           stableQuickCount);

    return 0;
}
