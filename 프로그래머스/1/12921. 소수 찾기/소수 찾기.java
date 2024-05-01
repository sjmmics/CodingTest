class Solution {
    public int solution(int n) {
        boolean[] arr = new boolean[n + 1];
        
        for (int i = 2; i < n + 1; i++) {
            arr[i] = true;
        }
        arr[0] = false;
        arr[1] = false;
        int answer = 0; 
        
        for (int i = 2; i < n + 1; i++) {
            if (arr[i]) {
                answer++;
            }
            for (int j = i * 2; j <= n; j += i) {
                arr[j] = false;
            }
        }
        
        return answer;
    }
}