#include <iostream>
#include <stdio.h>
#include <stack>
#include <set>
#include <vector>

#define MAX 51 // 1 ~ 50 사용
#define endl "\n"

using namespace std;

int N, L, R, answer = 0;
int map_i[MAX][MAX]; // 1,1 ~ 50,50
int isVisited[MAX][MAX]; // default false

// 우, 좌, 상, 하
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

void input();
void solve();
void isVisited_clear();

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    input();
    solve();

    cout << answer << endl;

    return 0;
}

void input() {
    cin >> N >> L >> R;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> map_i[i][j];
        }
    }
}
void solve() {
    bool loop_check = true;
    
    while (loop_check) {
        isVisited_clear();
        loop_check = false;
        bool answer_check = true;

        for (int p = 1; p <= N; p++) {
            for (int q= 1; q <= N; q++) {
                if (isVisited[p][q]) continue;

                stack<pair<int, int>> st;
                vector<pair<int, int>> locations;

                st.push(make_pair(p, q));
                isVisited[p][q] = true;

                while (!st.empty()) {
                    int i = st.top().first, j = st.top().second;
                    st.pop();
                    locations.emplace_back(make_pair(i, j));
                    
                    for (int k = 0; k < 4; k++) {
                        int nx = i + dx[k], ny = j + dy[k];
                        if (!isVisited[nx][ny] && nx >= 1 && nx <= N && ny >= 1 && ny <= N) { // 방문x && 내부
                            int calcu_abs = abs(map_i[nx][ny] - map_i[i][j]);
                            if (calcu_abs >= L && calcu_abs <= R) {
                                st.push(make_pair(nx, ny));
                                isVisited[nx][ny] = true;
                            }
                        }
                    }
                }
                
                if (locations.size() > 1) {
                    loop_check = true;
                    if (answer_check) {
                        answer++;
                        answer_check = false;
                    }

                    set<pair<int, int>> sset;
                    vector<pair<int, int>> new_v;
                    for (pair<int, int> pp : locations) sset.emplace(pp);
                    for (pair<int, int> pp : sset) new_v.emplace_back(pp); 

                    

                    int locations_sum = 0;
                    for (pair<int, int> location : new_v) locations_sum += map_i[location.first][location.second];
                    for (pair<int, int> location : new_v) map_i[location.first][location.second] = locations_sum / new_v.size();
                }
            }
        }
    }        
}

void isVisited_clear() {
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            isVisited[i][j] = false;
        }
    }
}