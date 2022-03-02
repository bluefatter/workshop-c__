#ifndef WORKSHOP_C___STUDENT_INFO_H
#define WORKSHOP_C___STUDENT_INFO_H
#include <iostream>
#include <vector>

class StudentInfo {
public:
    /**
     * The const on the declaration of grade is a promise that
     * calling the grade function will not change any of the data members of the Student_info object
     */
    StudentInfo();
//    StudentInfo(std::istream&);
    ~StudentInfo() {
        std::cout << "exiting StudentInfo" << std::endl;
    }

//    double grade() const;
//    std::istream& read(std::istream&);
    std::string getName() const {
        return name;
    }

private:
    std::string name;
    double midterm, final;
    std::vector<double> homework;
};

#endif //WORKSHOP_C___STUDENT_INFO_H
