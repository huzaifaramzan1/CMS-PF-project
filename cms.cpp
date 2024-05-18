#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;

const int MAX_USERS = 100;
const int MAX_COMPLAINTS = 100;
const int MAX_COURSES = 10;

struct User {
    string username;
    string password;
    bool loggedIn;
    string enrolledCourses[MAX_COURSES];
    int numEnrolledCourses;
    string grades[MAX_COURSES];
    float gpa;
    int fee;
};

struct Complaint {
    string username;
    string message;
};

int numUsers = 0;
User users[MAX_USERS];

Complaint complaints[MAX_COMPLAINTS];
int numComplaints = 0;

int findUserIndex(string username) {
    for (int i = 0; i < numUsers; ++i) {
        if (users[i].username == username) {
            return i;
        }
    }
    return -1;
}

void signUp() {
    if (numUsers >= MAX_USERS) {
        cout << "Maximum number of users reached. Cannot sign up." << endl;
        return;
    }

    User newUser;
    cout << "Enter username: ";
    cin >> newUser.username;
    cout << "Enter password: ";
    cin >> newUser.password;
    newUser.loggedIn = true;
    newUser.numEnrolledCourses = 0;

    users[numUsers++] = newUser;

    cout << "Sign up successful. Welcome, " << newUser.username << "!" << endl;
}

bool login(string username, string password) {
    int userIndex = findUserIndex(username);
    if (userIndex != -1 && users[userIndex].password == password) {
        users[userIndex].loggedIn = true;
        return true;
    }
    return false;
}

void showEnrolledCourses(string username) {
    int userIndex = findUserIndex(username);
    if (userIndex != -1) {
        cout << "Enrolled Courses:" << endl;
        for (int i = 0; i < users[userIndex].numEnrolledCourses; ++i) {
            cout << users[userIndex].enrolledCourses[i] << endl;
        }
    }
}

void addDrop() {
    // Implementation for adding and dropping courses
}

void fee() {
    char pay;
    cout << "Your Fee is: 200,000" << endl << "Do you want to pay ('Y' for yes 'N' for no): ";
    cin >> pay;
    int accno;
    switch (pay) {
        case 'Y':
        case 'y':
            cout << "Enter your account no.: ";
            cin >> accno;
            if (accno > 0) {
                cout << "Your fee is deducted from your account" << endl;
            } else {
                cout << "Try again" << endl;
            }
            break;
        case 'N':
        case 'n':
            cout << "Pay fee on time otherwise a fine will be sent to you!" << endl;
            break;
        default:
            cout << "Enter a valid character" << endl;
            break;
    }
}

void libRoom() {
    int timeChoice;
    int roomChoice;
    bool roomsFree[3] = {false, false, false};
    bool anyRoomFree = false; // Move initialization here

    cout << "Which time do you want to book a library room:" << endl;
    cout << "1. 12:00 to 2:00 pm" << endl
         << "2. 2:00 to 4:00 pm" << endl
         << "3. 4:00 to 6:00 pm" << endl;
    cin >> timeChoice;

    switch (timeChoice) {
        case 1:
        case 2:
        case 3:
            for (int i = 0; i < 3; ++i) {
                if (rand() % 2 == 0) {
                    cout << (i+1) << ". Room " << (i+1) << " is free" << endl;
                    roomsFree[i] = true;
                } else {
                    cout << (i+1) << ". Room " << (i+1) << " is reserved" << endl;
                }
            }

            for (int i = 0; i < 3; ++i) {
                if (roomsFree[i]) {
                    anyRoomFree = true;
                    break;
                }
            }

            if (anyRoomFree) {
                cout << "Type the number of the room you want to book: ";
                cin >> roomChoice;

                if (roomChoice >= 1 && roomChoice <= 3 && roomsFree[roomChoice-1]) {
                    cout << "Room " << roomChoice << " is booked successfully" << endl;
                } else {
                    cout << "Invalid room choice or room is not free" << endl;
                }
            } else {
                cout << "No room is available" << endl;
            }
            break;
        default:
            cout << "Invalid time choice" << endl;
            break;
    }
}

void timetable(int day) {
    cout << "(Type '1' for Monday, '2' for Tuesday, '3' for Wednesday, '4' for Thursday, '5' for Friday) Enter day for timetable: ";
    cin >> day;
    switch (day) {
        case 1:
            cout << "9:30 am to 11:00 is PF" << endl;
            cout << "11:00 am to 12:30 is break" << endl;
            cout << "12:30 pm to 2:00 is break" << endl;
            cout << "2:00 pm to 3:30 is FIT" << endl;
            cout << "3:30 pm to 5:00 is FIT" << endl;
            break;
        case 2:
            cout << "9:30 am to 11:00 is break" << endl;
            cout << "11:00 am to 12:30 is Expository writing" << endl;
            cout << "12:30 pm to 2:00 is break" << endl;
            cout << "2:00 pm to 3:30 is Probability and Stats" << endl;
            cout << "3:30 pm to 5:00 is DLD Lab" << endl;
            break;
        case 3:
            cout << "9:30 am to 11:00 is PF" << endl;
            cout << "11:00 am to 12:30 is break" << endl;
            cout << "12:30 pm to 2:00 is break" << endl;
            cout << "2:00 pm to 3:30 is break" << endl;
            cout << "3:30 pm to 5:00 is break" << endl;
            break;
        case 4:
            cout << "9:30 am to 11:00 is DLD" << endl;
            cout << "11:00 am to 12:30 is Expository writing" << endl;
            cout << "12:30 pm to 2:00 is break" << endl;
            cout << "2:00 pm to 3:30 is Probability and Stats" << endl;
            cout << "3:30 pm to 5:00 is DLD Lab" << endl;
            break;
        case 5:
            cout << "9:30 am to 11:00 is PF" << endl;
            cout << "11:00 am to 12:30 is break" << endl;
            cout << "12:30 pm to 2:00 is break" << endl;
            cout << "2:00 pm to 3:30 is FIT" << endl;
            cout << "3:30 pm to 5:00 is FIT" << endl;
            break;
        default:
            cout << "Enter valid day" << endl;
    }
}

void gpa(string username) {
    int userIndex = findUserIndex(username);
    if (userIndex != -1) {
        cout << "Your GPA is: " << users[userIndex].gpa << endl;
    }
}

void grades(string username) {
    int userIndex = findUserIndex(username);
    if (userIndex != -1) {
        cout << "Your Grades are: " << endl;
        for (int i = 0; i < users[userIndex].numEnrolledCourses; ++i) {
            cout << users[userIndex].grades[i] << endl;
        }
    }
}

void submitComplaint(string username, string message) {
    if (numComplaints < MAX_COMPLAINTS) {
        complaints[numComplaints].username = username;
        complaints[numComplaints].message = message;
        ++numComplaints;
        cout << "Complaint submitted successfully." << endl;
    } else {
        cout << "Maximum number of complaints reached. Cannot submit complaint." << endl;
    }
}

void logout(string username) {
    int userIndex = findUserIndex(username);
    if (userIndex != -1) {
        users[userIndex].loggedIn = false;
    }
    cout << "Logged out successfully." << endl;
}

void showStudentMenu() {
    cout << "1. Course Material" << endl;
    cout << "2. Enrolled Courses" << endl;
    cout << "3. Add and Drop Courses" << endl;
    cout << "4. Pay Tuition Fees" << endl;
    cout << "5. Book Rooms for Library" << endl;
    cout << "6. See Timetable for Classes" << endl;
    cout << "7. View GPA" << endl;
    cout << "8. See Grades" << endl;
    cout << "9. Submit Complaint" << endl;
    cout << "10. Logout" << endl;
}

void studentMenu(string username) {
    int choice;
    srand(static_cast<unsigned int>(time(0)));
    int day;
    do {
        showStudentMenu();
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Course Material" << endl;
                cout << "PF: Book1" << endl;
                cout << "DLD: Book1" << endl;
                cout << "Expository Writing: Book1" << endl;
                cout << "Stats and Probability: Book1" << endl;
                cout << "DLD Lab: Book1" << endl;
                break;
            case 2:
                showEnrolledCourses(username);
                break;
            case 3:
                cout << "Add and Drop Courses" << endl;
                addDrop();
                break;
            case 4:
                cout << "Pay Tuition Fees" << endl;
                fee();
                break;
            case 5:
                cout << "Book Rooms for Library" << endl;
                libRoom();
                break;
            case 6:
                cout << "See Timetable for Classes" << endl;
                timetable(day);
                break;
            case 7:
                cout << "View GPA" << endl;
                gpa(username);
                break;
            case 8:
                cout << "See Grades" << endl;
                grades(username);
                break;
            case 9: {
                string complaintMessage;
                cout << "Enter your complaint: ";
                cin.ignore();
                getline(cin, complaintMessage);
                submitComplaint(username, complaintMessage);
                cout << "Press Enter to return to the menu...";
                cin.ignore();
                cin.get();
                break;
            }
            case 10:
                logout(username);
                return;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
        if (choice != 10 && choice != 9) {
            cout << "Press Enter to return to the menu...";
            cin.ignore();
            cin.get();
        }
    } while (true);
}

void setTimetable() {
    int day;
    cout << "View teacher Timetable" << endl;
    timetable(day);
}

void giveGrades() {
    string username;
    int userIndex;
    cout << "Enter student's username to give grades: ";
    cin >> username;
    userIndex = findUserIndex(username);
    if (userIndex != -1) {
        for (int i = 0; i < users[userIndex].numEnrolledCourses; ++i) {
            cout << "Enter grade for " << users[userIndex].enrolledCourses[i] << ": ";
            cin >> users[userIndex].grades[i];
        }
        cout << "Grades updated successfully." << endl;
    } else {
        cout << "Student not found." << endl;
    }
}

void takeAttendance() {
    cout << "Attendance taken for all students." << endl;
}

void seeScheduledLectures() {
    cout << "Scheduled Lectures:" << endl;
    timetable(0); // Assuming the same timetable function to show the schedule
}

void uploadCourseMaterial() {
    string CM;
    cout << "Enter course material below: \n"<< endl;
    cin>>CM;
    cout<<"Course material has been added: \n"<<CM<<endl;
}

void showTeacherMenu() {
    cout << "Welcome to Teacher Menu" << endl;
    cout << "1. View teacher Timetable" << endl;
    cout << "2. Give Grades" << endl;
    cout << "3. Take Attendance" << endl;
    cout << "4. See Scheduled Lectures" << endl;
    cout << "5. Upload Course Material" << endl;
    cout << "6. Logout" << endl;
}

void teacherMenu(string username) {
    int choice;
    do {
        showTeacherMenu();
        cout << "Enter your choice: ";
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
                logout(username);
                return;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
        if (choice != 6) {
            cout << "Press Enter to return to the menu...";
            cin.ignore();
            cin.get();
        }
    } while (true);
}

int main() {
    // Predefined student accounts
    User student1 = {"student1", "password1", false, {"PF", "DLD", "Expository Writing", "Stats and Probability", "DLD Lab"}, 5, {"PF = A", "DLD = B", "Expository Writing  = D+", "Stats = A-", "DLD Lab = A"}, 3.1};
    User student2 = {"student2", "password2", false, {"PF", "DLD", "Expository Writing", "Stats and Probability", "DLD Lab"}, 5, {"PF = B", "DLD = A", "Expository Writing  = C+", "Stats = A-", "DLD Lab = A+"}, 3.2};
    User student3 = {"student3", "password3", false, {"PF", "DLD", "Expository Writing", "Stats and Probability", "DLD Lab"}, 5, {"PF = C", "DLD = B", "Expository Writing  = A+", "Stats = C-", "DLD Lab = B+"}, 2.8};
    User student4 = {"student4", "password4", false, {"PF", "DLD", "Expository Writing", "Stats and Probability", "DLD Lab"}, 5, {"PF = A+", "DLD = A", "Expository Writing  = A+", "Stats = A-", "DLD Lab = A+"}, 3.85};

    // Predefined teacher account
    User teacher = {"teacher", "teacherpassword", false, {}, 0};

    // Add predefined users to the user array
    users[numUsers++] = student1;
    users[numUsers++] = student2;
    users[numUsers++] = student3;
    users[numUsers++] = student4;
    users[numUsers++] = teacher;

    char userType;

    do {
        cout << "Are you a new user? (Enter 'Y' for Yes, 'N' for No): ";
        cin >> userType;

        if (userType == 'Y' || userType == 'y') {
            signUp();
        }

        cout << "Are you a teacher or a student? (Enter 'T' for teacher, 'S' for student): ";
        cin >> userType;

        string username, password;
        cout << "Enter username: ";
        cin >> username;
        cout << "Enter password: ";
        cin >> password;

        if (login(username, password)) {
            if (userType == 'T' || userType == 't') {
                teacherMenu(username);
            } else if (userType == 'S' || userType == 's') {
                studentMenu(username);
            }
        } else {
            cout << "Invalid username or password." << endl;
        }

        cout << "Do you want to exit the CMS? (Enter 'Y' for Yes, 'N' for No): ";
        cin >> userType;

    } while (userType == 'N' || userType == 'n');

    cout << "Thank you for using the Campus Management System." << endl;
    return 0;
}
