#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

struct Student {
    int rollNumber;
    std::string name;
    std::string course;
    float grade;
};

void addStudent(std::vector<Student>& students);
void viewStudents(const std::vector<Student>& students);
void updateStudent(std::vector<Student>& students);
void deleteStudent(std::vector<Student>& students);
void loadStudents(std::vector<Student>& students, const std::string& filename);
void saveStudents(const std::vector<Student>& students, const std::string& filename);

int main() {
    std::vector<Student> students;
    std::string filename = "students.txt";
    int choice;

    loadStudents(students, filename);

    do {
        std::cout << "\nStudent Record Management System\n";
        std::cout << "1. Add Student\n";
        std::cout << "2. View Students\n";
        std::cout << "3. Update Student\n";
        std::cout << "4. Delete Student\n";
        std::cout << "5. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        std::cin.ignore(); // Clear the newline character from the buffer

        switch (choice) {
            case 1:
                addStudent(students);
                break;
            case 2:
                viewStudents(students);
                break;
            case 3:
                updateStudent(students);
                break;
            case 4:
                deleteStudent(students);
                break;
            case 5:
                saveStudents(students, filename);
                std::cout << "Exiting...\n";
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
                break;
        }
    } while (choice != 5);

    return 0;
}

void addStudent(std::vector<Student>& students) {
    Student newStudent;
    std::cout << "Enter roll number: ";
    std::cin >> newStudent.rollNumber;
    std::cin.ignore();
    std::cout << "Enter name: ";
    std::getline(std::cin, newStudent.name);
    std::cout << "Enter course: ";
    std::getline(std::cin, newStudent.course);
    std::cout << "Enter grade: ";
    std::cin >> newStudent.grade;
    std::cin.ignore();
    students.push_back(newStudent);
    std::cout << "Student added successfully.\n";
}

void viewStudents(const std::vector<Student>& students) {
    if (students.empty()) {
        std::cout << "No student records available.\n";
    } else {
        for (const auto& student : students) {
            std::cout << "Roll Number: " << student.rollNumber << "\n";
            std::cout << "Name: " << student.name << "\n";
            std::cout << "Course: " << student.course << "\n";
            std::cout << "Grade: " << student.grade << "\n";
            std::cout << "-----------------------------\n";
        }
    }
}

void updateStudent(std::vector<Student>& students) {
    int rollNumber;
    std::cout << "Enter roll number of the student to update: ";
    std::cin >> rollNumber;
    std::cin.ignore();

    bool found = false;
    for (auto& student : students) {
        if (student.rollNumber == rollNumber) {
            found = true;
            std::cout << "Enter new name: ";
            std::getline(std::cin, student.name);
            std::cout << "Enter new course: ";
            std::getline(std::cin, student.course);
            std::cout << "Enter new grade: ";
            std::cin >> student.grade;
            std::cin.ignore();
            std::cout << "Student record updated successfully.\n";
            break;
        }
    }

    if (!found) {
        std::cout << "Student with roll number " << rollNumber << " not found.\n";
    }
}

void deleteStudent(std::vector<Student>& students) {
    int rollNumber;
    std::cout << "Enter roll number of the student to delete: ";
    std::cin >> rollNumber;
    std::cin.ignore();

    auto it = std::remove_if(students.begin(), students.end(), [rollNumber](const Student& student) {
        return student.rollNumber == rollNumber;
    });

    if (it != students.end()) {
        students.erase(it, students.end());
        std::cout << "Student record deleted successfully.\n";
    } else {
        std::cout << "Student with roll number " << rollNumber << " not found.\n";
    }
}

void loadStudents(std::vector<Student>& students, const std::string& filename) {
    std::ifstream inFile(filename);
    if (inFile.is_open()) {
        Student student;
        while (inFile >> student.rollNumber) {
            inFile.ignore(); // Ignore newline after roll number
            std::getline(inFile, student.name);
            std::getline(inFile, student.course);
            inFile >> student.grade;
            inFile.ignore(); // Ignore newline after grade
            students.push_back(student);
        }
        inFile.close();
    } else {
        std::cout << "Could not open file " << filename << " for reading.\n";
    }
}

void saveStudents(const std::vector<Student>& students, const std::string& filename) {
    std::ofstream outFile(filename);
    if (outFile.is_open()) {
        for (const auto& student : students) {
            outFile << student.rollNumber << "\n";
            outFile << student.name << "\n";
            outFile << student.course << "\n";
            outFile << student.grade << "\n";
        }
        outFile.close();
    } else {
        std::cout << "Could not open file " << filename << " for writing.\n";
    }
}
