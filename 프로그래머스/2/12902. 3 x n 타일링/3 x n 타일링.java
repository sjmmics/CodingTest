class Solution {
    public long solution(int n) {
        return getAnswer(n); 
    }
    public long getAnswer(int n) {
        int MOD = 1_000_000_007;
        long[] dpt = new long[n + 1];
        if (n >= 4) {
            dpt[4] = 11L;
        }
        if (n >= 2) {
            dpt[2] = 3L;
        }
        dpt[0] = 1;

        for (int i = 5; i <= n; i++) {
            if (i % 2 == 1) {
                continue;
            }
            dpt[i] = 3L * dpt[i - 2]; 
            for (int j = i - 4; j >= 0; j -= 2) {
                dpt[i] += 2L * dpt[j];
            }
            dpt[i] %= MOD;
        }
        return dpt[n];
    }
    
}