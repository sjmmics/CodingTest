import java.util.HashSet;

class Solution {
    public int solution(String skill, String[] skill_trees) {
        int answer = 0;
        char[] order = new char[skill.length()];
        for (int i = 0; i < skill.length(); i++) {
            order[i] = skill.charAt(i);
        }
        HashSet<Character> set = new HashSet<>();
        for (char s : order) {
            set.add((Character) s);
        }
        for (String skltr : skill_trees) {
            int orderIdx = 0;
            boolean flag = true;
            for (int i = 0; i < skltr.length(); i++) {
                Character s = skltr.charAt(i);
                if (set.contains(s)) {
                    if (orderIdx < order.length && order[orderIdx] == s) {
                        orderIdx++;
                    } else {
                        flag = false;
                        break;
                    }
                }
            }
            if (flag) {
                answer++;
            }
        }
        return answer;
    }
}