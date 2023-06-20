#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <cstring>
#include <cstdlib>

using namespace std;

struct student
{
    string firstName;
    string lastName;
    int points;
};

void quickSort(student *arr, int mode, int left, int right) {
    int middle = (left + right) / 2;

    student pivot = arr[middle];
    arr[middle] = arr[right];

    int boundary = left;
    int i = left;

    while (i < right) {
        if (arr[i].points < pivot.points && mode == 0) {
            swap(arr[boundary], arr[i]);
            boundary++;
        }
        else if (arr[i].points > pivot.points && mode == 1) {
            swap(arr[boundary], arr[i]);
            boundary++;
        }
        i++;
    }
    arr[right] = arr[boundary];
    arr[boundary] = pivot;

    if (left < boundary - 1) {
        quickSort(arr, mode, left, boundary - 1);
    }

    if (boundary + 1 < right) {
        quickSort(arr, mode, boundary + 1, right);
    }
}

void readStudents(student *&arr, int *n) {
    string path, line, temp;
    int numberOfStudents;
    fstream file;
    file.open("students.csv");
    char semicolons;
    file >> numberOfStudents;

    arr = new student[numberOfStudents];

    for (int i = 0; i < 2; i++)
        file >> semicolons;

    for (int i = 0; i < numberOfStudents; i++) {
        file >> line;
        stringstream ss(line);
        getline(ss, arr[i].firstName, ';');
        getline(ss, arr[i].lastName, ';');
        getline(ss, temp);
        arr[i].points = atoi(temp.c_str());
    }

    *n = numberOfStudents;

    file.close();
}

void deleteStudentArray(student *&arr) {
    delete arr;
}

void displayStudents(student *arr, int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i].firstName << " " << arr[i].lastName << "| points: " << arr[i].points << endl;
    }
}

int main() {
    int mode, numberOfStudents;
    int *ptr = &numberOfStudents;

    cout << "Sorting: 0 - ascending, 1 - descending: ";
    cin >> mode;

    student *arr = nullptr;
    readStudents(arr, ptr);
    displayStudents(arr, numberOfStudents);
    quickSort(arr, mode, 0, numberOfStudents - 1);

    cout << "AFTER SORTING =============" << endl;

    displayStudents(arr, numberOfStudents);
    deleteStudentArray(arr);

    return 0;
}
