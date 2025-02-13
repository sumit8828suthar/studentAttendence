#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <ctime>
#include <vector>

using namespace std;

//getting date
string getDate()
{
    time_t now = time(0);
    tm *ltm = localtime(&now);
    int year = 1900 + ltm->tm_year;
    int month = 1 + ltm->tm_mon;
    int day = ltm->tm_mday;

    stringstream date;
    date << year << "-" << (month < 10 ? "0" : "") << month << "-" << (day < 10 ? "0" : "") << day;

    return date.str();
}


//implementing different user
class User
{
protected:
    string userName;
    string password;

public:
    virtual bool login() = 0;
};

class Admin : public User
{
public:
    Admin(string userName, string password)
    {
        this->userName = userName;
        this->password = password;
    }

    bool login() override
    {
        if (userName == "Admin" && password == "hello123")
        {
            cout << endl << "Admin Login Successful!" << endl;
            return true;
        }
        cout << endl << "Invalid Admin Credentials." << endl;
        return false;
    }

    void addStudent()
    {
        ofstream file("students.csv", ios::app);
        if (file.tellp() == 0) {
            file << "Student ID,Student Name,Attendance Status,Last date\n";
        }
        string stuID, stuName;

        cout << "Enter Student ID: ";
        cin >> stuID;
        cin.ignore();  // To ignore any remaining newline character from previous input
        cout << "Enter Student Name: ";
        getline(cin, stuName);  // Use getline to capture full names with spaces

        file << stuID << "," << stuName << ",0,N/A\n";
        file.close();

        cout << "Student added successfully!" << endl;
    }
};

int main()
{
    int choice;
    string username, password;

    cout << "1. Admin Login\n2. Student Login\n";
    cin >> choice;

    cout << "Enter Username: ";
    cin >> username;
    cout << "Enter Password: ";
    cin >> password;

    if (choice == 1)
    {
        Admin admin(username, password);
        if (admin.login()||1)
        {
            int adminChoice;
            cout << "1. Add Student\n2. Mark Attendance\n3. View Attendance\n";
            cin >> adminChoice;

            if (adminChoice == 1)
            {
                admin.addStudent();
            }
            // else if (adminChoice == 2) {
            //     admin.markAttendance();
            // } else if (adminChoice == 3) {
            //     admin.viewAttendance();
            // }
        }
    }
    // else if (choice == 2) {
    //     Student student(username, password);
    //     if (student.login()) {
    //         student.viewAttendance();
    //     }
    // }

    return 0;
}
