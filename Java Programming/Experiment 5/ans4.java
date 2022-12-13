import java.util.*;
public class ans4 {
    static class A{
        final void printf(){
            System.out.println("printf() of class A");
        }
    }
    static class B extends A{
        void printf(){
            System.out.println("printf() of class B");
        }
    }
    static final class C{
        void temp(){
            System.out.println("Method of final class C");
        }
    }
    static class D extends C{
        void doratheexplorer(){
            System.out.println("Method of class D inherited by C");
        }
    }
    public static void main(String[] args){
        A a = new A();
        a.printf();
        B b = new B();
        b.printf();
        C c = new C();
        c.temp();
        D d = new D();
        d.doratheexplorer();
    }
}
