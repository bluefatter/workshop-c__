#include <iostream>
#include <list>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::list;
using std::string;
using std::strcmp;

/**
 * list just like Java LinkedList.
 */
int main() {
    string s;
    list<string> collectors;

    while (cin >> s) {
        if (strcmp(s.c_str(), "end") == 0) {
            break;
        }
        collectors.push_back(s);
    }

    for (list<string>::const_iterator it = collectors.begin(); it != collectors.end(); ++it) {
        cout << *it << endl;
    }

    for (string& str: collectors) {
        cout << str << endl;
    }
    return 0;
}
