/*  Frequencia de paraules amb diccionaris
    06.03.2024

    https://github.com/fyodormeteor
*/

#include<iostream>
#include<map>
#include<string>

using namespace std;

int main()
{
    char instruction;
    string key;

    map<string, int> dic;

    while(cin >> instruction >> key)
    {
        if (instruction == 'a')
        {
            dic[key]++;
        }
        else if (instruction == 'f')
        {
            cout << dic[key] << endl;
        }
    }
}