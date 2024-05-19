//解題思路:不同於version1用for loop檢查字串是否存在母音，此算法創建一函示判斷字串元素是否有存在母音
//並且在不同情況下start、end該如何++ or --
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    bool isVowel(char c){
        if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u'||c=='A'||c=='E'||c=='I'||c=='O'||c=='U'){
            return true;
        }
        else{
            return false;
        }
    }
    string reverseVowels(string s) {
        int start = 0;
        int end = s.length()-1;
        while(start < end){
            if(isVowel(s[start]) && !isVowel(s[end])){
                end--;
            }
            else if(!isVowel(s[start]) && isVowel(s[end])){
                start++;
            }
            else if(isVowel(s[start]) && isVowel(s[end])){
                char temp = s[start];
                s[start] = s[end];
                s[end] = temp;
                start++;
                end--;
            }
            else{
                start++;
                end--;
            }
        }
        return s;
        
    }
};

int main(){
    string name = "leetcode";
    Solution s;
    string result = s.reverseVowels(name);
    cout<<result;
}