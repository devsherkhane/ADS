#include <iostream>
using namespace std;

const int MAX_STUDENTS = 1000;


void createheap(int arr[], int n, int i) {
    int largest = i; 
    int left = 2 * i + 1; 
    int right = 2 * i + 2; 


    if (left < n && arr[left] > arr[largest])
        largest = left;

    
    if (right < n && arr[right] > arr[largest])
        largest = right;

    
    if (largest != i) {
        swap(arr[i], arr[largest]);

        createheap(arr, n, largest);
    }
}


void buildMax(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        createheap(arr, n, i);
}


int findMax(int arr[], int n) {
    buildMax(arr, n);
    return arr[0];
}

int findMin(int arr[], int n) {
    int min = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] < min)
            min = arr[i];
    }
    return min;
}

int main() {
    int marks[MAX_STUDENTS];
    int numStudents = 0;
    int choice, mark;

    do {
        cout << "Menu:\n";
        cout << "1. Add a mark\n";
        cout << "2. Find maximum mark\n";
        cout << "3. Find minimum mark\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                if (numStudents < MAX_STUDENTS) {
                    cout << "Enter the mark: ";
                    cin >> mark;
                    marks[numStudents++] = mark;
                } else {
                    cout << "Maximum number of students reached!\n";
                }
                break;
            case 2:
                if (numStudents == 0) {
                    cout << "No marks entered yet!\n";
                } else {
                    cout << "Maximum mark: " << findMax(marks, numStudents) << "\n";
                }
                break;
            case 3:
                if (numStudents == 0) {
                    cout << "No marks entered yet!\n";
                } else {
                    cout << "Minimum mark: " << findMin(marks, numStudents) << "\n";
                }
                break;
            case 4:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 4);

    return 0;
}
