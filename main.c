#include <stdio.h>
#include <stdlib.h>

long long mergeComp = 0;   
long long quickComp = 0;   


void merge(int a[], int l, int mid, int r)
{
    int n1 = mid - l + 1, n2 = r - mid;
    int *L = (int *)malloc(n1 * sizeof(int));
    int *R = (int *)malloc(n2 * sizeof(int));
    int i, j, k;

    for (i = 0; i < n1; i++) L[i] = a[l + i];
    for (j = 0; j < n2; j++) R[j] = a[mid + 1 + j];

    i = 0; j = 0; k = l;
    while (i < n1 && j < n2)
    {
        mergeComp++;        
        if (L[i] <= R[j]) a[k++] = L[i++];
        else              a[k++] = R[j++];
    }
    while (i < n1) a[k++] = L[i++];
    while (j < n2) a[k++] = R[j++];

    free(L);
    free(R);
}

void mergeSort(int a[], int l, int r)
{
    if (l < r)
    {
        int mid = l + (r - l) / 2;
        mergeSort(a, l, mid);
        mergeSort(a, mid + 1, r);
        merge(a, l, mid, r);
    }
}

int partition(int a[], int low, int high)
{
    int pivot = a[high];
    int i = low - 1, j, t;

    for (j = low; j < high; j++)
    {
        quickComp++;                    
        if (a[j] <= pivot)
        {
            i++;
            t = a[i]; a[i] = a[j]; a[j] = t;
        }
    }
    t = a[i + 1]; a[i + 1] = a[high]; a[high] = t;
    return i + 1;
}

void quickSort(int a[], int low, int high)
{
    if (low < high)
    {
        int p = partition(a, low, high);
        quickSort(a, low, p - 1);
        quickSort(a, p + 1, high);
    }
}

void mergeBatch(int a[], int n, int b[], int m, int res[])
{
    int i = 0, j = 0, k = 0;
    while (i < n && j < m)
    {
        if (a[i] <= b[j]) res[k++] = a[i++];
        else              res[k++] = b[j++];
    }
    while (i < n) res[k++] = a[i++];
    while (j < m) res[k++] = b[j++];
}

void printArray(const char *label, int a[], int n)
{
    int i;
    printf("%s", label);
    for (i = 0; i < n; i++) printf("%d%c", a[i], i == n - 1 ? '\n' : ' ');
}

int main()
{
    FILE *fp = fopen("input.txt", "r");
    int n, m, i;

    if (fp == NULL) { printf("Cannot open input.txt\n"); return 1; }

    fscanf(fp, "%d %d", &n, &m);

    int *orig  = (int *)malloc(n * sizeof(int));
    int *arrM  = (int *)malloc(n * sizeof(int));
    int *arrQ  = (int *)malloc(n * sizeof(int));
    int *batch = (int *)malloc(m * sizeof(int));
    int *res   = (int *)malloc((n + m) * sizeof(int));

    for (i = 0; i < n; i++) { fscanf(fp, "%d", &orig[i]); arrM[i] = arrQ[i] = orig[i]; }
    for (i = 0; i < m; i++) fscanf(fp, "%d", &batch[i]);
    fclose(fp);

    mergeSort(arrM, 0, n - 1);
    quickSort(arrQ, 0, n - 1);

    printArray("Merge Sort: ", arrM, n);
    printArray("Quick Sort: ", arrQ, n);
    printf("Merge Comparisons: %lld\n", mergeComp);
    printf("Quick Comparisons: %lld\n", quickComp);

    mergeBatch(arrM, n, batch, m, res);
    printArray("Updated Array: ", res, n + m);

    free(orig); free(arrM); free(arrQ); free(batch); free(res);
    return 0;
}