#include <iostream>
#include <string>
using namespace std;
int main()
{
int id1,id2,id3;
string title1,title2,title3;

cout<<"enter book 1 ID: ";
cin>>id1;
cin.ignore();
cout<<"enter book 1 title: ";
getline(cin,title1);

cout<<"enter book 2 ID: ";
cin>>id2;
cin.ignore();
cout<<"enter book 2 title: ";
getline(cin,title2);

cout<<"enter book 3 ID: ";
cin>>id3;
cin.ignore();
cout<<"enter book 3 title: ";
getline(cin,title3);

cout<<"\n ===LIBRARY BOOK===";
cout<<"\n enter id1"<<id1;
cout<<"\n enter title1"<<title1;
cout<<"\n enter id2"<<id2;
cout<<"\n enter title2"<<title2;
cout<<"\n enter id3"<<id3;
cout<<"\n enter title3"<<title3;

return 0;
}
