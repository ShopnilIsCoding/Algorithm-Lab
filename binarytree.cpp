#include <bits/stdc++.h>
using namespace std;

int parent(int i) {
    return (i - 1) / 2;
}

int leftChild(int i) {
    return 2 * i + 1;
}

int rightChild(int i) {
    return 2 * i + 2;
}

void inOrderTraversal(int arr[], int i, int n) 
{
    if (i < n) {
        inOrderTraversal(arr, leftChild(i), n);  
        cout << arr[i] << " ";
        inOrderTraversal(arr, rightChild(i), n); 
    }
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    int a[n];
    cout << "Enter the elements: ";
    for (int j = 0; j < n; j++) {
        cin >> a[j];
    }

    cout << "In-order traversal: ";
    inOrderTraversal(a, 0, n);
    cout << endl;

    return 0;
}
