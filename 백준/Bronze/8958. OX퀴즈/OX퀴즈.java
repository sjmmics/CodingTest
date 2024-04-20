import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int testcaseNum = Integer.parseInt(br.readLine());
        for (int i = 0; i < testcaseNum; i++) {
            String[] str = br.readLine().split("");
            System.out.println(getScore(str));
        }
    }

    private static int getScore(String[] arr) {
        int score = 0;
        int temp = 0;
        for (String letter : arr) {
            if (letter.equals("O")) {
                score += ++temp;
            } else {
                temp = 0;
            }
        }
        return score;
    }
}