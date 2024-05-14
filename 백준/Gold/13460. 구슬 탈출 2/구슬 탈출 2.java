import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {
    static int n, m, hollX, hollY;
    static String[][] grp;
    static int[] dx = {0, 0, 1, -1};
    static int[] dy = {1, -1, 0, 0};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        grp = new String[n][m];
        Ball bgn = new Ball();

        for (int i = 0; i < n; i++) {
            String line = br.readLine();
            for (int j = 0; j < m; j++) {
                grp[i][j] = Character.toString(line.charAt(j));
                if (grp[i][j].equals("R")) {
                    bgn.rx = i;
                    bgn.ry = j;
                } else if (grp[i][j].equals("B")) {
                    bgn.bx = i;
                    bgn.by = j;
                } else if (grp[i][j].equals("O")) {
                    hollX = i;
                    hollY = j;
                }
            }
        }
        System.out.println(bfs(bgn));

    }

    static int bfs(Ball bgn) {
        Queue<Ball> que = new LinkedList<>();
        que.add(bgn);
        while (!que.isEmpty()) {
            Ball crr = que.poll();
            if (crr.cnt >= 10) {
                continue;
            }
            for (int i = 0; i < 4; i++) {
                Ball nxtBall = getNxtBall(crr, i);
                if (nxtBall.isEquals(crr)) {
                    continue;
                }
                if (nxtBall.bx == hollX && nxtBall.by == hollY) {
                    continue;
                }
                if (nxtBall.rx == hollX && nxtBall.ry == hollY) {
                    return nxtBall.cnt;
                }
                que.add(nxtBall);
            }
        }
        return -1;

    }

    static Ball getNxtBall(Ball crr, int i) {
        int[] nxtRxy = {crr.rx, crr.ry};
        int[] nxtBxy = {crr.bx, crr.by};
        if (i == 0 && crr.rx == crr.bx) {
            if (crr.ry > crr.by) {
                nxtRxy = getNxtXy(crr.rx, crr.ry, i);
                nxtBxy = getNxtXySecond(crr.bx, crr.by, nxtRxy, i);
            } else {
                nxtBxy = getNxtXy(crr.bx, crr.by, i);
                nxtRxy = getNxtXySecond(crr.rx, crr.ry, nxtBxy, i);
            }
        } else if (i == 1 && crr.rx == crr.bx) {
            if (crr.ry < crr.by) {
                nxtRxy = getNxtXy(crr.rx, crr.ry, i);
                nxtBxy = getNxtXySecond(crr.bx, crr.by, nxtRxy, i);
            } else {
                nxtBxy = getNxtXy(crr.bx, crr.by, i);
                nxtRxy = getNxtXySecond(crr.rx, crr.ry, nxtBxy, i);
            }
        } else if (i == 2 && crr.ry == crr.by) {
            if (crr.rx > crr.bx) {
                nxtRxy = getNxtXy(crr.rx, crr.ry, i);
                nxtBxy = getNxtXySecond(crr.bx, crr.by, nxtRxy, i);
            } else {
                nxtBxy = getNxtXy(crr.bx, crr.by, i);
                nxtRxy = getNxtXySecond(crr.rx, crr.ry, nxtBxy, i);
            }
        } else if (i == 3 && crr.ry == crr.by) {
            if (crr.rx > crr.bx) {
                nxtBxy = getNxtXy(crr.bx, crr.by, i);
                nxtRxy = getNxtXySecond(crr.rx, crr.ry, nxtBxy, i);
            } else {
                nxtRxy = getNxtXy(crr.rx, crr.ry, i);
                nxtBxy = getNxtXySecond(crr.bx, crr.by, nxtRxy, i);
            }
        } else {
            nxtRxy = getNxtXy(crr.rx, crr.ry, i);
            nxtBxy = getNxtXy(crr.bx, crr.by, i);
        }
        return new Ball(nxtRxy[0], nxtRxy[1], nxtBxy[0], nxtBxy[1], crr.cnt + 1);
    }

    static int[] getNxtXySecond(int x, int y, int[] nxtRxy, int i) {
        int[] answer = {x, y};
        for (int step = 1; step <= 10; step++) {
            int nx = x + step * dx[i];
            int ny = y + step * dy[i];
            if (0 > nx || nx >= n || 0 > ny || ny >= m) {
                break;
            }
            if (grp[nx][ny].equals("#")) {
                break;
            }
            if (grp[nx][ny].equals("O")) {
                answer[0] = nx;
                answer[1] = ny;
                break;
            }
            if (nx == nxtRxy[0] && ny == nxtRxy[1]) {
                break;
            }
            answer[0] = nx;
            answer[1] = ny;
        }
        return answer;
    }

    static int[] getNxtXy(int x, int y, int i) {
        int[] answer = {x, y};
        for (int step = 1; step <= 10; step++) {
            int nx = x + step * dx[i];
            int ny = y + step * dy[i];
            if (0 > nx || nx >= n || 0 > ny || ny >= m) {
                break;
            }
            if (grp[nx][ny].equals("#")) {
                break;
            }
            if (grp[nx][ny].equals("O")) {
                answer[0] = nx;
                answer[1] = ny;
                break;
            }
            answer[0] = nx;
            answer[1] = ny;
        }
        return answer;
    }
}
class Ball {
    int rx, ry, bx, by;
    int cnt = 0;
    public Ball() {
    }

    public Ball(int rx, int ry, int bx, int by, int cnt) {
        this.rx = rx;
        this.ry = ry;
        this.bx = bx;
        this.by = by;
        this.cnt = cnt;
    }
    boolean isEquals(Ball otherBall) {
        return (this.rx == otherBall.rx && this.ry == otherBall.ry &&
                this.bx == otherBall.bx && this.by == otherBall.by);
    }
}