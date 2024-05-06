class Solution {
    public int solution(int n) {
        int mod = 1_000_000_007;
        
        int[] dpt = new int[n + 1];
        if (n > 2) {
            dpt[2] = 2;
            dpt[1] = 1;
        } else if (n > 1) {
            dpt[1] = 1;
        }
        for (int i = 3; i < n + 1; i++) {
            dpt[i] = (dpt[i - 1] + dpt[i - 2]) % mod;
        }
        return dpt[n];
        
    }
}