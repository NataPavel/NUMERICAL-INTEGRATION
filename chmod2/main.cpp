#include <iostream>
#include <math.h>
#include <iomanip> 

using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
double t[6] = {0.019, 0.127, 0.346, 0.417, 0.527, 0.696};
double u[6] = {0.258154, 0.277943, 0.323465, 0.339951, 0.367354, 0.414309}; // інтеграл за вольфрамом

double f1(double x, int i){
	return exp(t[i]*x)*(1+pow(x, 2))*((sin(x))/(x+2));
}
double I1(int k){
    double a = 0, b = 1;
    double h = 0.001; 
    double x0 = a;
    double x1 = a + h;
    
    double sum = 0;
  	
    for (double i = 0; i <= 1; i+=0.001) {
	sum += f1(x0, k) + 4*f1((i+i+ h)/2, k) + f1(x1, k);
	x0 += h;
	x1 += h;
    }	
    return (h/6) * sum;
	 
}

int main(int argc, char** argv) {
	cout<<setw(7)<<"a | "<< setw(10)<< "I | "<<setw(10)<< "I*(WolframAlpha)"<<endl;
	for(int k = 0; k < 6; k++){
	     cout<<setw(4)<<t[k]<< " | "<<setw(7)<<I1(k)<< " | "<<setw(7)<<u[k]<<endl;
	}
	return 0;
}
