## 有包含加分
- 透過hash Table的想法，不過剛好Ascii code的`decimal value`，並且對應可列印字元範圍`32-126`，所以直接使用decimal value當作key來查找，而且不會有collision的問題。
```c
Node *hash[127] = {NULL}; //line 42
```

- 根據獨取的char直接當index，查看array是否儲存該memory address，剛好Search time達到`$T(n) = \Theta(1)$`。

```c
if (hash[tmp] != NULL) { //line 48 
    (hash[tmp]->count) += 1;
    } else {
        //......
    }
```