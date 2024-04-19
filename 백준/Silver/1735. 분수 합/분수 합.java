import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int a = Integer.parseInt(st.nextToken());
        int b = Integer.parseInt(st.nextToken());
        st = new StringTokenizer(br.readLine());
        int c = Integer.parseInt(st.nextToken());
        int d = Integer.parseInt(st.nextToken());
        br.close();
        //     a * d + b + c / b * d
        int top = a * d + b * c;
        int bottom = b * d;

        int commonDiv = gcd(top, bottom);
        System.out.println(top / commonDiv + " " + bottom / commonDiv);
    }

    static int gcd(int x, int y) {
        if (x % y == 0) {
            return y;
        }
        return gcd(y, x % y);
    }

}