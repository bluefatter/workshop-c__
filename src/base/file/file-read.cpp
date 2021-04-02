#include <iostream>
#include <fstream>
#include <string>

using std::ifstream;
using std::cout;
using std::cerr;
using std::endl;
using std::getline;
using std::string;

int main(int argc, char** argv) {
    if (argc == 1) {
        return 1;
    }

    int fail_count = 0;
    for (int i = 1; i < argc; ++i) {
        ifstream in(argv[i]);
        if (in) {
            string s;
            while (getline(in, s))
                cout << s << endl;
        } else {
            cerr << "cant open file " <<  argv[i] << endl;
            ++fail_count;
        }
    }

    return fail_count;
}

