import java.util.Scanner;

public class ans7 {
    public static class Details{
        String first, last;
        long mobile;
        void display(){
            System.out.println("First Name: "+first);
            System.out.println("Last Name: "+last);
            System.out.println("Mobile: "+mobile);
        }
    }
    public static void main(String args[]){
        Scanner scan = new Scanner(System.in);
        int n;
        System.out.print("Enter number of details you will enter: ");
        n = scan.nextInt();
        String str[] = new String[n];
        for(int i=0; i<n; i++)
            str[i] = scan.nextLine();
        Details[] det = new Details [n];
        for(int i=0; i<n; i++){
            det[i].first = str[i].split(" ", 2)[0];
            det[i].last = str[i].split(" ", 2)[1];
            det[i].mobile = Long.parseLong(str[i].split("\t", 2)[1]);
        }
        for(int i=0; i<n; i++)
            det[i].display();
        scan.close();
    }
}
