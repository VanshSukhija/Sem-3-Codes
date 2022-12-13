public class ans2 {
    interface tempinterface{
        void method1();
    }
    static class tempclass implements tempinterface{
        public void method1(){
            System.out.println("Public method 1");
        }
    }
    public static void main(String[] args){
        tempclass t = new tempclass();
        t.method1();
    }
}
