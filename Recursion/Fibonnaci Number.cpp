class Solution {
public:
    map<int, int> fibno;
    int fib(int N) {
        if (fibno.find(N) == fibno.end()){
            if (N == 0 or N == 1) return N;
            int res = fib(N-1) + fib(N-2);
            fibno.insert({N, res});
            return res;
        }
        return fibno[N];
    }
};