import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int w = Integer.parseInt(st.nextToken());
        int L = Integer.parseInt(st.nextToken());
        int[] trucks = new int[n];
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++) {
            trucks[i] = Integer.parseInt(st.nextToken());
        }
        System.out.println(getSmstTime(trucks, w, L));
    }
    static int getSmstTime(int[] trucks, int span, int loadLimit) {
        Queue<Integer> que = new LinkedList<>();
        for (int i = 0; i < span; i++) {
            que.add(0);
        }
        int answer = 1;
        int load = 0;
        int idx = 0;
        while (true) {
            if (!que.isEmpty()) {
                load -= que.poll();
            }
            if (idx >= trucks.length) {
                if (load == 0) {
                    break;
                }
                que.add(0);
            } else if (load + trucks[idx] > loadLimit) {
                que.add(0);
            } else {
                que.add(trucks[idx]);
                load += trucks[idx++];
            }
            answer++;
        }
        return answer;
    }
}