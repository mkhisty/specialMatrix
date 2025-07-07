import specialmatrix
import numpy as np


print("--- SpecialMatrix Demo ---")

print("\n1. Creating a 2x2 SpecialMatrix ")
sm1 = specialmatrix.SpecialMatrix(2,2)

print(sm1)

print("\n3. Converting to a normal NumPy array")
nm1 = np.array(sm1.toNormal())
print(nm1)

sm2 = specialmatrix.SpecialMatrix(2, 2, True)
print("\n4. Created a second SpecialMatrix (2x2 Identity).")
print(sm2)

print("\n5. Matrix Multiplication (sm1 @ identity)")
sm_result_mul = sm1 @ sm2
print("Result of SpecialMatrix multiplication:")
print(sm_result_mul)

print("\n--- For comparison, using NumPy ---")
nm2 = np.array(sm2.toNormal())
nm_result_mul = nm1 @ nm2
print("Result of NumPy multiplication:")
print(nm_result_mul)
print("------------------------------------")


det_sm = sm1.det()
print(f"SpecialMatrix determinant: {det_sm}")

# Comparison with NumPy
det_nm = np.linalg.det(nm1)
print(f"NumPy determinant:         {det_nm}")


try:
    sm_inv = sm1 ** -1
    print("Inverse of SpecialMatrix:")
    print(sm_inv)
    print("\nInverse in normal form:")
    print(np.array(sm_inv.toNormal()))
except Exception as e:
    print(f"Could not compute inverse for SpecialMatrix: {e}")


print("\n8. Scalar Multiplication (sm1 * 5.0)")
sm_scalar_mul = sm1 * 5.0
print("Result of sm1 * 5.0:")
print(sm_scalar_mul)
print("\nScalar result in normal form:")
print(np.array(sm_scalar_mul.toNormal()))


def f(x):
    return x * 10 + 1

sm1_for_apply = sm1
print("Matrix before apply():")
print(sm1_for_apply)
sm1_for_apply.apply(f)
print("Matrix after apply(10x+1):")
print(sm1_for_apply)
print("\nResult in normal form:")
print(np.array(sm1_for_apply.toNormal()))


