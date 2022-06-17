line = input().split()
A, B = line[0], line[1]

idxA, idxB = len(A)-1, len(B)-1

answer = []
plus = 0
minRange = min(idxA, idxB) + 1
for i in range(minRange):
    sum = int(A[idxA-i]) + int(B[idxB-i]) + plus
    plus = 0
    if (sum >= 10):
        plus = 1
        sum -= 10
    answer.append(sum)

if idxA > idxB:
    for i in reversed(range(idxA-idxB)):
        sum = int(A[i]) + plus
        plus = 0
        if (sum >= 10):
            plus = 1
            sum -= 10
        answer.append(sum)
elif idxA < idxB:
    for i in reversed(range(idxB-idxA)):
        sum = int(B[i]) + plus
        plus = 0
        if sum >= 10:
            plus = 1
            sum -= 10
        answer.append(sum)
if plus == 1:
    answer.append(plus)

for i in reversed(answer):
    print(i, end="")

