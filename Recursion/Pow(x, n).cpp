class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0) return 1;
        if (x == 0) return 0;
        if (n == 2) return (x * x);
        if (n == 1) return x;
        if (n == INT_MIN) return x * myPow(x, INT_MIN + 1);
        bool fraction = false;
        if (n < 0)
        {
            fraction = true;
            n = -n;
        }
        double result;
        result = myPow(x, n /2);
        result = result * result;
        if (n % 2 != 0) result = result * x;
        if (fraction) result = 1 / result;
        return result;
    }
};
/*
Another Method
*/
class Solution {
public:
    double myPow(double x, int n) { 
        if(n==0) return 1;
        double k = 1;
        if (n%2 != 0){
            k = x;
        }
        if (n < 0) k = 1/k;
        n = n/2;
        if(n<0){
            n *= -1;
            x = 1/x;
        }
        return k*myPow(x*x, n);
    }
};