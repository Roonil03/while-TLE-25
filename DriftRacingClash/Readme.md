# Drift Racing Clash

You're observing several simulations of a drifting competition on a straight track. In each simulation, a number of cars line up. Every car is represented by an integer:

- The **sign** of the number indicates the **direction** the car is moving:  
  Positive for right, negative for left.

- The **absolute value** represents the car’s **power**.

All cars move at the same speed. When two cars meet:
- The **weaker** one gets knocked off the track.
- If both have **equal power**, **both are removed**.
- Cars moving in the **same direction** never collide.

Determine the final order of the cars after all possible collisions.

## Input

- The first line contains an integer `t`, the number of test cases.
- For each test case:
  - The first line contains an integer `n` — the number of cars in the simulation.
  - The second line contains `n` space-separated integers representing the lineup of cars.

## Output

For each test case, print a line of space-separated integers representing the final state of cars on the track after all clashes are resolved.  
If no cars remain, print an **empty line**.

## Example Input

```
3
3
5 10 -5
2
8 -8
3
10 2 -5
```


## Example Output

5 10

10


## Constraints

- `1 ≤ t ≤ 100`  
- `2 ≤ n ≤ 10⁴`  
- `-1000 ≤ car power ≤ 1000`  
- `car power ≠ 0`
