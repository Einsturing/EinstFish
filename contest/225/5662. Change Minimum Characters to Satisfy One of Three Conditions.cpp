//难度-中等
//周赛第二题，遍历每个字母作为基准，统计a和b中满足条件的字母的个数，三种方法各统计一次求最小
class Solution {
public:
    int minCharacters(string a, string b) {
        int la = a.size();
        int lb = b.size();
        vector<int> va(26, 0), vb(26, 0);
        for(char c : a) va[c - 'a']++;
        for(char c : b) vb[c - 'a']++;
        int res1 = la + lb;
        int res2 = la + lb;
        int res3 = la + lb;
        for(int i = 0; i < 25; i++) {
            int tmp = 0;
            for(int j = i + 1; j < 26; j++) tmp += va[j];
            for(int j = 0; j <= i; j++) tmp += vb[j];
            res1 = min(res1, tmp);
        }
        for(int i = 0; i < 25; i++) {
            int tmp = 0;
            for(int j = i + 1; j < 26; j++) tmp += vb[j];
            for(int j = 0; j <= i; j++) tmp += va[j];
            res2 = min(res2, tmp);
        }
        for(int i = 0; i < 26; i++) {
            int tmp = 0;
            for(int j = 0; j < 26; j++) {
                if(i == j) continue;
                tmp += va[j] + vb[j];
            }
            res3 = min(res3, tmp);
        }
        return min(res1, min(res2, res3));
    }
};