import java.util.*;
public class ans1 {
    static String str2;
    static{
        str2 = "Str-2";
    }
    static class Temp{
        static String str1 = "Str-1";
        static void print(){
            System.out.println(str1);
            System.out.println(str2);
        }
    }
    public static void main(String args[]){
        Temp t = new Temp();
        t.print();
    }
}
