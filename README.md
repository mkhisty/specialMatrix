# specialMatrix



The C++ has already been built and is ready to use in the test folder with example code and benchmarks provided.

```bash

➜  test git:(main) python3 test.py
/usr/lib/python3/dist-packages/numpy/linalg/linalg.py:2180: RuntimeWarning: overflow encountered in det
  r = _umath_linalg.det(a, signature=signature)
Multiplication Accuracy:  1.0
Average specialmatrix Multiplication time:  0.011118460414157502
Average numpy Multiplication time:  0.23537075683844072
Determinant Accuracy:  1.0
Average specialmatrix Determinant time:  0.01186529779798465
Average numpy Determinant time:  0.07348385917173966
Inverse Accuracy:  1.0
Average specialmatrix Inverse time:  0.04403484937367209
Average numpy Inverse time:  0.08273912898991025

```


In test.py, the n and d values have been chosen such that they prove the advantage of the specialMatrix library without taking up too much time. On different devices, they may need changing because for smaller matrices NumPy is still faster due to it utilizing the highly optimized LAPACK functions, while I made my own functions for the sake of learning.


If changes are needed, cmake can be run in the root folder, and the output of make must be put in the same directory as the python file


