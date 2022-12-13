public class ans1{
    public static class Dog{
        public void Bark(int num){
            System.out.println("Barking");
        }
        public void Bark(float num){
            System.out.println("Howling");
        }
    };
    public static void main(String args[]){
        Dog temp = new Dog();
        temp.Bark(12);
        temp.Bark(2.3f);
    }
}