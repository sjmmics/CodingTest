class Solution {
    public int solution(int a, int b, int n) {
        int answer = 0;
        int emptyBottle = n;
        while (emptyBottle >= a) {
            int crrGetBottle = b * (emptyBottle / a);
            answer += crrGetBottle;
            emptyBottle %= a;
            emptyBottle += crrGetBottle;
        }

        return answer;
    }
}