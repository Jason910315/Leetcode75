//Time complexity:O(n).We iterate over the candies array to find Max,take O(n)
//and we iterate each kids whether they have the most candies,take O(n)
//Space complexity:O(1):the output string does not count

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int i;
        int Max = 0;
        for(i = 0;i < candies.size();i++){
            if(Max < candies[i]){
                Max = candies[i];
            }
        } 
        vector<bool> result(candies.size());
        for(i = 0;i < candies.size();i++){
            if((candies[i] + extraCandies) >= Max ){
                result[i] = true;
            }
            else{
                result[i] = false;
            }
        }
        return result;
    }
};
int main(){
    vector<int> candies = {2,3,5,1,2};
    int extracandies = 3;
    Solution s;
    vector<bool> result = s.kidsWithCandies(candies,extracandies);
    int i,n = result.size();
    for(i = 0;i < n;i++){
        cout<<result[i]<<" ";
    }
}