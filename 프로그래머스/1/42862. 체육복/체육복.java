import java.util.HashSet;

class Solution {
    public int solution(int n, int[] lost, int[] reserve) {

        HashSet<Integer> lostSet  = new HashSet<>();
        HashSet<Integer> rsvSet = new HashSet<>();
        HashSet<Integer> cmmnSet = new HashSet<>();
        for (int lostOne : lost) {
            lostSet.add(lostOne);
            cmmnSet.add(lostOne);
        }
        for (int rsvOne : reserve) {
            rsvSet.add(rsvOne);
        }
        cmmnSet.retainAll(rsvSet);
        if (!cmmnSet.isEmpty()) {
            rsvSet.removeAll(cmmnSet);
            lostSet.removeAll(cmmnSet);
        }
        for (Integer rsvOne : rsvSet) {
            if (rsvOne - 1 > 0 && lostSet.contains(rsvOne - 1)) {
                lostSet.remove(rsvOne - 1);
            } else if (rsvOne + 1 <= n && lostSet.contains(rsvOne + 1)) {
                lostSet.remove(rsvOne + 1);
            }
        }
        return n - lostSet.size();
    }
}