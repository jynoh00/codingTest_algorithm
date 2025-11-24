#include <iostream>
#include <stdio.h>
#include <string>
#include <algorithm>

#define MAX 50

using namespace std;

int N;
pair<int, string> students_score[MAX];

void input();
void solve();

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    input();
    solve();

    return 0;
}

void input() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        string name;
        int score;
        cin >> name >> score;
        students_score[i] = make_pair(score, name);
    }
}

void solve() {
    vector<pair<int, string>> vec;
    for (int i = 0; i < N; i++) vec.emplace_back(students_score[i]);

    sort(vec.rbegin(), vec.rend());

    for (pair<int, string> p : vec) cout << p.second << " ";
    cout << endl;
}