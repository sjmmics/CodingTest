import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        long sum = 0L;
        String[] str = br.readLine().split("");
        br.close();
        
        for (int i = 0; i < N; i++) {
            sum += Long.parseLong(str[i]);
        }
        System.out.println(sum);
    }
}