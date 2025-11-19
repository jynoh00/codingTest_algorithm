#include <iostream>
#include <stdio.h>

using namespace std;

#define MAX 1000001

int N, B, C; // 감독관은 1명씩은 있어야함. 최소값 N개 + a (필요 부감독관 수)
int map[MAX]; // 1 ~ 1000000
long long ans = 0;

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
    for (int i = 1; i <= N; i++) {
        cin >> map[i];
    }
    cin >> B >> C;
}

void solution() {
    ans += N; // 총감독관 1명씩

    for (int i = 1; i <= N; i++) {
        int plus_students = map[i] - B;

        if (plus_students <= 0) continue; // 총감독관 1명으로 충분
        
        int need_managers = (plus_students % C) == 0 ? plus_students / C : (plus_students / C) + 1;
        ans += need_managers;
    }

    cout << ans << endl;
}