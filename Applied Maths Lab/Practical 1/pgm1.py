r = int(input("Enter number of rows: "))
c = int(input("Enter number of cols: "))

A = []
B = []

print("Enter elements for matrix A")
for _ in range(r): 
    l1 = list(map(int, input().split()))
    A.append(l1)

print("Enter elements for matrix B")
for _ in range(r): 
    l1 = list(map(int, input().split()))
    B.append(l1)


print("="*40)
print("Matrix Addition: ")
for i in range(r): 
    for j in range(c): 
        print(A[i][j] + B[i][j], end = " ")
    print()

print("="*40)
print("Matrix Subtraction: ")
for i in range(r): 
    for j in range(c): 
        print(A[i][j] - B[i][j], end = " ")
    print()

print("="*40)
print("Matrix Multiplication: ")

C = [[0 for _ in range(c)] for _ in range(r)]

for i in range(r): 
    for j in range(c): 
        for k in range(c): 
            C[i][j] += A[i][k] * B[k][j]

for i in range(r):
    for j in range(c):
        print(C[i][j], end=" ")
    print()


print("="*40)
scalar = int(input("Enter scalar value: "))
print("Scalar multiplication on Matrix A: ")
for i in range(r):
    for j in range(c):
        print(A[i][j] * scalar, end=" ")
    print()

print("="*40)
print("Scalar multiplication on Matrix B: ")
for i in range(r):
    for j in range(c):
        print(B[i][j] * scalar, end=" ")
    print()