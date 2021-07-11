#dict
A={0:"zero",1:"one",2:"two",3:"three",4:"four",5:"five",6:"six",7:"seven",8:"eight",9:"nine"}

a = input()
sum = 0
#get sum
for i in range(len(a)):
    sum = sum + int(a[i])
result = ""
for j in str(sum):
    result = result + A[int(j)] + " "

result = result[:-1]
print(result)