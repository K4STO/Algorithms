#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;

void allocateMemory1D(int *&tab, int n) {
    tab = new int[n];
}

void allocateMemory2D(int **&tab, int w, int k) {
    tab = new int *[w];

    for (int i = 0; i < w; i++) {
        tab[i] = new int[k];
    }
}

void fillArray1D(int *tab, int n, int a, int b) {
    srand(time(NULL));

    for (int i = 0; i < n; i++) {
        tab[i] = rand() % (b - a + 1) + a;
    }
}

void fillArray2D(int **tab, int w, int k, int a, int b) {
    srand(time(NULL));

    for (int i = 0; i < w; i++) {
        for (int j = 0; j < k; j++) {
            tab[i][j] = rand() % (b - a + 1) + a;
        }
    }
}

void deleteArray1D(int *&tab) {
    delete[] tab;
}

void deleteArray2D(int **&tab, int w) {
    for (int i = 0; i < w; i++) {
        delete tab[i];
    }

    delete[] tab;
}

void display1D(int *tab, int n) {
    cout << "ONE-DIMENSIONAL ARRAY:" << endl;

    for (int i = 0; i < n; i++) {
        cout << tab[i] << " ";
    }
}

void display2D(int **tab, int w, int k) {
    for (int i = 0; i < w; i++) {
        cout << endl;
        for (int j = 0; j < k; j++) {
            cout << tab[i][j] << " ";
        }
    }
}

void bubbleSort(int *tab, int n, int mode) {
    for (int i = n - 1; i > 0; i--) {
        for (int j = 0; j < i; j++) {
            if (mode == 1) {
                if (tab[j] > tab[j + 1]) {
                    swap(tab[j], tab[j + 1]);
                }
            } else if (mode == 2) {
                if (tab[j] < tab[j + 1]) {
                    swap(tab[j], tab[j + 1]);
                }
            }
        }
    }
}

void selectionSort(int *tab, int n, int mode) {
    for (int i = n - 1; i > 0; i--) {
        int ind = 0;
        for (int j = 1; j <= i; j++) {
            if (mode == 1) {
                if (tab[j] > tab[ind]) {
                    ind = j;
                }
            } else if (mode == 2) {
                if (tab[j] < tab[ind]) {
                    ind = j;
                }
            }
        }
        swap(tab[i], tab[ind]);
    }
}

void insertionSort(int *tab, int n, int mode) {
    for (int i = n - 2; i >= 0; i--) {
        int j = i;
        int temp = tab[j];
        if (mode == 1) {
            while (temp > tab[j + 1] && j < n - 1) {
                tab[j] = tab[j + 1];
                j++;
            }
        } else if (mode == 2) {
            while (temp < tab[j + 1] && j < n - 1) {
                tab[j] = tab[j + 1];
                j++;
            }
        }
        tab[j] = temp;
    }
}

void bubbleSort2D(int **tab, int w, int k, int mode, int colNumber) {
    for (int i = w - 1; i > 0; i--) {
        for (int j = 0; j < i; j++) {
            if (mode == 1) {
                if (tab[j][colNumber] > tab[j + 1][colNumber]) {
                    swap(tab[j], tab[j + 1]);
                }
            } else if (mode == 2) {
                if (tab[j][colNumber] < tab[j + 1][colNumber]) {
                    swap(tab[j], tab[j + 1]);
                }
            }
        }
    }
}

void task2() {
    int n, a, b, tryb;

    cout << "Enter n: ";
    cin >> n;

    int *tab = new int[n];
    allocateMemory1D(tab, n);

    cout << "Enter a: ";
    cin >> a;
    cout << "Enter b: ";
    cin >> b;

    cout << "Enter sorting mode (1 - ascending, 2 - descending): ";
    cin >> tryb;

    fillArray1D(tab, n, a, b);

    cout << endl;

    display1D(tab, n);

    bubbleSort(tab, n, tryb);

    cout << endl;

    display1D(tab, n);

    deleteArray1D(tab);
}

void task3() {
    int n, a, b, tryb;

    cout << "Enter n: ";
    cin >> n;

    int *tab = new int[n];
    allocateMemory1D(tab, n);

    cout << "Enter a: ";
    cin >> a;
    cout << "Enter b: ";
    cin >> b;

    cout << "Enter sorting mode (1 - ascending, 2 - descending): ";
    cin >> tryb;

    fillArray1D(tab, n, a, b);

    cout << endl;

    display1D(tab, n);

    selectionSort(tab, n, tryb);

    cout << endl;

    display1D(tab, n);

    deleteArray1D(tab);
}

void task4() {
    int n, a, b, tryb;

    cout << "Enter n: ";
    cin >> n;

    int *tab = new int[n];
    allocateMemory1D(tab, n);

    cout << "Enter a: ";
    cin >> a;
    cout << "Enter b: ";
    cin >> b;

    cout << "Enter sorting mode (1 - ascending, 2 - descending): ";
    cin >> tryb;

    fillArray1D(tab, n, a, b);

    cout << endl;

    display1D(tab, n);

    insertionSort(tab, n, tryb);

    cout << endl;

    display1D(tab, n);

    deleteArray1D(tab);
}

void task5() {
    int a, b, w, k, tryb, colNumber;

    cout << "Enter w: ";
    cin >> w;

    cout << "Enter k: ";
    cin >> k;

    int **tab = nullptr;

    allocateMemory2D(tab, w, k);

    cout << "Enter a: ";
    cin >> a;
    cout << "Enter b: ";
    cin >> b;

    fillArray2D(tab, w, k, a, b);

    cout << "Enter sorting mode (1 - ascending, 2 - descending): ";
    cin >> tryb;

    cout << "Enter the column number to sort: ";
    cin >> colNumber;

    cout << endl;

    display2D(tab, w, k);

    bubbleSort2D(tab, w, k, tryb, colNumber);

    cout << endl;

    display2D(tab, w, k);

    deleteArray2D(tab, w);
}

int main() {
    int numer;

    cout << "Enter the task number (2, 3, 4, 5): ";
    cin >> numer;

    if (numer == 2) {
        task2();
    } else if (numer == 3) {
        task3();
    } else if (numer == 4) {
        task4();
    } else if (numer == 5) {
        task5();
    } else {
        cout << "No such task exists";
    }

    return 0;
}
