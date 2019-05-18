import java.io.*;

public class Main {
	public static void main(String args[]){
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		String line;
		try{
			while((line = br.readLine()) != null){
				if (!line.isEmpty()) { 
					{line = br.readLine();
					bw.write(line);
					bw.newLine();}
			}
			br.close();
			bw.close();
		} catch (IOException e) {
    		e.printStackTrace();
		} 	
	}
}