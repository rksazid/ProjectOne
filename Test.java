
public class Test {
public Complex q1;
public ComplexNumber c1;
public ComplexNumber c2;
public void TestRun(){
	q1=new Complex(10);		
	c1=new ComplexNumber(10.3,10.0);
	c2=new ComplexNumber(10.3,10.0);
	q1.addItem(c1);
	q1.addItem(c2);
	q1.show();
}
	public static void main(String[] args) {
		Test c = new Test();
		c.TestRun();

	}

}
