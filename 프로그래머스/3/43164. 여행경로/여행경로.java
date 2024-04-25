
import java.util.*;

class Solution {
    static ArrayList<String> route;
    static ArrayList<String[]> answers = new ArrayList<String[]>(); 
    static Boolean[] usedTicket;
    
    public String[] solution(String[][] tickets) {
        usedTicket = new Boolean[tickets.length];
        for (int i = 0; i < usedTicket.length; i++) {
            usedTicket[i] = false;
        }
        
        route = new ArrayList<String>();
        route.add("ICN");
        dfs(tickets, "ICN");
        
        return getFirst(answers);
    }
    
    static void dfs(String[][] tickets, String crrNode) {
        if (route.size() == tickets.length + 1) {
            answers.add(route.toArray(new String[tickets.length + 1]));
            return;
        }
        
        for (int i = 0; i < tickets.length; i++) {
            if (crrNode.equals(tickets[i][0]) && !usedTicket[i]) {
                usedTicket[i] = true;
                route.add(tickets[i][1]);
                dfs(tickets, tickets[i][1]);
                usedTicket[i] = false;
                route.remove(route.size() - 1);
            }
        }
    }
    
    static String[] getFirst(ArrayList<String[]> list) {
        String[] combinedArr = new String[list.size()];
        int idx = 0;
        for (String[] subArr : list) {
            StringBuilder sb = new StringBuilder();
            for (String city : subArr) {
                sb.append(city);
            }
            combinedArr[idx++] = sb.toString();
        }
        Arrays.sort(combinedArr);
        String[] result = new String[combinedArr[0].length() / 3];
        for (int i = 0; i < combinedArr[0].length() / 3; i++) {
            int j = i * 3;
            result[i] = combinedArr[0].substring(j, j + 3);
        }
        return result;
    }
}