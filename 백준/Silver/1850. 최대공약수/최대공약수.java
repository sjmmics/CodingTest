import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        long a = Long.parseLong(st.nextToken());
        long b = Long.parseLong(st.nextToken());
        br.close();

        long gcd = getGcd(a, b);
        StringBuilder sb = new StringBuilder();
        for (long i = 0L; i < gcd; i++) {
            sb.append("1");
        }
        String res = sb.toString();
        System.out.println(res);

    }

    static long getGcd(long x, long y) {
        if (x % y == 0L) {
            return y;
        }
        return getGcd(y, x % y);
    }
}