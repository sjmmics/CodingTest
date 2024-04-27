class Solution {
    public int solution(int number, int limit, int power) {
        int answer = 0;
        for (int numKnight = 1; numKnight <= number; numKnight++) {
            int numDiv = getNumDiv(numKnight);
            if (numDiv > limit) {
                answer += power;
            } else {
                answer += numDiv;
            }
        }
        
        return answer;
    }
    static int getNumDiv(int x) {
        int answer = 0;
        for (int div = 1; div * div <= x; div++) {
            if (div * div == x) {
                answer++;
            } else if (x % div == 0) {
                answer += 2;
            }
        }
        return answer;
    }
}