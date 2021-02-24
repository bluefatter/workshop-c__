#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

int main() {
    // char* to string
    char cs[] = {'a', 'b', 'c'};
    cout << cs << endl;

    string css = string(cs);
    cout << css << endl;

    // string to char*
    string a = "asbdasdasd";
    for (char& c: a) {
        cout << c << endl;
    }

    /**
     * string c_str() return c-string with null character terminating
     */
    const char* acs = a.c_str();
    /**
     * cout operator<< overloaded for const char*,
     * taking the const char* actually treats it like a C-string and outputs every character until the terminating null character.
     */
    cout << acs << endl;
    return 0;
}
