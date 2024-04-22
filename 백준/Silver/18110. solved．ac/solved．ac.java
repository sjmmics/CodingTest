import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int[] arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = Integer.parseInt(br.readLine());

        }
        Arrays.sort(arr);
        int sum = 0;
        int excludeNum = (int) Math.round(0.15 * n);
        for (int i = excludeNum; i < n - excludeNum; i++) {
            sum += arr[i];
        }
        int avg = (int) Math.round((double) sum / (n - 2 * excludeNum));
        System.out.println(avg);
    }
}