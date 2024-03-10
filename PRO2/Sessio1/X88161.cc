/*  Classificacio de la lliga
    14.02.2024

    https://github.com/fyodormeteor
*/

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

typedef vector<pair<int,int>> Row;
typedef vector<Row> Mat;

struct Team
{
    int number;
    int points;
    int scored;
    int scored_against;
};
typedef vector<Team> Teams;

// Pre: m matrix cuadrada de parejas int size n x n
void read_matrix(int n, Mat& m)
{
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cin >> m[i][j].first;
            cin >> m[i][j].second;
        }
    }
}

bool sort_teams(Team t1, Team t2)
{
    if (t1.points > t2.points) return true;
    if (t1.points == t2.points)
    {
        if (t1.scored-t1.scored_against > t2.scored-t2.scored_against) return true;
        if (t1.scored-t1.scored_against == t2.scored-t2.scored_against)
        {
            if (t1.number < t2.number) return true;
        }
    }

    return false;

}

int main()
{
    int n;
    cin >> n;

    Mat m(n,Row(n));
    read_matrix(n, m);

    Teams teams(n);

    for (int i = 0; i < n; ++i)
    {
        teams[i].number = i+1;
        teams[i].points = teams[i].scored = teams[i].scored_against = 0;
    }

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (i != j)
            {
                if (m[i][j].first > m[i][j].second)
                {
                    teams[i].points += 3;
                }
                else if (m[i][j].first == m[i][j].second)
                {
                    teams[i].points += 1;
                    teams[j].points += 1;
                }
                else
                {
                    teams[j].points += 3;
                }

                teams[i].scored += m[i][j].first;
                teams[j].scored += m[i][j].second;

                teams[i].scored_against += m[i][j].second;
                teams[j].scored_against += m[i][j].first;
            }
        }
    }

    sort(teams.begin(), teams.end(), sort_teams);

    for (int i = 0; i < n; ++i)
    {
        cout << teams[i].number << " " << teams[i].points << " " << teams[i].scored << " " << teams[i].scored_against << endl;
    }
}