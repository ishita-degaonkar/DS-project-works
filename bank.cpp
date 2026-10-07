#include <iostream>
using namespace std;

int main()
{
    int queue[5];
    int front = -1, rear = -1;
    int choice, token;

    do
    {
        cout << "\n--- Bank Token System ---" << endl;
        cout << "1. Issue Token" << endl;
        cout << "2. Display All Tokens" << endl;
        cout << "3. Serve Customer" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1:
                if(rear == 4)
                {
                    cout << "Queue is full!" << endl;
                }
                else
                {
                    cout << "Enter token number: ";
                    cin >> token;

                    if(front == -1)
                        front = 0;

                    rear++;
                    queue[rear] = token;

                    cout << "Token issued successfully." << endl;
                }
                break;

            case 2:
                if(front == -1 || front > rear)
                {
                    cout << "No tokens available." << endl;
                }
                else
                {
                    cout << "Tokens: ";
                    for(int i = front; i <= rear; i++)
                    {
                        cout << queue[i] << " ";
                    }
                    cout << endl;
                }
                break;

            case 3:
                if(front == -1 || front > rear)
                {
                    cout << "No customer to serve." << endl;
                }
                else
                {
                    cout << "Customer with token "
                         << queue[front]
                         << " is served." << endl;

                    front++;

                    if(front > rear)
                    {
                        front = -1;
                        rear = -1;
                    }
                }
                break;

            case 4:
                cout << "Program exited." << endl;
                break;

            default:
                cout << "Invalid choice!" << endl;
        }

    } while(choice != 4);

    return 0;
}
