import java.time.LocalDate;

class Solution {
    public int solution(int[] date1, int[] date2) {
        LocalDate day1 = LocalDate.of(date1[0], date1[1], date1[2]);
        LocalDate day2 = LocalDate.of(date2[0], date2[1], date2[2]);
        int answer = 0;
        if (day1.isBefore(day2)) {
            answer = 1;
        } else {
            answer = 0;
        }
        return answer;
    }
}