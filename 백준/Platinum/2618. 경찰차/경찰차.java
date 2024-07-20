import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    static int N, W;
    static int[][] arr;
    static int[][] dpt;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        W = Integer.parseInt(br.readLine());
        arr = new int[W + 1][2];
        for (int i = 1; i < W + 1; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            arr[i][0] = Integer.parseInt(st.nextToken());
            arr[i][1] = Integer.parseInt(st.nextToken());
        }
        dpt = new int[W + 1][W + 1];
        for (int i = 0; i < W + 1; i++) {
            for (int j = 0; j < W + 1; j++) {
                dpt[i][j] = -1;
            }
        }
        System.out.println(solution(0, 0));
        route(0, 0);
    }

    static int solution(int p1, int p2) {
        if (p1 == W || p2 == W) {
            return 0;
        }
        if (dpt[p1][p2] != -1) {
            return dpt[p1][p2];
        }

        int nxt = Math.max(p1, p2) + 1;
        int d1, d2;

        if (p1 == 0) {
            d1 = getDstc(1, 1, arr[nxt]);
        } else {
            d1 = getDstc(arr[p1], arr[nxt]);
        }

        if (p2 == 0) {
            d2 = getDstc(N, N, arr[nxt]);
        } else {
            d2 = getDstc(arr[p2], arr[nxt]);
        }

        int res1 = d1 + solution(nxt, p2);
        int res2 = d2 + solution(p1, nxt);
        dpt[p1][p2] = Math.min(res1, res2);
        return dpt[p1][p2];
    }

    static void route(int p1, int p2) {
        if (p1 == W || p2 == W) {
            return;
        }

        int nxt = Math.max(p1, p2) + 1;
        int d1, d2;

        if (p1 == 0) {
            d1 = getDstc(1, 1, arr[nxt]);
        } else {
            d1 = getDstc(arr[p1], arr[nxt]);
        }

        if (p2 == 0) {
            d2 = getDstc(N, N, arr[nxt]);
        } else {
            d2 = getDstc(arr[p2], arr[nxt]);
        }

        if (dpt[nxt][p2] + d1 < dpt[p1][nxt] + d2) {
            System.out.println(1);
            route(nxt, p2);
        } else {
            System.out.println(2);
            route(p1, nxt);
        }
    }

    static int getDstc(int crrX, int crrY, int[] nxt) {
        return Math.abs(crrX - nxt[0]) + Math.abs(crrY - nxt[1]);
    }

    static int getDstc(int[] crr, int[] nxt) {
        return Math.abs(crr[0] - nxt[0]) + Math.abs(crr[1] - nxt[1]);
    }
}