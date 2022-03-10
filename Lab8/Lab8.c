#include <stdio.h>
#include <math.h>

#define PROMPT "Enter value for n:\n"

double geta(int x);
double getb(int n);
double getC(int n);
double gety(double a, double b, double c);
 
int main(){
    int n;

    printf(PROMPT);
    scanf("%d", &n);

    double a = geta(n);
    double b = getb(n);
    double c = getC(n);

    printf("n = %d\n", n);
    printf("a = %0.2lf\n", a);
    printf("b = %0.2lf\n", b);
    printf("c = %0.2lf\n", c);

    printf("The value of y =%.2f\n", gety(a, b, c));


    return 0;
}

double geta(int n){
    int sum=0;
    if(n < 3){
        int prod=1; 
        for(int i=1; i<=n; i++){
            prod = 1;
            for(int j=1; j<=i; j++){
                prod *= j+(1/i); 
            }
            sum += prod;
        }
        return sum;

    }else if(n>=3 && n<20){
        for(int i=1; i<=n; i++){
            sum+=i*2;
        }
        return 5 + sum;

    }else if(n >= 20){
        return sqrt((double)n);;
    }

    return n;
}

double getb(int n){

    switch(n){
        case 0 ... 4:
            return sqrt(n); 
        case 5 ... 24:
            return (n-1)*(n+2);
        case 25 ... 44:
            return n;
        default:
            return n;
    }
}



double getC(int n){
    if(n==1 || n==2){
        return n + cos(n);
    } 

    if(n>=3 && n<=5){
        return (double)n - 3;
    }

    if(n>5){
        return (double)n * 2;
        
    }

    return n;
}

double gety(double a, double b, double c){
    return a-b*(-c);
}