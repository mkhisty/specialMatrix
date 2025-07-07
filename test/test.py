import specialmatrix
import numpy as np
import random
import time

np.set_printoptions(linewidth=float('inf'))
ITER = 100
totalMultiplyTimeSM = 0
totalMultiplyTimeNM = 0
totalDeterminantTimeSM = 0
totalDeterminantTimeNM = 0
totalInverseTimeSM = 0
totalInverseTimeNM = 0
totalMultiplyCorrect = 0
totalDeterminantCorrect = 0
totalInverseCorrect = 0
totalInverses = 0

def measure(f):
    start_time = time.perf_counter()
    out = f()
    end_time = time.perf_counter()
    return out, end_time - start_time

for _ in range(1, ITER):
    n = random.randint(20, 30)
    d = random.randint(20, 30)
    sm = specialmatrix.SpecialMatrix(n, d)
    nm = np.array(sm.toNormal())
    sm2 = specialmatrix.SpecialMatrix(n, d)
    nm2 = np.array(sm2.toNormal())

    sm3, time_sm_mult = measure(lambda: sm @ sm2)
    totalMultiplyTimeSM += time_sm_mult
    nm3, time_nm_mult = measure(lambda: nm @ nm2)
    totalMultiplyTimeNM += time_nm_mult

    if np.allclose(np.array(sm3.toNormal()), nm3):
        totalMultiplyCorrect += 1

    smD, time_sm_det = measure(lambda: sm3.det())
    totalDeterminantTimeSM += time_sm_det
    nmD, time_nm_det = measure(lambda: np.linalg.det(nm3))
    totalDeterminantTimeNM += time_nm_det

    if np.isclose(smD, nmD, rtol=1e-3):
        totalDeterminantCorrect += 1

    if nmD != 0:
        totalInverses += 1
        sm4, time_sm_inv = measure(lambda: sm3^-1)
        totalInverseTimeSM += time_sm_inv
        nm4, time_nm_inv = measure(lambda: np.linalg.inv(nm3))
        totalInverseTimeNM += time_nm_inv

        if np.allclose(np.array(sm4.toNormal()), nm4):
            totalInverseCorrect += 1

print("Multiplication Accuracy: ", totalMultiplyCorrect / (ITER - 1))
print("Average specialmatrix Multiplication time: ", totalMultiplyTimeSM / (ITER - 1))
print("Average numpy Multiplication time: ", totalMultiplyTimeNM / (ITER - 1))
print("Determinant Accuracy: ", totalDeterminantCorrect / (ITER - 1))
print("Average specialmatrix Determinant time: ", totalDeterminantTimeSM / (ITER - 1))
print("Average numpy Determinant time: ", totalDeterminantTimeNM / (ITER - 1))
print("Inverse Accuracy: ", totalInverseCorrect / totalInverses)
print("Average specialmatrix Inverse time: ", totalInverseTimeSM / totalInverses)
print("Average numpy Inverse time: ", totalInverseTimeNM / totalInverses)
