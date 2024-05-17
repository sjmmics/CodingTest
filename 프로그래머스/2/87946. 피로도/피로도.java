class Solution {
    static boolean[] vstd;
    static int answer;
    
    public int solution(int k, int[][] dungeons) {
        vstd = new boolean[dungeons.length];
        answer = 0;
        for (int i = 0; i < vstd.length; i++) {
            vstd[i] = false;
        }
        dfs(dungeons, k, 0);
        return answer;
        
    }
    public void dfs(int[][] dungeons, int crrPoint, int depth) {
        if (depth > answer) {
            answer = depth;
        }
        for (int i = 0; i < vstd.length; i++) {
            if (vstd[i]) {
                continue;
            }
            if (dungeons[i][0] <= crrPoint) {
                vstd[i] = true;
                dfs(dungeons, crrPoint - dungeons[i][1], depth + 1);
                vstd[i] = false;
            }
        }
    }
    
    
    
    
}