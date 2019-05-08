import java.util.Scanner;

public class Main {
	public static void main(String args[]) {
		Scanner sc = new Scanner(System.in);
		int count = sc.nextInt();
		String n = sc.next();
		int sum = 0;
		
		for(int i = 0; i < count; i++)
		{
			sum += Integer.parseInt(n.substring(i, i + 1));
		}
		System.out.println(sum);
	}
}