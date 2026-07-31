# 最大公因數與最小公倍數 GCD & LCM

## 核心知識點

從因數與 $gcd, lcm$ 公式下手，通常就可以解題。

---

## 介紹

$gcd(a, b)$ 代表 $a, b$ 的最大公因數，而 $lcm(a, b)$ 代表 $a, b$ 的最小公倍數。而這兩個函數有一些需要熟知的公式：

1. $gcd(a, b) \times lcm(a, b) = a \times b$
2. 結合律。如： $gcd(a, gcd(b, c)) = gcd(gcd(a, b), c)$ 與 $lcm(a, lcm(b, c)) = lcm(lcm(a, b), c)$

通常遇到與 $gcd$ 與 $lcm$ 有關的題目時，要從幾個方向下手：

1. 若數字範圍不大，可以從**所有數的因數 / 質因數**下手，畢竟 $gcd$ 其實就是：**所有數的質因數次方的最小值**， $lcm$ 則是：**所有數的質因數次方的最大值**。
2. 若要求 $gcd = k$ 或 $lcm = k$，需要從倍數計數與組合數下手。TODO

---

## 常見模型

### gcd(x, y) 與 x, y 關係

若 $d \mid \gcd(x, y)$，則 $d \mid x \wedge d \mid y$。也因此 $x, y$ 的線性組合也必定可被 $d$ 整除。也就是：

$$d \mid (px + qy) \text{ if } p, q \in \mathbb{Z}$$

::: details 證明

由於 $d = \gcd(x, y)$，因此 $x, y$ 可以表示成：$x = kd, y = td \text{ if } k, t \in \mathbb{Z} \wedge \gcd(k, t) = 1$

當 $x, y$ 線性組合後，就會變成：$pkd + qtd = d(pk + qt)$，這必定是 $d$ 的倍數。

故得證。

:::

### gcd(ka, kb) = k gcd(a, b)

$$ \gcd(ka, kb) = k \gcd(a, b) $$

::: details 證明

GCD 可把相同的因數提出，又因為 $ka, kb$ 中皆有因數 $k$，因此可以提出。

:::

### 輾轉相除法（Euclidean algorithm）

$$
\gcd(a, b) = \gcd(a, b + ka) \text{ if } k \in \mathbb{Z}
$$

::: details 證明

若令 $\gcd(a, b) = d$，則 $a = pd, b = qd \text{ if } p, q \in \mathbb{Z} \wedge \gcd(p, q) = 1$。這時帶入 $\gcd(a, b + ka)$ 可得：
$$\gcd(pd, qd + kpd)$$

可將 $d$ 提出，得到：
$$d \gcd(p, q + kp)$$

令 $g = \gcd(p, q + kp)，則可知：
$$g \mid p \wedge g \mid q + kp$$

又因為 $g \mid p$，所以 $g \mid kp$，也因此 $g \mid q$。

這時，由於 $g \mid p \wedge g \mid q \wedge \gcd(p, q) = 1$，因此 $g = 1$。

故 $d\gcd(p, q + kp) = d$，也因此：

$$\gcd(a, b) = d = \gcd(a, b + ka)$$

得證。

:::

### gcd(a, b) = a

若 $\gcd(a, b) = a$，則可以推出：$a \mid b$。

::: details 證明

因為 $a = \gcd(a, b)$，則 $b = ka \text{ if } k \in \mathbb{Z}$，也因此必定是 $a$ 的倍數。

故得證。

### ax + by = c 的整數解

若 $ax + by = c$ 有整數解，當且僅當：

$$\gcd(a, b) \mid c$$$

TODO

---

## 常見錯誤

TODO

---

## 代表題目

| 題目 | 重點 |

TODO

---

## Agent Prompt

> 請你扮演這個知識點的老師，按照本文的介紹詮釋這個知識點。
> 若本文知識點有誤，請點出錯誤的地方並予以修正。
