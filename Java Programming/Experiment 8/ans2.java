public class ans2 {
    static class outer{
        public void outermeth(){
            inner i = new inner();
            i.innermeth();
        }
        private class inner{
            private void innermeth(){
                System.out.println("This is the private method of the inner class");
            }
        }
    }
    public static void main(String[] args){
        outer o = new outer();
        o.outermeth();
    }
}