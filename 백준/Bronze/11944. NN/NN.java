import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        StringTokenizer st = new StringTokenizer(br.readLine());
        String N = st.nextToken();
        int M = Integer.parseInt(st.nextToken());
        int intN = Integer.parseInt(N);
        for (int i = 0; i < intN; i++) {
            sb.append(N);
        }
        String res = sb.toString();
        if (res.length() > M) {
            res = res.substring(0, M);
        }
        System.out.println(res);

    }
}