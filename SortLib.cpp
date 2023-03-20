// SortLib.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
using namespace std;
#include"sort.h"

void selection_sort_test() {
    cout << "selection sort:" << endl;
    int arr[] = {16, 7, 2, 9, 5, 3};
    int n = sizeof(arr) / sizeof(int);
    selection_sort(arr, n);
    cout << "[";
    for (int i = 0; i < n; i++) {
        if (i != n - 1) {
            cout << arr[i] << ", ";
        }
        
        else {
            cout << arr[i] << "]";
        }
    }
    cout << endl;
}

void merge_sort_test() {
    cout << "merge sort:" << endl;
    int arr[] = { 16, 7, 2, 9, 5, 3 };
    int n = sizeof(arr) / sizeof(int);
    merge_sort(arr, n);
    cout << "[";
    for (int i = 0; i < n; i++) {
        if (i != n - 1) {
            cout << arr[i] << ", ";
        }

        else {
            cout << arr[i] << "]";
        }
    }
}
int main()
{
    selection_sort_test();
    merge_sort_test();
    //std::cout << "Hello World!\n";
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
