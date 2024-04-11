import java.util.Queue;
import java.util.LinkedList;

class Solution {
    private static int[] dx = {0, 0, 1, -1};
    private static int[] dy = {1, -1, 0, 0};
    
    public int solution(int[][] maps) {
        
        int answer = 0;
        // 행, 열의 크기 구하기
        int row = maps.length;
        int col = maps[0].length;
        // bfs 탐색
        int[][] visited = new int[row][col];
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                visited[i][j] = 0;
            }
        }
        visited[0][0] = 1;
        Queue<int[]> que = new LinkedList<>();
        que.add(new int[] {0, 0});
        
        
        while (!que.isEmpty()) {
            int[] crrXY = que.poll();
            int crrX = crrXY[0];
            int crrY = crrXY[1];
            
            for (int d = 0; d < 4; d++) {
                int nx = crrX + dx[d];
                int ny = crrY + dy[d];
                if (0 <= nx && nx < row && 0 <= ny && ny < col) {
                    if (visited[nx][ny] == 0) {
                        if (maps[nx][ny] == 1) {
                            visited[nx][ny] = visited[crrX][crrY] + 1;
                            que.add(new int[] {nx, ny});
                        }
                    }
                }
            }
        }
        if (visited[row - 1][col - 1] == 0) {
            answer = -1;
        } else {
            answer = visited[row - 1][col - 1];
        }
        return answer;
    }
}