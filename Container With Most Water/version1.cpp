//Time complexuty:O(n),we traverse all the vector
//Space complexity:O(1)

//此題也是用兩個指標left、right紀錄，主要是currentArea及maxArea不斷比較決定哪個面積較大。
//注意要選擇left、right哪個要移動時，一定是較小的一方去移動，因為每次移動勢必會讓寬度減小1，而面積的高度影響主因會在較小的一方
//故如果較大一方移動必不會讓面積變更大。

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