#include <iostream>

using std::cout;
using std::endl;

// Passing by reference without pointers
void swap(int& p1, int& p2) {
    int temp;
    temp = p1;
    p1 = p2;
    p2 = temp;
}

// Passing by reference using pointers
void swap(int* p1, int* p2) {
    int temp;
    temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

int main() {
    int a = 1, b = 2;
    swap(a, b);
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;

    int c = 3, d = 4;
    swap(&c, &d);
    cout << "c = " << c << endl;
    cout << "d = " << d << endl;

    int f = 5;
    int& g = f;
    cout << g << endl;
}
