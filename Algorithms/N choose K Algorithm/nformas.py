# Cn,k+1 = n-k/k+1 * Cn,k
# Using recursive formula

def choose(n, k):
    triangle = []
    for i in range(n):
        Cnk = 1
        triangle.append([])
        for j in range(k+i):
            if(Cnk != 0):
                triangle[i].append(Cnk)
            Cnk = Cnk * (i-j) // (j+1)
    return triangle[n-1][k-1] + triangle[n-1][k]

print(choose(100, 50))