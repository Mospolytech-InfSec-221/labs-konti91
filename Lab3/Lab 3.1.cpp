#include <iostream>
using namespace std;

template <typename T>
void array_output(T mas, int size) {
    cout << "Array size " << size << ":\n";
    for (int i = 0; i < size; i++) {
        cout << mas [i] << " ";
    }
    cout << endl;
}

template <typename T>
void array_input(T mas, int& size){
    while (true) {
        cout << "Enter the size of the array: ";
        cin >> size;
        if (size > 0 && size <= 5) break;
        else cout << "Mistake. Re enter. n must be greater than 0 and less than 1000\n";
    }
    cout << "Enter the elements of the array into a string separated by a space:\n";
    for (int i = 0; i < size; i++) {
        cin >> mas[i];
    }
}

template <>
void array_input(char* mas, int& size) {
    while (true) {
        cout << "Enter the size of the array: ";
        cin >> size;
        if (size > 0 && size <= 5) break;
        else cout << "Mistake. Re-enter. n must be greater than 0 and less than 1000\n";
    }
    cout << "Enter the elements of the literal array line by line:\n";
    for (int i = 0; i < size; i++) {
        while (true) {
            cin >> mas[i];
            if (mas[i] >= 'a' && mas[i] <= 'z') break;
            else cout << "The symbol is not a letter of the english alphabet. Retype\n\n";
        }
    }
}

void bubblesort(int* mas, int size) {
    int temp;
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (mas[j] > mas[j + 1]) {
                temp = mas[j];
                mas[j] = mas[j + 1];
                mas[j + 1] = temp;
            }
        }
    }
}

void countsort(char* mas, int size) {
    #define DIF_ELEM 26
    int arr[DIF_ELEM] = {0};
    int j;
    for (int i = 0; i < size; i++) {
        j = (int)(mas[i] - 'a');
        arr[j]++;
    }
    int i = 0;
    j = 0;
    while (j <= DIF_ELEM) {
        if (arr[j] > 0) {
            mas[i] = (char)((int)'a' + j);
            i++;
            arr[j]--;
        }
        else j++;
    }
}

void mergesort(int* mas, int l, int r) {
    if (l == r) return;
    int mid = (l + r) / 2;
    mergesort(mas, l, mid);
    mergesort(mas, mid + 1, r);
    int i = l;
    int j = mid + 1;
    int tmp[5];
    for (int step = 0; step < r - l + 1; step++) {
        if (j > r || (i <= mid && mas[i] < mas[j])) {
            tmp[step] = mas[i];
            i++;
        }
        else {
            tmp[step] = mas[j];
            j++;
        }
    }
    for (int step = 0; step < r - l + 1; step++) mas[l + step] = tmp[step];
}

template <typename T>
void check(T mas, int &size) {
    char option;
    if (size == 0) array_input<T>(mas, size);
    else {
        cout << "хотите повторить ввод массива (y/n): ";
        cin >> option;
        if (option == 'y') array_input<T>(mas, size);
    }
}

int main() {
    int mas1[5], mas3[5], n1 = 0, n2 = 0, n3 = 0;
    char mas2[5];
    char option;
    while (true) {
        cout << "Select an action: \n"
            << "1. Bubble sort\n"
            << "2. Sorting by counting\n"
            << "3. Merge sort\n"
            << "4. Exit\n"
            << "Your choice: ";
        cin >> option;
        switch (option) {
        case '1':
            check(mas1, n1);
            bubblesort(mas1, n1);
            cout << "\nSorted Array: \n";
            array_output(mas1, n1);
            break;
        case '2':
            check(mas2, n2);
            countsort(mas2, n2);
            cout << "\nSorted Array: \n";
            array_output(mas2, n2);
            break;
        case '3':
            check(mas3, n3);
            mergesort(mas3, 0, n3-1);
            cout << "\nSorted Array: \n";
            array_output(mas3, n3);
            break;
        case '4':
            return 0;
            break;
        default:
            system("cls");
            continue;
            break;
        }
        system("pause");
        system("cls");
    }
}
