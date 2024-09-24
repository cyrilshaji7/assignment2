#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

struct STUDENT_DATA {
    string firstName;
    string lastName;
};

void readStudentData(const string& filename, vector<STUDENT_DATA>& students) {
    ifstream file(filename);
    string line;
    if (!file.is_open()) {
        cerr << "Error opening file: " << filename << endl;
        return;
    }
    while (getline(file, line)) {
        istringstream ss(line);
        string firstName, lastName;

        if (getline(ss, firstName, ',') && getline(ss, lastName)) {
            STUDENT_DATA student;
            student.firstName = firstName;
            student.lastName = lastName;
            students.push_back(student);
        }
    }
    file.close();
}


int main() {
    vector<STUDENT_DATA> students;

    readStudentData("C:\\Users\\Cyril\\Downloads\\resource-files\\StudentData.txt", students);

    return 1;
}
