class Solution {
public:
    int trap(vector<int>& height) {
        int l = 0, r = height.size() - 1;
        int lmax = 0, rmax = 0;
        int total = 0;

        while(l < r){
            if(height[l] <= height[r]){
                //We will cal the water always work on smaller one
                if(lmax > height[l]){
                    total += lmax - height[l];
                }
                else 
                  lmax = height[l];
                
                l++;
            }
            else{
                if(rmax > height[r]){
                    total += rmax - height[r];
                }
                else
                    rmax = height[r];
                
                r--;
            }
        }

        return total;
    }
};
