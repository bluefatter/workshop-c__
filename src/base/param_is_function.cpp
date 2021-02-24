#include <iostream>

using std::cout;
using std::endl;
using std::back_inserter;
using std::stable_partition;

/**
 * Define function param just like header file define function, Just Function Declaration!!!
 */
void process_function(int compute(int, int), int a, int b) {
    cout <<  compute(a, b) << endl;
}

int add(int a, int b) {
    return a + b;
}

int minus(int a, int b) {
    return a - b;
}

int main() {
    process_function(add, 1, 2);
    process_function(minus, 1, 2);
    return 0;
}
