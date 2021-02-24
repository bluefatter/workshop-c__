#include <iostream>
#include <vector>
#include "median.h"

using std::istream;
using std::vector;

void readHomeworks(istream& in, vector<double>& homeworks) {
    homeworks.clear();
    double score;
    while (in >> score) {
        homeworks.push_back(score);
    }
}

istream& read(istream& in, StudentInfo& record) {
    in >> record.name >> record.midTerm >> record.final;
    readHomeworks(in, record.homeworks);
    return in;
}

bool compare(const StudentInfo& s1, const StudentInfo& s2) {
    return s1.name < s2.name;
}
