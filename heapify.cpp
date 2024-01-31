#include <iostream>
using namespace std;

void heapify(int arr[], int n, int i) {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < n && arr[l] > arr[largest])
        largest = l;

    if (r < n && arr[r] > arr[largest])
        largest = r;
    if (largest != i) {
        swap(arr[i], arr[largest]);

        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
    for (int i = n - 1; i >= 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

void printDetails(int arr[], int n) {
    cout << "Root and its left and right child after making the array max heap:\n";
    int j=(n/2) -1;
    for (int i = 0; i < n; i++) {
        int root = arr[i];
        int leftChild = (2 * i + 1 < n) ? arr[2 * i + 1] : -1;
        int rightChild = (2 * i + 2 < n) ? arr[2 * i + 2] : -1;
        
        if(j>=0)
        {
        cout << "Root: " << root << ", Left Child: " << leftChild ;
        if(rightChild!=-1)
        cout << ", Right Child: " << rightChild << endl;
        else
        cout << ", Right Child: " << "Null"<< endl;
        j--;
        }
    }
}


void printArray(int arr[], int n) {
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << "\n";
}

int main() {
    int n;
    cout << "Enter array size: ";
    cin >> n;
    int arr[n];
    cout << "Enter array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }

    printDetails(arr, n);

    heapSort(arr, n);

    cout << "Sorted array is:\n";
    printArray(arr, n);

    return 0;
}
