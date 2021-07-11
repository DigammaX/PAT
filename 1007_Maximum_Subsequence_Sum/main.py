n = int(input())
A = list(map(int, input().split(" ")))  # input
C = [0]  # dp,维护一个以第n个数字结尾，和最大的数组(0-n)
D = [[0, 0]]  # 定位数组 [i,j) (i,i+1,,j-1)
cnt = 0
flag = 1 #判定是不是全都是负数
for i in A:
    flag = flag & (i<0)
    cnt=cnt+1
    m = max(0, i, C[-1] + i)  # 递推只有三种情况
    C.append(m)
    if (m==0):
        D.append([cnt,cnt])
    elif (m==i):
        D.append([cnt,cnt+1])
    else:
        D.append([D[-1][0],cnt+1])

index = C.index(max(C))
if (flag == 1):
    print("{} {} {}".format(0,A[0],A[-1]))
elif (max(C) > 0) :
    print("{} {} {}".format(max(C),A[D[index][0]-1],A[D[index][1]-2])) #正常情况下,数列长度不为0
else:
    print("{} {} {}".format(0,0,0))