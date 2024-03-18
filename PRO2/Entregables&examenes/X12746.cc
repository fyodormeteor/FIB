/*  Vectors amb resize, i push i pop a front i back
    18.03.2024

    https://github.com/fyodormeteor
*/

#include <iostream>
#include <string>
#include <map>
using namespace std;

int main()
{
    map<int,int> v;
    int first = 0;
    int last = 0;

    // v[first] is first element in vector
    // v[last-1] is last element in vector
    // v[first+n] is n-th element in vector

    string command;
    while (cin >> command)
    {
        if (command == "v.push_back(")
        {
            int val;
            cin >> val;
            string ending;
            cin >> ending; // Això consumeix el ");"
            
            v[last++] = val;
        }
        else if (command == "v.push_front(")
        {
            int val;
            cin >> val;
            string ending;
            cin >> ending; // Això consumeix el ");"

            v[--first] = val;
        }
        else if (command == "v.pop_front();")
        {
            v[first++] = 0;
        }
        else if (command == "v.pop_back();")
        {
            v[--last] = 0;
        }
        else if (command == "v.resize(")
        {
            int newsize;
            cin >> newsize;
            string ending;
            cin >> ending; // Això consumeix el ");"

            if (newsize < (last-first))
            {
                auto it = v.lower_bound(newsize + first);
                v.erase(it, v.end());
            }

            last += newsize-(last-first);
        }
        else if (command == "cout<<v[")
        {
            int index;
            cin >> index;
            string ending;
            cin >> ending; // Això consumeix el "];"

            index += first;

            int ret = 0;
            if (index < last-first)
            {
                auto it = v.find(index);
                if (it != v.end())
                {
                    ret = it->second;
                }
            }

            cout << ret << endl;
        }
        else if (command == "cout<<v;")
        {
            for(int i = first; i < last; ++i)
            {
                auto it = v.find(i);
                if (it != v.end())
                {
                    cout << it->second;
                }
                else cout << 0;

                if (i < last-1) cout << ',';
            }
            cout << endl;
        }
        else if (command == "v[")
        {
            int index;
            cin >> index;
            string mid;
            cin >> mid; // Això consumeix el "]="
            int val;
            cin >> val;
            string ending;
            cin >> ending; // Això consumeix el ";"
            
            index += first;
            v[index] = val;

            if (index >= last-first)
            {
                last += index-(last-first);
            }
        }
        else if (command == "//")
        {
            string comment;
            getline(cin, comment);
            cout << "//" << comment << endl;
        }
        else
        {
            cout << "Wrong command '" << command << "'" << endl;
            string discard;
            getline(cin, discard);
        }
    }
}