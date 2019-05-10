import java.io.*;
import java.util.StringTokenizer;

public class Main{
	public static void main(String args[]){
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

		int n, x, count = 0, tmp;
		StringTokenizer st;

		try {
			st = new StringTokenizer(br.readLine());
			n = Integer.parseInt(st.nextToken());
			x = Integer.parseInt(st.nextToken());

			st = new StringTokenizer(br.readLine());
			for(int i = 0; i < n; i++){
				tmp = Integer.parseInt(st.nextToken());
				if(tmp < x){
					bw.write(Integer.toString(tmp) + " ");
				}
			}
			br.close();
			bw.close();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}
}
/*
input
	10 5
	1 10 4 9 2 3 8 5 7 6
output
	1 4 2 3
*/