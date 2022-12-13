import java.util.*;
public class ans1 {
    public static void main(String args[]){
        int num;
        Scanner scan = new Scanner(System.in);
        System.out.print("Enter a number: ");
        num = scan.nextInt();
        int mul=1;
        for(int i=1; num/i>0; i*=10){
            mul *= (num/i)%10;
        }
        System.out.println("Product of integers: "+mul);
        scan.close();
    }
}