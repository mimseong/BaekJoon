import java.util.Scanner;

public class Main {
	public static void main(String args[])
	{
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int i, j;
		for(i = 0;i < n;i++)
		{
			for(j = 0; j < i; j--)
				System.out.print(" ");
			for(j = (n - i); j > 0; j--)
				System.out.print("*");
			System.out.print('\n');
		}
	}
}
/*
*****
 ****
  ***
   **
    *
*/