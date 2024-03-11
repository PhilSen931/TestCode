#define _CRT_SECURE_NO_WARNINGS 

//quick sort

#include <iostream>
using namespace std;

// ��������Ԫ��
void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

// �����黮��Ϊ�����֣������طֽ������
int partition(int arr[], int low, int high) {
    int pivot = arr[high];  // ѡȡ���һ��Ԫ����Ϊ��׼
    int i = (low - 1);  // ����С�ڻ�׼�ķֽ������

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

// ����������
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);  // ��ȡ�ֽ������

        quickSort(arr, low, pi - 1);  // ����벿�ֵݹ�����
        quickSort(arr, pi + 1, high);  // ���Ұ벿�ֵݹ�����
    }
}

// ��ӡ����Ԫ��
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = { 64, 25, 12, 22, 11 };
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "ԭʼ���飺" << endl;
    printArray(arr, n);

    quickSort(arr, 0, n - 1);

    cout << "���������飺" << endl;
    printArray(arr, n);

    return 0;
}


