class Solution {
    static final int MOD = 1234567;
    public int solution(int n) {
        
        int[] dpt = new int[n + 1];
        dpt[0] = 0;
        dpt[1] = 1;
        dpt[2] = 1;
        for (int i = 3; i <= n; i++) {
            dpt[i] = dpt[i - 1] + dpt[i - 2];
            dpt[i] = dpt[i] % MOD;
        }
        
        return dpt[n];
    }
}