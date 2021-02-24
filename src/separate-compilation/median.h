#ifndef WORKSHOP_C___MEDIAN_H
#define WORKSHOP_C___MEDIAN_H
#include <iostream>
#include <vector>

struct StudentInfo {
    std::string name;
    double midTerm, final;
    std::vector<double> homeworks;
};

bool compare(const StudentInfo&, const StudentInfo&);
std::istream& read(std::istream&, StudentInfo&);
#endif //WORKSHOP_C___MEDIAN_H
