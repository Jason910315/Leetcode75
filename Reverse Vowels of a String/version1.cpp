//Time complexity:O(n),we use i,j to traverse all string
//Space complexity:O(1),we use the original input string ti manipulate thr proccess

#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    string reverseVowels(string s) {
        int i = 0;
        int j = s.length()-1;
        char vowels[] = {'a','e','i','o','u','A','E','I','O','U'};
       
        while(i < j){
            bool left = false;
            bool right = false;
            for(int m = 0;m < 10;m++){
                if(s[i]==vowels[m]){
                    left = true;
                }
                if(s[j]==vowels[m]){
                    right = true;
                }
            }
            if(left&&right){
                char temp = s[i];
                s[i] = s[j];
                s[j] = temp;
                i++;
                j--;
            }
            if(!left){
                i++;
            }
            if(!right){
                j--;
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