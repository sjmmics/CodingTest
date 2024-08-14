#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#define INF 987654321

using namespace std;

int N, M;
vector<int> prnts, res;
vector<vector<int>> grp;


int get_prnt(int x) {
    if (prnts[x] == x) return x;
    prnts[x] = get_prnt(prnts[x]);
    return prnts[x];
}

bool is_union_set(int x, int y) {
    x = get_prnt(x);
    y = get_prnt(y);
    return x == y;
}

void union_set(int x, int y) {
    x = get_prnt(x);
    y = get_prnt(y);
    if (x > y) {
        prnts[x] = y;
    } else {
        prnts[y] = x;
    }
}

void solution() {
    
    set<int> prnts_set;
    map<int, vector<int>> dict;

    for (int i = 1; i <= N; i++) {
        dict[prnts[i]].push_back(i);
        prnts_set.insert(prnts[i]);
    }
    int group_cnt = prnts_set.size();

    for (int k = 1; k <= N; k++) {
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {                
                grp[i][j] = min(grp[i][j], grp[i][k] + grp[k][j]);
            }
        }
    }
    for (int i = 1; i <= N; i++) {
        grp[i][i] = 1;
    }
    vector<int> res;
    set<int>::iterator iter;
    for (iter = prnts_set.begin(); iter != prnts_set.end(); iter++) {
        vector<int> sub_vt = dict[*iter];
        vector<pair<int, int>> temp;
        for (int i : sub_vt) {
            int bgst_val = 0;
            for (int j : sub_vt) {
                if (grp[i][j] > bgst_val) {
                    bgst_val = grp[i][j];
                }
            }
            temp.push_back({ bgst_val, i });
        }
        sort(temp.begin(), temp.end());
        res.push_back(temp[0].second);
    }
    sort(res.begin(), res.end());
    cout << group_cnt << "\n";
    for (int node : res) {
        cout << node << "\n";
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M;
    prnts.assign(N + 1, 0);
    for (int i = 0; i <= N; i++) {
        prnts[i] = i;
    }
    grp.assign(N + 1, vector<int>(N + 1, INF));
    for (int i = 0; i < M; i++) {
        int a, b;  cin >> a >> b;
        if (!is_union_set(a, b)) {
            union_set(a, b);
        }
        grp[a][b] = 1;
        grp[b][a] = 1;
    }
    for (int i = 1; i <= N; i++) {
        get_prnt(i);
    }
    solution();

}