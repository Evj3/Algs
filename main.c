#include <stdio.h>
// wrong answer if element not in sorted massive
// O log log n
int interpolationSearch(int *array, int size, int element){
    int left = 0;
    int right = size -1;

    while ((array[left] < element) && (element < array[right])){
        int difLeft = (element - array[left]) * (right - left); // числитель в формуле поиска индекса элемента
        int difRight = (array[right] - array[left]);
        int midIndex = left + (difLeft / difRight);

        if (array[midIndex] < element){
            left = midIndex + 1;
        } else if (array[midIndex] > element){
            right = midIndex - 1;
        } else{
            right = midIndex;
            break;
        }
    }
    if (array[left] == element){
        return left;
    } else if (array[right == element]){
        return right;
    } else{
        return -1;
    }
}

int main() {
    int arr[20] = {1, 1, 1, 2, 2, 3, 3, 3, 4, 4, 4, 4, 5, 5, 6, 6, 7, 7, 8, 8};
    int res = interpolationSearch(arr, 20, 8);
    printf("%d", res);
    return 0;
}