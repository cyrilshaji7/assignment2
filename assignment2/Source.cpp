#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

struct STUDENT_DATA {
    string firstName;
    string lastName;
    string email;  
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

#ifdef PRE_RELEASE
void readStudentEmails(const string& filename, vector<STUDENT_DATA>& students) {
    ifstream file(filename);
    string line;

    if (!file.is_open()) {
        cerr << "Error opening file: " << filename << endl;
        return;
    }

    while (getline(file, line)) {
        istringstream ss(line);
        string email;
        if (getline(ss, email)) {
            students[students.size() - 1].email = email;  
        }
    }
    file.close();
}
#endif

void displayStudents(const vector<STUDENT_DATA>& students) {
    cout << "Student List:\n";
    for (const auto& student : students) {
        cout << student.firstName << " " << student.lastName;
#ifdef PRE_RELEASE
        cout << ", Email: " << student.email;
#endif
        cout << endl;
    }
}

int main() {
    vector<STUDENT_DATA> students;

#ifdef PRE_RELEASE
    cout << "Running Pre-Release Version\n";
#else
    cout << "Running Standard Version\n";
#endif

    readStudentData("C:\\Users\\Cyril\\Downloads\\resource-files\\StudentData.txt", students);

#ifdef PRE_RELEASE
    readStudentEmails("C:\\Users\\Cyril\\Downloads\\resource-files\\StudentData_Emails.txt", students);
#endif

    displayStudents(students);

    return 1;
}
