#include <iostream>
using namespace std;

int main()
{
    int marks[5];
    int temp;

    cout << "Enter 5 marks: ";

    for (int i = 0; i < 5; i++)
    {
        cin >> marks[i];
    }

    for (int i = 0; i < 5; i++)
    {
        for (int j = i + 1; j < 5; j++)
        {
            if (marks[i] < marks[j])
            {
                temp = marks[i];
                marks[i] = marks[j];
                marks[j] = temp;
            }
        }
    }

    cout << "Descending order:" << endl;

    for (int i = 0; i < 5; i++)
    {
        cout << marks[i] << " ";
    }

    return 0;
}
