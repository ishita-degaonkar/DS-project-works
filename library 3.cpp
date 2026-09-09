#include<iostream>
using namespace std;

int main()
{
    int book[5];
    int searchID;

cout<<"Enter 5 book id:\n";
for(int i=0; i<5; i++)
{
    cin >> book [i];
}

//Sorting 
for(int i=0; i < 4; i++)
{
    for (int j = 0; j<4-i; j++)
{
 if (book[j] > book[j+1])
 {
     int temp = book[j];

     book[j] = book[j+1];
     book[j+1] = temp;
 }
}

}
cout<<"\n books after sorting:\n";
for (int i=0; i<5; i++)
{
    cout<< book[i]<<" ";
}
    return 0;
}
