# 找環

## 核心知識點

無向圖：找到拜訪過的點就是環。
有向圖：找到拜訪過的點，**若在 `stack` 中就是環，反之就不是**。

---

## 介紹

「找環」通常涉及**循找循環**。通常題目會要找出循環、重複的條件，這時就可以使用[圖論建模](\Coding_Practice\techniques\graph\graph_theory_modeling)技巧，再加上找環技巧解題。

### 無向圖找環

在無向圖找環時，因為**邊沒有方向性**，因此若從樹根開始，**找到之前拜訪過的點，就一定會形成環**。

實作如下：

```cpp

void dfs(int x, int last) {
    visit[x] = 1;
    for (auto y : e[x]) {
        if (y == last) {
            // 去除 A-B-A 這種非環
            continue;
        }
        if (visit[y]) {
            // 找到環
        } else {
            dfs(y, x);
        }
    }
}
```

### 有向圖找環

在有向圖找環時，因為邊有方向性，因此若找到之前拜訪過的點，不一定會是環。

以下是一個反例：

![finding_a_visited_node_in_a_direct_graph_is_not_always_a_cycle](img\finding_a_visited_node_in_a_direct_graph_is_not_always_a_cycle.png)

這時就必須使用一個 `stack` 來**記錄目前的遞迴究竟拜訪的是哪些點，才能確定已拜訪過的點真的可以連回一個環**。

但這時，問題浮現：

> 我把點的 `visi[x]`，進入時標記，離開時擦除，那時間複雜度不就是指數級暴漲？？？

但其實，**一個點若已經拜訪過，那就不可能再創造出含此點在內的新環**。畢竟所有環在拜訪此點時都試過了。

實作方法如下：

```cpp
void dfs(int x) {
    visit[x] = in_stack[x] = 1;
    for (auto y : e[x]) {
        if (visit[y]) {
            if (in_stack[y]) {
                // 找到環
            }
        } else {
            from[y] = x;
        }
    }

    // 離開點時取消在 in_stack 的標記，就可以記錄一次遞迴究竟拜訪哪些點。
    in_stack[x] = 0;
}
```

---

## 常見模型

### 回溯環

這類題目可以**使用一個 `from[]` 紀錄他的父節點**。若找到環，就可以從此點一路找 `from[x]` 回推出整個環。

### 圖論建模

先建模，再用找環技巧找到循環。

---

## 常見錯誤

- 忘記此圖不是連通的。
- 沒注意此圖有向還是無向。
- 忘記**一個點若已經拜訪過，那就不可能再創造出含此點在內的新環**，沒有使用 `visi + in_stack` 系統。

---

## 代表題目

| 題目 | 重點 |
| --- | --- |
| [CSES1669 Round Trip](https://cses.fi/problemset/task/1669) | 無向圖回溯環 |
| [CSES1678 Round Trip II](https://cses.fi/problemset/task/1678/) | 有向圖回溯環 |
| [ABC456E Endless Holidays](https://atcoder.jp/contests/abc456/tasks/abc456_e) | 圖論建模 + 有向圖找環 |

---

## Agent Prompt

> 請你扮演這個知識點的老師，按照本文的介紹詮釋這個知識點。
> 若本文知識點有誤，請點出錯誤的地方並予以修正。
