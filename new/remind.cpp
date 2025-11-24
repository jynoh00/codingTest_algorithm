#include <iostream>
#include <stdio.h>
#include <vector>

#define endl "\n"
// #define MAX 91

using namespace std;

int T, test_case;
vector<int> N_num;
vector<vector<int>> values;
int binary_code[4][2] = {{0, 0}, {0, 1}, {1, 0}, {1, 1}}; // 0, 1, 2, 3

void input();
void solve();
int calcu_ans(int idx);
int bitwiseXOR(int i, int j, int idx);

int calcu_ans_new(int idx, int tmp_N);
// int byDP(int i, int idx);

int main() {
    cin.tie(NULL);
    cout.tie(NULL);

    ios_base::sync_with_stdio(false);

    input();
    solve();

    return 0;
}

void input() {
    cin >> T;
    
    for (test_case = 0; test_case < T; test_case++) { // T개의 테스트케이스
        int tmp_N;
        cin >> tmp_N;
        N_num.emplace_back(tmp_N);

        vector<int> tmp_values;
        for (int i = 0; i < tmp_N; i++) {
            int tmp_value;
            cin >> tmp_value;

            tmp_values.emplace_back(tmp_value);
        }

        values.emplace_back(tmp_values);
    }
}

void solve() {
    // 1번 방식
    for (int i = 0; i < T; i++) {
        cout << "#" << i+1 << " " << calcu_ans(i) << endl;
    }

    // 2번 방식
    for (int i = 0; i < T; i++) {
        cout << "#" << i+1 << " " << calcu_ans_new(i, N_num[i]) << endl;
    }
}

// 1번 방식
int calcu_ans(int idx) {
    int result_sum = 0;

    for (int i = 0; i < N_num[idx]; i++) {
        for (int j = i; j < N_num[idx]; j++) {
            if (i == j) {
                result_sum += values[idx][i];
                continue;
            }

            result_sum += bitwiseXOR(i, j, idx);
        }
    }

    return result_sum;
}

int bitwiseXOR(int i, int j, int idx) {
    pair<int, int> binary_p = make_pair(binary_code[values[idx][i]][0], binary_code[values[idx][i]][1]);

    for (int p = i+1; p <= j; p++) {
        if (binary_p.first == binary_code[values[idx][p]][0]) binary_p.first = 0;
        else binary_p.first = 1;

        if (binary_p.second == binary_code[values[idx][p]][1]) binary_p.second = 0;
        else binary_p.second = 1;        
    }

    return binary_p.first * 2 + binary_p.second * 1;
}

// 2번 방식
int calcu_ans_new(int idx, int tmp_N) {
    int result = 0;
    
    for (int i = 0; i < tmp_N; i++) {
        int before_XOR = values[idx][i];
        result += before_XOR;

        for (int j = i+1; j < tmp_N; j++) {
            result += before_XOR ^ values[idx][j];
            before_XOR ^= values[idx][j];
        }
    }

    return result;
}