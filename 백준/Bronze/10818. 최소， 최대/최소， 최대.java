import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int smst = 1_000_001;
        int bgst = -1_000_001;
        int N = Integer.parseInt(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++) {
            int crr = Integer.parseInt(st.nextToken());
            if (crr < smst) {
                smst = crr;
            }
            if (crr > bgst) {
                bgst = crr;
            }
        }
        System.out.println(smst + " " + bgst);
    }
}