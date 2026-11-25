#include <iostream>
#include <string>
#include <limits>
using namespace std;

struct Student
{
    int rollNo;
    string name;
    int age;
    string course;

    Student* next;
    Student* hashNext;
};

Student* head = NULL;

const int SIZE = 10;
Student* hashTable[SIZE] = {NULL};

// Hash Function
int hashFunction(int rollNo)
{
    return rollNo % SIZE;
}

// Register Student
void registerStudent()
{
    Student* s = new Student;

    cout << "Enter Student Roll Number: ";
    cin >> s->rollNo;

    int index = hashFunction(s->rollNo);

    Student* temp = hashTable[index];

    // Check Duplicate Roll Number
    while (temp != NULL)
    {
        if (temp->rollNo == s->rollNo)
        {
            cout << "Roll Number already exists!\n";
            delete s;
            return;
        }

        temp = temp->hashNext;
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Enter Student Name: ";
    getline(cin, s->name);

    cout << "Enter Student Age: ";
    cin >> s->age;

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Enter Course Name: ";
    getline(cin, s->course);

    // Insert into Linked List
    s->next = head;
    head = s;

    // Insert into Hash Table
    s->hashNext = hashTable[index];
    hashTable[index] = s;

    cout << "Student registered successfully!\n";
}

// Search Student
void searchStudent()
{
    int rollNo;

    cout << "Enter Roll Number to search: ";
    cin >> rollNo;

    int index = hashFunction(rollNo);

    Student* temp = hashTable[index];

    while (temp != NULL)
    {
        if (temp->rollNo == rollNo)
        {
            cout << "\nStudent Found!\n";
            cout << "Roll Number: " << temp->rollNo << endl;
            cout << "Student Name: " << temp->name << endl;
            cout << "Age: " << temp->age << endl;
            cout << "Course: " << temp->course << endl;
            return;
        }

        temp = temp->hashNext;
    }

    cout << "Student not found!\n";
}

// Update Student Information
void updateStudent()
{
    int rollNo;

    cout << "Enter Roll Number to update: ";
    cin >> rollNo;

    int index = hashFunction(rollNo);

    Student* temp = hashTable[index];

    while (temp != NULL)
    {
        if (temp->rollNo == rollNo)
        {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            cout << "Enter New Student Name: ";
            getline(cin, temp->name);

            cout << "Enter New Age: ";
            cin >> temp->age;

            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            cout << "Enter New Course Name: ";
            getline(cin, temp->course);

            cout << "Student information updated successfully!\n";
            return;
        }

        temp = temp->hashNext;
    }

    cout << "Student not found!\n";
}

// Enroll Student in Course
void enrollCourse()
{
    int rollNo;

    cout << "Enter Student Roll Number: ";
    cin >> rollNo;

    int index = hashFunction(rollNo);

    Student* temp = hashTable[index];

    while (temp != NULL)
    {
        if (temp->rollNo == rollNo)
        {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            cout << "Enter New Course Name: ";
            getline(cin, temp->course);

            cout << "Student enrolled in course successfully!\n";
            return;
        }

        temp = temp->hashNext;
    }

    cout << "Student not found!\n";
}

// Remove Student
void removeStudent()
{
    int rollNo;

    cout << "Enter Roll Number to remove: ";
    cin >> rollNo;

    int index = hashFunction(rollNo);

    // Search in Hash Table
    Student* temp = hashTable[index];
    Student* prev = NULL;

    while (temp != NULL && temp->rollNo != rollNo)
    {
        prev = temp;
        temp = temp->hashNext;
    }

    if (temp == NULL)
    {
        cout << "Student not found!\n";
        return;
    }

    // Delete from Hash Table
    if (prev == NULL)
    {
        hashTable[index] = temp->hashNext;
    }
    else
    {
        prev->hashNext = temp->hashNext;
    }

    // Delete from Linked List
    if (head == temp)
    {
        head = temp->next;
    }
    else
    {
        Student* current = head;

        while (current != NULL && current->next != temp)
        {
            current = current->next;
        }

        if (current != NULL)
        {
            current->next = temp->next;
        }
    }

    delete temp;

    cout << "Student removed successfully!\n";
}

// Display All Students
void displayStudents()
{
    Student* temp = head;

    if (temp == NULL)
    {
        cout << "No students registered!\n";
        return;
    }

    cout << "\n----- STUDENT RECORDS -----\n";

    while (temp != NULL)
    {
        cout << "\nRoll Number: " << temp->rollNo << endl;
        cout << "Student Name: " << temp->name << endl;
        cout << "Age: " << temp->age << endl;
        cout << "Course: " << temp->course << endl;

        temp = temp->next;
    }
}

// Main Function
int main()
{
    int choice;

    do
    {
        cout << "\n===== UNIVERSITY STUDENT MANAGEMENT SYSTEM =====\n";

        cout << "1. Register Student\n";
        cout << "2. Search Student\n";
        cout << "3. Update Student Information\n";
        cout << "4. Enroll Student in Course\n";
        cout << "5. Remove Student\n";
        cout << "6. Display All Students\n";
        cout << "7. Exit\n";

        cout << "Enter Your Choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                registerStudent();
                break;

            case 2:
                searchStudent();
                break;

            case 3:
                updateStudent();
                break;

            case 4:
                enrollCourse();
                break;

            case 5:
                removeStudent();
                break;

            case 6:
                displayStudents();
                break;

            case 7:
                cout << "Exiting Program...\n";
                break;

            default:
                cout << "Invalid Choice!\n";
        }

    } while (choice != 7);

    // Free Memory
    while (head != NULL)
    {
        Student* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
