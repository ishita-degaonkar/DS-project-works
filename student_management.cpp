#include <iostream>
using namespace std;

int main()
{
    int rollNo[100];
    int marks[100];
    int count = 0;
    int choice, roll, found;

    do
    {
        cout << "\n===== Student Management System =====\n";
        cout << "1. Add Student\n";
        cout << "2. Display Student Records\n";
        cout << "3. Search Student by Roll No\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                cout << "Enter Roll No: ";
                cin >> rollNo[count];

                cout << "Enter Marks: ";
                cin >> marks[count];

                count++;

                cout << "Student added successfully!\n";
                break;

            case 2:
                if (count == 0)
                {
                    cout << "No student records found.\n";
                }
                else
                {
                    cout << "\nStudent Records:\n";

                    for (int i = 0; i < count; i++)
                    {
                        cout << "Roll No: " << rollNo[i]
                             << "  Marks: " << marks[i] << endl;
                    }
                }
                break;

            case 3:
                cout << "Enter Roll No to search: ";
                cin >> roll;

                found = 0;

                for (int i = 0; i < count; i++)
                {
                    if (rollNo[i] == roll)
                    {
                        cout << "Student Found!\n";
                        cout << "Roll No: " << rollNo[i] << endl;
                        cout << "Marks: " << marks[i] << endl;
                        found = 1;
                        break;
                    }
                }

                if (found == 0)
                {
                    cout << "Student not found.\n";
                }
                break;

            case 4:
                cout << "Exiting program...\n";
                break;

            default:
                cout << "Invalid choice! Please try again.\n";
        }

    } while (choice != 4);

    return 0;
}
