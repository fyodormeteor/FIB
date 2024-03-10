/*  Estadistiques d'una sequencia d'enters amb esborrat
    06.03.2024

    https://github.com/fyodormeteor
*/

#include<iostream>
#include<list>

using namespace std;

int main()
{
    int instruction;
    int value;

    list<int> l;

    while(cin >> instruction and instruction != 0)
    {
        cin >> value;
        if (instruction == -1)
        {
            l.push_back(value);
        }
        else if (instruction == -2)
        {
            list<int>::iterator it = l.begin();
            bool done = false;
            while(it != l.end() and !done)
            {
                if (*it == value)
                {
                    it = l.erase(it);
                    done = true;
                }
                else it++;
            }
        }

        if (!l.empty())
        {
            int min,max;
            double mean = 0;

            list<int>::iterator it = l.begin();

            min = *it;
            max = *it;

            while(it != l.end())
            {
                mean += *it;
                if (*it < min) min = *it;
                if (*it > max) max = *it;

                it++;
            }

            mean /= l.size();

            cout << min << ' ' << max << ' ' << mean << endl;
        }
        else
        {
            cout << 0 << endl;
        }
    }
}