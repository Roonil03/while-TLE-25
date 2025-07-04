# Signal Synchronization Check

In a signal reconstruction task, engineers receive two input signal traces X and Y, and a final combined trace Z. They need to determine if Z could have been produced by merging X and Y in the following way:  
- Characters from X and Y are picked one by one to build Z.  
- The order of characters within X must be preserved.  
- The order of characters within Y must also be preserved.  
- At any step, the next character can be taken from either X or Y.

Your task is to check, for multiple test cases, whether a given Z could have been formed by this type of merging process of X and Y.

---

### Input

The first line contains an integer `T` — the number of test cases.  
Each test case consists of three lines:  
- A string `X`  
- A string `Y`  
- A string `Z`

```
3
aabcc
dbbca
aadbbcbcac
aabcc
dbbca
aadbbbaccc
""
""
""
```

---

### Output

For each test case, output `true` if `Z` can be formed by merging `X` and `Y` character by character while preserving their individual orders. Otherwise, print `false`.

```
true
false
true
```

---

### Constraints

```
1 ≤ T ≤ 100  
0 ≤ length of X, Y ≤ 100  
0 ≤ length of Z ≤ 200  
X, Y, and Z consist only of lowercase English letters.
```
