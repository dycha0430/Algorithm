N = 0
maxNum = 0
cars = []
mem =[[-1]*50000 for _ in range(3)]
def main():
    global N, maxNum, cars
    N = int(input())
    cars = list(map(int, input().split()))
    maxNum = int(input())

    print(DP(0, 3, 0))

def DP(curSum, leftCarNum, start_idx):
    global mem, N, maxNum, cars
    if (leftCarNum == 0 or start_idx >= N):
        return curSum

    tmp_mem = mem[leftCarNum-1][start_idx]
    if (tmp_mem != -1):
        return tmp_mem
    maxRet = 0
    for i in range(start_idx, N):
        tmpSum = curSum
        for j in range(i, min(N, i+maxNum)):
            tmpSum += cars[j]
        maxRet = max(maxRet, DP(tmpSum, leftCarNum-1, i+maxNum))
    mem[leftCarNum-1][start_idx] = maxRet
    return maxRet

main()

