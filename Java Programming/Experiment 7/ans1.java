public class ans1 {
    static abstract class base{
        abstract void print();
        base(){
            print();
        }
    }
    static class derived extends base{
        int num = 69;
        void print(){
            System.out.println("num: "+num);
        }
    }
    public static void main(String[] args){
        derived d = new derived();
        d.print();
    }
}
