#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

bool customsort(pair<int,string> p1, pair<int,string> p2) // true if p1 goes BEFORE p2
{
    if (p1.first > p2.first) {
        return true;
    }
    if (p1.first < p2.first) {
        return false;
    }
    else {
        return (p1.second < p2.second);
    }
}

struct Player {
        private:
    
    int elo;
    bool online;

        public:
    
    Player() {
        elo = 1200;
        online = true;
    }

    void WonMatch() {
        elo += 10;
    }

    void LostMatch() {
        elo -= 10;
        if (elo < 1200) elo = 1200;
    }

    int GetElo() {
        return elo;
    }

    void Login() {
        online = true;
    }

    void Logout() {
        online = false;
    }

    bool IsOnline() {
        return online;
    }
};

int main()
{
    map<string,Player> data;

    string input;
    while(cin >> input) {
        if (input == "LOGIN") {
            string id;
            cin >> id;

            data[id].Login();
        }
        else if (input == "LOGOUT") {
            string id;
            cin >> id;

            if (data.count(id) == 1) data[id].Logout();
        }
        else if (input == "PLAY") {
            string id1, id2;
            cin >> id1 >> id2;

            if (data.count(id1) == 0 or data.count(id2) == 0) {
                cout << "player(s) not connected" << endl;
            }
            else if (!data.at(id1).IsOnline() or !data.at(id2).IsOnline()) {
                cout << "player(s) not connected" << endl;
            }
            else {
                data[id1].WonMatch();
                data[id2].LostMatch();
            }
        }
        else if (input == "GET_ELO") {
            string id;
            cin >> id;

            cout << id << ' ' << data[id].GetElo() << endl;
        }
    }

    //print ranking
    cout << endl << "RANKING" << endl;
    
    vector<pair<int,string>> aux(data.size());

    int i = 0;
    for (auto it = data.begin(); it != data.end(); it++)
    {
        aux[i] = make_pair(it->second.GetElo(), it->first);
        i++;
    }

    sort(aux.begin(), aux.end(), customsort);

    for (int i = 0; i < aux.size(); i++)
    {
        cout << aux[i].second << ' ' << aux[i].first << endl;
    }
}