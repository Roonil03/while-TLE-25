
# 🏢 Minimum Conference Rooms Required

## Problem Statement

You are given a list of events, where each event is represented as a pair of integers `[start, end]`, indicating that the event starts at time `start` and ends at time `end` (inclusive).

Two events are considered **conflicting** if they occur at the same time or **share even a single point in time**.  
For example:
- `[2, 4]` and `[4, 6]` **conflict**, since they share time `4`.

Your task is to find the **minimum number of conference rooms** required to schedule all events such that **no two conflicting events** are assigned to the same room.

---

## Input

- `events`: A list of `n` events, where each event is a list `[start, end]`.

## Constraints

- `1 <= events.length <= 10^5`
- `1 <= start <= end <= 10^6`

---

## Output

- Return an integer: the **minimum number of conference rooms** required.

---

## Example

### Input
```python
events = [[1, 3], [2, 4], [4, 6]]
```

### Output
```
2
```

### Explanation

- Event `[1, 3]` and `[2, 4]` conflict (overlap at 2, 3)
- Event `[2, 4]` and `[4, 6]` conflict (overlap at 4)
- You need 2 rooms:  
  - Room 1: `[1, 3]`, then `[4, 6]`  
  - Room 2: `[2, 4]`

---

## Notes

- Since `end` is inclusive, an event ending at time `t` cannot be scheduled in the same room with another event starting at time `t`.
- Try to optimize for time complexity as `events.length` can be up to `10^5`.
