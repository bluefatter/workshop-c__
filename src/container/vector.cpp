#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::string;

/**
 * vector just like Java ArrayList.
 */
int main() {
    string s;
    vector<string> collectors;

    while (cin >> s) {
        if (s == "end") {
            break;
        }
        collectors.push_back(s);
    }

    for (vector<string>::const_iterator it = collectors.begin(); it != collectors.end(); ++it) {
        cout << *it << endl;
    }

    for (string& str: collectors) {
        cout << str << endl;
    }
    return 0;
}
