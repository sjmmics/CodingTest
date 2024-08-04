#include <iostream>
#define DVSR 1'000'000'007
using namespace std;

int N, M;
long long tmp;

long long power(long long a, long long b) {
    if (b == 0) return 1;
    tmp = power(a, b / 2) % DVSR;
    if (b % 2 == 1) {
        return tmp * tmp % DVSR * a % DVSR;
    }
    return tmp * tmp % DVSR;
}

long long solution() {
    long long a = 1, b = 1;
    for (int i = N; i >= N - M + 1; i--) {
        a = (a * i) % DVSR;
    }
    for (int i = 1; i <= M; i++) {
        b = (b * i) % DVSR;
    }
    long long ret = ((a % DVSR) * power(b, DVSR - 2) % DVSR) % DVSR;
    return ret; 
}

int main() {
    cin >> N >> M;

    cout << solution() << "\n";
}