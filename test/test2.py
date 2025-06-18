#!/usr/bin/env python3
"""
Comprehensive test suite for the SpecialMatrix class.
Tests all functionality including constructors, operators, and methods.
"""

import specialmatrix as sm
import math

def test_function(x):
    return (x * 2)+5

def sqrt_function(x):
    """Square root function for testing"""
    return math.sqrt(abs(x))

# Test 1: Constructor with dimensions
matrix1 = sm.SpecialMatrix(2, 3, False)  # d=2, n=3, random values
identity = sm.SpecialMatrix(2, 2, True)  # d=2, n=2, identity
# Test 3: Constructor with 3D vector
print("\n3. Testing Constructor with 3D vector")
# Create a 2x2x2 matrix manually
test_data = [
    [[1.0, 2.0], [3.0, 4.0]],
    [[5.0, 6.0], [7.0, 8.0]]
]
matrix2 = sm.SpecialMatrix(test_data)
print(f"   Custom matrix dimensions: d={matrix2.d}, n={matrix2.n}")
print("   3D vector constructor successful")

# Test 4: String representation
print("\n4. Testing String Representation")
small_matrix = sm.SpecialMatrix(2, 2, True)
str_repr = str(small_matrix)
print("   Matrix string representation (first 150 chars):")
print(f"   {str_repr[:150]}...")
print("   String representation works")

# Test 5: toNormal method
print("\n5. Testing toNormal() method")
normal_matrix = matrix2.toNormal()
print(f"   Normal matrix size: {len(normal_matrix)}x{len(normal_matrix[0])}")
print(f"   First row: {normal_matrix[0]}")
print("   toNormal() successful")

# Test 6: Scalar operations
print("\n6. Testing Scalar Operations")
# Test scalar multiplication
result_mul = matrix2 * 2.0
print("   Scalar multiplication successful")

# Test scalar division
result_div = matrix2 / 2.0
print("   Scalar division successful")

# Test scalar addition
result_add = matrix2 + 1.0
print("   Scalar addition successful")

# Test scalar subtraction
result_sub = matrix2 - 1.0
print("   Scalar subtraction successful")

# Test 7: Matrix multiplication
print("\n7. Testing Matrix Multiplication")
# Create two compatible matrices
mat_a = sm.SpecialMatrix(2, 2, True)
mat_b = sm.SpecialMatrix(2, 2, True)

# Test & operator
result_and = mat_a & mat_b
print("   Matrix multiplication (&) successful")

# Test @ operator
result_matmul = mat_a @ mat_b
print("   Matrix multiplication (@) successful")

# Test 8: Matrix power
print("\n8. Testing Matrix Power")
mat_power = mat_a ^ 2
print("   Matrix power (^) successful")

mat_power2 = mat_a ** 2
print("   Matrix power (**) successful")

# Test power of 0 (should return identity)
mat_power0 = mat_a ^ 0
print("   Matrix power 0 successful")

# Test 9: Determinant
print("\n9. Testing Determinant Calculation")
det_value = identity.det()
print(f"   Identity matrix determinant: {det_value}")
print("   Determinant calculation successful")

# Test 10: Apply function
print("\n10. Testing apply() method")
test_matrix = sm.SpecialMatrix(2, 2, True)
print(f"   Original data sample: {test_matrix.data[0][0][0]}")
test_matrix.apply(test_function)
print(f"   After apply(x*2): {test_matrix.data[0][0][0]}")
print("   apply() method successful")

# Test 11: ApplyAll function
print("\n11. Testing applyAll() method")
test_matrix2 = sm.SpecialMatrix(2, 2, True)
result_matrix = test_matrix2.applyAll(sqrt_function)
print(f"   ApplyAll result size: {len(result_matrix)}x{len(result_matrix[0])}")
print(f"   Sample result: {result_matrix[0][0]}")
print("   applyAll() method successful")

# Test 12: Data access
print("\n12. Testing Data Access")
print(f"   Matrix1 sample data: {matrix1.data[0][0][0]}")
print(f"   Matrix2 first block: {matrix2.data[0][0]}")
print(f"   Identity sample: {identity.data[0][0]}")
print("   Data access successful")

# Test 13: Dimension verification
print("\n13. Testing Dimension Properties")
matrices = [matrix1, matrix2, identity]
names = ["matrix1", "matrix2", "identity"]

for i, (mat, name) in enumerate(zip(matrices, names)):
    print(f"   {name}: d={mat.d}, n={mat.n}")
    expected_data_shape = (mat.n, mat.n, mat.d)
    actual_shape = (len(mat.data), len(mat.data[0]), len(mat.data[0][0]))
    print(f"   {name} data shape: {actual_shape} (expected: {expected_data_shape})")
