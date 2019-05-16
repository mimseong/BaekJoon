import java.io.*;
import java.util.StringTokenizer;

public class Main {
	public static void main(String args[]){
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

		int n1, n2, result;
		StringTokenizer st;
		
		try{
   		 	int inputNum = Integer.parseInt(br.readLine());
			for(int i = 0; i < inputNum; i++){
				st = new StringTokenizer(br.readLine());
				n1 = Integer.parseInt(st.nextToken());
				n2 = Integer.parseInt(st.nextToken());

				result = LCM(n1, n2);

				bw.write(Integer.toString(result));
				bw.newLine();
			}
			br.close();
			bw.close();
		} catch (IOException e) {
    		e.printStackTrace();
		} 	
	}

	public static int LCM(int n1, int n2){
		return ((n1 * n2) / GCD(n1, n2));
	}

	public static int GCD(int n1, int n2){
		if(n2 == 0)
			return n1;
		return GCD(n2, n1 % n2);
	}
}
/*
<input>
	3
	1 45000
	6 10
	13 17

<output>
	45000
	30
	221

*/