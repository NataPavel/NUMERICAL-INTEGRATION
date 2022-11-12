#include <iostream>
#include <math.h>
#include <iomanip> 

using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
double t[6] = {0.019, 0.127, 0.346, 0.417, 0.527, 0.696};
double u[6] = {0.258154, 0.277943, 0.323465, 0.339951, 0.367354, 0.414309}; // інтеграл за вольфрамом

/*
double f1(double x){
	return exp(t[0]*x)*(1+pow(x, 2))*((sin(x))/(x+2));
}
double f2(double x){
	return exp(t[1]*x)*(1+pow(x, 2))*((sin(x))/(x+2));
}
double f3(double x){
	return exp(t[2]*x)*(1+pow(x, 2))*((sin(x))/(x+2));
}

double f4(double x){
	return exp(t[3]*x)*(1+pow(x, 2))*((sin(x))/(x+2));
}
double f5(double x){
	return exp(t[4]*x)*(1+pow(x, 2))*((sin(x))/(x+2));
}
double f6(double x){
	return exp(t[5]*x)*(1+pow(x, 2))*((sin(x))/(x+2));
}*/
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
/*
double I1(){
	double a = 0, b = 1;
	double h = 0.001; 
	double x0 = a;
    double x1 = a + h;
    
    double sum = 0;
    
    for (double i = 0; i <= 1; i+=0.001) {
        sum += f1(x0) + 4*f1((i+i+ h)/2) + f1(x1);
        x0 += h;
        x1 += h;
    }
    return (h/6) * sum;
    
}
double I2(){
	double a = 0, b = 1;
	double h = 0.001; 
	double x0 = a;
    double x1 = a + h;
    
    double sum = 0;
    
    for (double i = 0; i <= 1; i+=0.001) {
        sum += f2(x0) + 4*f2((i + i+ h)/2) + f2(x1);
        x0 += h;
        x1 += h;
    }
    return (h/6) * sum;
}
double I3(){
	double a = 0, b = 1;
	double h = 0.001; 
	double x0 = a;
    double x1 = a + h;
    
    double sum = 0;
    
    for (double i = 0; i <= 1; i+=0.001) {
        sum += f3(x0) + 4*f3((i + i+ h)/2) + f3(x1);
        x0 += h;
        x1 += h;
    }
    return (h/6) * sum;
}

double I4(){
	double a = 0, b = 1;
	double h = 0.001; 
	double x0 = a;
    double x1 = a + h;
    
    double sum = 0;
    
    for (double i = 0; i <= 1; i+=0.001) {
        sum += f4(x0) + 4*f4((i + i+ h)/2) + f4(x1);
        x0 += h;
        x1 += h;
    }
    return (h/6) * sum;
}
double I5(){
 double a = 0, b = 1;
	double h = 0.001; 
	double x0 = a;
    double x1 = a + h;
    
    double sum = 0;
    
    for (double i = 0; i <= 1; i+=0.001) {
        sum += f5(x0) + 4*f5((i + i+ h)/2) + f5(x1);
        x0 += h;
        x1 += h;
    }
    return (h/6) * sum;
}
double I6(){
	double a = 0, b = 1;
	double h = 0.001; 
	double x0 = a;
    double x1 = a + h;
    
    double sum = 0;
    
    for (double i = 0; i <= 1; i+=0.001) {
        sum += f6(x0) + 4*f6((i + i+ h)/2) + f6(x1);
        x0 += h;
        x1 += h;
    }
    return (h/6) * sum;
}
*/
int main(int argc, char** argv) {

	cout<<setw(7)<<"a | "<< setw(10)<< "I | "<<setw(10)<< "I*(WolframAlpha)"<<endl;
	for(int k = 0; k < 6; k++){
		cout<<setw(4)<<t[k]<< " | "<<setw(7)<<I1(k)<< " | "<<setw(7)<<u[k]<<endl;
	}
	/*cout<<setw(4)<<t[0]<< " | "<<setw(7)<<I1()<< " | "<<setw(7)<<u[0]<<endl;
	cout<<setw(4)<<t[1]<< " | "<<setw(7)<<I2()<< " | "<<setw(7)<<u[1]<<endl;
	cout<<setw(4)<<t[2]<< " | "<<setw(7)<<I3()<< " | "<<setw(7)<<u[2]<<endl;
	cout<<setw(4)<<t[3]<< " | "<<setw(7)<<I4()<< " | "<<setw(7)<<u[3]<<endl;
	cout<<setw(4)<<t[4]<< " | "<<setw(7)<<I5()<< " | "<<setw(7)<<u[4]<<endl;
	cout<<setw(4)<<t[5]<< " | "<<setw(7)<<I6()<< " | "<<setw(7)<<u[5]<<endl;*/
	return 0;
}
