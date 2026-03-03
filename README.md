# 📐 Linear System Solver – Direct & Iterative Numerical Methods (C++)

A C++ implementation of classical numerical methods for solving linear systems of equations:

\[
Ax = b
\]

This project compares **direct** and **iterative** approaches while verifying important matrix properties such as symmetry and positive definiteness.

---

## 📌 Project Overview

The program:

- ✔ Checks if the matrix is **symmetric**
- ✔ Checks if the matrix is **positive definite** (Sylvester criterion)
- ✔ Solves the system using:
  - Gaussian Elimination (Direct Method)
  - Jacobi Method (Iterative)
  - Gauss–Seidel Method (Iterative)
- ✔ Displays number of iterations
- ✔ Uses numerical tolerance stopping criteria

This project focuses on **algorithm comparison, convergence behavior, and numerical stability**.

---

## 🧮 System Used

Matrix:


A =
[ 23.6 1.5 -0.9 -0.8 ]
[ 1.5 14.6 0.7 0.2 ]
[ -0.9 0.7 11.3 -0.6 ]
[ -0.8 0.2 -0.6 9.9 ]


Vector:


b = [-1.2, 0.9, 4.7, -1.2]


Initial guess for iterative methods:


x₀ = [0, 0, 0, 0]


Tolerance:


ε = 10⁻³


---

# 🔍 Matrix Validation

## 1️⃣ Symmetry Check

The matrix is symmetric if:


A[i][j] = A[j][i]


Symmetric matrices:
- Have real eigenvalues
- Provide better numerical stability
- Help ensure convergence of iterative methods

---

## 2️⃣ Positive Definiteness

Verified using **Sylvester’s Criterion**.

A matrix is positive definite if all leading principal minors are positive:

- det(A₁) > 0
- det(A₂) > 0
- det(A₃) > 0
- det(A₄) > 0

If positive definite:
- ✔ The system has a unique solution
- ✔ Gauss–Seidel is guaranteed to converge
- ✔ Numerical stability improves

---

# ⚙️ Implemented Methods

---

## 🔹 1. Gaussian Elimination (Direct Method)

Steps:
- Partial pivoting
- Forward elimination
- Back substitution

### Time Complexity

O(n³)


### Characteristics

✔ Deterministic  
✔ Exact solution (floating-point precision)  
✔ No convergence condition required  
❌ Less efficient for very large systems  

---

## 🔹 2. Jacobi Method

Update formula:


x_i^(k+1) = (1 / a_ii) * ( b_i - Σ a_ij x_j^(k) )


### Convergence Condition

Jacobi converges if:
- Matrix is strictly diagonally dominant, OR
- Matrix is symmetric positive definite

### Convergence Order
Linear

### Time Complexity
Per iteration:

O(n²)


Total:

O(n² · k)


Where k = number of iterations

### Characteristics

✔ Easy to implement  
✔ Parallelizable  
❌ Slower convergence than Gauss–Seidel  

---

## 🔹 3. Gauss–Seidel Method

Update formula:


x_i^(k+1) = (1 / a_ii) * ( b_i - Σ(a_ij x_j^(updated)) )


Uses updated values immediately.

### Convergence

For symmetric positive definite matrices:
✔ Guaranteed convergence

### Convergence Order
Linear (but typically faster than Jacobi)

### Time Complexity

O(n² · k)


### Characteristics

✔ Faster practical convergence  
✔ More stable than Jacobi  
❌ Sequential (not easily parallelizable)

---

# 📊 Convergence Comparison

| Method          | Type      | Convergence | Stability | Speed |
|---------------|----------|------------|----------|-------|
| Gaussian       | Direct   | Deterministic | High | Fast (small n) |
| Jacobi         | Iterative | Linear | Medium | Moderate |
| Gauss–Seidel   | Iterative | Linear (faster) | High | Faster |

Expected behavior for this matrix:

- Gaussian → immediate solution
- Jacobi → moderate number of iterations
- Gauss–Seidel → fewer iterations than Jacobi

---

# 🧠 Numerical Stability

The implementation includes:

- Partial pivoting
- Determinant-based positive definiteness validation
- Error-based stopping condition
- Iteration counter tracking

Stopping condition:


max |x_new - x_old| < ε


---

# ⏱ Computational Complexity Summary

| Method        | Complexity |
|--------------|------------|
| Gaussian     | O(n³) |
| Jacobi       | O(n² · k) |
| Gauss–Seidel | O(n² · k) |

Where:
- n = system size
- k = number of iterations

For small systems (n = 4), Gaussian is extremely fast.  
For large systems, iterative methods become more practical.

---

[lab 2 CHiochiu.docx](https://github.com/user-attachments/files/25716897/lab.2.CHiochiu.docx)

