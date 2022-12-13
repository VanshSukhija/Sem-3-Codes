import java.lang.*;
import java.util.*;

public class prime2{
    public static void main(String agrs[]){
        Scanner scan = new Scanner(System.in);
        System.out.print("Enter a number: ");
        int num = scan.nextInt();
        System.out.print("Prime numbers till "+num+" are: ");
        for(int i=2; i<=num; i++){
            int j;
            for(j=2; j<i; j++){
                if(i%j==0)
                    break;
            }
            if(j==i)
                System.out.print(i+" ");
        }
        System.out.println();
    }
}