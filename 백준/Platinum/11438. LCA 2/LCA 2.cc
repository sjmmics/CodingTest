#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int N, M;
int prnts[100'001][18];
int depths[100'001];
int bgst;
vector<int> trees[100'001];

void set_tree_prnt(int prnt, int crr, int depth) {
    prnts[crr][0] = prnt;
    depths[crr] = depth;
    
    for (int i = 1; i <= bgst; i++) {
        prnts[crr][i] = prnts[prnts[crr][i - 1]][i - 1];
    }

    for (int i = 0; i < trees[crr].size(); i++) {
        int child = trees[crr][i];
        if (child == prnt) continue;
        set_tree_prnt(crr, child, depth + 1);
    }
}

int find(int x, int y) {
    if (depths[x] < depths[y]) {
        swap(x, y);
    }
    for (int k = bgst; k >= 0; k--) {
        int diff = depths[x] - depths[y];
        if (diff >= (1 << k)) {
            x = prnts[x][k];
        }
    }

    if (x == y) {
        return x;
    }

    for (int k = bgst; k >= 0; k--) {
        if (prnts[x][k] != prnts[y][k]) {
            x = prnts[x][k];
            y = prnts[y][k];
        }
    }
    return prnts[x][0];

}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    bgst = (int) floor(log2(100'001));

    for (int i = 0; i < N - 1; i++) {
        int a, b;
        cin >> a >> b;
        trees[a].push_back(b);
        trees[b].push_back(a);
    }

    set_tree_prnt(0, 1, 1);
    
    cin >> M;
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        cout << find(a, b) << "\n";
    }
    
}