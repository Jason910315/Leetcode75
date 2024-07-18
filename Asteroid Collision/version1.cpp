/*
Time complexity:O(n)
Space complexity:O(n),ans陣列來儲存答案

範例:Input:{-7,-2,5,4,-3,6,-5}
    Output:{-7,5,4,6}
因為行星的移動規則，最終結果必定是[-,-,...,+,+,+]這種格式，否則若+在-左邊則會相撞，不是一個穩定態，
遍歷整個陣列 asteroids[i]:
step1 : + 當作穩定，只要遇到 + 代表行星往右，都push進vector，
step2 : 遇到 - :(行星往左)
        case1 : (若stack為空或stack.top是-)，直接push
        case2 : 承上述若不空或stack.top為+，則代表行星相撞，要比較，若往左的行星較大，則破壞原本stack.top繼續比較
        或兩者size相等則破壞行星，迴圈繼續
*/

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
   
class Solution{    
public:
    vector<int> asteroidCollision(vector<int>& asteroids){
        vector<int> ans;
        for(int i=0;i<asteroids.size();i++){
            int weight = asteroids[i];
            if(weight>0){
                ans.push_back(weight);
            }
            else{  //weight<0
                if(ans.empty() || ans.back()<0){  //stack為空或stack.top為-(往左)
                    ans.push_back(weight);
                }
                else if(abs(ans.back()) <= abs(weight)){    //stack.top為+(往右)會相撞，比較大小
                    if(abs(ans.back()) < abs(weight)){  //代表stack頂端的要被破壞，往左的要持續比較
                        i--;                            //故要固定迴圈，i--
                    }
                    ans.pop_back();                      
                }
            }
        }
        return ans;
    }
};
int main(){
    Solution s;
    vector<int> asteroids = {10,2,-5}; 
    vector<int> ans = s.asteroidCollision(asteroids);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
}