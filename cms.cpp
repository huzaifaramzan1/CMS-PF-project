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

int findComplaintIndex(string username) {
    for (int i = 0; i < numComplaints; ++i) {
        if (complaints[i].username == username) {
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

void logout(string username) {
    int userIndex = findUserIndex(username);
    if (userIndex != -1) {
        users[userIndex].loggedIn = false;
        cout << "Logged out successfully." << endl;
    }
}

void deleteAccount(string username) {
    int userIndex = findUserIndex(username);
    if (userIndex != -1) {
        for (int i = userIndex; i < numUsers - 1; ++i) {
            users[i] = users[i + 1];
        }
        numUsers--;

        int complaintIndex = findComplaintIndex(username);
        while (complaintIndex != -1) {
            for (int i = complaintIndex; i < numComplaints - 1; ++i) {
                complaints[i] = complaints[i + 1];
            }
            numComplaints--;
            complaintIndex = findComplaintIndex(username);
        }

        cout << "Account deleted successfully." << endl;
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

void showMenu(string username) {
    cout << "Welcome, " << username << "!" << endl;
    cout << "1. Submit Complaint" << endl;
    cout << "2. Logout" << endl;
    
}

int main() {
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
        case 'S':
            {
                string username, password;
                cout << "Enter username: ";
                cin >> username;
                cout << "Enter password: ";
                cin >> password;

                if (login(username, password)) {
                    showMenu(username); 
                    int choice;
                    cin >> choice;
                    switch (choice) {
                        case 1:
                            {
                                string complaintMessage;
                                cout << "Enter your complaint: ";
                                cin.ignore();
                                getline(cin, complaintMessage);
                                submitComplaint(username, complaintMessage);
                                break;
                            }
                        case 2:
                            logout(username);
                            break;
                        default:
                            cout << "Invalid choice." << endl;
                    }
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
