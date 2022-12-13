import java.util.*;

public class comparison1{
    static void compare(String str1, String str2){
        if(str1.equals(str2))
            System.out.println("Both strings are equal");
        else
            System.out.println("Strings are not equal");
    }
    public static void main(String args[]){
        Scanner scan = new Scanner(System.in);
        String str1, str2;
        System.out.print("Enter 1st String: ");
        str1 = scan.nextLine();
        System.out.print("Enter 2nd String: ");
        str2 = scan.nextLine();
        compare(str1, str2);
        scan.close();
    }
}