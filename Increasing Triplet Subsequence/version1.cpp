//解題思路:使用兩個變數來維護最小及第二小之值，當找到一個值大於此兩個變數，代表已找到increasing triplet
//case1:nums[i]<=最小 => 最小更新成nums[i]
//case2:nums[i]>最小且nums[i]<=第二小 => 第二小更新成nums[i]
//case3:當nums[i]都沒有小於最小與第二小，代表已找到increasing triplet，返回true
//Time complexity:O(n),we traverse all numbers in array
//Space complexity:O(1),we use just only consatnt variable

#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int first_min = INT_MAX;  //最小之值
        int second_min = INT_MAX; //第二小之值
        for(int i = 0;i < nums.size();i++){
            if(nums[i] <= first_min){  //case1  1 1 -2 6
                first_min = nums[i];
            }
            else if(nums[i] <= second_min){ //case2
                second_min = nums[i];
            }
            else if(nums[i] > second_min){    //case3
                return true;
            }
        }
        return false;
    }
};
int main(){
    vector<int> nums = {1,1,-2,6};
    Solution s;
    bool result = s.increasingTriplet(nums);
    cout<<result;

}