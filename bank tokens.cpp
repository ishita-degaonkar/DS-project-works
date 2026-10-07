#include <iostream>
using namespace std;

int main()
{
    int stack[5];
    int top = -1;
    int token;

    cout << "Enter 5 customer token numbers:" << endl;

    for(int i = 0; i < 5; i++)
    {
        cin >> token;
        top++;
        stack[top] = token;
    }

    cout << "\n--- Service List ---" << endl;
    cout << "Most recently served customer first:" << endl;

    while(top >= 0)
    {
        cout << stack[top] << endl;
        top--;
    }

    return 0;
}
