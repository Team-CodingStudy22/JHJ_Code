package jspbook.pr34;

public class Calculator {
	private int op1;
	private int op2;
	String operator;
	
	public int getOp1() {
		return op1;
	}
	public void setOp1(int op1) {
		this.op1 = op1;
	}
	public int getOp2() {
		return op2;
	}
	public void setOp2(int op2) {
		this.op2 = op2;
	}
	public String getOperator() {
		return operator;
	}
	public void setOperator(String operator) {
		this.operator = operator;
	}
	
	private int add(int a, int b) {return a+b;}
	private int sub(int a, int b) {return a-b;}
	private int mult(int a, int b) {return a*b;}
	private int div(int a, int b) {return a/b;}
	
	public int calc() {
		if(operator.equals("+"))
			return add(op1, op2);
		else if(operator.equals("-"))
			return sub(op1, op2);
		else if(operator.equals("*"))
			return mult(op1, op2);
		else if(operator.equals("/"))
			return div(op1, op2);
		else
			return -1;
	}
	
}
