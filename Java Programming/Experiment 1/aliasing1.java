import java.lang.*;
import java.util.*;

class Alias{
    float flt = 0.69f;
};

public class aliasing1{
    public static void main(String args[]){
        Alias al = new Alias();
        Alias temp = al;
        System.out.println("al: "+al.flt);
        System.out.println("temp: "+temp.flt);
    }
};