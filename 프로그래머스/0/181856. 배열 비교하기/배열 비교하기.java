class Solution {
    public int solution(int[] arr1, int[] arr2) {
        int answer = 0;
        if (arr1.length > arr2.length) {
            answer = 1;
        } else if (arr1.length < arr2.length) {
            answer = -1;
        } else {
            int sumArr1 = getSum(arr1);
            int sumArr2 = getSum(arr2);
            if (sumArr1 > sumArr2) {
                answer = 1;
            } else if (sumArr1 < sumArr2) {
                answer = -1;
            } else {
                answer = 0;
            }
        }
        return answer;
    }
    int getSum(int[] arr) {
        int answer = 0;
        for (int num : arr) {
            answer += num;
        }
        return answer;
    }
}