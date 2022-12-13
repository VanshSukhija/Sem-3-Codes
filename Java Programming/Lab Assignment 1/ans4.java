import java.util.Scanner;
public class ans4 {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        System.out.print("Enter Balance : ");
        double balance = scan.nextDouble();
        System.out.print("Enter annual interest rate : ");
        double annualRate = scan.nextDouble();
        double interest = (balance * annualRate) / 1200.0;
        System.out.println("Installment"+" "+ interest);
        scan.close();
    }
}
