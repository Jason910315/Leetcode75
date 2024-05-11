#include <iostream>
#include <string>
using namespace std;

class Solution{
    public:
     string mergeAlternately(string word1, string word2){
        if(word1.length()==0){
            return word1;
        }
        if(word2.length()==0){
            return word2;
        }
        int minSize = word1.length();
        string result;
        if(word1.length() > word2.length()){
            minSize = word2.length();
        }
        int i;
        for(i = 0;i < minSize;i++){
            result+=word1[i];
            result+=word2[i];
        }
        if(word1.length() > word2.length()){
            for(;i < word1.length();++i){
                result+=word1[i];
            }
        }
        else{
            for(;i < word2.length();++i){
                result+=word2[i];
            }
        }
        return result;
     }
};

int main(){
    string str1 = "abc";
    string str2 = "pd e";
    Solution s;
    string result = s.mergeAlternately(str1,str2);
    cout<<result;
}

