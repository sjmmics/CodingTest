class Solution {
    public long solution(int price, int money, int count) {
        long answer = (long) money - (price * (count * (count + 1) / 2L));
        if (answer >= 0L) {
            answer = 0L;
        }
        return -answer;
    }
}