//We traverse both string and pick each of words,so the time complexity of it is O(n),
//since n is the length of the longest words

//Space complexity is O(1)

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string result = "";
        int i = 0; 
        while(i < word1.length()||i < word2.length()){
            if(i < word1.length()){
                result+=word1[i];
            }
            if(i < word2.length()){
                result+=word2[i];
            }
            i++;
        }
        return result;
    }
};
int main(){
    string str1 = "abc";
    string str2 = "pder";
    Solution s;
    string result = s.mergeAlternately(str1,str2);
    cout<<result;
}