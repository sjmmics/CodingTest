class Solution {
    static int solution(int n, int[][] results) {
        int[][] grp = new int[n][n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                grp[i][j] = 0;
            }
        }

        for (int[] subArr : results ) {
            int win = subArr[0] - 1;
            int lose = subArr[1] - 1;
            grp[win][lose] = 1;
            grp[lose][win] = -1;
        }

        for (int t = 0; t < n; t++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (grp[i][t] == 1 && grp[t][j] == 1) {
                        grp[i][j] = 1;
                        grp[j][i] = -1;
                    }
                    if (grp[i][t] == -1 && grp[t][j] == -1) {
                        grp[i][j] = -1;
                        grp[j][i] = 1;
                    }
                }
            }
        }
        int answer = 0;
        for (int[] subArr : grp) {
            int temp = 0;
            for (int num : subArr) {
                if (num != 0) {
                    temp++;
                }
            }
            if (temp == n - 1) {
                answer++;
            }
        }
        return answer;
    }
}