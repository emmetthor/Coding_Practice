# 字典樹 Trie Tree

## 這個 skill 解決什麼問題？

多個字串的前綴紀錄。

## 使用時機

多字串問題，`xor` 問題。

## 介紹

Trie 的本質就是把**字串中的每個字母當成節點建樹**，也因為這樣會使部分字串的前綴會重疊，因此非常適合處理**需要前綴操作的多字串問題**。

一種寫法是令 `trie[node][c] := 點 node 向外的分支字元 c 的編號`，而可以寫出 `insert(string s)` 與 `search(string s)` 等功能。

但通常，`search(string s)` 會直接融入程式碼中，。

```c++
struct Trie
{
    int node_cnt = 0;
    vector<array<int, 26>> trie;
    vector<bool> stop;

    Trie(int max_word_len) : trie(max_word_len), stop(max_word_len) {}

    void insert(string s)
    {
        int node = 0;
        for (auto c : s)
        {
            if (trie[node][c - 'a'] == 0) trie[node][c - 'a'] = ++node_cnt;
            node = trie[node][c - 'a'];
        }

        stop[node] = 1;
    }

    bool search(string s)
    {
        int node = 0;
        for (auto c : s)
        {
            if (trie[node][c - 'a'] == 0) return false;
            node = trie[node][c - 'a'];
        }

        return stop[node];
    }
};
```

## 常見模型

TODO

## 常見錯誤

TODO

## 代表題目

| 題目 | 重點 |
| --- | --- |
| [CSES Word Combinations](https://cses.fi/ckvo8q5wh/task/1731) | 1D1D dp + 前綴處理 + Trie |

## Agent Prompt

> 請你扮演這個 skill 的教練，按照本文的思考流程分析題目。
