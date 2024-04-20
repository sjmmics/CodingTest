import java.io.*;

public class Main {
    
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] strArr = br.readLine().split(" ");
        int res = 0;
        for (String str : strArr) {
            if (str != "") {
                res++;
            }
        }
        System.out.println(res);
       
    }
}