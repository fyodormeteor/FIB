/*  Programming teams balanced in solidarity
    2023-24 Q1

    https://github.com/fyodormeteor
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct Programmer
{
    string name;
    int level;
};
typedef vector<Programmer> ListProgrammers;
typedef vector<string> Team;
typedef vector<Team> ListTeams;

int main()
{
    int k;
    while(cin >> k)
    {
        int n1;
        cin >> n1;
        ListProgrammers type1(n1); // Israeli nationality generalised to "type1" programmer
        for(int i = 0; i < n1; ++i)
        {
            string name;
            int level;
            cin >> name >> level;

            type1[i] = {name, level};
        }

        int n2;
        cin >> n2;
        ListProgrammers type2(n2); // Palestinian nationality generalised to "type2" programmer
        for(int i = 0; i < n2; ++i)
        {
            string name;
            int level;
            cin >> name >> level;

            type2[i] = {name, level};
        }

        int number_of_teams = (n1+n2)/k;
        ListTeams teams(number_of_teams);
        
        int counter1 = 0; // Counters to keep track of accounted programmers from each type
        int counter2 = 0; //

        //Apply criterions to assemble the teams
        for(int i = 0; i < number_of_teams; ++i)
        {
            Team team(k, "placeholder");
            int balance = 0; // negative if more "type1" programmers, positive if more "type2" programmers. 0 means perfect balance.
            for(int j = 0; j < k; ++j)
            {
                int level1 = -1;
                int level2 = -1;
                string name1;
                string name2;
                if (counter1 < n1) //Protect type1 vec (if counter1 >= n1 then access is out of bounds of the vector)
                {
                    level1 = type1[counter1].level;
                    name1 = type1[counter1].name;
                }
                if (counter2 < n2) //Protect type2 vec
                {
                    level2 = type2[counter2].level;
                    name2 = type2[counter2].name;
                }

                bool next_teammate_is_type1 = false;

                if (level1 == level2) // Criterion 1 (programmer level)
                {
                    if (balance == 0) // Criterion 2 (balance in type (nationality))
                    {
                        if (name1 < name2) next_teammate_is_type1 = true; // Criterion 3 (lexicographic order)
                    }
                    else if (balance > 0) next_teammate_is_type1 = true;
                }
                else if (level1 > level2) next_teammate_is_type1 = true;

                if (next_teammate_is_type1)
                {
                    team[j] = name1;
                    counter1++;
                    balance--;
                }
                else
                {
                    team[j] = name2;
                    counter2++;
                    balance++;
                }
            }
            
            teams[i] = team;
        }

        //Sort the teams and print output
        for(int i = 0; i < number_of_teams; ++i)
        {
            sort(teams[i].begin(), teams[i].end());
            for(int j = 0; j < k; ++j)
            {
                cout << teams[i][j];
                if (j < k-1) cout << ' ';
            }
            cout << endl;
        }

        cout << endl;
    }
}
