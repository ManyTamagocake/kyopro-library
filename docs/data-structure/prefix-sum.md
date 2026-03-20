# Prefix-Sum.hpp

## コンストラクタ

``` 
(1) PrefixSumHalfOpen sum(vector<ll> vec)
(2) PrefixSumClosed sum(vector<ll> vec)
```

* (1) 半開区間の区間和を取れる累積和を作ります。
* (2) 閉区間の区間和を取れる累積和を作ります。

計算量は配列の大きさを $N$ としたとき $ O\left(N\right) $ です。

## prod

```
ll sum.prod(int l, int r)
```

` vec ` の区間和と返します。\
計算量は $ O \left(1\right)$ です。

### 制約
` PrefixSumHalfOpen ` に対して $ 0 \leq l \leq r \leq N $ \
` PrefixSumClosed ` に対して $ 0 \leq l \leq r < N $
