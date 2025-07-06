# specialMatrix



The C++ has already been built and is ready to use in the test folder with example code and benchmarks provided.

```bash
$ python3 test.py
/usr/lib/python3/dist-packages/numpy/linalg/linalg.py:2180: RuntimeWarning: overflow encountered in det
  r = umath_linalg.det(a, signature=signature)
Multiplication Accuracy:  1.0
Average SM Multiplication time:  0.008987155424238889
Average NP Multiplication time:  0.1927241227373786
Determinant Accuracy:  1.0
Average SM Determinant time:  0.008878118040380892
Average NP Determinant time:  0.05779320853536425
Inverse Accuracy:  1.0
Average SM Inverse time:  0.03591465654544939
Average NP Inverse time:  0.06441826532325723
```

In test.py, the n and d values have been chosen such that they prove the advantage of the specialMatrix library without taking up too much time. On different devices, they may need changing because for smaller matrices NumPy is still faster due to it utilizing the highly optimized LAPACK functions, while I made my own functions for the sake of learning.


If changes are needed, cmake can be run in the root folder, and the output of make must be put in the same directory as the python file


