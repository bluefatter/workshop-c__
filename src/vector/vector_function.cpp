#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <ios>
#include <iomanip>
#include <stdexcept>

using std::string;
using std::istream;
using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::sort;
using std::streamsize;
using std::setprecision;
using std::domain_error;

// param: vector<double>& vec is reference copy, without const means modify vec
void readHomeworks(istream& in, vector<double>& vec) {
    vec.clear();
    double score;
    while (in >> score) {
        vec.push_back(score);
    }
    in.clear();
}

double grade(const double midterm, const double final, double homeworkMid) {
    return 0.2 * midterm + 0.4 * final + 0.4 * homeworkMid;
}

// param: vector<double> homeworks is value copy
double homeworkMid(vector<double> homeworks) {
    typedef vector<double>::size_type vec_sz;
    vec_sz size = homeworks.size();

    if (size == 0) {
        throw domain_error("median of an empty vector");
    }

    sort(homeworks.begin(), homeworks.end());

    vec_sz mid = size / 2;
    return size % 2 == 0 ? (homeworks[mid] + homeworks[mid - 1]) / 2 : homeworks[mid];
}

// param: const vector<double>& homeworks is reference copy, with const means unmodify homeworks
double grade(const double midterm, const double final, const vector<double>& homeworks) {
    if (homeworks.empty()) {
        throw domain_error("student has no homeworks");
    }
    return grade(midterm, final, homeworkMid(homeworks));
}

/**
 * Important: very common C++ idiom of accepting values by constant references into functions,
 * which avoids unnecessary copying and construction of temporary objects.
 *
 * @return 0
 */
int main() {
    cout << "please enter your name: ";

    string name;
    cin >> name;

    cout << "please enter your midterm and final score: ";
    double midterm, final;
    cin >> midterm >> final;

    cout << "please enter all your homeworks scores: ";
    vector<double> homeworks;
    readHomeworks(cin, homeworks);

    try {
        double finalScore = grade(midterm, final, homeworks);
        const streamsize precision = cout.precision();
        cout << "your final scores: " << setprecision(3)
             << finalScore
             << setprecision(precision) << endl;
        return 0;
    } catch (domain_error) {
        cout << "you must input your scores,"
                "please try again" << endl;
        return 1;
    }
}
