import java.util.Scanner;

public class Main{
	public static void main(String args[]){
		Scanner sc = new Scanner(System.in);
		int grade = sc.nextInt();
		if(90 <= grade && grade <= 100)
			System.out.println("A");
		else if(80 <= grade && grade < 90)
			System.out.println("B");
		else if(70 <= grade && grade < 80)
			System.out.println("C");
		else if(60 <= grade && grade < 70)
			System.out.println("D");
		else
			System.out.println("F");
	}
}