class Solution {
public:
    int kthGrammar(int N, int K) {
        if (N == 1) return 0;
        int x = kthGrammar(N - 1, (k+1)/2);
        if ((x == 0 and K%2 == 0) or (x == 1 and K%2 == 1)){
            return 1;
        }
        return 0;
    }
};
/*
*
*  Optimized Solution
*
*/
class Solution {
public:
    int kthGrammar(int N, int K) {
        if(N==1){
            return 0;
        }
        int x=kthGrammar(N-1,(K+1)/2);
        if(K%2==1)
        {
            return x;
        }
        else
        {
            if(x==1){
                return 0;
            }
            else{
                return 1;
            }
        }
    }
};