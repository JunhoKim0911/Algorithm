import java.util.*;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		String input = sc.next();
		
		int length = input.length();
		int first = input.charAt(0) - '0';
		
		if(length == 1) {
			System.out.println(first);
			return;
		}
		
		int answer = 0;
		int second = input.charAt(1) - '0';
		
		if(first < 2) {
			answer = first + second;
		}else {
			if(second < 2) {
				answer = first + second;
			}else {
				answer = first * second;
			}
		}
		
		for(int i = 2; i < length; i++) {
			int next = input.charAt(i) - '0';
			
			if(next < 2) {
				answer += next;
			}else {
				answer *= next;
			}
		}
		
		System.out.println(answer);
	}
}
