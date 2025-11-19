#include <iostream>
#include <stdio.h>
#include <vector>

#define MAX 20 // 1 ~ 15

using namespace std;

int N;
vector<pair<int, int>> days = {{0,0}};
int ans = 0;
int pay[MAX];

int max(int a, int b) { return a > b ? a : b; }
void input();
void solution();

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    input();
    solution();

    return 0;
}

void input() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        int T, P;
        cin >> T >> P;
        days.emplace_back(make_pair(T, P));
    }
}

void solution() {
    if (days[N].first == 1) pay[N] = days[N].second; // 초기값 (역)

    for (int i = N-1; i >= 1; i--) {
        // days[i].first == 1 -> pay[i] = days[i].second + pay[i+1];
        if (days[i].first == 1) pay[i] = days[i].second + pay[i+1];
        if ((i + days[i].first - 1) <= N) pay[i] = max(days[i].second + pay[i + days[i].first], pay[i+1]);
        if ((i + days[i].first - 1) > N) pay[i] = pay[i+1];
    }

    cout << pay[1] << endl;
}