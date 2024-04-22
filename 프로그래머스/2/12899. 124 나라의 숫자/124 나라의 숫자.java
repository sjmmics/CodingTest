class Solution {
    public String solution(long n) {
        String answer = "";     
        answer = get124(n);
        return answer;
    }

    static String get124(long x) {
        String[] oneTwoFour = { "4", "1", "2"}; 
        StringBuilder sb = new StringBuilder();
        while (x > 0) {
            int mod = (int) (x % 3L);
            sb.append(oneTwoFour[mod]);
            x /= 3;
            if (mod == 0) {
                x--;
            }
            if (0 < x && x < 3) {
                sb.append(oneTwoFour[(int) x]);
                break;
            }
        }
        sb.reverse();
        String answer = sb.toString();
        return answer;
    }
}

// 1, 2, 4,
// 11, 12, 14,
// 21, 22, 24, 
// 41(10 -> 101), 42(11), 44(12),
// 111, 112, 114,

