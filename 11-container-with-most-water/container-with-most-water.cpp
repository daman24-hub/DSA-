class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size();
        int left=0;
        int right=n-1;
        int maxwater=0;
        while(left<right){
            
                int width=right-left;
                int ht=min(height[left],height[right]);
                int area=width*ht;
                maxwater=max(area,maxwater);
        height[left]<height[right]?left++:right--;

            
        }
        return maxwater;
        
    }
};