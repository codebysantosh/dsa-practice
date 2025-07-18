//Approach-1 (Using Recursion + Memoization)
class Solution {
public:
    int t[31];

    int solve(int n) {
        if(n <= 1) {
            return n;
        }

        if(t[n] != -1) {
            return t[n];
        }

        return t[n] = fib(n-1) + fib(n-2);
    }

    int fib(int n) {
        memset(t, -1, sizeof(t));

        return solve(n);
    }

//Approach-2 (Using Bottom Up DP)
class Solution {
public:
    int fib(int n) {
        if(n <= 1) {
            return n;
        }

        vector<int> t(n+1);
        //state definition
        //t[i] = ith fibonacci number

        t[0] = 0;
        t[1] = 1;

        for(int i = 2; i<n+1; i++) {
            t[i] = t[i-1] + t[i-2];
        }

        return t[n];
    }
};

//Approach-3 (Constant Space Complexity)
class Solution {
public:
    int fib(int n) {
        if(n <= 1) {
            return n;
        }

        int a = 0, b = 1;
        int c;

        for(int i = 1; i<n; i++) {

            c = a + b;

            a = b;
            b = c;

        }

        return c;
    }
};
