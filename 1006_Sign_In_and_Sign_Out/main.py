n = int(input())
A=[]
for i in range(n):
    a,b,c = input().split(" ")
    b = int("".join(b.split(":")))
    c = int("".join(c.split(":")))
    A.append([a,b,c])

B=sorted(A,key= lambda ele: ele[1])
C=sorted(A,key= lambda ele: ele[2])
print("{} {}".format(B[0][0],C[-1][0]))