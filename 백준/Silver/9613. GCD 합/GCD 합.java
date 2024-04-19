import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());
        for (int i = 0; i < t; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int n = Integer.parseInt(st.nextToken());
            int[] arr = new int[n];
            for (int j = 0; j < n; j++) {
                arr[j] = Integer.parseInt(st.nextToken());
            }
            System.out.println(getSumGcd(arr));
        }
        br.close();
    }

    static int gcd(int x, int y) {
        if (x % y == 0) {
            return y;
        }
        return gcd(y, x % y);
    }

    static long getSumGcd(int[] arr) {
        long ans = 0L;
        for (int i = 0; i < arr.length - 1; i++) {
            for (int j = i + 1; j < arr.length; j++) {
                ans += gcd(arr[i], arr[j]);
            }
        }
        return ans;
    }
}