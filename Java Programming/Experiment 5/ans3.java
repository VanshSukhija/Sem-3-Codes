import java.util.*;
public class ans3 {
    static class base{
        void meth(){
            System.out.println("Method 1");
        }
        void meth(int a){
            System.out.println("Method 2");
        }
        void meth(int a, int b){
            System.out.println("Method 3");
        }
    };
    static class derived extends base{
        void meth(double a){
            System.out.println("Method 4");
        }
    };
    public static void main(String[] args){
        derived d = new derived();
        d.meth();
        d.meth(10);
        d.meth(10, 20);
        d.meth(0.69);
    }
}
