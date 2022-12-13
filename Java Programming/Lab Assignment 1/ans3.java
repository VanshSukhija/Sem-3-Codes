import java.util.Scanner;
public class ans3 {
    public static void main(String args[]){
        Scanner scan = new Scanner(System.in);
        System.out.print("Enter Height in inches : ");
        double height = scan.nextDouble();
        if (height == 0.0d)
            System.out.println("Sorry, height can not be zero");
        height *= 0.0254;
        System.out.print("Enter weight in pounds : ");
        double weight = scan.nextDouble();
        weight *= 0.45359237;
        double BMI = weight / (height * height);
        System.out.println("BMI is " + BMI);
        scan.close();
    }
}