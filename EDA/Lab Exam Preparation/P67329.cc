#include <iostream>
#include <vector>

using namespace std;

void print(const vector<char>& l) {
    for (char c : l) {
        cout << c;
    }
    cout << endl;
}

void backtrack(int i, int n, vector<char>& current) {
    if (i == n) {
        print(current);
        return;
    }

    current[i] = 'A';
    backtrack(i+1, n, current);
    current[i] = 'C';
    backtrack(i+1, n, current);
    current[i] = 'G';
    backtrack(i+1, n, current);
    current[i] = 'T';
    backtrack(i+1, n, current);
}

int main() {
    int n;
    cin >> n;
    vector<char> solutions(n);
    backtrack(0, n, solutions);
}