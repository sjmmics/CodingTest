import java.io.*;
import java.util.Arrays;
import java.util.StringTokenizer;


public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        int N = Integer.parseInt(br.readLine());
        Integer[] arr = new Integer[N];
        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++) {
            arr[i] = Integer.parseInt(st.nextToken());
        }
        Arrays.sort(arr);
        Integer left = 0;
        Integer right = N - 1;
        Integer smstGap = 2_000_000_001;
        Integer[] ans = new Integer[2];
        while (left < right) {
            int crrGap = arr[right] + arr[left];
            if (smstGap > Math.abs(crrGap)){
                smstGap = Math.abs(crrGap);
                ans[0] = arr[left];
                ans[1] = arr[right];
            }
            if (crrGap > 0) {
                right--;
            } else if (crrGap < 0) {
                left++;
            } else {
                break;
            }
        }
        bw.write(Integer.toString(ans[0]) + " " + Integer.toString(ans[1]));

        bw.close();
        br.close();

    }
}