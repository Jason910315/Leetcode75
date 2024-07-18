/*
Time complexity:O(n)
Space complexity:O(n-m)
此方法完全採用Stack FILO的概念，當遇到不是'*'的字元則push進stack(此處是字串)，當遇到'*'則對stack作一次pop
因為新字串裡不會有'*'產生，所以不用怕遇到連續'*'而出現錯誤的情形。  
*/

#include <iostream>
#include <string>
#include <algorithm> 
using namespace std;
class Solution{
public: //leet**cod*e
    string removeStars(string s){  
        string ans;
        for(int i = 0;i < s.size();i++){
            if(s[i] != '*'){
                ans.push_back(s[i]);
            }
            else{
                ans.pop_back();
            }
        }
        return ans;              
    }
};

int main(){
    Solution s; 
    string str = "abb*cdfg*****x*";
    string ans = s.removeStars(str);
    cout<<ans;
}