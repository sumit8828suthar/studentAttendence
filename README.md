
# Student Attendance Management System (C++)


This is a Student Attendance Management System where an admin can control student attendance and students can check their attendance records. Students' data and attendance are stored in CSV files, and the system features both admin and student login.


## Features


Admin Login: Admin can log in and operate on students, such as adding new students, taking attendance, and viewing attendance reports.

Student Login: Students can log in to see their own attendance.

Attendance Management:
Admin can take attendance for a particular student or loop through all students.
The date is stored along with the attendance count for each student.

CSV Storage:
Student information (ID, Name, Attendance Count, Last Attendance Date) is stored in a CSV file.
Login credentials (password and username) are kept in a standalone CSV file as well.

File Structure
main.cpp: Primary file with the system implementation.

students.csv: CSV file used to store the student 
records. Each row includes:

Student ID, Student Name, Attendance Count, Last Attendance Date.

Admin Login:
Enter 1 on being asked to login.
Input the admin password and username (kept in users.csv).
Once logged in successfully, you can:
Add new students to the system.
Mark attendance for specific students or all students.
View all attendance records.

Student Login:
Press 2 when asked to login.
Input the student username and password (saved in users.csv).
Students can see their own attendance details (ID, Name, Attendance Count, Last Attendance Date) after successful login.
Admin Functionalities


Add Student:
Admin can add new students to the system by inputting the Student ID and Name.
The new student information is maintained in students.csv having an initial attendance of 0 and N/A for the last attend date.

Mark Attendance:
Admin may opt to mark attendance for a single student by providing their ID.
Or the admin may loop through all students and mark attendance for all of them, incrementing the attendance count and last attend date for each student.

View Attendance:
Admin can see all attendance records, student ID, name, attendance count, and the last date attended.
Student Functionalities

View Attendance:
Students can login with their credentials and see their own attendance record, their total attendance count, and the last date they were present.

CSV File Structure

students.csv:
StudentID,StudentName,AttendanceCount,LastAttendanceDate
101,John Doe,5,2025-02-12
102,Jane Smith,3,2025-02-10
