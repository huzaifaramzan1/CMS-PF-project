#include <iostream>

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
    // Add more user-related data as needed
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
    newUser.loggedIn = true; // Automatically logged in after sign-up
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

void logout(string username) {
    int userIndex = findUserIndex(username);
    if (userIndex != -1) {
        users[userIndex].loggedIn = false;
        cout << "Logged out successfully." << endl;
    }
}

void submitComplaint(string username, string message) {
    if (numComplaints < MAX_COMPLAINTS) {
        complaints[numComplaints].username = username;
        complaints[numComplaints].message = message;
        numComplaints++;
        cout << "Complaint submitted successfully." << endl;
    } else {
        cout << "Maximum number of complaints reached. Cannot submit complaint." << endl;
    }
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

void showStudentMenu() {
    cout << "Welcome to Student Menu" << endl;
    cout << "1. See Course Material" << endl;
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
                break;
            case 4:
                cout << "Pay Tuition Fees" << endl;
                break;
            case 5:
                cout << "Book Rooms for Library" << endl;
                break;
            case 6:
                cout << "See Timetable for Classes" << endl;
                break;
            case 7:
                cout << "View GPA" << endl;
                break;
            case 8:
                cout << "See Grades" << endl;
                break;
            case 9:
                {
                    string complaintMessage;
                    cout << "Enter your complaint: ";
                    cin.ignore(); // Clear the input buffer
                    getline(cin, complaintMessage);
                    submitComplaint(username, complaintMessage);
                    cout << "Press Enter to return to the menu...";
                    cin.ignore();
                    cin.get();
                    break;
                }
            case 10:
                logout(username);
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
        if (choice != 10 && choice != 9) {
            cout << "Press Enter to return to the menu...";
            cin.ignore();
            cin.get();
        }
    } while (choice != 10);
}

int main() {
    // Predefined student accounts
    User student1 = {"student1", "password1", false, {"PF", "DLD", "Expository Writing", "Stats and Probability", "DLD Lab"}, 5};
    User student2 = {"student2", "password2", false, {"PF", "DLD", "Expository Writing", "Stats and Probability", "DLD Lab"}, 5};
    User student3 = {"student3", "password3", false, {"PF", "DLD", "Expository Writing", "Stats and Probability", "DLD Lab"}, 5};
    User student4 = {"student4", "password4", false, {"PF", "DLD", "Expository Writing", "Stats and Probability", "DLD Lab"}, 5};

    // Predefined teacher account
    User teacher = {"teacher", "teacherpassword", false, {}, 0};

    // Add predefined users to the user array
    users[numUsers++] = student1;
    users[numUsers++] = student2;
    users[numUsers++] = student3;
    users[numUsers++] = student4;
    users[numUsers++] = teacher;

    char userType;

    cout << "Are you a new user? (Enter 'Y' for Yes, 'N' for No): ";
    cin >> userType;

    if (userType == 'Y') {
        signUp();
    }

    cout << "Are you a teacher or a student? (Enter 'T' for teacher, 'S' for student): ";
    cin >> userType;

    switch (userType) {
        case 'T':
            {
                string username, password;
                cout << "Enter username: ";
                cin >> username;
                cout << "Enter password: ";
                cin >> password;

                if (login(username, password)) {
                    cout << "Login successful. Welcome, " << username << "!" << endl;
                    // Provide access to teacher menu (not implemented yet)
                } else {
                    cout << "Incorrect username or password. Access denied." << endl;
                }
                break;
            }
        case 'S':
            {
                string username, password;
                cout << "Enter username: ";
                cin >> username;
                cout << "Enter password: ";
                cin >> password;

                if (login(username, password)) {
                    cout << "Login successful. Welcome, " << username << "!" << endl;
                    studentMenu(username);
                } else {
                    cout << "Incorrect username or password. Access denied." << endl;
                }
                break;
            }
        default:
            cout << "Invalid input. Please enter 'T' for teacher or 'S' for student." << endl;
    }

    return 0;
}
