
public class Complex {
	private ComplexNumber[] Q;
	private int upperpointer;
	private int lowerpointer;
	
	public Complex() {
		Q=new ComplexNumber[100];
		upperpointer=0;
		lowerpointer=0;
		
	}
	public Complex(int size) {
		Q = new ComplexNumber[size];
		
	}
	public Complex(int size,double initreal,double initimag) {
	
		
	}
	public void addItem(ComplexNumber Item){
		Q[upperpointer]=Item;
		upperpointer++;
	}
	public void addItem(double real,double imag){
		Q[upperpointer]=new ComplexNumber(real,imag);
		upperpointer++;
	}
	public void removeItem(){
		lowerpointer++;
	}
	public void show(){
		for (int i = lowerpointer; i < upperpointer; i++) {
			Q[i].showTheNumber();
			
		}
	}
	
}

