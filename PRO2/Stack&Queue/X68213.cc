/*  Biblioteca
    28.02.2024

    https://github.com/fyodormeteor
*/

#include<iostream>
#include<stack>
#include<vector>
using namespace std;

typedef vector<stack<string>> Stacks;

void print_stack(stack<string> s)
{
    while (!s.empty())
    {
        cout << s.top() << endl;
        s.pop();
    }
    cout << endl;
}

int main()
{
    int n;
    cin >> n;
    Stacks s(n);

    int instruction;
    while (cin >> instruction and instruction != -4)
    {
        string name;
        int category;
        int remove_amt;

        switch(instruction)
        {
            case -1:
                cin >> name >> category;

                s[category-1].push(name);
            break;

            case -2:
                cin >> remove_amt >> category;

                for(int i = 0; i < remove_amt; ++i) s[category-1].pop();
            break;

            case -3:
                cin >> category;

                cout << "Pila de la categoria " << category << endl;
                print_stack(s[category-1]);
            break;

            default: break;
        }
    }
}

