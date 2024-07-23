#include <iostream>
#include <vector>
#define MOD 1000000007LL

using namespace std;

long long D;
vector<vector<long long>> mtrx = {
    { 0, 1, 1, 0, 0, 0, 0, 0 },
    { 1, 0, 1, 1, 0, 0, 0, 0 },
    { 1, 1, 0, 1, 1, 0, 0, 0 },
    { 0, 1, 1, 0, 1, 1, 0, 0 },
    { 0, 0, 1, 1, 0, 1, 0, 1 },
    { 0, 0, 0, 1, 1, 0, 1, 0 },
    { 0, 0, 0, 0, 0, 1, 0, 1 },
    { 0, 0, 0, 0, 1, 0, 1, 0 }
};

vector<vector<long long>> res(8, vector<long long>(8));

vector<vector<long long>> mltp_mtrx(const vector<vector<long long>> &M1, 
                                    const vector<vector<long long>> &M2) {
    vector<vector<long long>> ans(8, vector<long long>(8));
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            long long x = 0;
            for (int k = 0; k < 8; k++) {
                x += M1[i][k] * M2[k][j];
                x %= MOD;
            }
            ans[i][j] = x % MOD;
        }
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> D;
    
    for (int i = 0; i < 8; i++) {
        res[i][i] = 1;
    }
    
    while (D > 0) {
        if (D & 1) {
            res = mltp_mtrx(res, mtrx);
            D--;
        }
        mtrx = mltp_mtrx(mtrx, mtrx);
        D >>= 1;
    }
    cout << res[0][0] << "\n";
}