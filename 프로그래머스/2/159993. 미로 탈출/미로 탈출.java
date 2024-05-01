import java.util.Queue;
import java.util.LinkedList;

class Solution {

    public static class Point {
        int x;
        int y;
        public Point(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }
    
    public int solution(String[] maps) {
        String[][] grp = new String[maps.length][maps[0].length()];
        
        for (int i = 0; i < maps.length; i++) {
            for (int j = 0; j < maps[0].length(); j++) {
                grp[i][j] = Character.toString(maps[i].charAt(j));
            }
        }
        int[] points = getPoints(grp);
        
        Point bgn = new Point(points[0], points[1]);
        Point end = new Point(points[2], points[3]);
        Point lvr = new Point(points[4], points[5]);
        
        int firstHalf = bfs(grp, bgn, lvr);
        if (firstHalf == -1) {
            return -1;
        }
        int secondHalf = bfs(grp, lvr, end);
        if (secondHalf == -1) {
            return -1;
        }
        return firstHalf + secondHalf;
    }
    
    static int bfs(String[][] grp, Point strt, Point goal) {
        int[][] vstd = new int[grp.length][grp[0].length];
        for (int i = 0; i < grp.length; i++) {
            for (int j = 0; j < grp[0].length; j++) {
                vstd[i][j] = Integer.MAX_VALUE;
            }
        }
        int[] dx = {1, -1, 0, 0};
        int[] dy = {0, 0, 1, -1};
        Queue<Point> que = new LinkedList<>();
        que.add(strt);
        vstd[strt.x][strt.y] = 0;
        while (!que.isEmpty()) {
            Point crr = que.poll();
            int x = crr.x;
            int y = crr.y;
            if (x == goal.x && y == goal.y) {
                return vstd[x][y];
            }
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (0 > nx || nx >= grp.length || 0 > ny || ny >= grp[0].length) {
                    continue;
                }
                if (grp[nx][ny].equals("X")) {
                    continue;
                }
                if (vstd[nx][ny] > vstd[x][y] + 1) {
                    que.add(new Point(nx, ny));
                    vstd[nx][ny] = vstd[x][y] + 1;
                }
            }
        }
        if (vstd[goal.x][goal.y] == Integer.MAX_VALUE) {
            return -1;
        }
        return vstd[goal.x][goal.y];
    }
    
    static int[] getPoints (String[][] grp) {
        int[] ans = new int[6];
        for (int i = 0; i < grp.length; i++) {
            for (int j = 0; j < grp[0].length; j++) {
                if (grp[i][j].equals("S")) {
                    ans[0] = i;
                    ans[1] = j;
                } else if (grp[i][j].equals("E")) {
                    ans[2] = i;
                    ans[3] = j;
                } else if (grp[i][j].equals("L")) {
                    ans[4] = i;
                    ans[5] = j;
                }
            }
        }
        return ans;
    }
}