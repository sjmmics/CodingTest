#include <iostream>
#define DVSR 1'000'000'007

using namespace std;

int M;
long long dpt[4'000'001];

long long power(long long a, long long b) {
    if (b == 1) return a % DVSR;
    if (b == 0) return 1;
    long long temp = power(a, b / 2) % DVSR;
    if (b % 2 == 1) {
        return (temp * a) % DVSR * temp % DVSR;
    } else {
        return (temp * temp) % DVSR;
    }
}

void dp() {
    dpt[0] = 1;
    for (int i = 1; i <= 4'000'000; i++) {
        dpt[i] = dpt[i - 1] * i % DVSR;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    dp();
    cin >> M;
    while (M--) {
        int N, K;  cin >> N >> K;
        long long x = dpt[N];
        long long y = dpt[N - K] * dpt[K] % DVSR;
        y = power(y, DVSR - 2);
        cout << x * y % DVSR << "\n";
        
    }

}