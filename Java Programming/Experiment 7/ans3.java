public class ans3 {
    interface A{
        void A1();
        void A2();
    }
    interface B{
        void B1();
        void B2();
    }
    interface C{
        void C1();
        void C2();
    }
    interface D extends A, B, C{
        void D1();
    }
    static class temp implements D{
        public void A1(){
            System.out.println("Function A1");
        }
        public void A2(){
            System.out.println("Function A2");
        }
        public void B1(){
            System.out.println("Function B1");
        }
        public void B2(){
            System.out.println("Function B2");
        }
        public void C1(){
            System.out.println("Function C1");
        }
        public void C2(){
            System.out.println("Function C2");
        }
        public void D1(){
            System.out.println("Function D1");
        }
    }
    public static void main(String[] args){
        temp t = new temp();
        t.A1();
        t.B1();
        t.C1();
        t.D1();
    }
}
