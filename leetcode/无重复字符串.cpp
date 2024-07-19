class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len=s.size();
        if(len==0){
            return 0;
        }
        int left=0,right=0,result=0,bestresult=0;
        unordered_map<char,int> hash;
        while(right<len){
            hash[s[right]]++;
            while(hash[s[right]]>1){
                hash[s[left]]--;
                left++;}
            result=right-left+1;
            if(result>bestresult){
                bestresult=result; }       
            right++;
        }
        return bestresult==0?1:bestresult;
    }
};
