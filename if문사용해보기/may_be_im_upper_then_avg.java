import java.io.*;
import java.util.StringTokenizer;

public class Main{
	public static void main(String args[]){
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

		int testcase_num, student_num, count = 0;
		double [] score;
		double sum = 0.0, avg, tmp;
		StringTokenizer st;

		try {
			testcase_num = Integer.parseInt(br.readLine());
			
			for(int i = 0; i < testcase_num; i++){
				st = new StringTokenizer(br.readLine());	//read one line
				student_num = Integer.parseInt(st.nextToken());		//first token
				score = new double[student_num];

				for(int j = 0; j < student_num; j++){
					score[j] = Double.parseDouble(st.nextToken());
					sum += score[j];
				}
				avg = sum / (double)student_num;
				
				for(int j = 0; j < student_num; j++){
				 	if(score[j] > avg)
				        count++;
				}
				tmp = ((double)count / (double)student_num * 100);
				bw.write(String.format("%.3f", tmp) + "%\n");
				count = 0;
				sum = 0;
			}

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
	5 50 50 70 80 100
	7 100 95 90 80 70 60 50
	3 70 90 80
	3 70 90 81
	9 100 99 98 97 96 95 94 93 91

output
	40.000%
	57.143%
	33.333%
	66.667%
	55.556%
*/