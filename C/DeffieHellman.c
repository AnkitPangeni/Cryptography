#include <stdio.h>
//function to compute 'a^m mode n'
int compute(int a, int m, int n)
{
	int r;
	int y=1;
	while(m>0)
	{
	r=m%2;
	//fast exponention
	if(r==1){
		y=(y*a) %n;
	}	
	a=a*a%n;
	m=m/2;
	}
	
	return y;
}

int main()
{
	int p=23; // modulus
	int g=5; // base
	// a= Alices secret key, b=Bobs secret key
	int a,b;
	int A,B;
	a=6;
	A=compute(g,a,p);
	b=15;
	B=compute(g,b,p);
	// Alice and Bob exchange their public key 'A' and 'B' with each other
	int keyA=compute(B,a,p);
	int keyB=compute(A,b,p);
	
	printf("Alices's secret key is %d \n Bobs secret key is %d", keyA,keyB);
	return 0;
}
	

