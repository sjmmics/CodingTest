#include <iostream>
#include <vector>
using namespace std;

long long N;
vector<long long> vt;
vector<bool> vstd;
vector<vector<pair<long long, pair<long long, long long>>>> grp;

long long gcd(long long a, long long b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

void dfs(long long crr) {
    vstd[crr] = true;
    for (pair<long long, pair<long long, long long>> nxt_pair : grp[crr]) {
        long long nxt = nxt_pair.first;
        long long ratio_crr = nxt_pair.second.first;
        long long ratio_nxt = nxt_pair.second.second;
        if (vstd[nxt]) continue;
        vt[nxt] = vt[crr] * ratio_nxt / ratio_crr;
        dfs(nxt);
    }
}

int main() {
    long long lcm = 1;
    cin >> N;
    vt.assign(N, 0);
    vstd.assign(N, 0);
    grp.assign(N, vector<pair<long long, pair<long long, long long>>>());
    for (long long i = 0; i < N - 1; i++) {
        long long a, b, p, q;
        cin >> a >> b >> p >> q;
        lcm *= (p * q) / gcd(p, q);
        grp[a].push_back({ b, { p, q }});
        grp[b].push_back({ a, { q, p }});
    }
    vt[0] = lcm;
    dfs(0);
    long long gcd_of_vt = vt[0];
    for (int i = 1; i < N; i++) {
        gcd_of_vt = gcd(gcd_of_vt, vt[i]);
    }
    for (int i = 0; i < N; i++) {
        cout << vt[i] / gcd_of_vt << " ";
    }
}