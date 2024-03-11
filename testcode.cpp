#define _CRT_SECURE_NO_WARNINGS 

//quick sort

#include <iostream>
using namespace std;

// 交换两个元素
void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

// 将数组划分为两部分，并返回分界点索引
int partition(int arr[], int low, int high) {
    int pivot = arr[high];  // 选取最后一个元素作为基准
    int i = (low - 1);  // 定义小于基准的分界点索引

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

// 快速排序函数
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);  // 获取分界点索引

        quickSort(arr, low, pi - 1);  // 对左半部分递归排序
        quickSort(arr, pi + 1, high);  // 对右半部分递归排序
    }
}

// 打印数组元素
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = { 64, 25, 12, 22, 11 };
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "原始数组：" << endl;
    printArray(arr, n);

    quickSort(arr, 0, n - 1);

    cout << "排序后的数组：" << endl;
    printArray(arr, n);

    return 0;
}


