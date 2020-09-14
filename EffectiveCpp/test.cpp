#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

int compute(int x, int y, char s) {
    if(s == '+') return x + y;
    if(s == '-') return x - y;
    if(s == '*') return x*y;
    if(s == '/') return x/y;
    return -1;
}


int main() {
    int T;
    cin >> T;
    vector<string> strs(T);
    
    for(int i = 0; i < T; ++i) {
        getline(cin, strs[i]);
    }
    for(int i = 0; i < T; ++i) {
        string s = strs[i];
        std::cout << s << endl;
        int len = s.length();
        stack<char> st;
        stack<int> data;
        int res;
        for(int i = 0; i < len; ++i) {
            if(s[i] == ' ') continue;
            else if(s[i] == ')') {
                int x, y;
                if(data.empty()) {
                    cout << "invalid" << endl;
                    break;
                }
                x = data.top();
                data.pop();
                 if(data.empty()) {
                    cout << "invalid" << endl;
                    break;
                }
                y = data.top();
                data.pop();
                if(st.empty()) {
                    cout << "invalid" << endl;
                    break;
                }
                char c = st.top();
                st.pop();
                 if(st.empty() || st.top() != '(') {
                    cout << "invalid" << endl;
                    break;
                }
                st.pop();
                res = compute(y, x, c);
                cout << "res" << res << endl;
                data.push(res);
            } else if(s[i] >= '0' && s[i] <= '9') {
                int x = s[i] - '0';
                cout << "data " << x << endl;
                data.push(x);
            } else {
                st.push(s[i]);
            }
        }
        res = data.top();
        cout << "res " << res << endl;
        int ans = (res % 10000000 + 10000000) % 10000000;
        cout << ans << endl;
    }
}
