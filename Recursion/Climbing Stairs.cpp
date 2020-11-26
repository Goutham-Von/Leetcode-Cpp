class Solution {
public:
    int climbStairs(int n) {
        // problem is similar to a fibonacci sequence
        if(n == 0 || n == 1 || n == 2)
            return n;
        int first = 1, second = 2, answer;
        for(int i = 3; i <= n; i++)
        {
            answer = first + second;
            first = second;
            second = answer;
        }
        return answer;
    }
};
/*
Using Recursive Method
*/
class Solution {
public:
    map<int, int> count;
    int climbStairs(int n) {
        if (n == 1 or n == 0){
            return 1;
        } else if(n < 0){
            return 0;
        }
        if (count.find(n) != count.end()){
            return count[n];
        }
        int steps = climbStairs(n - 1) + climbStairs(n - 2);
        count.insert({n, steps});
        return steps;
    }
};