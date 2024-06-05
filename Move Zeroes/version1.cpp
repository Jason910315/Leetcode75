//Time complexity:O(n):we traverse all the array
//Space complexity:O(1),we just use the in-place space of this array
//解題思路:分為兩部分
//Steps1:for loop遍歷整個陣列，當遇到非零元素時，將nums[NonZero]修改為此非零元素，並NonZero++
//(此步驟若沒有遇到非零元素則NonZero不會++，故未修改前的NonZero位置必定為零)
//Steps2:經過步驟1後陣列前方就都是非零元素，此時只要將後方的元素都修改為零即可

//要注意陣列overflow的問題
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int NonZero = 0;
        for(int i = 0;i < nums.size();i++){
            if(nums[i]!=0){
                nums[NonZero++] = nums[i];   //另一種方法在此使用swap(nums[i],nums[NonZero])，即可直接交換兩數，而以下迴圈也不必跑
            }
        }
        for(int i = NonZero;i < nums.size();i++){
            nums[i] = 0;
       }
    }
};

int main(){
    vector<int> nums = {1,0,3,6,0,5,0};
    Solution s;
    s.moveZeroes(nums);
    for(int i = 0;i<nums.size();i++){
        cout<<nums[i];
    }
}