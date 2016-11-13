import java.util.Scanner;
import java.math.*;

public class ComplexNumber
{
    double real;
    double img;
    double magnitude;
    double arg;

    public ComplexNumber(){
    	this.real = 0.0;
        this.img = 0.0;
        magnitude = 0.0;
        arg = 0.0;
    }
    
    public ComplexNumber(double real,double img){
        this.real = real;
        this.img = img;
        magnitude = Math.sqrt(real*real + img*img);
        arg = Math.toDegrees(Math.atan(img/real));
    }
    
    public void showTheNumber(){
            System.out.println(real+"+"+img+"i" + "\n" +"# Magnitude : " + magnitude + "\n# Argument : "+ arg);
    }
   
    
    public ComplexNumber add(ComplexNumber c){
            double rl = this.real+c.real;
            double im = this.img+c.img;
            ComplexNumber cc = new ComplexNumber(rl,im);
            return cc;
    }
    
    public ComplexNumber sub(ComplexNumber c){
        double rl = this.real-c.real;
        double im = this.img-c.img;
        ComplexNumber cc = new ComplexNumber(rl,im);
        return cc;
    }
    
    public ComplexNumber multiplication(ComplexNumber c){
        double rl = this.real*c.real;
        double im = this.img*c.img;
        ComplexNumber cc = new ComplexNumber(rl,im);
        return cc;
    }
    
    public double magnitude(){
    	return Math.sqrt(real*real + img*img);
    }
    
    public ComplexNumber add(ComplexNumber c1,ComplexNumber c2){
            return new ComplexNumber(c1.real+c2.real,c1.img+c2.img);
    }
    
    public static void main(String[] args){
    	System.out.println("Complex 1 :");
        ComplexNumber c1 = new ComplexNumber(3,4);
        c1.showTheNumber();
        System.out.println("Complex 2 :");
        ComplexNumber c2 = new ComplexNumber(2,3);
        c2.showTheNumber();
        System.out.println("Complex add :");
        c1.add(c2).showTheNumber();
        System.out.println("Complex Multiplication :");
       // System.out.println(c1.magnitude());
        c1.multiplication(c2).showTheNumber();
    }
}
