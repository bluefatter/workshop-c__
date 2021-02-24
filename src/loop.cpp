#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::cin;
using std::endl;

int main() {
    cout << "please input your name: ";
    string name;
    cin >> name;

    const string message = "hello " + name + "!";

    const int pad = 1;
    const int rows = pad * 2 + 3;
    const string::size_type cols = message.size() + pad * 2 + 2;

    cout << endl;

    for (int r = 0; r != rows; ++r) {
        string::size_type col = 0;
        while (col != cols) {
            if (r == pad + 1 && col == pad + 1) {
                cout << message;
                col += message.size();
            } else {
                if (r == 0 || r == rows - 1 || col == 0 || col == cols - 1) {
                    cout << "*";
                } else {
                    cout << " ";
                }
                ++col;
            }
        }
        cout << endl;
    }
    return 0;
}
