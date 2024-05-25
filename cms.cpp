#include <iostream>
#include <fstream>
#include <cstring>
#include <limits>

using namespace std;

const char* USERS_FILE = "users.txt";
const char* COMPLAINTS_FILE = "complaints.txt";
const char* TIMETABLE_FILE = "timetable.txt";
const char* ATTENDANCE_FILE = "attendance.txt";
const char* COURSE_MATERIAL_FILE = "course_material.txt";
const char* GRADES_FILE = "grades.txt";
const char* FEES_FILE = "fees.txt";
const char* LIBRARY_BOOKINGS_FILE = "library_bookings.txt";
const char* TEACHER_USERNAME = "teacher";
const char* TEACHER_PASSWORD = "teacher123";

char usernames[100][50];
char passwords[100][50];
int numUsers = 0;

void loadUsers() {
    ifstream inFile(USERS_FILE);
    if (!inFile) {
        cerr << "Error opening users file." << endl;
        return;
    }

    while (inFile >> usernames[numUsers] >> passwords[numUsers]) {
        numUsers++;
    }

    inFile.close();
}

void saveUser(const char* username, const char* password) {
    ofstream outFile(USERS_FILE, ios::app);
    if (!outFile) {
        cerr << "Error opening users file." << endl;
        return;
    }

    outFile << username << ' ' << password << endl;
    outFile.close();
}

void showMainMenu() {
    cout << "1. Login\n";
    cout << "2. Sign Up\n";
    cout << "3. Exit\n";
    cout << "Enter your choice: ";
}

void showTeacherMenu() {
    cout << "1. Set Timetable\n";
    cout << "2. Give Grades\n";
    cout << "3. Take Attendance\n";
    cout << "4. See Scheduled Lectures\n";
    cout << "5. Upload Course Material\n";
    cout << "6. Logout\n";
    cout << "Enter your choice: ";
}

void showStudentMenu() {
    cout << "1. Submit Complaint\n";
    cout << "2. See Course Material\n";
    cout << "3. Enrolled Courses\n";
    cout << "4. Add and Drop Courses\n";
    cout << "5. Pay Tuition Fees\n";
    cout << "6. Book Rooms for Library\n";
    cout << "7. See Timetable for classes\n";
    cout << "8. View GPA\n";
    cout << "9. See Grades\n";
    cout << "10. Logout\n";
    cout << "Enter your choice: ";
}

void signUp() {
    char username[50], password[50];
    cout << "Enter username: ";
    cin >> username;

    for (int i = 0; i < numUsers; i++) {
        if (strcmp(usernames[i], username) == 0) {
            cout << "Username already exists. Please choose another username.\n";
            return;
        }
    }

    cout << "Enter password: ";
    cin >> password;

    strcpy(usernames[numUsers], username);
    strcpy(passwords[numUsers], password);
    numUsers++;

    saveUser(username, password);
    cout << "Sign up successful. You can now login.\n";
}

void setTimetable() {
    ofstream outFile(TIMETABLE_FILE, ios::app);
    if (!outFile) {
        cerr << "Error opening timetable file." << endl;
        return;
    }

    string day;
    string pfTime, expositoryTime, dldTime;
    cout << "Enter day of the week (1-5 for Monday-Friday): ";
    cin >> day;

    cout << "Enter time for PF: ";
    cin >> pfTime;
    cout << "Enter time for Expository Writing: ";
    cin >> expositoryTime;
    cout << "Enter time for DLD: ";
    cin >> dldTime;

    outFile << "Day " << day << ":" << endl;
    outFile << "PF: " << pfTime << endl;
    outFile << "Expository Writing: " << expositoryTime << endl;
    outFile << "DLD: " << dldTime << endl;

    outFile.close();
}

void giveGrades() {
    ofstream outFile(GRADES_FILE, ios::app);
    if (!outFile) {
        cerr << "Error opening grades file." << endl;
        return;
    }

    char username[50], pfGrade[10], expositoryGrade[10], dldGrade[10];
    cout << "Enter student's username: ";
    cin >> username;

    cout << "Enter grade for PF: ";
    cin >> pfGrade;
    outFile << username << " PF: " << pfGrade << endl;

    cout << "Enter grade for Expository Writing: ";
    cin >> expositoryGrade;
    outFile << username << " Expository Writing: " << expositoryGrade << endl;

    cout << "Enter grade for DLD: ";
    cin >> dldGrade;
    outFile << username << " DLD: " << dldGrade << endl;

    outFile.close();
}

void takeAttendance() {
    ofstream outFile(ATTENDANCE_FILE, ios::app);
    if (!outFile) {
        cerr << "Error opening attendance file." << endl;
        return;
    }

    char course[50], status[10];
    cout << "Enter course (PF, Expository Writing, DLD): ";
    cin >> course;

    for (int i = 0; i < numUsers; i++) {
        if (strcmp(usernames[i], TEACHER_USERNAME) != 0) {
            cout << "Mark attendance for " << usernames[i] << " (P for present, A for absent): ";
            cin >> status;
            outFile << usernames[i] << ' ' << course << ' ' << status << endl;
        }
    }

    outFile.close();
}

void seeScheduledLectures() {
    cout << "PF: 9:30-11\n";
    cout << "DLD: 2-3:30\n";
    cout << "Expository: 3:30-5:00\n";
}

void uploadCourseMaterial() {
    ofstream outFile(COURSE_MATERIAL_FILE, ios::app);
    if (!outFile) {
        cerr << "Error opening course material file." << endl;
        return;
    }

    string material;
    cout << "Enter course material (end with a single period '.'): ";
    cin.ignore();
    while (getline(cin, material) && material != ".") {
        outFile << material << endl;
    }

    outFile.close();
}

void submitComplaint() {
    ofstream outFile(COMPLAINTS_FILE, ios::app);
    if (!outFile) {
        cerr << "Error opening complaints file." << endl;
        return;
    }

    string complaint;
    cout << "Enter your complaint: ";
    cin.ignore();
    getline(cin, complaint);

    outFile << complaint << endl;
    outFile.close();
}

void seeCourseMaterial() {
    ifstream inFile(COURSE_MATERIAL_FILE);
    if (!inFile) {
        cerr << "Error opening course material file." << endl;
        return;
    }

    string line;
    while (getline(inFile, line)) {
        cout << line << endl;
    }

    inFile.close();
}

void showEnrolledCourses() {
    char username[50];
    cout << "Enter your username: ";
    cin >> username;

    for (int i = 0; i < numUsers; i++) {
        if (strcmp(usernames[i], username) == 0) {
            cout << "Enrolled Courses: \n";
            ifstream inFile("enrolled_courses.txt");
            if (!inFile) {
                cerr << "Error opening enrolled courses file." << endl;
                return;
            }

            string line;
            while (getline(inFile, line)) {
                if (line.find(username) != string::npos) {
                    cout << line << endl;
                }
            }

            inFile.close();
            return;
        }
    }

    cout << "Username not found.\n";
}

void addAndDropCourses() {
    char username[50], course[50];
    cout << "Enter your username: ";
    cin >> username;

    for (int i = 0; i < numUsers; i++) {
        if (strcmp(usernames[i], username) == 0) {
            char choice;
            cout << "Do you want to add or drop a course? (a/d): ";
            cin >> choice;

            if (choice == 'a') {
                cout << "Enter course to add: ";
                cin >> course;

                ofstream outFile("enrolled_courses.txt", ios::app);
                if (!outFile) {
                    cerr << "Error opening enrolled courses file." << endl;
                    return;
                }

                outFile << username << ' ' << course << endl;
                outFile.close();
                cout << "Course added successfully.\n";
            } else if (choice == 'd') {
                cout << "Enter course to drop: ";
                cin >> course;

                ifstream inFile("enrolled_courses.txt");
                if (!inFile) {
                    cerr << "Error opening enrolled courses file." << endl;
                    return;
                }

                ofstream tempFile("temp.txt");
                if (!tempFile) {
                    cerr << "Error opening temporary file." << endl;
                    return;
                }

                string line;
                while (getline(inFile, line)) {
                    if (line.find(username) == string::npos || line.find(course) == string::npos) {
                        tempFile << line << endl;
                    }
                }

                inFile.close();
                tempFile.close();

                remove("enrolled_courses.txt");
                rename("temp.txt", "enrolled_courses.txt");
                cout << "Course dropped successfully.\n";
            } else {
                cout << "Invalid choice.\n";
            }
            return;
        }
    }

    cout << "Username not found.\n";
}

void payTuitionFees() {
    char username[50];
    cout << "Enter your username: ";
    cin >> username;

    ifstream inFile(FEES_FILE);
    if (!inFile) {
        cerr << "Error opening fees file." << endl;
        return;
    }

    string line;
    while (getline(inFile, line)) {
        if (line.find(username) != string::npos) {
            cout << "Tuition fees have already been paid.\n";
            inFile.close();
            return;
        }
    }

    inFile.close();

    ofstream outFile(FEES_FILE, ios::app);
    if (!outFile) {
        cerr << "Error opening fees file." << endl;
        return;
    }

    outFile << username << " Paid\n";
    outFile.close();
    cout << "Tuition fees paid successfully (RS 200,000).\n";
}

void bookRoomsForLibrary() {
    char username[50], timeslot[50];
    cout << "Enter your username: ";
    cin >> username;
    cout << "Enter time slot for library room: ";
    cin >> timeslot;

    ofstream outFile(LIBRARY_BOOKINGS_FILE, ios::app);
    if (!outFile) {
        cerr << "Error opening library bookings file." << endl;
        return;
    }

    outFile << username << ' ' << timeslot << endl;
    outFile.close();
    cout << "Library room booked successfully.\n";
}

void seeTimetableForClasses() {
    seeScheduledLectures();
}

void viewGPA() {
    cout << "GPA viewed successfully.\n";
}

void seeGrades() {
    char username[50];
    cout << "Enter your username: ";
    cin >> username;

    ifstream inFile(GRADES_FILE);
    if (!inFile) {
        cerr << "Error opening grades file." << endl;
        return;
    }

    string line;
    while (getline(inFile, line)) {
        if (line.find(username) != string::npos) {
            cout << line << endl;
        }
    }

    inFile.close();
}

void waitForUser() {
    cout << "Press Enter to continue...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
}

void login() {
    char username[50], password[50];
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    if (strcmp(username, TEACHER_USERNAME) == 0 && strcmp(password, TEACHER_PASSWORD) == 0) {
        int choice;
        do {
            showTeacherMenu();
            cin >> choice;
            switch (choice) {
                case 1:
                    setTimetable();
                    break;
                case 2:
                    giveGrades();
                    break;
                case 3:
                    takeAttendance();
                    break;
                case 4:
                    seeScheduledLectures();
                    break;
                case 5:
                    uploadCourseMaterial();
                    break;
                case 6:
                    cout << "Logged out successfully.\n";
                    break;
                default:
                    cout << "Invalid choice. Try again.\n";
                    break;
            }
            waitForUser();
        } while (choice != 6);
    } else {
        for (int i = 0; i < numUsers; i++) {
            if (strcmp(usernames[i], username) == 0 && strcmp(passwords[i], password) == 0) {
                int choice;
                do {
                    showStudentMenu();
                    cin >> choice;
                    switch (choice) {
                        case 1:
                            submitComplaint();
                            break;
                        case 2:
                            seeCourseMaterial();
                            break;
                        case 3:
                            showEnrolledCourses();
                            break;
                        case 4:
                            addAndDropCourses();
                            break;
                        case 5:
                            payTuitionFees();
                            break;
                        case 6:
                            bookRoomsForLibrary();
                            break;
                        case 7:
                            seeTimetableForClasses();
                            break;
                        case 8:
                            viewGPA();
                            break;
                        case 9:
                            seeGrades();
                            break;
                        case 10:
                            cout << "Logged out successfully.\n";
                            break;
                        default:
                            cout << "Invalid choice. Try again.\n";
                            break;
                    }
                    waitForUser();
                } while (choice != 10);
                return;
            }
        }
        cout << "Invalid username or password. Try again.\n";
    }
}

int main() {
    loadUsers();

    int choice;
    do {
        showMainMenu();
        cin >> choice;
        switch (choice) {
            case 1:
                login();
                break;
            case 2:
                signUp();
                break;
            case 3:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
                break;
        }
    } while (choice != 3);

    return 0;
}
