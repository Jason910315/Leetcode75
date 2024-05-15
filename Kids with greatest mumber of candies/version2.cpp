#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

class Solution {
public:
vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool> result;
        int Max = *max_element(candies.begin(),candies.end());
        for(int i = 0;i < candies.size();i++){
            candies[i] = candies[i] + extraCandies;
        }
        for(int i = 0;i < candies.size();i++){
            result.push_back(candies[i] >= Max);
        }
        return result;       
    }
};
int main(){
    vector<int> candies = {2,3,5,1,2};
    int extracandies = 3;
    Solution s;
    vector<bool> result = s.kidsWithCandies(candies,extracandies);
    int i;
    int n = result.size();
    for(i = 0;i < n;i++){
    cout<<result[i]<<" ";
    }
}