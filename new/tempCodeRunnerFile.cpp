int byDP(int i, int idx) {
//     int tmp_N = N_num[idx];
//     int dp[tmp_N - i]; // 4 - {0, 1, 2, 3} => 4(00 01 02 03) 3(11 12 13) 2(22 23) 1(33)

//     dp[0] = values[idx][i] ^ values[idx][i+1];

//     for (int ii = i+1; ii < tmp_N; ii++) {
//         dp[ii] = dp[ii-1] ^ values[idx][ii+1];
//     }

//     return dp[tmp_N - 1 - i - 1]; // dp 마지막 값
// }