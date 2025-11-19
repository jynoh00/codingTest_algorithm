#include <iostream>
#include <stdio.h>

#define MAX 51

using namespace std;
int N, M;
int ans = 99999999;
vector<pair<int, int>> chicken_locations, home_locations;
int isDeletedIdx[MAX];

void solve();
void input();
void solution(int idx, int cnt); // chicken_locations idx, deleted cnt
int calcu_dis();

int main(){
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    solve();
    cout << ans << endl;

    return 0;
}

void solve() {
    input();
    if (chicken_locations.size() == M) {
        ans = calcu_dis();
        return;
    }

    solution(0, 0);
}

void input() {
    cin >> N >> M;
    for (int i = 1; i <= N; i++){
        for (int j = 1; j <= N; j++){
            int tmp_num;
            cin >> tmp_num;
            if (tmp_num == 2) chicken_locations.emplace_back(make_pair(i, j));
            if (tmp_num == 1) home_locations.emplace_back(make_pair(i, j));
        }
    }
}

void solution(int idx, int cnt) {
    if (cnt == chicken_locations.size() - M) {
        ans = min(ans, calcu_dis());
        return;
    }

    for (int i = idx; i < chicken_locations.size(); i++) {
        int x_pos = chicken_locations[i].first, y_pos = chicken_locations[i].second;
        isDeletedIdx[i] = true;

        solution(i+1, cnt+1);
        
        isDeletedIdx[i] = false;
    }
}

int calcu_dis() {
    int dis = 0;

    for (int i = 0; i < home_locations.size(); i++) {
        int home_x = home_locations[i].first, home_y = home_locations[i].second;
        int tmp_dis = 999;

        for (int j = 0; j < chicken_locations.size(); j++) {
            if (isDeletedIdx[j]) continue;

            int chicken_x = chicken_locations[j].first, chicken_y = chicken_locations[j].second;
            tmp_dis = min(tmp_dis, abs(chicken_x - home_x) + abs(chicken_y - home_y));
        }
        dis += tmp_dis;
    }

    return dis;
}

