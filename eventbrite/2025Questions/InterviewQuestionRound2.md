### Problem Statement (in clearer terms):

You have **n chocolates** initially.  
For every **k wrappers**, you can exchange them for **1 additional chocolate**.  
Each new chocolate you get from wrappers also gives a new wrapper.

**Goal:** Find the **maximum number of chocolates** you can eat in total.

---

### Example:

- `n = 10`, `k = 3`
    

Eat 10 → get 10 wrappers  
Exchange 9 wrappers → get 3 chocolates → now have 3 new wrappers  
Use 3 wrappers → get 1 chocolate → 1 wrapper  
Now only 1 wrapper left → can't exchange  
**Total chocolates eaten: 10 + 3 + 1 = 14**

---

### Code (Python):

```python
def max_chocolates(n, k):
    chocolates = n
    wrappers = n

    while wrappers >= k:
        new_chocolates = wrappers // k
        chocolates += new_chocolates
        wrappers = wrappers % k + new_chocolates

    return chocolates
```

---

### Time Complexity:

- **O(log n)** (since wrappers reduce each time in a loop)
    

---

