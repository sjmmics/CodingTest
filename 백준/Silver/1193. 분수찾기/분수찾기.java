import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        long x = scanner.nextLong();
        boolean isUp = true;
        long left = 0L;
        long numInSector = 0L;
        long line = 0;
        for (long i = 1L; i <= 10_000_000L; i++) {
            if (left < x && x <= left + i) {
                line = i + 1L;
                numInSector = x - left;
                break;
            }
            left += i;
            isUp = (!isUp);
        }

        long up = 0L;
        long bottom = 0L;
        if (isUp) {
            up = line - numInSector;
            bottom = line - up;
        } else {
            bottom = line - numInSector;
            up = line - bottom;
        }
        System.out.println(up + "/" + bottom);

    }
}
