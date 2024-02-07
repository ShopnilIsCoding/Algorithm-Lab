#include<iostream>
using namespace std;

int max(int a, int b) {
    return (a > b) ? a : b;
}

int main() {
    int n;
    cout << "Enter the number of items: ";
    cin >> n;

    int p[n+1], wt[n+1];

    
    cout << "Enter the profit of items:";
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
    }

   
    cout << "Enter the weights of items:";
    for (int i = 1; i <= n; i++) {
        cin >> wt[i];
    }

    int m;
    cout << "Enter the capacity : ";
    cin >> m;

    int k[n + 1][m + 1];

    
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= m; w++) {
            if (i == 0 || w == 0)
                k[i][w] = 0;
        }
    }

    
    for (int i = 1; i <= n; i++) {
        for (int w = 1; w <= m; w++) {
            if (wt[i] <= w)
                k[i][w] = max(p[i] + k[i - 1][w - wt[i]], k[i - 1][w]);
            else
                k[i][w] = k[i - 1][w];
        }
    }

    
    cout << "Maximum profit : " << k[n][m] << endl;

}