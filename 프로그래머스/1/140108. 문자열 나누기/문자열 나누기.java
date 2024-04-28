import java.util.ArrayList;

class Solution {
    public int solution(String s) {
        int[] cnt = new int[2];
        int answer = 0;
        char firstLetter = s.charAt(0);
        boolean isFirst = true;
        for (int i = 0; i < s.length(); i++) {
            if (isFirst) {
                firstLetter = s.charAt(i);
                cnt[0]++;
                isFirst = false;
            } else {
                if (firstLetter == s.charAt(i)) {
                    cnt[0]++;
                } else {
                    cnt[1]++;
                }
                if (cnt[0] == cnt[1]) {
                    cnt[0] = 0;
                    cnt[1] = 0;
                    isFirst = true;
                    answer++;
                }
            }
        }
        if (cnt[0] != 0 || cnt[1] != 0) {
            answer++;
        }
        return answer;
    }
}