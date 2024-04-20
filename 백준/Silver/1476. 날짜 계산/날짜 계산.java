import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int E = Integer.parseInt(st.nextToken());
        int S = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());

        System.out.println(getDate(E, S, M));
    }

    static int getDate(int earth, int sun, int moon) {
        int ans = 1;
        int e = 1, s = 1, m = 1;
        while (true) {
            if (e == earth && s == sun && m == moon) {
                return ans;
            }
            if (++e > 15) {
                e = 1;
            }
            if (++s > 28) {
                s = 1;
            }
            if (++m > 19) {
                m = 1;
            }
            ans++;
        }
    }
}