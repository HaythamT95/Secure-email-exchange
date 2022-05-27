# Secure-email-exchange

## An application for secure email exchange with:

## Encryption-Decryption with FROG in CFB mode and secure secret key delivery using Merkle–Hellman knapsack and signature based on EL-GAMAL.

**Encryption with Frog:**

Frog works with any block size between 8 and 128 bytes and supports keys of size between 5 and 125 bytes.

8 iterations are made in the encryption process. Each iteration uses a record of the internal key (called internKey), which is a data structure with 8 records.
Each record has 3 fields: a 16-byte array (xorBu) that is used in an initial XOR operation with the byte block,
a 256-byte array (substPermu) that represents a replacement table for byte values and an array 16 bytes (bombPermu) where each of which points
to different byte positions within the block and therefore has a value between 0 and 15.

Each iteration sequentially crosses the 16-byte block (from the least significant to the most significant byte) and performs 4 basic operations on each byte:

1 – XOR between the next byte of the block with the next byte of the xorBu field

2 – Replace the computed byte in operation 1 with the byte in the substitution table (substPermu) indexed by it

3 – Modify the next byte in the block by XOR with the byte computed in operation 2. When the end of the block is reached, then the least significant byte 
of the block is considered the next byte

4 – Use the next byte of the bombPermu array to define a position in the block. Modify the byte at that position of the block by XOR with the byte computed
in operation 2

**Secret Key Setup:**

FROG computes the internal key as a function of the user key. Each iteration made uses a record that has 16 bytes for the xorBuf field,
256 bytes for the substPermu field and 16 bytes for the bombPermu field. Thus, the internal key has 2,304 bytes.

1 – The 2304 byte long array (simpleKey) is filled with data that depends on the user’s key and the internal constant (randomSeed) that is filled
with 251 true random bytes. SimpleKey is first populated with copies of the user’s key and then sequentially XOR with copies of randomSeed.
Any bytes on the right are ignored. The resulting array is then processed by the makeInternalKey function and transformed into a valid internal FROG key.

2 – An IV (initialization vector) is created using the least significant 16 bytes of the user’s key (if the key is less than 16 bytes,
then the rest is filled with zeros). Then an XOR of the value corresponding to the size of the user’s key is made in byte with the least significant byte of the IV.
This ensures that different user key sizes always create different ciphertext.

### Merkle-Hellman knapsack:

Merkle–Hellman is a public key cryptosystem, meaning that two keys are used, a public key for encryption and a private key for decryption.

**Key generation:**

1. Choose a block size n. Integers up to n bits in length can be encrypted with this key.
2. Choose a random superincreasing sequence of n positive integers ![](https://latex.codecogs.com/gif.latex?%5Cbg_white%20%5CLARGE%20w%3D%7Bw_%7B1%7D%2C...%2Cw_%7Bn%7D%7D)
3. The superincreasing requirement means that ![](https://latex.codecogs.com/gif.latex?%5Cbg_white%20%7Bw_%7Bk%7D%7D%3E%5Csum_%7Bi%3D1%7D%5E%7Bk-1%7D%7Bw_%7Bi%7D%7D), for ![](https://latex.codecogs.com/gif.latex?%5Cbg_white%201%3Ck%5Cleq%20n)
4. Choose a random integer q such that ![](https://latex.codecogs.com/gif.latex?%5Cbg_white%20%7Bq%7D%3E%5Csum_%7Bi%3D1%7D%5E%7Bn%7D%7Bw_%7Bi%7D%7D)
5. Choose a random integer r such that gcd(r,q)=1 (that is, r and q are coprime).
6. Calculate the sequence ![](https://latex.codecogs.com/gif.latex?%5Cbg_white%20B%3D%28b_%7B1%7D%2C...%2Cb_%7Bn%7D%29) where ![](https://latex.codecogs.com/gif.latex?%5Cbg_white%20b_%7Bi%7D%3D%28rw_%7Bi%7D%29modq)
7. The public key is B and the private key is (W,q,r)

**Encryption:**

Let m be an n-bit message consisting of bits ![](https://latex.codecogs.com/gif.latex?%5Cbg_white%20m_%7B1%7Dm_%7B2%7D...m_n), with ![](https://latex.codecogs.com/gif.latex?%5Cbg_white%20m_%7B1%7D) the highest order bit.
Select each ![](https://latex.codecogs.com/gif.latex?%5Cbg_white%20b_%7Bi%7D) for which ![](https://latex.codecogs.com/gif.latex?%5Cbg_white%20m_%7Bi%7D) is nonzero, and add them together. Equivalently, calculate ![](https://latex.codecogs.com/gif.latex?%5Cbg_white%20c%3D%5Csum_%7Bi%3D1%7D%5E%7Bn%7Dm_%7Bi%7Db_%7Bi%7D) 
The ciphertext is c.

**Decryption:**

To decrypt a ciphertext c, we must find the subset of B which sums to c. We do this by transforming the problem into one of finding a subset of W. That problem can be solved in polynomial time since W is superincreasing.
1. Calculate the modular inverse of r modulo q using the Extended Euclidean algorithm. The inverse will exist since r is coprime to q. ![](https://latex.codecogs.com/gif.latex?%5Cbg_white%20r%7B%7D%27%3A%3Dr%5E%7B-1%7D%28modq%29)
2. Calculate ![](https://latex.codecogs.com/gif.latex?%5Cbg_white%20c%7B%7D%27%3A%3Dcr%5E%7B-1%7D%28modq%29)
3. Solve the subset sum problem for c' using the superincreasing sequence W, by the simple greedy algorithm described below. Let ![](https://latex.codecogs.com/gif.latex?%5Cbg_white%20X%3D%7Bx_%7B1%7D%2C...%2Cx_%7Bk%7D%7D) be the resulting list of indexes of the elements of W which sum to c'.
4. Construct the message m with a 1 in each ![](https://latex.codecogs.com/gif.latex?%5Cbg_white%20x_%7Bi%7D) bit position and a 0 in all other bit positions: ![](https://latex.codecogs.com/gif.latex?%5Cbg_white%20m%3D%5Csum_%7Bi%3D1%7D%5E%7Bk%7D%7B2%5E%7Bn-x_%7Bi%7D%7D%7D)

### El-Gamal signature:
The ElGamal signature scheme is a digital signature scheme based on the algebraic properties of modular exponentiation, together with the discrete logarithm problem.
The algorithm uses a key pair consisting of a public key and a private key. The private key is used to generate a digital signature for a message,
and such a signature can be verified by using the signer's corresponding public key.
The digital signature provides message authentication (the receiver can verify the origin of the message),
integrity (the receiver can verify that the message has not been modified since it was signed) and non-repudiation
(the sender cannot falsely claim that they have not signed the message).

**Key generation:**

Key generation has two phases. The first phase is a choice of algorithm parameters which may be shared between different users of the system, while the second phase computes a single key pair for one user.

**Parameter generation:**
1. Choose a key length N.
2. Choose a N-bit prime number p
3. Choose a cryptographic hash function H with output length L bits. If L>N, only the leftmost N bits of the hash output are used.
4. Choose a generator g<p of the multiplicative group of integers modulo p, ![](https://latex.codecogs.com/gif.latex?%5Cbg_white%20Z_%7Bp%7D%5E%7B*%7D)

The algorithm parameters are (p,g). These parameters may be shared between users of the system.

**Per-user keys:**

Given a set of parameters, the second phase computes the key pair for a single user:
1. Choose an integer x randomly from ![](https://latex.codecogs.com/gif.latex?%5Cbg_white%20%7B1%2C...%2Cp-2%7D)
2. Compute ![](https://latex.codecogs.com/gif.latex?%5Cbg_white%20y%3A%3Dg%5E%7Bx%7Dmodp)

x is the private key and y is the public key.

**Signing:**

A message m is signed as follows:

1. Choose an integer k randomly from ![](https://latex.codecogs.com/gif.latex?%5Cbg_white%20%7B2%2C..%2Cp-2%7D) with k relatively prime to p-1.
2. Compute ![](https://latex.codecogs.com/gif.latex?%5Cbg_white%20r%3A%3Dg%5E%7Bk%7Dmodp)
3. Compute ![](https://latex.codecogs.com/gif.latex?%5Cbg_white%20s%3A%3D%28H%28m%29-xr%29k%5E%7B-1%7Dmod%28p-1%29)
4. In the unlikely event that s=0 start again with a different random k.

The signature is (r,s).

**Verifying a signature:**

One can verify that a signature (r,s) is a valid signature for a message m as follows:

1. Verify that 0<r<p and 0<s<p-1
2. The signature is valid if and only if ![](https://latex.codecogs.com/gif.latex?%5Cbg_white%20g%5E%7BH%28m%29%7D%5Cequiv%20y%5E%7Br%7Dr%5E%7Bs%7D%28modp%29)
