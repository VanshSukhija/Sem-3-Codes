import java.util.*;
public class ans2 {
    static class base{
        base(int a){
            System.out.println("Base is constructed");
        }
    };
    static class derived extends base{
        derived(){
            super(10);
            System.out.println("Default constructor of Derived");
        }
        derived(int a){
            super(a);
            System.out.println("Non-Default constructor of Derived");
        }
    };
    public static void main(String[] args){
        derived d = new derived();
        derived de = new derived(69);
    }
}