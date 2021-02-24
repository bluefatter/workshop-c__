#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <ios>
#include <iomanip>

using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::sort;
using std::streamsize;
using std::setprecision;

int main() {
    cout << "please enter your name: ";

    string name;
    cin >> name;

    cout << "please enter your midterm and final score: ";
    double midterm, final;
    cin >> midterm >> final;

    cout << "please enter all your homeworks scores: ";
    vector<double> homeworks;
    double score;
    while (cin >> score) {
        homeworks.push_back(score);
    }

    typedef vector<double>::size_type vec_sz;
    vec_sz size = homeworks.size();

    if (size == 0) {
        cout << "homeworks not be empty";
        return 1;
    }

    sort(homeworks.begin(), homeworks.end());

    vec_sz mid = size / 2;
    double midScore = size % 2 == 0 ? (homeworks[mid] + homeworks[mid - 1]) / 2 : homeworks[mid];

    const streamsize precision = cout.precision();
    cout << "your final scores: " << setprecision(3)
         << 0.2 * midterm + 0.4 * final + 0.4 * midScore
         << setprecision(precision) << endl;
}
