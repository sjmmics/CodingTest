#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M, K;
//  (r-1, c-1), (r-1, c), (r-1, c+1), (r, c-1), (r, c+1), (r+1, c-1), (r+1, c), (r+1, c+1) 
int DX[8] = { -1, -1, -1, 0, 0, 1, 1, 1 };
int DY[8] = { -1, 0, 1, -1, 1, -1, 0, 1 };
vector<vector<int>> crr_nut;
vector<vector<vector<int>>> trees;
vector<vector<int>> plus_nut;
vector<pair<int, int>> spread_trees;

void add_nut() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            crr_nut[i][j] += plus_nut[i][j];
        }
    }
}

void spread() {
    for (pair<int, int> st : spread_trees) {
        int x = st.first;
        int y = st.second;
        for (int i = 0; i < 8; i++) {
            int nx = x + DX[i];
            int ny = y + DY[i];
            if (N <= nx || nx < 0 || N <= ny || ny < 0) {
                continue;
            }
            trees[nx][ny].push_back(1);
        }
    }
    spread_trees.clear();
}

void grow() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            vector<int> temp;
            int dead_to_nut = 0;
            if (trees[i][j].size() > 1) {
                sort(trees[i][j].begin(), trees[i][j].end());
            }
            for (int crr : trees[i][j]) {
                if (crr <= crr_nut[i][j]) {
                    temp.push_back(crr + 1);
                    crr_nut[i][j] -= crr;
                    if ((crr + 1) % 5 == 0) {
                        spread_trees.push_back({ i, j });
                    }
                } else {
                    dead_to_nut += crr / 2;
                }
            }
            trees[i][j].clear();
            for (int nxt : temp) {
                trees[i][j].push_back(nxt);
            }
            crr_nut[i][j] += dead_to_nut;
        }
    }
}

int solution() {
    for (int i = 0; i < K; i++) {
        grow();
        spread();
        add_nut();
    }
    int res = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            res += trees[i][j].size();
        }
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M >> K;
    plus_nut.assign(N, vector<int>(N, 0));
    crr_nut.assign(N, vector<int>(N, 5));
    trees.assign(N, vector<vector<int>>(N, vector<int>()));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> plus_nut[i][j];
        }
    }
    for (int i = 0; i < M; i++) {
        int x, y, a;  cin >> x >> y >> a;
        x--, y--;
        trees[x][y].push_back(a);
    }
    cout << solution() << "\n";
}