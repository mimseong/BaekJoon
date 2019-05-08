import java.util.Scanner;

public class Main{
	public static void main(String args[])
	{
		Scanner sc = new Scanner(System.in);
		String input = sc.next();
		int length = input.length();
		int i;
		for(i = 0; i < (length / 10) * 10; i = i + 10){
			System.out.println(input.substring(i, i + 10));
		}
		if(length % 10 != 0){
			System.out.println(input.substring(i, i + (length % 10)));
		}
	}
}