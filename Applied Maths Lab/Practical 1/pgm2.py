import math

a = float(input("Enter a11: "))
b = float(input("Enter a12: "))
c = float(input("Enter a21: "))
d = float(input("Enter a22: "))

trace = a + d
det = a*d - b*c

discriminant = trace**2 - 4*det

if discriminant < 0:
    print("\nComplex eigenvalues. Diagonalization over reals not possible.")
    exit()

lambda1 = (trace + math.sqrt(discriminant)) / 2
lambda2 = (trace - math.sqrt(discriminant)) / 2

print("\nEigenvalues:")
print("L1 =", lambda1)
print("L2 =", lambda2)


def eigenvector(a, b, c, d, lam):
    if b != 0:
        x = 1
        y = -(a - lam) / b
    elif c != 0:
        y = 1
        x = -(d - lam) / c
    else:
        x, y = 1, 0
    return [x, y]


v1 = eigenvector(a, b, c, d, lambda1)
v2 = eigenvector(a, b, c, d, lambda2)

print("\nEigenvector for L1:", v1)
print("Eigenvector for L2:", v2)


P = [[v1[0], v2[0]],
     [v1[1], v2[1]]]

D = [[lambda1, 0],
     [0, lambda2]]

print("\nMatrix P (Eigenvectors):")
print(P)

print("\nDiagonal Matrix D:")
print(D)


detP = P[0][0]*P[1][1] - P[0][1]*P[1][0]

if detP != 0:
    print("\nMatrix is diagonalizable.")
else:
    print("\nMatrix is NOT diagonalizable.")
