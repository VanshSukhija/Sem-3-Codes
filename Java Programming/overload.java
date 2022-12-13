public class overload{
  public static void main(String args[]){
    System.out.println("main() with string args");
    main(2);
    main(6.9);
    main(true);
  }
  public static void main(int args){
    System.out.println("main() with int args");
  }
  public static void main(double args){
    System.out.println("main() with double args");
  }
  public static void main(boolean args){
    System.out.println("main() with boolean args");
  }
}