//难度-中等
//遍历，保存最后遇到的下标
class Solution {
public:
    int findClosest(vector<string>& words, string word1, string word2) {
        int length = words.size();
        int ans = length;
        int idx1 = -1, idx2 = -1;
        for(int i = 0; i < length; i++) {
            if(words[i] == word1) idx1 = i;
            if(words[i] == word2) idx2 = i;
            if(idx1 >= 0 && idx2 >= 0) ans = min(ans, abs(idx1 - idx2));
        }
        return ans;
    }
};