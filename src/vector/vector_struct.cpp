#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stdexcept>
#include <iomanip>

using std::string;
using std::vector;
using std::istream;
using std::cin;
using std::cout;
using std::endl;
using std::max;
using std::sort;
using std::domain_error;
using std::streamsize;
using std::setprecision;

struct StudentInfo {
    string name;
    double midTerm, final;
    vector<double> homeworks;
};

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
