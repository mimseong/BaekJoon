import java.util.Scanner;

public class Main{

     public static void main(String []args){
        Scanner sc = new Scanner(System.in);
        int input = sc.nextInt();
        int[] N = new int[input + 1];
        int[] P = new int[input + 1];
        int i, min1, tmp, min2, count = 0;
        boolean check = true;
        N[0] = 0;           //numer of sugar 
        P[0] = -1;          //parent array

        for(i = 1; i <= input; i++)         //put in array
        {
            if(i-3 < 0)
                min1 = 9999;
            else
                min1 = N[i-3];
            if(i-5 < 0)
                min2 = 9999;
            else
                min2 = N[i-5];

            if(min1 <= min2)
            {
                N[i] = min1 + 1;
                if(N[i] > 9999)
                    P[i] = -2;
                else
                    P[i] = i - 3;
            }
            else {
                N[i] = min2 + 1;
                if(N[i] > 9999)
                    P[i] = -2;
                else
                    P[i] = i - 5;
            }
        }
        if(P[input] == -1)
            System.out.println(0);
        else if(P[input] == -2)
            System.out.println(-1);
        else
            System.out.println(N[input]);
     }
}
/*
    baekjoon 2839
*/