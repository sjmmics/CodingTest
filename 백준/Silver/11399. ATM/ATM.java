import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        int[] waitLine = new int[N];
        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++) {
            waitLine[i] = Integer.parseInt(st.nextToken());

        }
        Arrays.sort(waitLine);
        br.close();
        int sum = 0;
        for (int idx = 0; idx < N; idx++) {
            sum += waitLine[idx] * (N - idx);
        }

        System.out.println(sum);
    }
}