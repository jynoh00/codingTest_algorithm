#include <iostream>
#include <stdio.h>
#include <vector>
#include <cmath>

#define MAX 20

using namespace std;

int N, answer = 99999999;
int ability[MAX][MAX];
bool isTeamStart[MAX];

void input();
void solve(int idx, int cnt);
int min(int a, int b) { return a > b ? b : a; }
int calcu_team_ability();

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    input();
    solve(0, 0);

    cout << answer << endl;

    return 0;
}

void input() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> ability[i][j];
        }
    }
}

void solve(int idx, int cnt) {
    if (cnt == N/2) {
        answer = min(answer, calcu_team_ability());
        return;
    }

    for (int i = idx; i < N; i++) {
        isTeamStart[i] = true; // i 인덱스 추가
        solve(i+1, cnt+1);
        isTeamStart[i] = false;
    }
}

int calcu_team_ability() {
    int team_s = 0, team_l = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i == j) continue;
            
            if (isTeamStart[i] == true && isTeamStart[j] == true) { // 스타트 팀 
                team_s += ability[i][j];
            }

            if (isTeamStart[i] == false && isTeamStart[j] == false) {
                team_l += ability[i][j];
            }
        }
    }

    return abs(team_s - team_l);
}