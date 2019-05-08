import java.util.Scanner;

public class Main {
    public static void main(String argc[]) {
        Scanner sc = new Scanner(System.in);
        int input = sc.nextInt();
        int result = greed(input);
        if(result > 9999)
             System.out.println(-1);
        else
            System.out.println(result);

        sc.close();
    }
    
    public static int greed(int k) {
        if(k == 0) return 0;
        else if(k < 0) return 9999;
        return(Math.min(greed(k-3), greed(k-5)) + 1);
    }
}