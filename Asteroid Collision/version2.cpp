/*
Time complexity:O(n)
Space complexity:O(n),ans陣列來儲存答案
*/
#include <iostream>
#include <vector>
#include <stack>
using namespace std;
  
class Solution{    
public:
    vector<int> asteroidCollision(vector<int>& asteroids){
        stack <int> stack;
        for(int ast:asteroids){  //ast表示要模擬進入的行星，一一遍歷
            bool alive = true;   //一開始行星都設存活
            //while除外的條件為 1.堆疊為空 2.行星為+，代表往右 3.行星頂端為 - 往左
            //三條件都成立代表堆疊頂端的行星往右，有一行星往左與之碰撞，此while用來模擬每顆行星的進入
            while(!stack.empty() && ast<0 && stack.top()>0){ //使用while是讓剛進來的行星只要沒爆炸就能不斷比較
                if(stack.top()<-ast){
                    stack.pop();
                    continue; //直接繼續下個while
                }
                else if(stack.top() == -ast){
                    stack.pop();    
                }
                alive = false; //表示往左的行星小於等於堆疊頂端，爆炸
                break;         //此往左行星以爆炸，直接結束此次迴圈
            }
            if(alive == true){
                stack.push(ast);
            }
        }
        vector<int> result(stack.size());
        for(int i=result.size()-1;i>=0;i--){  //stack.top是輸出陣列的最尾端，所以要從尾部遍歷
            result[i] = stack.top();
            stack.pop();
        }
        return result;
    }
};
int main(){
    Solution s;
    vector<int> asteroids = {5,10,-5}; 
    vector<int> ans = s.asteroidCollision(asteroids);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
}