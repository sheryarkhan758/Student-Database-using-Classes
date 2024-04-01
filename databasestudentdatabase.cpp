#include <iostream>
#include <string>
using namespace std;

#define MAX_STUD 70
#define MAX_SUB 3

class Student {
private:
    int Regno;
    string name;
    float marks[MAX_SUB];
    char grade;
    int yearOfBirth; // Added year of birth
    int monthOfBirth; // Added month of birth
    int dayOfBirth; // Added day of birth

public:
    void calculateGrade();
    void setter();
    void getter();
    void deleteStudent(int rollNo, Student s[], int& n);
    int searchStudent(int rollNo, Student s[], int n);
    void updateStudent();

    class Airtime {
    private:
        int inHours;
        int inMinutes;
        int inSeconds;
        int outHours;
        int outMinutes;
        int outSeconds;

    public:
        void init(int inHr, int inMin, int inSec, int outHr, int outMin, int outSec);
        void setter();
        void getter();
    } airtime;
};

// Function to calculate the grade
void Student::calculateGrade() {
    float totalMarks = 0;
    for (int i = 0; i < MAX_SUB; i++) {
        totalMarks += marks[i];
    }
    float averageMarks = totalMarks / MAX_SUB;

    if (averageMarks >= 90)
        grade = 'A';
    else if (averageMarks >= 80)
        grade = 'B';
    else if (averageMarks >= 70)
        grade = 'C';
    else if (averageMarks >= 60)
        grade = 'D';
    else
        grade = 'F';
}

// Function to set student data
void Student::setter() {
    cout << "Enter the number of students (maximum 70): ";
    int numStudents;
    cin >> numStudents;

    while (numStudents < 1 || numStudents > MAX_STUD) {
        cout << "Invalid number of students. Please enter a number between 1 and 70." << endl;
        cout << "Enter the number of students (maximum 70): ";
        cin >> numStudents;
    }

    for (int i = 0; i < numStudents; i++) {
        cout << "Enter data for Student " << i + 1 << ":" << endl;

        cout << "Enter the Student Name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter the reg no for the Student: ";
        cin >> Regno;

        // Prompt for year of birth with a check
        do {
            cout << "Enter year of birth (1950-2023): ";
            cin >> yearOfBirth;
            if (yearOfBirth < 1950 || yearOfBirth > 2023) {
                cout << "Invalid Entry of the year. Please Enter Again." << endl;
            }
        } while (yearOfBirth < 1950 || yearOfBirth > 2023);

        // Prompt for month of birth
        do {
            cout << "Enter month of birth (1-12): ";
            cin >> monthOfBirth;
            if (monthOfBirth < 1 || monthOfBirth > 12) {
                cout << "Invalid entry for the month. Please enter again:" << endl;
            }
        } while (monthOfBirth < 1 || monthOfBirth > 12);

        do {
            cout << "Enter day of birth (1-31): ";
            cin >> dayOfBirth;
            if (dayOfBirth < 1 || dayOfBirth > 31) {
                cout << "Invalid entry for the day of birth. Please enter again:" << endl;
            }
        } while (dayOfBirth < 1 || dayOfBirth > 31);

        cout << "Enter marks for subjects (out of 100):" << endl;
        for (int j = 0; j < MAX_SUB; j++) {
            do {
                cout << "Subject " << j + 1 << ": ";
                cin >> marks[j];
                if (marks[j] < 0 || marks[j] > 100) {
                    cout << "Invalid marks. Marks should be between 0 and 100. Please try again." << endl;
                }
            } while (marks[j] < 0 || marks[j] > 100);
        }

        // Get airtime data for each student
        airtime.setter();
        calculateGrade();
    }
}

// Function to display student data
void Student::getter() {
    cout << endl << "Roll No: " << Regno << endl;
    cout << "Name: " << name << endl;
    cout << "Date of Birth: " << yearOfBirth << "/" << monthOfBirth << "/" << dayOfBirth << endl;
    cout << "Marks: ";
    for (int i = 0; i < MAX_SUB; i++) {
        cout << marks[i] << " ";
    }
    cout << endl;
    cout << "Grade: " << grade << endl;
    airtime.getter(); // Display Airtime data
}

// Function to delete a student record by roll number
void Student::deleteStudent(int rollNo, Student s[], int& n) {
    int pos = searchStudent(rollNo, s, n);
    if (pos != -1) {
        s[pos] = s[n - 1];
        n--;
        cout << "Student record deleted successfully." << endl;
    }
    else {
        cout << "Student not found with the given Roll Number." << endl;
    }
}

// Function to search for a student by roll number
int Student::searchStudent(int rollNo, Student s[], int n) {
    for (int i = 0; i < n; i++) {
        if (s[i].Regno == rollNo) {
            return i;
        }
    }
    return -1;
}

// Member function to update a student's information
void Student::updateStudent() {
    cout << "Enter updated information for Student " << Regno << ":" << endl;
    cout << "Enter the Student Name: ";
    cin.ignore();
    getline(cin, name);

    // Prompt for updated year of birth
    cout << "Enter updated year of birth (1950-2023): ";
    cin >> yearOfBirth;
    // Prompt for updated month of birth
    cout << "Enter updated month of birth (1-12): ";
    cin >> monthOfBirth;
    // Prompt for updated day of birth
    cout << "Enter updated day of birth (1-31): ";
    cin >> dayOfBirth;

    // Prompt for updated marks
    cout << "Enter updated marks for subjects (out of 100):" << endl;
    for (int j = 0; j < MAX_SUB; j++) {
        do {
            cout << "Updated marks for Subject " << j + 1 << ": ";
            cin >> marks[j];
        } while (marks[j] < 0 || marks[j] > 100);
    }

    // Recalculate the grade
    calculateGrade();

    cout << "Student record updated successfully." << endl;
}

// Function to initialize Airtime
void Student::Airtime::init(int inHr, int inMin, int inSec, int outHr, int outMin, int outSec) {
    inHours = inHr;
    inMinutes = inMin;
    inSeconds = inSec;
    outHours = outHr;
    outMinutes = outMin;
    outSeconds = outSec;
}

// Function to set Airtime data
void Student::Airtime::setter() {
    // Prompt for the entered time
    cout << "Enter time in (hh mm ss) 24 hour format when the student entered the classroom: ";
    cin >> inHours >> inMinutes >> inSeconds;

    // Check if entered hours, minutes, and seconds are valid
    while (inHours < 0 || inHours > 23 || inMinutes < 0 || inMinutes > 59 || inSeconds < 0 || inSeconds > 59) {
        cout << "Invalid time format. Hours must be between 0 and 23, and minutes and seconds must be between 0 and 59. Please try again." << endl;
        cout << "Enter time in (hh mm ss) 24 format when the student entered the classroom: ";
        cin >> inHours >> inMinutes >> inSeconds;
    }

    // Prompt for the leaving time
    cout << "Enter time in (hh mm ss) 24 hour format when the student left the classroom: ";
    cin >> outHours >> outMinutes >> outSeconds;

    // Check if leaving time is valid and later than entering time
    while (outHours < 0 || outHours > 23 || outMinutes < 0 || outMinutes > 59 || outSeconds < 0 || outSeconds > 59 ||
        (outHours == inHours && outMinutes == inMinutes && outSeconds <= inSeconds) ||
        (outHours == inHours && outMinutes <= inMinutes) ||
        (outHours < inHours)) {
        cout << "Invalid leaving time. Hours must be between 0 and 23, minutes and seconds must be between 0 and 59, and it should be later than the entering time. Please try again." << endl;
        cout << "Enter time in (hh mm ss) 24 hour format when the student left the classroom: ";
        cin >> outHours >> outMinutes >> outSeconds;
    }
}

// Function to display Airtime data
void Student::Airtime::getter() {
    cout << "Time in: " << inHours << ":" << inMinutes << ":" << inSeconds << endl;
    cout << "Time out: " << outHours << ":" << outMinutes << ":" << outSeconds << endl;
}

// User-Defined Function to update a student record
void updateStudent(Student s[], int n) {
    int searchRollNo;
    cout << "Enter the Roll Number to update: ";
    cin >> searchRollNo;

    int searchResult = -1;

    for (int i = 0; i < n; i++) {
        if (s[i].searchStudent(searchRollNo, s, n) != -1) {
            searchResult = i;
            break;
        }
    }

    if (searchResult != -1) {
        s[searchResult].updateStudent();
    }
    else {
        cout << "Student not found with the given Roll Number." << endl;
    }
}

// Function to search for a student by roll number using member function
void searchStudentByRollNumber(Student s[], int n) {
    int searchRollNo;
    cout << "Enter the Roll Number to search: ";
    cin >> searchRollNo;
    int searchResult = -1;

    for (int i = 0; i < n; i++) {
        if (s[i].searchStudent(searchRollNo, s, n) != -1) {
            searchResult = i;
            break;
        }
    }

    if (searchResult != -1) {
        s[searchResult].getter();
    }
    else {
        cout << "Student not found with the given Roll Number." << endl;
    }
}

int main() {
    Student s[MAX_STUD];
    int n = 0;
    int choice;

    do {
        cout << "************** RESULT CARD MENU ************" << endl
            << " 1. Display Result Card " << endl
            << " 2. Append/Read Student Data " << endl
            << " 3. Delete Student Record " << endl
            << " 4. Search Student by Roll No " << endl
            << " 5. Update Student Record " << endl
            << " 6. Exit " << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            if (n == 0) {
                cout << "No student data available. Please use option 2 to append or read data." << endl;
            }
            else {
                for (int i = 0; i < n; i++) {
                    s[i].getter();
                }
            }
            break;
        case 2:
            if (n >= MAX_STUD) {
                cout << "Maximum number of students reached. Cannot append more." << endl;
            }
            else {
                s[n].setter();
                n++;
                cout << "Student record added successfully." << endl;
            }
            break;
        case 3:
            int searchRollNo;
            cout << "Enter the Roll Number to delete: ";
            cin >> searchRollNo;
            s[0].deleteStudent(searchRollNo, s, n);
            break;
        case 4:
            searchStudentByRollNumber(s, n);
            break;
        case 5:
            updateStudent(s, n);
            break;
        case 6:
            cout << "Exiting the program. Goodbye!" << endl;
            break;
        default:
            cout << "Invalid choice. Please choose a valid option." << endl;
        }
    } while (choice != 6);

    return 0;
}
