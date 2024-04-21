class Solution {
    public int solution(int[][] sizes) {
        int garo = 0;
        int sero = 0;
        for (int i = 0; i < sizes.length; i++) {
            int v = sizes[i][0];
            int h = sizes[i][1];
            if (v > h) {
                if (garo < v) {
                    garo = v;
                }
                if (sero < h) {
                    sero = h;
                }
            } else {
                if (garo < h) {
                    garo = h;
                }
                if (sero < v) {
                    sero = v;
                }
            }
           
        }
        int ans = garo * sero;
        return ans;
    
    }
}