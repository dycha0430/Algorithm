def main():
    N = int(input())
    strength = list(map(int, input().split()))

    maxStrength = max(strength)
    maxIndex = list(filter(lambda x: strength[x] == maxStrength, range(len(strength))))
    
    B = maxIndex[0]
    R = N - maxIndex[len(maxIndex)-1] - 1

    if R > B:
        print("R")
    elif R < B:
        print("B")
    else:
        print("X")

main()
