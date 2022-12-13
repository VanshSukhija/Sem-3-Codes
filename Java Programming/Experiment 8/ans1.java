public class ans1 {
    static class outer{
        private int temp=10;
        private void outermeth1(){
            System.out.println("Value of temp: "+temp);
        }
        public class inner{
            public void innermeth1(){
                temp++;
                outermeth1();
            }
        }
        public void outermeth2(){
            inner i = new inner();
            i.innermeth1();
        }
    }
    public static void main(String[] args){
        outer o = new outer();
        o.outermeth2();
    }
}
