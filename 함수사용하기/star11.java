import java.util.Scanner;

public class Main{
	public static void main(String args[]){
		Scanner sc = new Scanner(System.in);
		int input = sc.nextInt();
		StarTower(input);

	}

	public static void StarTower(int n){
		int i, j;
		for(i = 0; i < n/3; i++){
			for(j = 0;;)
				EmptyBox();
			for(j = 0;;)
				EmptyTriangle
			for(j = 0;;)
		}
	}

	public static void EmptyBox(){
		System.out.println("     ");
		System.out.println("     ");
		System.out.println("     ");
	}
	public static void EmptyTriangle(){
		System.out.println("   ");
		System.out.println("  ");
		System.out.println(" ");		
	}
	public static void UpsideEmptyTriangle(){
		System.out.println("     ");
		System.out.println("   ");
		System.out.println(" ");		
	}
	public static void Star(){
		System.out.println("*");
		System.out.println("*  *");
		System.out.println("*****");
	}
}