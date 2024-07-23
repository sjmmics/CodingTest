#include <iostream>
#define SPAN 1'000'000
using namespace std;

int mu[SPAN + 10];
long long smst, bgst;

void set_mu() {
    mu[1] = 1;
    for (int i = 1; i <= SPAN; i++) {
        for (int j = 2 * i; j <= SPAN; j += i) {
            mu[j] -= mu[i];
        }
    }
}

long long get_cnt(long long n) {
    long long cnt = 0;
    for (long long i = 1; i * i <= n; i++) {
        cnt += mu[i] * (n / (i * i));
    }
    return cnt;
}

int main() {
    set_mu();
    cin >> smst >> bgst;
    cout << get_cnt(bgst) - get_cnt(smst - 1) << "\n"; 
}