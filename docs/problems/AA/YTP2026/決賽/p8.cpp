#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int n;
    cin >> n;

    vector<int> a(n + 2), b(n + 2); 
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];
    b[0] = b[n + 1] = 0;

    vector<int> rightmost(n + 2);
    stack<int> right;
    for (int i = 1; i <= n + 1; i++)
    {
        while (right.size() && b[right.top()] > b[i])
        {
            rightmost[right.top()] = i;
            right.pop();
        }
        right.push(i);
    }

    vector<int> leftmost(n + 2);
    stack<int> left;
    for (int i = n; i >= 0; i--)
    {
        while (left.size() && b[left.top()] > b[i])
        {
            leftmost[left.top()] = i;
            left.pop();
        }
        left.push(i);
    }

    vector<ll> prefix(n + 1);
    for (int i = 1; i <= n; i++) prefix[i] = prefix[i - 1] + a[i];

    ll ans = 0;
    for (int i = 1; i <= n; i++)
    {
        ans = max(ans, b[i] * (prefix[rightmost[i] - 1] - prefix[leftmost[i]]));
    }
    cout << ans;
}