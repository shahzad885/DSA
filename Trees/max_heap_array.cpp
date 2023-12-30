#include<iostream>
using namespace std;

// Function prototypes
void insert(int num);
void del();
void display();

int arr[100], n;

int main() {
    int choice, num;
    n = 0;

    while (1) {
        cout << "1. insert\n";
        cout << "2. delete\n";
        cout << "3. display\n";
        cout << "4. quit\n";
        cout << "5. enter your choice\n";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "enter the number to be inserted: ";
                cin >> num;
                insert(num);
                break;
            case 2:
                del();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                cout << "wrong choice\n";
        }
    }

    return 0;
}

void display() {
    int i;
    if (n == 0) {
        cout << "heap is empty\n";
    }
    for (i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

void insert(int num) {
    int loc = n;
    int par;

    while (loc > 0) {
        par = (loc - 1) / 2;
        if (num <= arr[par]) {
            arr[loc] = num;
            return;
        }
        arr[loc] = arr[par];
        loc = par;
    }
    arr[0] = num;
    n = n + 1;
}

void del() {
    if (n == 0) {
        cout << "heap is empty\n";
        return;
    }

    int num = arr[0];
    int last = arr[n - 1];
    n = n - 1;

    int i = 0;
    int child;

    while (2 * i + 1 < n) {
        child = 2 * i + 1;

        if (child + 1 < n && arr[child + 1] > arr[child]) {
            child = child + 1;
        }

        if (last >= arr[child]) {
            arr[i] = last;
            return;
        }

        arr[i] = arr[child];
        i = child;
    }

    arr[i] = last;
}
