#include <iostream>
#include <vector>
#include <string>
#include <cctype>
#include <algorithm>

using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::isspace;
using std::find_if;
using std::back_inserter;

vector<string> split(const string& str) {
    vector<string> result;
    typedef string::size_type string_size;
    string_size str_size = str.size();
    string_size i = 0;

    while (i != str_size) {
        while (i != str_size && isspace(str[i]))
            ++i;

        string_size j = i;
        while (j != str_size && !isspace(str[j]))
            ++j;

        if (j != i) {
            result.push_back(str.substr(i, j - i));
            i = j;
        }
    }
    return result;
}

bool is_not_space(char c) {
    return !isspace(c);
}

bool is_space(char c) {
    return isspace(c);
}

vector<string> splitUseAlgorithm(const string& str) {
    vector<string> result;
    typedef string::const_iterator iter;
    iter i = str.begin();

    while (i != str.end()) {
        i = find_if(i, str.end(), is_not_space);

        iter j = find_if(i, str.end(), is_space);

        if (i != j) {
            result.push_back(string(i, j));
            i = j;
        }
    }
    return result;
}

int main() {
    string a = " 1 2 3 ";
    vector<string> result = split(a);
    for (string& s: result) {
        cout << s << endl;
    }
    vector<string> result1 = splitUseAlgorithm(a);
    for (string& s: result1) {
        cout << s << endl;
    }
    return 0;
}
