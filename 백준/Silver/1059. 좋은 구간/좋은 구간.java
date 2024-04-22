import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int L = Integer.parseInt(br.readLine());
        int[] arr = new int[L];
        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 0; i < L; i++) {
            arr[i] = Integer.parseInt(st.nextToken());
        }
        Arrays.sort(arr);
        int n = Integer.parseInt(br.readLine());
        br.close();
        System.out.println(getGoodSection(arr, n));

    }
    static int getGoodSection(int[] arr, int n) {
        int left = 0;
        int right = 1001;
        for (int num : arr) {
            if (num == n) {
                return 0;
            }
            if (num < n && num > left) {
                left = num;
            }
            if (num > n && num < right) {
                right = num;
            }

        }
        int ans = 0;
        for (int i = left + 1; i <= n; i++) {
            for (int j = right - 1; j >= n; j--) {
                if (i < j) {
                    ans++;
                }
            }
        }
        return ans;
    }
}