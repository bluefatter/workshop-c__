#include <iostream>
#include <map>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::map;
using std::pair;

/**
 * map just like Java key-value Map.
 */
int main() {
    string s;
    map<string, int> counters;

    while (cin >> s) {
        if (s == "end") {
            break;
        }

        /**
         * counters[s] get map value with key is `s`
         * when key `s` not in map first time, the map automatically creates a new element with that key, and do value-initialized !!!
         */
        ++counters[s];
    }

    for (map<string, int>::const_iterator i = counters.begin(); i != counters.end(); ++i) {
        cout << "key: " << i -> first << " value: " << i -> second << endl;
    }

    for (pair<const string, int>& pair: counters) {
        cout << "key: " << pair.first << " value: " << pair.second << endl;
    }

    return 0;
}
