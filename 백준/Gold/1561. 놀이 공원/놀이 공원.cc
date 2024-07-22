#include <iostream>
#include <vector>

using namespace std;

long long N, M;
long long T;
vector<long long> rides;

int solution() {
    if (M >= N) return N;

    long long low = 0;
    long long high = 30 * N + 1;
    while (low <= high) {
        long long mid = (low + high) / 2;
        long long cnt = M;

        for (int i = 0; i < M; i++) {
            cnt += mid / rides[i];
        }
        if (cnt >= N) {
            T = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    if (T == N) {
        long long prev_cnt = M;
        vector<long long> rmn(M);
        for (int i = 0; i < M; i++) {
            prev_cnt += (T - 1) / rides[i];
            long long rm = T % rides[i];
            if (rm == 0) {
                rmn[i] = rides[i];
            } else {
                rmn[i] = rides[i] - rm;
            }
        }
        for (int i = M - 1; i >= 0; i--) {
            if (rides[i] == rmn[i]) {
                return i + 1;
            }
        }
    } else {
        long long prev_cnt = M;
        for (int i = 0; i < M; i++) {
            prev_cnt += (T - 1) / rides[i];
        }
        for (int i = 0; i < M; i++) {
            if (T % rides[i] == 0) {
                prev_cnt++;
                if (prev_cnt == N) {
                    return i + 1;
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M;
    rides = vector<long long>(M);
    for (int i = 0; i < M; i++) {
        cin >> rides[i];
    }
    cout << solution() << "\n";
}