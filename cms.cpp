#include <iostream>

using namespace std;

int main() {
    char userType;

   
    cout << "Are you a teacher or a student? (Enter 'T' for teacher, 'S' for student): ";
    cin >> userType;

    switch (userType) {
        case 'T':
            {
                
                string teacherUsername = "teacher123";
                string teacherPassword = "password123";
                string username, password;

                cout << "Enter username: ";
                cin >> username;
                cout << "Enter password: ";
                cin >> password;

                if (username == teacherUsername && password == teacherPassword) {
                    cout << "Login successful. Welcome, teacher!" << endl;
                    
                } else {
                    cout << "Incorrect username or password. Access denied." << endl;
                }
                break;
            }
        case 'S':
            {
             
                string studentUsername1 = "student1";
                string studentPassword1 = "pass1";
                string studentUsername2 = "student2";
                string studentPassword2 = "pass2";
                string username, password;

                cout << "Enter username: ";
                cin >> username;
                cout << "Enter password: ";
                cin >> password;

                if ((username == studentUsername1 && password == studentPassword1) ||
                    (username == studentUsername2 && password == studentPassword2)) {
                    cout << "Login successful. Welcome, student!" << endl;
                    
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
