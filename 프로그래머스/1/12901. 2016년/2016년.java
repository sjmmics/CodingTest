class Solution {
    public String solution(int a, int b) {
        int[] daysOfmonth = { 0, 31, 29, 31, 30, 31, 30, 
                            31, 31, 30, 31, 30, 31 };
        String[] days = { "THU", "FRI", "SAT", "SUN", "MON", "TUE", "WED" };
        
        String answer = "";
        int dayOfYear = 0;
        for (int i = 1; i < a; i++)  {
            dayOfYear += daysOfmonth[i];
        }
        dayOfYear += b;
        answer = days[dayOfYear % 7];
        
        return answer;
    }
}