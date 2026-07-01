class Solution {
public:
    string processStr(string s) {
        deque<char> d;
        bool dir = 0;
        for (auto c : s)
        {
            if (c == '*')
            {
                if (d.empty()) continue;
                if (dir)
                    d.pop_front();
                else
                    d.pop_back();
            }
            else if (c == '#')
            {
                int sz = d.size();
                vector<int> res;
                if (dir)
                    for (int i = sz - 1; i >= 0; i--) res.push_back(d[i]);
                else
                    for (int i = 0; i < sz; i++) res.push_back(d[i]);

                if (dir)
                    for (int i = 0; i < sz; i++) d.push_front(res[i]);
                else
                    for (int i = 0; i < sz; i++) d.push_back(res[i]);
            }
            else if (c == '%')
            {
                dir = (dir == 0 ? 1 : 0);
            }
            else
            {
                if (dir)
                    d.push_front(c);
                else
                    d.push_back(c);
            }
        }

        int sz = d.size();
        string ans;
        if (dir)
            for (int i = sz - 1; i >= 0; i--) ans += d[i];
        else
            for (int i = 0; i < sz; i++) ans += d[i];

        return ans;
    }
};
