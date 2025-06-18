# specialMatrix



The C++ has already been built and is ready to use in the test folder with example code and benchmarks provided.

In test.py, the n and d values have been chosen such that they prove the advantage of the specialMatrix library without taking up too much time. On different devices, they may need changing because for smaller matrices NumPy is still faster due to it utilizing the highly optimized LAPACK functions, while I made my own functions for the sake of it.


If changes are needed, cmake can be run in the root folder, and the output of make must be put in the same directory as the python file
