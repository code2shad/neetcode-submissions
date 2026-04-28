class Solution {
public:
    int climbStairs(int n) {
        int prev2 = 1, prev = 2;

        if(n == 1) return 1;
        if(n == 2) return 2;
        int curr = 0;
        for(int i = 3; i <= n; i++ ){
            curr = prev + prev2;
            prev2 = prev;
            prev = curr;
        }

        return prev;
    }
};
