#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

int main() {
    cout << "1. value copy" << endl;
    vector<double> value1;
    value1.push_back(0.0);

    // value assign
    vector<double> value2 = value1;
    value2.push_back(1.1);

    cout << "****** value1 *******" << endl;
    for (double& i : value1) {
        cout << i << endl;
    }

    cout << endl;

    cout << "****** value2 *******" << endl;
    for (double& i : value2) {
        cout << i << endl;
    }

    cout << endl;

    cout << "2. reference copy" << endl;
    vector<double> ref1;
    ref1.push_back(2.2);

    // reference assign
    vector<double>& ref2 = ref1;
    ref2.push_back(3.3);

    cout << "****** ref1 *******" << endl;
    for (double& i : ref1) {
        cout << i << endl;
    }

    cout << endl;

    cout << "****** ref2 *******" << endl;
    for (double& i : ref2) {
        cout << i << endl;
    }

    cout << endl;
    cout << "3. value & reference cout" << endl;

    int value = 1;
    int& ref3 = value;
    cout << ref3 << endl;
}
