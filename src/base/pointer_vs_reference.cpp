#include <iostream>

using std::cout;
using std::endl;

template<class T> class Test {
public:
    explicit Test(T v) {
        value = v;
    }

    T& getValue() {
        return value;
    }

private:
    T value;
};

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

    /**
     * This is difference between pointer and reference!
     * pointer i = &<value>
     * reference j = <value>
     */
    int h = 1;
    int* i = &h;
    int& j = h;

    Test<int> test(1);
    int k = test.getValue();
    int& l = test.getValue();
    cout << k << endl;
    cout << l << endl;
}
