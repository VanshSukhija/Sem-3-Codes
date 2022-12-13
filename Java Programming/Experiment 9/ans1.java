import java.io.FileNotFoundException;

public class ans1 {
    ans1(String msg){
        System.out.println("Message in Constructor");
    }
    public static void main(String[] args)
    throws Exception {
        try {
            throw new FileNotFoundException();
        } 
        catch (FileNotFoundException e) {
            throw new Exception("File not found");
        } 
        catch (Exception e) {
            System.out.println(e.getMessage());
        } 
        finally {
            System.out.println("'Finally' is called");
        }
    }
}