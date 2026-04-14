// ============================================================
// Lab W7: C++ OOP Review - Classes, Encapsulation, Strings,
//         Copy Constructors, Operator Overloading
// Course: Object-Oriented Programming
// Duration: 40 minutes
// ============================================================
// TEACHER VERSION - Complete Solution
// ============================================================

#include <iostream>
#include <string>
#include <cstring>
using namespace std;

// ================================
// CLASS DEFINITIONS
// ================================

class Student {
private:
    string name;
    int id;
    double gpa;

public:
    // ----- Task 1: Constructors & Destructor -----

    // 1a: Default constructor
    Student() {
        name = "Unknown";
        id = 0;
        gpa = 0.0;
    }

    // 1b: Parameterized constructor
    Student(string n, int i, double g) {
        name = n;
        id = i;
        gpa = g;
    }

    // 1c: Copy constructor
    Student(const Student& other) {
        name = other.name;
        id = other.id;
        gpa = other.gpa;
    }

    // 1d: Destructor
    ~Student() {
        cout << "Student " << name << " destroyed" << endl;
    }

    // ----- Task 2: Getters (Encapsulation) -----

    // 2a: Getter for name
    string getName() const {
        return name;
    }

    // 2b: Getter for id
    int getId() const {
        return id;
    }

    // 2c: Getter for gpa
    double getGpa() const {
        return gpa;
    }

    // ----- Task 3: Setters with Validation -----

    // 3a: Setter for name
    void setName(string n) {
        if (!n.empty()) {
            name = n;
        }
    }

    // 3b: Setter for GPA
    void setGpa(double g) {
        if (g >= 0.0 && g <= 4.0) {
            gpa = g;
        }
    }

    // ----- Task 4: String Operation -----

    // 4: getFormattedName() - returns name in uppercase
    string getFormattedName() const {
        string upper = name;
        for (size_t i = 0; i < upper.length(); i++) {
            upper[i] = toupper(upper[i]);
        }
        return upper;
    }

    // ----- Task 5: Operator Overloading -----

    // 5a: Equality operator
    bool operator==(const Student& other) const {
        return id == other.id;
    }

    // 5b: Less-than operator
    bool operator<(const Student& other) const {
        return gpa < other.gpa;
    }

    // 5c: Stream insertion operator
    friend ostream& operator<<(ostream& os, const Student& s) {
        os << "Student(" << s.name << ", ID: " << s.id << ", GPA: " << s.gpa << ")";
        return os;
    }
};

// ================================
// STANDALONE FUNCTION
// ================================

// Function Overloading - findBestStudent
// Version 1: Two students
Student findBestStudent(const Student& a, const Student& b) {
    if (b < a) {
        return a;
    }
    return b;
}

// Version 2: Array of students
Student findBestStudent(Student arr[], int size) {
    Student best = arr[0];
    for (int i = 1; i < size; i++) {
        if (best < arr[i]) {
            best = arr[i];
        }
    }
    return best;
}

// ================================
// MAIN FUNCTION
// ================================
int main() {
    // --- Demo: Default Constructor ---
    Student s1;
    cout << "Default: " << s1 << endl;

    // --- Demo: Parameterized Constructor ---
    Student s2("Ali", 101, 3.5);
    Student s3("Ayse", 102, 3.8);
    cout << "s2: " << s2 << endl;
    cout << "s3: " << s3 << endl;

    // --- Demo: Copy Constructor ---
    Student s4(s2);
    cout << "Copy of s2: " << s4 << endl;

    // --- Demo: Encapsulation (Getters) ---
    cout << "s3 name: " << s3.getName() << endl;
    cout << "s3 GPA: " << s3.getGpa() << endl;

    // --- Demo: Setter Validation ---
    s2.setGpa(5.0);  // Invalid, should not change
    cout << "s2 after invalid setGpa(5.0): " << s2 << endl;

    s2.setGpa(3.9);  // Valid
    cout << "s2 after valid setGpa(3.9): " << s2 << endl;

    // --- Demo: String Operation ---
    cout << "Formatted: " << s3.getFormattedName() << endl;

    // --- Demo: Operator Overloading ---
    cout << "s2 == s4? " << (s2 == s4 ? "Yes" : "No") << endl;
    cout << "s2 < s3? " << (s2 < s3 ? "Yes" : "No") << endl;

    // --- Demo: Function Overloading ---
    Student best2 = findBestStudent(s2, s3);
    cout << "Best of two: " << best2 << endl;

    Student roster[] = {s1, s2, s3, s4};
    Student bestAll = findBestStudent(roster, 4);
    cout << "Best of all: " << bestAll << endl;

    return 0;
}
