import java.util.Scanner;

public class Main{
	public static void main(String args[]){
		Scanner sc = new Scanner(System.in);
		int[] num = new int[3];
		int tmp;
		for(int i = 0; i < 3;i++){
			num[i] = sc.nextInt();
		}
		if(num[0] > num[1]){
			tmp = num[1];
			num[1] = num[0];
			num[0] = tmp;
		}
		if(num[0] > num[2]){
			tmp = num[2];
			num[2] = num[0];
			num[0] = tmp;
		}
		if(num[1] > num[2]){
			tmp = num[1];
			num[1] = num[2];
			num[2] = tmp;
		}		
		System.out.println(num[1]);
	}
}