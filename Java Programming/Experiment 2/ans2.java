public class ans2 {
    public static class Dog{
        String name, says;
        public void display(){
            System.out.println("Name: "+name);
            System.out.println("Says: "+says);
            System.out.println();
        }
    };
    public static void main(String args[]){
        Dog Spot = new Dog();
        Dog Scruffy = new Dog();
        Spot.name = "Spot";
        Spot.says = "Ruff!";
        Scruffy.name = "Scruffy";
        Scruffy.says = "Wurf!";

        Spot.display();
        Scruffy.display();

        Dog Temp = Spot;
        if(Temp==Spot)
            System.out.println("Temp and Spot are equal");
        else
            System.out.println("Temp and Spot are not equal");
    }
}