public class ans3 {
    public static class Temp{
        Temp(int num){
            System.out.println("Constructor with INTEGER parameter is called");
        }
        Temp(double num){
            this((int)num);
            System.out.println("Constructor with DOUBLE parameter is called");
        }
    }
    public static void main(String args[]){
        Temp t = new Temp(0.69);
    }    
}