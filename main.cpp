#include <iostream>
#include <cmath>

using namespace std;

// =============================
// Verificare SIMETRIE
// =============================
bool isSymmetric(double A[4][4]) {
    for (int i = 0; i < 4; i++) {
        for (int j = i + 1; j < 4; j++) {
            if (fabs(A[i][j] - A[j][i]) > 1e-9)
                return false;
        }
    }
    return true;
}

// =============================
// Verificare POZITIV DEFINITĂ
// Folosind criteriul lui Sylvester
// =============================

bool isPositiveDefinite(double A[4][4]) {
    double det1 = A[0][0];
    if (det1 <= 0) return false;

    double det2 = A[0][0]*A[1][1] - A[0][1]*A[1][0];
    if (det2 <= 0) return false;

    double det3 =
          A[0][0]*(A[1][1]*A[2][2] - A[1][2]*A[2][1])
        - A[0][1]*(A[1][0]*A[2][2] - A[1][2]*A[2][0])
        + A[0][2]*(A[1][0]*A[2][1] - A[1][1]*A[2][0]);
    if (det3 <= 0) return false;

    // determinant 4x4 - Gauss simplificat
    double temp[4][4];
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            temp[i][j] = A[i][j];

    double det4 = 1;

    for (int i = 0; i < 4; i++) {
        det4 *= temp[i][i];
        for (int j = i + 1; j < 4; j++) {
            double factor = temp[j][i] / temp[i][i];
            for (int k = i; k < 4; k++)
                temp[j][k] -= factor * temp[i][k];
        }
    }

    if (det4 <= 0) return false;

    return true;
}

// =============================
// Eliminare Gauss
// =============================
void gaussianElimination(double A[4][4], double b[4], double x[4], int& iterations) {
    int n = 4;
    iterations = 0;

    for (int i = 0; i < n; i++) {

        double maxEl = fabs(A[i][i]);
        int row = i;
        for (int k = i + 1; k < n; k++) {
            if (fabs(A[k][i]) > maxEl) {
                maxEl = fabs(A[k][i]);
                row = k;
            }
        }

        if (row != i) {
            for (int j = 0; j < n; j++)
                swap(A[i][j], A[row][j]);
            swap(b[i], b[row]);
        }

        for (int j = i + 1; j < n; j++) {
            double factor = A[j][i] / A[i][i];
            b[j] -= factor * b[i];
            for (int k = i; k < n; k++) {
                A[j][k] -= factor * A[i][k];
            }
        }
        iterations++;
    }

    // Back substitution
    for (int i = n - 1; i >= 0; i--) {
        x[i] = b[i] / A[i][i];
        for (int j = i - 1; j >= 0; j--)
            b[j] -= A[j][i] * x[i];
    }

    cout << "\nMetoda Gauss:\n";
    for (int i = 0; i < 4; i++) cout << x[i] << " ";
    cout << "\nNumar iteratii: " << iterations << "\n";
}

// =============================
// Jacobi
// =============================
void jacobiMethod(double A[4][4], double b[4], double x[4], double epsilon, int& iterations) {
    int n = 4;
    double x_new[4];
    iterations = 0;

    double error;

    do {
        error = 0;
        for (int i = 0; i < n; i++) {
            double sum = 0;
            for (int j = 0; j < n; j++)
                if (i != j) sum += A[i][j] * x[j];

            x_new[i] = (b[i] - sum) / A[i][i];
            error = max(error, fabs(x_new[i] - x[i]));
        }

        for (int i = 0; i < n; i++)
            x[i] = x_new[i];

        iterations++;

    } while (error > epsilon);

    cout << "\nMetoda Jacobi:\n";
    for (int i = 0; i < 4; i++) cout << x[i] << " ";
    cout << "\nNumar iteratii: " << iterations << "\n";
}

// =============================
// Gauss–Seidel
// =============================
void gaussSeidelMethod(double A[4][4], double b[4], double x[4], double epsilon, int& iterations) {
    int n = 4;
    iterations = 0;

    double error;

    do {
        error = 0;
        for (int i = 0; i < n; i++) {

            double sum1 = 0;
            for (int j = 0; j < i; j++)
                sum1 += A[i][j] * x[j];

            double sum2 = 0;
            for (int j = i + 1; j < n; j++)
                sum2 += A[i][j] * x[j];

            double x_new = (b[i] - sum1 - sum2) / A[i][i];
            error = max(error, fabs(x_new - x[i]));
            x[i] = x_new;
        }

        iterations++;

    } while (error > epsilon);

    cout << "\nMetoda Gauss–Seidel:\n";
    for (int i = 0; i < 4; i++) cout << x[i] << " ";
    cout << "\nNumar iteratii: " << iterations << "\n";
}

// =============================
// MAIN – cu matricea TA
// =============================
int main() {

    double A[4][4] = { //schimbam matricea
        {23.6, 1.5, -0.9, -0.8},
        {1.5, 14.6, 0.7, 0.2},
        {-0.9, 0.7, 11.3, -0.6},
        {-0.8, 0.2, -0.6, 9.9}
    };

    double b[4] = {-1.2, 0.9, 4.7, -1.2};

    // Verificări
    cout << "\n=== Verificari matrice ===\n";
    cout << "Simetrica? " << (isSymmetric(A) ? "DA" : "NU") << endl;
    cout << "Pozitiv definita? " << (isPositiveDefinite(A) ? "DA" : "NU") << endl;

    // Copii pentru metode
    double A1[4][4], A2[4][4], A3[4][4];
    double b1[4], b2[4], b3[4];

    memcpy(A1, A, sizeof(A));
    memcpy(A2, A, sizeof(A));
    memcpy(A3, A, sizeof(A));
    memcpy(b1, b, sizeof(b));
    memcpy(b2, b, sizeof(b));
    memcpy(b3, b, sizeof(b));

    double x[4] = {0, 0, 0, 0};
    int it;

    // GAUSS
    gaussianElimination(A1, b1, x, it);

    // reset x
    for (int i = 0; i < 4; i++) x[i] = 0;

    // JACOBI
    jacobiMethod(A2, b2, x, 1e-3, it);

    // reset x
    for (int i = 0; i < 4; i++) x[i] = 0;

    // SEIDEL
    gaussSeidelMethod(A3, b3, x, 1e-3, it);

    return 0;
}