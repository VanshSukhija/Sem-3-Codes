import java.util.*;
public class ans2 {
    public static void main(String args[]){
        long min;
        Scanner scan = new Scanner(System.in);
        System.out.print("Enter minutes: ");
        min = scan.nextInt();
        long days = min/(24*60);
        System.out.println("Number of years: "+days/365);
        System.out.println("Number of days: "+days%365);
        scan.close();
    }
}
