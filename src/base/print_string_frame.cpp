#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::max;

string::size_type maxLength(const vector<string>& strs) {
    string::size_type maxLen = 0;
    for (const string& str: strs) {
        maxLen = max(maxLen, str.size());
    }
    return maxLen;
}

vector<string> frame(const vector<string>& strs) {
    vector<string> result;
    string::size_type max = maxLength(strs);

    string border(max + 4, '*');
    result.push_back(border);

    for (const string& str: strs) {
        result.push_back("*" + str + string(max - str.size(), ' ') + "*");
    }

    result.push_back(border);
    return result;
}

int main() {
    vector<string> strs;
    strs.emplace_back("adjskldjaskld");
    strs.emplace_back("ldjaskld");
    strs.emplace_back("adjskldjd");
    strs.emplace_back("adjsklkld");

    vector<string> result = frame(strs);
    vector<string>::const_iterator begin = result.begin(), end = result.end();

    cout << "for iterator" << endl;
    while (begin != end) {
        cout << *begin << endl;
        ++begin;
    }

    cout << "for str : result" << endl;
    for (string& str: result) {
        cout << str << endl;
    }
    return 0;
}
