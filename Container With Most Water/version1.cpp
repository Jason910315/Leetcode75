#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size()-1;
        int maxArea = 0;
        while(left < right){
            int currentArea = (right-left) * min(height[left],height[right]);
            if(height[left] <= height[right]){
                left++;
            }
            else{
                right--;
            }
            if (currentArea > maxArea){
                maxArea = currentArea;
            }
        }
        return maxArea;
    }
};

int main(){
    vector<int> height = {1,8,6,2,5,4,8,3,7};
    Solution s;
    int Area = s.maxArea(height);
    cout<<Area;
}