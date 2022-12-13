import java.util.*;

public class viva {
    public static void main(String[] args){
        HashMap<String, String> mp = new HashMap<>();
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the number of students in class: ");
        int n = sc.nextInt();
        System.out.println("Enter First name and Last name of students:");
        for(int i=0; i<n; i++){
            String a = sc.next();
            String s = sc.next();
            mp.put(a, s);
        }
        System.out.println("\nPrinting First name and Last name of Student");
        for(String i:mp.keySet()){
            System.out.println(i + '\t' + mp.get(i));
        }
        System.out.println("\nPrinting First name and Last name of Student");
        for(Map.Entry<String, String> i:mp.entrySet()){
            System.out.println(i.getKey() + '\t' + i.getValue());
        }
    }
}