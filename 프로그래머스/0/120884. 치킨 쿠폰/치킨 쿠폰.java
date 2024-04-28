class Solution {
    public int solution(int chicken) {
        int answer = 0;
        int coupon = chicken;
        while (coupon > 10) {
            int srvc = coupon / 10;
            answer += srvc;
            coupon -= srvc * 10;
            coupon += srvc;
        }
        answer += (coupon / 10);
        return answer;
    }
}