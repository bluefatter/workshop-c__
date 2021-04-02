#include <iostream>

using std::cout;
using std::endl;

/**
 * Pointer阅读方法：把一个声明从右向左读（* 读成 pointer to）
 *
 * @return 0
 */
int main() {
    int a = 5;
    // p pointer to const int
    const int* p = &a;
    cout << &a << endl;
    cout << p << endl;
    cout << ++p << endl;

    int b = 5;
    // p1 is const pointer to int
    int* const p1 = &b;
    cout << &b << endl;
    cout << p1 << endl;
    // not support ++p1
//    cout << ++p1 << endl;
    return 0;
}
