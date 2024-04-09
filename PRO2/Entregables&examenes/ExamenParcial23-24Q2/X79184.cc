/*  Aniversaris
    09.04.2024

    https://github.com/fyodormeteor
*/

#include <iostream>
#include <string>
#include <map>
#include <set>

using namespace std;

int main()
{
    // All data will be stored in a map where the key is the age, and the set of string are the people that have that age
    map<int, set<string>> data;

    // Auxiliary map for people's ages in order to be able to efficiently retrive a person's age in the BIRTHDAY command.
    map<string, int> ages;

    string command;
    while (cin >> command)
    {
        if (command == "NEWPERSON")
        {
            string person;
            int age;
            cin >> person >> age;

            data[age].insert(person);
            ages[person] = age;
        }
        else if (command == "BIRTHDAY")
        {
            string person;
            cin >> person;

            int age = ages[person];
            ages[person]++;

            auto it = data[age].find(person);
            data[age].erase(it);

            data[age+1].insert(person);
        }
        else if (command == "NUMBERWITHAGE")
        {
            int age;
            cin >> age;

            cout << data[age].size() << endl;
        }
        else if (command == "PEOPLEWITHAGE")
        {
            int age;
            cin >> age;

            auto it = data[age].begin();
            while(it != data[age].end())
            {
                cout << *it;
                auto it_aux = it;
                it_aux++;
                if (it_aux != data[age].end()) cout << ' '; // if next element in map is not the end, add a space to the output
                it++;
            }
            cout << endl;
        }
    }
}