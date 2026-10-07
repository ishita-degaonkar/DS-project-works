#include <iostream>
using namespace std;

int main()
{
    int orderstack[5];
    int top = -1;

    cout << "Enter 5 cancelled order numbers:\n";

    for (int i = 0; i < 5; i++)
    {
        cin >> orderstack[++top];
    }

    cout << orderstack[top] << endl;
    top--;

    return 0;
}
