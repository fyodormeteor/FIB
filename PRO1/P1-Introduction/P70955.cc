/*  How many seconds are they?
    14.09.2023

    https://github.com/fyodormeteor
*/

#include<iostream>
using namespace std;

int main()
{
    int years, days, hours, minutes, seconds;
    cin >> years >> days >> hours >> minutes >> seconds;

    days += years*365;
    hours += days*24;
    minutes += hours*60;
    seconds += minutes*60;

    cout << seconds << endl;
}