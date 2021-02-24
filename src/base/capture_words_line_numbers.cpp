#include <iostream>
#include <map>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::map;
using std::vector;
using std::istream;
using std::string;
using std::getline;
using std::pair;

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

/**
 * Notice!!!
 * Return value Type map<string, vector<int> > has a space between two >!!!
 * Without this space, compiler will assume that it is looking at an >> operator, rather than at two separate > symbols.
 */
/**
 * Second parameter `= split` means default value !!!
 */
map<string, vector<int> > wordLineNumberMap(istream& in, vector<string> find_words(const string&) = split) {
    string line;
    int line_number = 0;
    map<string, vector<int> > result;

    while (getline(in, line)) {
        if (line == "end") {
            break;
        }

        ++line_number;
        vector<string> words = find_words(line);
        for (vector<string>::const_iterator it = words.begin(); it != words.end(); ++it) {
            result[*it].push_back(line_number);
        }
    }
    return result;
}

int main() {
    map<string, vector<int> > result = wordLineNumberMap(cin);
    for (pair<const string, vector<int> >& pair: result) {
        cout << pair.first << endl;
        for (int& value: pair.second) {
            cout << value << " ";
        }
        cout << endl;
    }
    return 0;
}

