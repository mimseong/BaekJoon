import java.util.Scanner;

public class Main {
	public static void main(String args[]){
		int i;
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		for(i = 1; i <= 9; i++)
		{
			System.out.println(n + " * " + i + " = " + n*i);
		}
		sc.close();
	}
}