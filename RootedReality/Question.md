
# Check if the Connected Component of Node 0 is a Valid Tree

You are given an **undirected graph** with `n` nodes labeled from `0` to `n - 1`, and a list of `edges` where each edge is a pair `[u, v]` representing a **bidirectional connection** between nodes `u` and `v`.

However, the graph **may contain isolated nodes** (nodes with no connections at all).

---

## ❓ Problem Statement

Your task is to determine **whether the connected component that includes node `0` forms a valid tree**.

A **valid tree** satisfies two conditions:
1. **Connected** — every node in the component is reachable from node `0`.
2. **Acyclic** — the component must not contain any cycles.

---

## ✅ Input Format (Multiple Test Cases)

Each test case consists of:
- A single integer `n` — the number of nodes.
- A single integer `m` — the number of edges.
- `m` lines follow, each containing two integers `u` and `v`, representing an undirected edge between node `u` and node `v`.

Multiple test cases are separated by a **blank line**.

### Example Input:
```
5
4
0 1
0 2
1 3
1 4

6
5
0 1
1 2
2 3
1 3
1 4
```

---

## 📤 Output Format

For each test case, output a single line:
- `"true"` if the component containing node 0 is a valid tree.
- `"false"` otherwise.

Results should be printed in the order the test cases appear in the input.

### Example Output:
```
true
false
```

---

## 🧠 Constraints

- `1 <= n <= 10^5`
- `0 <= m <= 2 * 10^5`
- `0 <= u, v < n`
- The graph may be **disconnected**
- Self-loops or multiple edges between the same nodes are **not allowed**

---

## ✅ Notes

- Only the component containing node `0` is relevant.
- Other disconnected components should be ignored.
