class Temp{
    private void pri_method(){
        System.out.println("This is a Private method");
    }
    public void pub_method(){
        System.out.println("This is a Public method");
    }
    protected void pro_method(){
        System.out.println("This is a Protected method");
    }
};
public class ans1 {
    public static void main(String[] args){
        Temp t = new Temp();
        // t.pri_method();
        t.pub_method();
        t.pro_method();
    }
}
