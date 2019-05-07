import java.util.Scanner;

public class Main {
	public static void main(String args[])
	{
		Scanner sc = new Scanner(System.in);
		int month = sc.nextInt();
		int day = sc.nextInt();
		int sum = 0;

		for(int i = 2; i <= month; i++)
		{	switch(i)
			{
				case 2: case 4: case 6: case 8: case 9: case 11:
					sum += 31;
					break;
				case 5: case 7: case 10: case 12:
					sum += 30;
					break;
				case 3:
					sum += 28;
					break;
			}
		}
		sum = (sum + day) % 7;

		switch(sum){
			case 1:
				System.out.print("Mon");
				break;
			case 2:
				System.out.print("TUE");
				break;
			case 3:
				System.out.print("WED");
				break;
			case 4:
				System.out.print("THU");
				break;
			case 5:
				System.out.print("FRI");
				break;
			case 6:
				System.out.print("SAT");
				break;
			case 0:
				System.out.print("SUN");
				break;	
		}
	}
}