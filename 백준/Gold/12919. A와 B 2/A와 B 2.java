import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String S = br.readLine();
        String T = br.readLine();
        int res = func(T, S);
        System.out.println(res);

    }

    static int func(String crr, String goal) {
        if (crr.length() == goal.length()) {
            if (crr.equals(goal)) {
                return 1;
            } else {
                return 0;
            }
        }
        // 1. 뒤에 있는 A를 제거한다.
        if (crr.charAt(crr.length() - 1) == 'A') {
            String nxt = crr.substring(0, crr.length() - 1);
            if (func(nxt, goal) == 1) {
                return 1;
            }
        }
        // 2. 맨 앞에 B가 있으면, 뒤집고 맨 뒤에 있는 B를 제거한다.
        if (crr.charAt(0) == 'B') {
            String nxt = crr.substring(1);
            StringBuilder sb = new StringBuilder(nxt);
            sb.reverse();
            nxt = sb.toString();
            if (func(nxt, goal) == 1) {
                return 1;
            }
        }
        return 0;
    }
}