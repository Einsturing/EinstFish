//难度-中等
//字符串模拟
class Solution {
public:
    string validIPAddress(string queryIP) {
        if(queryIP.find('.') != string::npos) {
            int l = -1;
            for(int i = 0; i < 4; i++) {
                int r = (i == 3 ? queryIP.size() : queryIP.find('.', l + 1));
                if(r == string::npos) return "Neither";
                if(r - (l + 1) < 1 || r - (l + 1) > 3) return "Neither";
                int sum = 0;
                for(int j = l + 1; j < r; j++) {
                    if(!isdigit(queryIP[j])) return "Neither";
                    sum = sum * 10 + (queryIP[j] - '0');
                }
                if(sum > 255) return "Neither";
                if(sum > 0 && queryIP[l + 1] == '0') return "Neither";
                if(sum == 0 && r - (l + 1) > 1) return "Neither";
                l = r;
            }
            return "IPv4";
        }
        else {
            int l = -1;
            for(int i = 0; i < 8; i++) {
                int r = (i == 7 ? queryIP.size() : queryIP.find(':', l + 1));
                if(r == string::npos) return "Neither";
                if(r - (l + 1) < 1 || r - (l + 1) > 4) return "Neither";
                for(int j = l + 1; j < r; j++) if(!isdigit(queryIP[j]) && !('a' <= tolower(queryIP[j]) && tolower(queryIP[j]) <= 'f')) return "Neither";
                l = r;
            }
            return "IPv6";
        }
    }
};