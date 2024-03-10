/*  How many games does each person win?
    2023-24 Q1

    ALERTA
    Esta solucion solo pasa los juegos de prueba publicos.

    https://github.com/fyodormeteor
*/

#include<iostream>
#include<vector>
using namespace std;

struct Player
{
    string name;
    int level;
    int wins;
};

typedef vector<Player> List;

int main()
{
    int n;
    while(cin >> n)
    {
        List type1(n); // Russian generalised to type1 player
        for(int i = 0; i < n; ++i)
        {
            Player player;
            cin >> player.name >> player.level;
            player.wins = 0;
            type1[i] = player;
        }

        List type2(n); // USA generalised to type2 player
        for(int i = 0; i < n; ++i)
        {
            Player p1;
            cin >> p1.name >> p1.level;
            p1.wins = 0;

            for (int j = 0; j < n; ++j)
            {
                Player& p2 = type1[j];
                
                if (p1.level > p2.level)
                {
                    p1.wins += 2;
                }
                else if (p1.level == p2.level)
                {
                    p1.wins++;
                    p2.wins++;
                }
                else
                {
                    p2.wins += 2;
                }
            }

            type2[i] = p1;
        }

        // Output
        for(int i = 0; i < n; ++i)
        {
            cout << type1[i].name << ' ' << type1[i].wins;
            if (i != n-1) cout << ' ';
        }
        cout << endl;

        for(int i = 0; i < n; ++i)
        {
            cout << type2[i].name << ' ' << type2[i].wins;
            if (i != n-1) cout << ' ';
        }
        cout << endl << endl;
    }
}