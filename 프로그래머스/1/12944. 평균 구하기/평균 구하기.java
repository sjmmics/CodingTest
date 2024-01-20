class Solution {
    public double solution(int[] arr) {
        int tot = 0;
        for (int num : arr) {
            tot += num;
        }
        double answer = (double) tot / arr.length;
        return answer;
    }
}