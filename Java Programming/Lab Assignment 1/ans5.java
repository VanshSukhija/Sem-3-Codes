import java.util.Scanner;
public class ans5{
    public static void main(String[] s) {
        Scanner scan = new Scanner(System.in);
        int num1, num2;
        System.out.print("Enter 2 numbers: ");
        num1 = scan.nextInt();
        num2 = scan.nextInt();
        if(num2 > num1 || num2 == 0)
            System.out.println("Not a multiple");
        else{
            if(num1 % num2 == 0)
                System.out.println("Yes it is a multiple");
            else
                System.out.println("Not a multiple");
        }
        scan.close();
    }
}
