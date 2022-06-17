N = 0
maxNum = 0
cars = []
mem =[[0]*50001 for _ in range(4)]
def main():
    global N, maxNum, cars
    N = int(input())
    cars = list(map(int, input().split()))
    cars.insert(0, 0)
    for i in range(1, N+1):
        cars[i] += cars[i-1]
    maxNum = int(input())

    startIdx = maxNum
    for i in range(1, 4):
        for j in range(startIdx, N+1):
            mem[i][j] = max(mem[i][j-1], cars[j] - cars[j-maxNum] + mem[i-1][j-maxNum])
            

    print(mem[3][N])
    
main()

