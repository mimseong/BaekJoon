import java.io.*;
import java.util.StringTokenizer;

public class Main{
	public static void main(String args[]){
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

		int subject_num;
		double best_score, sum = 0;
		StringTokenizer st;

		try {
			subject_num = Integer.parseInt(br.readLine());
			double [] score = new double[subject_num];

			st = new StringTokenizer(br.readLine());
			score[0] = Double.parseDouble(st.nextToken());
			best_score = score[0];
			for(int i = 1; i < subject_num; i++){
				score[i] = Double.parseDouble(st.nextToken());				
				if(best_score < score[i])
					best_score = score[i];
			}
			for(int i = 0; i < subject_num; i++)
				sum += score[i] / best_score * 100;
			bw.write(Double.toString(sum / (double)subject_num));

			br.close();
			bw.close();
		} catch(IOException e) {
			e.printStackTrace();
		}
	}
}
/*
input 
	5
	1 2 4 8 16
output
	38.75
*/