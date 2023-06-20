#include <iostream>
#include <cstdlib>
#include <time.h>
#include <cmath>

using namespace std;

void allocateMemory1D(int *&tab, int n){

    tab = new int[n];

}

void allocateMemory2D(int **&tab, int w, int k){

    tab = new int*[w];

    for (int i = 0; i < k; i++){
        tab[i] = new int[k];
    }

}

void fillArray1D(int *tab, int n, int a, int b){

    int i;
    srand(time(NULL));

    for (i = 0; i < n; i++){
        tab[i] = rand()%(b-a+1)+a;
    }
}

void fillArray2D(int **tab, int w, int k, int a, int b){

    int i, j;
    srand(time(NULL));

    for (i = 0; i < w; i++){
        for (j = 0; j < k; j++){
            tab[i][j] = rand()%(b-a+1)+a;
        }
    }
}

void deleteArray1D(int *&tab){

    delete []tab;

}

void deleteArray2D(int **&tab, int w){
    int i;

    for (i = 0; i < w; i++){
        delete tab[i];
    }

    delete []tab;
}

void display1D(int* tab, int n){

    int j;
    cout<<"ONE-DIMENSIONAL ARRAY:"<<endl;

    for(int j = 0; j < n; j++){
        cout << tab[j] << " ";
    }
}

void display2D(int** tab, int w, int k){
    int i, j;

    for (i = 0; i < w; i++){
        cout << endl;
        for (j = 0; j < k; j++){
            cout << tab[i][j] <<" ";

        }
    }
}

bool isPrime(int a){

    int i;
    for (int i = 3; i < sqrt(a) + 1; i += 2){
        if (a % i == 0){
            return false;
        }
    }
    return true;
}

void minimumElement(){

    int n, a, b, i;

    cout << "Enter n: ";
    cin >> n;

    int *tab = new int[n];
    allocateMemory1D(tab, n);

    cout << "Enter a: ";
    cin >> a;
    cout << "Enter b: ";
    cin >> b;

    fillArray1D(tab, n, a, b);
    int minimum = tab[0];

    for (i = 0; i < n; i++){
        if (tab[i] < minimum){
            minimum = tab[i];
        }
    }
    cout << "Minimum = " << minimum << endl << "Number " << minimum << (isPrime(minimum) ? "" : " is not") << " prime\n";

    deleteArray1D(tab);

}

void countElements(){

    int n, a = 0, b = 9, i, j, counter;

    cout << "Enter n: ";
    cin >> n;

    int *tab = new int[n];
    allocateMemory1D(tab, n);
    fillArray1D(tab, n, a, b);
    display1D(tab, n);

    cout << endl;

    for (i = a; i <= b; i++){
        counter = 0;
        for (j = 0; j < n; j++){
            if (tab[j] == i){
                counter++;
            }
        }
        cout << "Digit " << i << " - " << counter << " times" << endl;
    }

    deleteArray1D(tab);

}

void maximumElement(){

    int a, b, i, j, w, k, sum = 0;

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
    int maximum = tab[0][0];

    for (i = 0; i < w; i++){
        for (j = 0; j < k; j++){
            if (tab[i][j] > maximum){
                maximum = tab[i][j];
            }
        }
    }

    cout << "Maximum = " << maximum << endl;

    for (i = 0; i < w; i++){
        for (j = 0; j < k; j++){
            if (tab[i][j] == maximum){
                sum += maximum;
            }
        }
    }

    cout << "Sum of digits = " << sum;

    deleteArray2D(tab, w);

}

void average(){

    int w, k, a = 7, b = 122, prz, i, j, l, sum = 0;
    double average_upper, average_lower;
    cout << "Enter the size of the square array: ";
    cin >> w;

    k = w;

    int **tab = nullptr;

    allocateMemory2D(tab, w, k);

    fillArray2D(tab, w, k, a, b);


    cout << "Upper" << endl;

    for (i = 0; i < w; i++){
        for (j = i + 1; j < k; j++){
            sum += tab[i][j];
            cout << tab[i][j] << " ";
            l++;
        }
    }

    cout << endl;

    display2D(tab, w, k);

    cout << endl;

    average_upper = sum / l;

    l = 0;

    cout << endl << "Lower" << endl;

    for (i = 0; i < w; i++){
        for (j = 0; j < i; j++){
            sum += tab[i][j];
            cout << tab[i][j] << " ";
            l++;
        }
    }

    average_lower = sum / l;

    cout << endl;
    cout << "Average above the diagonal: " << average_upper << endl;
    cout << "Average below the diagonal: " << average_lower << endl;

    deleteArray2D(tab, w);

}

int main(){

    int n, number;
    int *tab = new int[n];

    cout << "Enter the task number (2, 3, 4, 5): ";
    cin >> number;

    if (number == 2){
        minimumElement();
    }
    if (number == 3){
        countElements();
    }
    if (number == 4){
        maximumElement();
    }
    if (number == 5){
        average();
    }
    if (number < 2 || number > 5){
        cout << "No such task";
    }

    return 0;
}
