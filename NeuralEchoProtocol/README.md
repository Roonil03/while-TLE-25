# NEURAL ECHO PROTOCOL
## Question Level: Hard
### Problem Statement

In the neon-soaked underbelly of Neo-Tokyo 2087, you are **Cipher**, a renowned data-runner specializing in corporate espionage. Your latest contract involves infiltrating the Quantum Dynamics Corporation's neural interface system, where sensitive data is protected by an advanced encryption protocol known as the **Neural Echo Protocol**.

The corporation's security system generates access tokens by taking a base neural signature code and replicating it multiple times in sequence to create massive data streams. However, due to the quantum processing limitations of their neural firewall, these enormous concatenated codes are then processed through a modular hash function to fit within the system's memory constraints.

Your cybernetic implant has intercepted fragments of the authentication process, but you need to reverse-engineer the final hash values to gain access to their classified neural data vaults. The fate of the resistance depends on your ability to crack this encryption scheme before the corporate security algorithms detect your intrusion.

### Technical Briefing

The Neural Echo Protocol works as follows:

- A base neural signature `A` is repeated exactly `N` times to form a massive data stream
- This concatenated stream is then processed through a quantum hash function with modulus `M`
- Your task is to compute the final hash value that the system will generate

For example, if the neural signature is `120` and it's repeated `3` times, the data stream becomes `120120120`. The quantum hash function then computes this massive number modulo `M`.

### Input Format

The first line contains `T`, the number of intercepted authentication sequences you need to decrypt.

Each of the next `T` lines contains three integers:

- `A`: The base neural signature code (0 ≤ A ≤ 10^9)
- `N`: The number of times the signature is echoed in the data stream (1 ≤ N ≤ 10^12)
- `M`: The modulus value used by the quantum hash function (2 ≤ M ≤ 10^9)


### Output Format

For each authentication sequence, output a single integer representing the final hash value that the Neural Echo Protocol will generate (the result of the concatenated number modulo M).

### Constraints

- 1 ≤ T ≤ 10^5
- 0 ≤ A ≤ 10^9
- 1 ≤ N ≤ 10^12
- 2 ≤ M ≤ 10^9


### Sample Input

```
2
120 3 1000
5 4 7
```


### Sample Output

```
120
4
```


### Explanation

**Case 1:** Neural signature `120` repeated `3` times creates the data stream `120120120`. When processed through the hash function with modulus `1000`, the result is `120120120 % 1000 = 120`.

**Case 2:** Neural signature `5` repeated `4` times creates the data stream `5555`. The hash function computes `5555 % 7 = 4`.

*"In the shadows of the digital realm, only the sharpest minds can pierce through the corporate veil. The resistance is counting on you, Cipher. Jack in and break their code."*


### <i>Question made by <a href="https://github.com/Roonil03">Roonil03</a></i>