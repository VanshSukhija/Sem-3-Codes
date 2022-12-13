import java.util.*;
public class ans1 {
    static class A{
        A(){
            System.out.println("Constructor for A");
        }
    };
    static class B{
        B(){
            System.out.println("Constructor for B");
        }
    };
    static class C extends A{
        B temp;
    }
    public static void main(String[] args){
        C temp = new C();
    }
}
