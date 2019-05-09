import java.io.*;
import java.util.StringTokenizer;

public class Main {
	public static void main(String args[]){
		BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

		int n1, n2;
		StringTokenizer st;
		
		try{
   		 	int inputNum = Integer.parseInt(bf.readLine());
			for(int i = 0; i < inputNum; i++){
				st = new StringTokenizer(bf.readLine());
				n1 = Integer.parseInt(st.nextToken());
				n2 = Integer.parseInt(st.nextToken());
				bw.write((n1 + n2) + '\n');
			}
			bw.close();
		} catch (IOException e)
		{
    		e.printStackTrace();
		}
	}
}
/*
input 
	5
	1 1
	12 34
	5 500
	40 60
	1000 1000

output
	2
	46
	505
	100
	2000
*/