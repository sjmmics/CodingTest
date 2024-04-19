import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        long X = Long.parseLong(br.readLine());
        int n = Integer.parseInt(br.readLine());
        long sum = 0L;
        for (int i = 0; i < n; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            long crrMoney = Long.parseLong(st.nextToken());
            int crrQtt = Integer.parseInt(st.nextToken());
            sum += (crrMoney * crrQtt);
        }
        br.close();
        if (X == sum) {
            System.out.println("Yes");
        } else {
            System.out.println("No");
        }
    }

}