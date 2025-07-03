# Network of Ai
## Question Difficulty: Hard
### Description:
In the neon-soaked streets of Neo-Tokyo 2087, data streams flow like digital blood through the city's neural networks. Alice Chen, a brilliant quantum hacker, discovers an encrypted love letter hidden within the city's tree-structured communication grid. The message can only be decoded by finding "beautiful paths" - routes through the network where data packets of matching encryption signatures can travel without being corrupted by intermediate nodes carrying the same signature.

Bob Nakamura, a rogue AI security specialist, has been secretly embedding romantic messages throughout the city's data infrastructure. Each beautiful path represents a moment of their forbidden love - two souls connected across the digital divide, their emotions flowing through channels where no interference can corrupt their bond.

Your task is to help Alice decode Bob's messages by counting all the beautiful paths in each network segment. A beautiful path exists between two nodes of the same color (encryption signature) if no intermediate nodes along the path share that same color. Each discovered path brings Alice closer to understanding the depth of Bob's feelings, hidden within the very fabric of the city's digital consciousness.

### Input:
The first line contains a single integer t (1 ≤ t ≤ 10^5) - the number of network segments Alice must analyze.

For each network segment:
- First line contains n (2 ≤ n ≤ 2×10^5) - the number of nodes in this network tree

- Second line contains n integers c₁, c₂, ..., cₙ (1 ≤ cᵢ ≤ n) - the encryption signature (color) of each node

- Next n-1 lines each contain two integers u and v (1 ≤ u, v ≤ n; u ≠ v) - representing a bidirectional connection between nodes u and v

The connections form a valid tree structure - the digital backbone of Neo-Tokyo's communication grid.

### Output:
For each network segment, output a single integer representing the number of beautiful paths Alice can discover.

A beautiful path connects two nodes with identical encryption signatures, with no intermediate nodes sharing that same signature. Each path represents a fragment of Bob's encoded love letter.

### Constraints

- Number of test cases: 1 ≤ t ≤ 10^5

- Nodes per network: 2 ≤ n ≤ 2×10^5

- Encryption signatures: 1 ≤ cᵢ ≤ n

- Total nodes across all networks: ≤ 4×10^5

- All connections form valid tree structures

### Check the samples <a href="https://github.com/Roonil03/while-TLE-25/tree/main/NetworkOfAi/Tests/SampleCases/">here</a>

### *Question designed by <a href="https://github.com/Roonil03">Roonil03</a>