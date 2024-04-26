import java.util.HashSet;
import java.util.HashMap;

class Solution {
    public boolean solution(String[] phone_book) {
        return checkPrefix(phone_book);
    }
    
    static boolean checkPrefix(String[] phoneBook) {
        boolean answer = true;
        
        HashSet<String> set = new HashSet<>();
        for (String phoneNum : phoneBook) {
            set.add(phoneNum);
        }
        for (String phoneNum : phoneBook) {
            for (int i = 1; i < phoneNum.length(); i++) {
                if (set.contains(phoneNum.substring(0, i))) {
                    answer = false;
                    break;
                }
            }
        }
        return answer;
    }
}