/*
Date: 2026-07-26

Tags: bit_enumeration, state_compression
Independent: 5
Understanding: 5 
Implementation: 5
Recognition: 5
*/
#include <algorithm>
#include <bits/stdc++.h>
#include <bitset>
using namespace std;
using ll = long long;
using i128 = __int128_t;

#define cerr if(true)cerr

const int SZ = 10;

void print_vector_i128(vector<i128> &a)
{
    int n = a.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < SZ; j++) cerr << int((a[i] >> j) & 1) << " \n"[j == SZ - 1];
    }
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    
    int _bl, _bu, _br, _bd; cin >> _bl >> _bu >> _br >> _bd;

    int n; cin >> n;
    vector<ll> ori;

    vector<array<ll, 4>> rect(n); for (auto &[a, b, c, d] : rect)
    {
        cin >> a >> b >> c >> d;
        ori.push_back(a);
        ori.push_back(b);
        ori.push_back(c);
        ori.push_back(d);
    }

    ori.push_back(_bl);
    ori.push_back(_bu);
    ori.push_back(_br);
    ori.push_back(_bd);

    sort(ori.begin(), ori.end());
    ori.erase(unique(ori.begin(), ori.end()), ori.end());

    auto get_item = [&](ll ori_num)
    {
        return lower_bound(ori.begin(), ori.end(), ori_num) - ori.begin() + 1;
    };

    int bl = get_item(_bl);
    int bu = get_item(_bu);
    int br = get_item(_br);
    int bd = get_item(_bd);

    int ma = ori.size();
    vector<i128> mp(ma + 5);

    vector<i128> check_mask(ma + 5);
    for (int i = bl; i < br; i++)
    {
        for (int j = bd; j < bu; j++)
        {
            check_mask[i] |= ((i128)1 << j);
        }
    }

    //print_vector_i128(check_mask);

    vector<i128> range1(ma + 5);
    for (int i = 1; i <= ma + 2; i++)
    {
        for (int j = 0; j < i; j++)
        {
            range1[i] |= ((i128)1 << j);
        }
    }

    int ans = 1e9;
    for (int b = 1; b < (1 << n); b++)
    {
        for (int i = 1; i <= ma + 2; i++) mp[i] = 0;
        int cnt = 0;
        for (int j = 0; j < n; j++)
        {
            if ((b >> j) & 1)
            {
                cnt++;

                auto [_l, _u, _r, _d] = rect[j];
                int l = get_item(_l);
                int u = get_item(_u);
                int r = get_item(_r);
                int d = get_item(_d);

                for (int i = l; i < r; i++)
                {
                    mp[i] |= range1[u - d] << d;
                    //cerr << "add " << range1[u - d] << " to " << d << '\n';
                }
            }
        }

        //print_vector_i128(mp);
        //cerr << cnt << '\n' << '\n';

        //cerr << "checking...\n";
        if (mp == check_mask)
        {
            ans = min(ans, cnt);
        }
    }

    cout << (ans == 1e9 ? -1 : ans);
}