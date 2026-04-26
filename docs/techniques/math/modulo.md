# Modulo

## 介紹

取餘，也就是取餘數，是競程常見的考點。

### 基本定義

若 $i \bmod j \equiv r$，則也可以寫成： 
$$i - j \times \lfloor \frac{i}{j} \rfloor = r$$

寫成這樣的好處是：

1. 可以去掉難處理的 `mod`。
2. 可以**固定或枚舉** $\lfloor \frac{i}{j} \rfloor$ 去快速**預處理**結果。

---

### 同餘

$$
\because \begin{cases}
a = mq_1 + r\\
b = mq_2 + r
\end{cases} 
\Longrightarrow a - b = m (q_1 - q_2) \Longleftrightarrow a - b = mq\\
\therefore a \equiv b \pmod m $$

因此：

$$\text{if } a - b = mq \Longrightarrow a \equiv b \pmod m$$

---

### 分配律

只有**加、減、乘**具有分配律。

> **[注意]**\
> 如果在處理減法時出現**負數**，應該要**加回模數**，因為模運算的結果必定 $ans \in [0, \text{MOD}]$。

---

### 模數除法

如果模數為質數，則可以使用費馬小定理證明出：
$$
b \div a \pmod m \Longleftrightarrow b \times a^{m-2} \pmod m
$$

證明如下：

若模數為質數，則利用費馬小定理：
$$
\text{Let } p \text{ is a prime, then } \forall a \in \mathbb{Z}\quad a^p \equiv a \pmod{p}\
\Longrightarrow a^{p-1} \equiv 1 \pmod{p}
$$
可推出
$$
a \times a^{p-2} \pmod{p} \equiv 1 \Longrightarrow a^{-1} \equiv a^{p-2} \pmod{p}
$$
最後
$$
\frac{b}{a} = b \times a^{-1} \equiv b \times a^{p-2} \pmod{p}
$$
因此，除法 $b \div a$ 可表示成 $b \times a^{MOD - 2}$ 若模數為質數。

---

## 題目

| 題目 | 詳解 |
| - | - |
| [ABC452E You WILL Like Sigma Problem](https://atcoder.jp/contests/abc452/tasks/abc452_e) | TODO |
