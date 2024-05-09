import java.util.HashMap;

class Solution {
    public int[] solution(String[] keyinput, int[] board) {
        
        return getCoordinate(keyinput, board);
    }
    
    static int[] getCoordinate(String[] directions, int[] span) {
        HashMap<String, Integer> dmap = new HashMap<>();
        dmap.put("up", 0);
        dmap.put("down", 1);
        dmap.put("left", 2);
        dmap.put("right", 3);
        int[] dx = {0, 0, -1, 1};
        int[] dy = {1, -1, 0, 0};
        int n = span[0] / 2;
        int m = span[1] / 2;
        Point crr = new Point();
        for (String d : directions) {
            int nx = crr.x + dx[dmap.get(d)];
            int ny = crr.y + dy[dmap.get(d)];
            if (nx < -n || nx > n || ny < -m || ny > m) {
                continue;
            }
            crr.x = nx;
            crr.y = ny;
        }
        return new int[]{crr.x, crr.y};
    }
    static class Point {
        int x;
        int y;
        
        public Point() {
            this.x = 0;
            this.y = 0;
        }
    }
}