import java.util.Scanner;

public class Main {
	public static void main(String args[]){
		int i;
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		for(i = 1; i <= n; i++)
		{
			System.out.println(i);
		}
		sc.close();
	}
}