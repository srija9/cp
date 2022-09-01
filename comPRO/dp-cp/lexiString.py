# mincost to arrange the given strings in lexicographical order without moving but only reversing them
def mincost(arr, reversecost, n):
    dp = [[float("Inf")]*2 for i in range(n)]
    dp[0][0] = 0
    dp[0][1] = reversecost[0]
    rev_arr = [i[::-1] for i in arr]

    for i in range(1, n):
        for j in range(2):

            curStr = arr[i] if j == 0 else rev_arr[i]
            curCost = 0 if j == 0 else reversecost[i]

            if(curStr >= arr[i-1]):
                dp[i][j] = min(dp[i][j], dp[i-1][0] + curCost)
            if(curStr >= rev_arr[i-1]):
                dp[i][j] = min(dp[i][j], dp[i-1][1] + curCost)

    res = min(dp[n-1][0], dp[n-1][1])
    return res if res != float("Inf") else -1


def main():

    tc = int(input())
    while(tc):
        n = int(input())
        arr = []
        reversecost = []

        arr = [int(item) for item in input().split()]

        for i in range(0, n):
            reversecost.append(input())

        res = mincost(arr, reversecost, n)

        print(res)

        # print(arr)
        # print(reversecost)

        tc -= 1


if __name__ == "__main__":
    main()
