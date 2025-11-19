#include <iostream>
#include <stdio.h>

#define MAX 11

using namespace std;

int N;
int numbers[MAX];
int op[4]; // + - * /
int ans_max = -1000000001;
int ans_min = +1000000001;

int max(int a, int b){ return a > b ? a : b; }
int min(int a, int b){ return a > b ? b : a; }
void input();
void solution(int idx, int calcu); // numbers idx
int calculator(int a, int b, int idx);

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    input();
    solution(0, numbers[0]);

    cout << ans_max << endl;
    cout << ans_min << endl;

    return 0;
}

void input() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> numbers[i];
    }
    for (int i = 0; i < 4; i++) {
        cin >> op[i];
    }
}

void solution(int idx, int calcu) {
    if (idx == N - 1) {
        ans_max = max(ans_max, calcu);
        ans_min = min(ans_min, calcu);
        return;
    }

    for (int i = 0; i < 4; i++) {
        if (op[i] == 0) continue;

        op[i]--; // 사용
        int tmp_calcu = calcu;
        calcu = calculator(tmp_calcu, numbers[idx+1], i);
        
        solution(idx+1, calcu);
        
        calcu = tmp_calcu;
        op[i]++;
    }
}

int calculator(int a, int b, int idx) {
    if (idx == 0) return a + b;
    if (idx == 1) return a - b;
    if (idx == 2) return a * b;
    
    return a / b;
}