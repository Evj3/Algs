#include <stdio.h>


void swap(int *a, int *b){
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}

int partition (int a[], int l, int r){

    //int mid = a[l + (r - l)/2];
    int mid = a[(l + r) / 2];
    //int mid = a[l];
    int i = l;
    int j = r;
    while (i <= j){
        while (a[i] < mid){
            ++i;
        }
        while (a[j] > mid){
            --j;
        }
        if (i <= j){
            swap(&a[i], &a[j]);
            i++;
            j--;
        }
    }
    return i;
}

void quickSort(int a[], int l, int r){
    if (l < r){
        int q = partition(a, l, r);
        quickSort(a, l, q -1);
        quickSort(a, q, r);
    }
}

void printArray(int *a, int size){
    for (int i = 0; i < size; ++i) {
        printf("arr[%d]:%d ", i, a[i]);
    }
    printf("\n");
}

int findOrderedStatistic(int *a, int k, int arrLen){
    int left = 0;
    int right = arrLen - 1;
    while (1){
        int mid = partition(a, left, right);

        if (mid == k){
            return a[mid];
        }
        else if (k < mid){
            right = mid;
        }
        else{
            k -= mid + 1;
        }
    }
}

int main() {
    int a[10] = {0, 4, 8, 55, 16, 49, 1, 44, 4, 0};
    printArray(a, 10);
    quickSort(a, 0, 10 -1);
    printArray(a, 10);
    printf("%d", findOrderedStatistic(a, 4, 10));
    return 0;
}