
class Solution {
    static int[] prnts;
    public int solution(int n, int[][] computers) {
        prnts = new int[n];
        for (int i = 0; i < n; i++) {
            prnts[i] = i;
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i != j && computers[i][j] == 1) {
                    union(i, j);    
                }
            }
        }
        int answer = 0;
        for (int i = 0; i < n; i++) {
            if (prnts[i] == i) {
                answer++;
            }
        }
        return answer;
    }
    
    static int getPrnt(int x) {
        if (prnts[x] == x) {
            return x;
        }
        return getPrnt(prnts[x]);
    }
    
    static void union(int x, int y) {
        x = getPrnt(x);
        y = getPrnt(y);
        if (x == y) {
            return;
        } else if (x < y) {
            prnts[y] = x;
        } else {
            prnts[x] = y;
        }
    }
}