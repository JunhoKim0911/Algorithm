import java.util.*;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		String input = sc.next();

		int zeroStart = 0;
		int oneStart = 0;
		
		if(input.charAt(0) == '0')
			zeroStart++;
		else
			oneStart++;
		
		if(input.length() == 1)
		{
			System.out.println(1);
			return;
		}
		
		for(int i = 0; i < input.length() - 1; i++)
		{
			if(input.charAt(i) != input.charAt(i + 1))
			{
				if(input.charAt(i + 1) == '0')
					zeroStart++;
				else
					oneStart++;
			}
		}
		
		if(zeroStart <= oneStart)
			System.out.println(zeroStart);
		else
			System.out.println(oneStart);
	}
}