import java.util.*;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		int N = sc.nextInt();
		
		int[] arr = new int[N];
		
		for(int i = 0; i < N; i++){
			arr[i] = sc.nextInt();
		}
		
		Arrays.sort(arr);
		
		int count = 0;
		int total = 1;
		
		for(int i = 0; i < N; i++) {
			if(arr[i] == total) {
				total = 1;
				count++;
			}else if(arr[i] > total){
				total++;
			}else {
				break;
			}
		}
		
		System.out.println(count);
	}
}
