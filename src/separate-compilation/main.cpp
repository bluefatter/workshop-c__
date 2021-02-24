#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <stdexcept>
#include <ios>
#include <list>

#include "median.h"
#include "grade.h"

using std::vector;
using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::setprecision;
using std::sort;
using std::max;
using std::domain_error;
using std::streamsize;
using std::list;
using std::shared_ptr;

int main() {
    vector<StudentInfo> students;
    StudentInfo record;
    string::size_type maxLen = 0;

    while (read(cin, record)) {
        maxLen = max(record.name.size(), maxLen);
        students.push_back(record);
    }

    sort(students.begin(), students.end(), compare);

    for (auto& student : students) {
        cout << student.name << string(maxLen + 1 - student.name.size(), ' ');

        try {
            double finalScore = grade(student);
            streamsize prec = cout.precision();
            cout << setprecision(3) << finalScore << setprecision(prec);
        } catch (domain_error e) {
            cout << e.what();
        }

        cout << endl;
    }
    return 0;
}
