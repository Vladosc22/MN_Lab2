# 📐 Linear System Solver – Direct & Iterative Methods (C++)

> Comparative implementation of classical methods for solving linear systems  
> Includes matrix property validation (symmetry & positive definiteness)

---

## 📌 Overview

This project implements and compares **direct and iterative numerical methods** for solving a linear system:

\[
Ax = b
\]

Where:
- \( A \) is a 4×4 matrix
- \( b \) is a 4×1 vector
- \( x \) is the solution vector

The program:

✔ Verifies matrix symmetry  
✔ Verifies positive definiteness (Sylvester criterion)  
✔ Solves the system using:
- Gaussian Elimination (direct method)
- Jacobi Method (iterative)
- Gauss–Seidel Method (iterative)

---

## 🧮 Matrix Used

```text
A =
[ 23.6   1.5  -0.9  -0.8 ]
[  1.5  14.6   0.7   0.2 ]
[ -0.9   0.7  11.3  -0.6 ]
[ -0.8   0.2  -0.6   9.9 ]

b = [-1.2, 0.9, 4.7, -1.2]
🔍 Matrix Validation
1️⃣ Symmetry Check

The matrix is symmetric if:

𝐴
𝑖
𝑗
=
𝐴
𝑗
𝑖
A
ij
	​

=A
ji
	​


This property is important because:

Symmetric matrices have real eigenvalues

If also positive definite → guaranteed convergence for iterative methods

2️⃣ Positive Definiteness

Verified using Sylvester’s Criterion:

A matrix is positive definite if all leading principal minors are positive:

det
⁡
(
𝐴
1
)
>
0
det(A
1
	​

)>0
det
⁡
(
𝐴
2
)
>
0
det(A
2
	​

)>0
det
⁡
(
𝐴
3
)
>
0
det(A
3
	​

)>0
det
⁡
(
𝐴
4
)
>
0
det(A
4
	​

)>0

This guarantees:

✔ Unique solution
✔ Convergence of Gauss–Seidel
✔ Stability of the system

⚙️ Implemented Methods
1️⃣ Gaussian Elimination (Direct Method)

Uses partial pivoting

Forward elimination + back substitution

Deterministic algorithm

Time Complexity:
𝑂
(
𝑛
3
)
O(n
3
)

For n = 4 → negligible cost, but scales cubically.

Characteristics:

✔ Exact solution (within floating-point precision)
✔ No convergence issues
❌ More computationally expensive for large systems

2️⃣ Jacobi Method (Iterative)

Update formula:

𝑥
𝑖
(
𝑘
+
1
)
=
1
𝑎
𝑖
𝑖
(
𝑏
𝑖
−
∑
𝑗
≠
𝑖
𝑎
𝑖
𝑗
𝑥
𝑗
(
𝑘
)
)
x
i
(k+1)
	​

=
a
ii
	​

1
	​

	​

b
i
	​

−
j

=i
∑
	​

a
ij
	​

x
j
(k)
	​

	​

Convergence Condition

Jacobi converges if:

Matrix is strictly diagonally dominant, OR

Matrix is symmetric positive definite

Order of Convergence:

Linear

Time Complexity per iteration:
𝑂
(
𝑛
2
)
O(n
2
)

Total cost:

𝑂
(
𝑛
2
⋅
𝑘
)
O(n
2
⋅k)

Where:

n = system size

k = number of iterations

✔ Easy to parallelize
❌ Slower convergence than Gauss–Seidel

3️⃣ Gauss–Seidel Method (Iterative)

Update formula:

𝑥
𝑖
(
𝑘
+
1
)
=
1
𝑎
𝑖
𝑖
(
𝑏
𝑖
−
∑
𝑗
<
𝑖
𝑎
𝑖
𝑗
𝑥
𝑗
(
𝑘
+
1
)
−
∑
𝑗
>
𝑖
𝑎
𝑖
𝑗
𝑥
𝑗
(
𝑘
)
)
x
i
(k+1)
	​

=
a
ii
	​

1
	​

(b
i
	​

−
j<i
∑
	​

a
ij
	​

x
j
(k+1)
	​

−
j>i
∑
	​

a
ij
	​

x
j
(k)
	​

)

Uses updated values immediately.

Convergence:

For symmetric positive definite matrices:
✔ Guaranteed convergence

Order of Convergence:

Linear (but typically faster than Jacobi)

Time Complexity:
𝑂
(
𝑛
2
⋅
𝑘
)
O(n
2
⋅k)

✔ Faster practical convergence
✔ More stable than Jacobi
❌ Sequential nature (harder to parallelize)

📊 Convergence Comparison
Method	Type	Convergence	Stability	Speed
Gaussian	Direct	Deterministic	High	Fast (small n)
Jacobi	Iterative	Linear	Medium	Moderate
Gauss–Seidel	Iterative	Linear (faster)	High	Faster than Jacobi

Expected behavior for this matrix:

Gaussian → immediate exact solution

Jacobi → converges in moderate iterations

Gauss–Seidel → converges in fewer iterations than Jacobi

🧠 Numerical Stability Considerations

✔ Partial pivoting in Gaussian elimination
✔ Positive definiteness ensures convergence
✔ Error-based stopping criterion (epsilon = 1e-3)
✔ Iteration counter tracking


[lab 2 CHiochiu.docx](https://github.com/user-attachments/files/25716851/lab.2.CHiochiu.docx)
