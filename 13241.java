import java.io.*;
import java.util.StringTokenizer;

public class Main {
	public static void main(String args[]){
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

		long n1, n2;
		StringTokenizer st;
		
		try{
			st = new StringTokenizer(br.readLine());
			n1 = Long.parseLong(st.nextToken());
			n2 = Long.parseLong(st.nextToken());

			bw.write(Long.toString(GCD(n1, n2)) + '\n');
			bw.write(Long.toString(LCM(n1, n2)));

			br.close();
			bw.close();
		} catch (IOException e) {
    		e.printStackTrace();
		} 	
	}

	public static long LCM(long n1, long n2){
		return ((n1 * n2) / GCD(n1, n2));
	}

	public static long GCD(long n1, long n2){
		if(n2 == 0)
			return n1;
		return GCD(n2, n1 % n2);
	}
}
/*
<input>
	121 199

<output>
	24079
*/