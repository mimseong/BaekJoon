import java.util.Scanner;

public class Main {
	public static void main(String args[]){
		int i, j;
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		for(i = 1; i <= n; i++)
		{
			for(j = 0; j < i; j++)
			{System.out.print('*');}
			System.out.print('\n');
		}
		sc.close();
	}
}
/*
input 5:
*
**
***
****
*****
*/