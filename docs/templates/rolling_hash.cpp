struct HashString
{
    int n;
    string s;
    ll m;
    ll b;
    vector<ll> pow;
    vector<ll> hash_table;

    HashString(string _s, ll _m = 1e9 + 7, ll _b = 114514)
    : n(_s.size()), s(_s), m(_m), b(_b), hash_table(_s.size() + 1)
    {
        int pp = 1;
        for (int i = 0; i <= n; i++)
        {
            pow.push_back(pp);
            pp = pp * b % m;
        }

        for (int i = 0; i < n; i++)
        {
            hash_table[i + 1] = (hash_table[i] * b % m + (s[i] - 'a' + 1)) % m;
        }
    }

    ll get(int l, int r)
    {
        return ((hash_table[r + 1] - hash_table[l] * pow[r - l + 1] % m) % m + m) % m;
    }
};

