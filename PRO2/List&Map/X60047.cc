/*  FALTA ACABAR

    Punt mig d'una llista
    06.03.2024

    https://github.com/fyodormeteor
*/

#include <iostream>
#include <list>
#include <string>

using namespace std;

int main()
{
    list<int> l;
    list<int>::iterator it = l.begin();
    string instruction;
    while(cin >> instruction)
    {
        if(instruction == "push_front")
        {
            int x;
            cin >> x;

            l.push_front(x);

            if(l.size() % 2 == 1)
            {
                it++;
            }
        }
        else if(instruction == "push_back")
        {
            int x;
            cin >> x;
            l.push_back(x);

            if(l.size() % 2 == 1)
            {
                it++;
            }
        }
        else if(instruction == "pop_front")
        {
            if (l.empty()) cout << "error" << endl;
        }
        else if(instruction == "pop_back")
        {

        }
        else if(instruction == "get_mid_value")
        {

        }
    }
}