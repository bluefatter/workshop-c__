#include <vector>
#include <stdexcept>

#include "grade.h"

using std::vector;
using std::domain_error;

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

double grade(const StudentInfo& student) {
    return 0.2 * student.midTerm + 0.4 * student.midTerm + 0.4 * homeworkMid(student.homeworks);
}
