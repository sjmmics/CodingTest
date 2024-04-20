import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.StringTokenizer;

public class Main {
    static List<Integer> temp = new ArrayList<>();

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());

        int[] arr = new int[N];
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++) {
            arr[i] = Integer.parseInt(st.nextToken());
        }
        Arrays.sort(arr);

        getSeq(arr, 0,  N, M);

    }

    static void getSeq(int[] arr, int crrIdx, int arrLength, int seqLength) {
        if (temp.size() == seqLength) {
            for (Integer num : temp) {
                System.out.print(num);
                System.out.print(" ");
            }
            System.out.println();
            return;
        }
        for (int i = crrIdx; i < arrLength; i++) {
            temp.add((Integer) arr[i]);
            getSeq(arr, i, arrLength, seqLength);
            temp.remove(temp.size() - 1);
        }
    }
}