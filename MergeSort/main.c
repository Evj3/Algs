#include <stdio.h>

void merge(int *a, int left, int mid, int right){
    int it1 = 0;
    int it2 = 0;
    int result[right - left];

    while (((left + it1) < mid) && ((mid + it2) < right)){
        if (a[left+it1] < a[mid + it2]){
            result[it1 + it2] = a[left + it1];
            ++it1;
        } else{
            result[it1 + it2] = a[mid + it2];
            ++it2;
        }
    }

    while ((left + it1) < mid){
        result[it1 + it2] = a[left + it1];
        ++it1;
    }

    while ((mid + it2) < right){
        result[it1 + it2] = a[mid + it2];
        ++it2;
    }

    for (int i = 0; i < it1 + it2; ++i) {
        a[left + i] = result[i];
    }
}

void mergeSortRecursive(int *a, int left, int right){
    if ((left + 1) >= right){
        return;
    }

    int mid = (left + right) / 2;
    mergeSortRecursive(a, left, mid);
    mergeSortRecursive(a, mid, right);
    merge(a, left, mid, right);
}

int min(int a, int b){
    if (a < b)  return a;
    else        return b;
}
// O(log(n)) memory economy for recursive calls
void mergeSortIterative(int *a, int size){
    for (int i = 1; i <= size; i *= 2) {
        for (int j = 0; j <= size - i; j += 2 * i) {
            merge(a, j, j + i, min(j + 2 * i, size));
        }
    }
}

void printArray(int *a, int size){
    for (int i = 0; i < size; ++i) {
        printf("arr[%d]:%d, ", i, a[i]);
    }
    printf("\n");
}

int main() {
    const int size = 6;
    int a[size] = {8, 23, 15, 42, 4, 16};

    printArray(a, size);
    mergeSortRecursive(a, 0, size); //wA
    //mergeSortIterative(a, size);
    printArray(a, size);
    return 0;
}
