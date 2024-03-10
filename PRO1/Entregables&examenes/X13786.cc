/*  You look younger
    2023-24 Q1

    https://github.com/fyodormeteor
*/

#include <iostream>
using namespace std;

int main()
{
    string skip; //used to filter out unneeded information from the input sentence
    string name;
    int age;
    int suggested_age;

    while (cin >> skip >> skip >> skip >> name >> skip >> skip >> skip >> age >> skip >> skip)
    {
        suggested_age = age - (age/10);
        cout << name << ", you look younger. I thought you were " << suggested_age << " years old." << endl;
    }
}   	