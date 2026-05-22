# Monotonic Sequence 單調隊列

## 這個 skill 解決什麼問題？

**固定窗口或限制距離內的最大最小值**。

## 使用時機

固定窗口，限定距離，極值。

## 核心想法

把**不可能的答案去掉**，讓留下來的的數**在隊列裡呈現遞增或遞減**。

## 常見模型

### 固定窗口求極值

在固定窗口枚舉求極值時，每次移動窗口會新增一個數並減少一個數。則不失一般性以求最大值為例：

1. 先移除要移除的數。
2. 若新的數很大，那把其他比他還小的數全部刪除，畢竟他們**不可能成為答案**。
3. 會發現這樣維護的數列會是遞增的，因此就是單調隊列的一種應用。

這種技巧在 dp 轉移時也可能使用。

一般實作時，通常維護的陣列裡不會存數字，而是序號。

```cpp
vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    vector<int> q; // 存 index
    int front_iter = 0;
    vector<int> ans;

    for (int i = 0; i < nums.size(); i++) {
        // 1. 移除不在窗口內的 index
        while (front_iter < q.size() && q[front_iter] <= i - k) {
            front_iter++;
        }

        // 2. 維持單調遞減
        while (front_iter < q.size() && nums[q.back()] <= nums[i]) {
            q.pop_back();
        }

        // 3. 加入目前 index
        q.push_back(i);

        // 4. 形成完整窗口後取答案
        if (i >= k - 1) {
            ans.push_back(nums[q[front_iter]]);
        }
    }

    return ans;
}
```

### 限制距離內的極值

與固定窗口類似，這種題型常常是其他題型的前置作業之一。

## 常見錯誤

## 代表題目

| 題目 | 重點 |
| --- | --- |

## Agent Prompt

> 請你扮演這個 skill 的教練，按照本文的思考流程分析題目。
