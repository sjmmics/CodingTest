import java.util.HashSet;

class Solution {
    public int solution(int[] elements) {
        int span = elements.length;
        int answer = 0;
        HashSet<Integer> set = new HashSet<>();
        for (int subSeqLength = 1; subSeqLength <= elements.length; subSeqLength++) {
            for (int bgn = 0; bgn < 2 * elements.length - subSeqLength; bgn++) {
                int tempSum = 0;
                for (int i = bgn; i < bgn + subSeqLength; i++) {
                    tempSum += elements[i % elements.length];
                }
                set.add((Integer) (tempSum));
            }
        }
        return set.size();
    }
}


// 0, 1, 2
// 3, 4, 5