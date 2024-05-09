class Solution {
    public int solution(int[] num_list) {
        return getCntMakeOne(num_list);
    }
    static int getCntMakeOne(int[] arr) {
        int answer = 0;
        for (int num : arr) { 
            int cnt = 0;
            while (num > 1) {
                if (num % 2 == 0) {
                    num /= 2;
                } else {
                    num--;
                    num /= 2;
                }
                cnt++;
            }
            answer += cnt;
        }    
        return answer;
    }
    
}