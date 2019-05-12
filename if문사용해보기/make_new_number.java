import java.util.Scanner;

public class Main{
	public static void main(String args[]){
		Scanner sc = new Scanner(System.in);
		int first_num = sc.nextInt();
		int sum = 0, cycle = 0, n = first_num;

		while(true){
			sum = (n / 10) + (n % 10);
			n = (n % 10) * 10 + (sum % 10);
			cycle++;

			if(first_num == n)
				break;	
		}
		System.out.println(cycle);
	}
}
/*
input
55
output
3
*/
