import java.util.Scanner;
public class ans6{
    public static void main(String[] s) {
        Scanner scan = new Scanner(System.in);
        int num1;
        System.out.print("Enter a number: ");
        num1 = scan.nextInt();
        System.out.print("Binary representation: ");
        String bin = Integer.toBinaryString(num1);
        System.out.println(bin);
        System.out.print("Octal representation: ");
        bin=Integer.toOctalString(num1);
        System.out.println(bin);
        System.out.print("Hexadecimal representation: ");
        bin=Integer.toHexString(num1);
        System.out.println(bin);
        scan.close();
    }
}
