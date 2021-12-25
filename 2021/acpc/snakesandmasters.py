# def main():
#     n = int(input())

#     k = 1
#     curr = [1,2]
#     while k < n:
#         curr.append(curr[k-1]+curr[k])
#         k+=1

#     print(curr[n])
#     return

# if __name__ == "__main__":
#     main()
def dp(N):
    memo = {0:1, 1:1, 2: 2}
    if N == 1: return 1
    if N == 2: return 2
    for step in range(3, N+1):
        memo[step] = (memo[step-1] + memo[step-2]) % 1000000
    return memo[N] 

N = int(input())
print(dp(N))


# import sys
# sys.setrecursionlimit(1000000)

# # dp = [0,1]

# # def fib(n: int) -> int:
# #     if n <= 1: return n 
# #     if n < len(dp) - 1: return dp[n]
# #     result = fib(n-1) + fib(n-2)
# #     dp.append(result)
# #     return result

# # print(fib(int(input())+1))
# # def fib(n: int):
# #     out = [0,1]
# #     for i in range(2,n+1):
# #         out.append(out[i-1]+out[i-2])
# #     return out[len(out)-1]

# # print(fib(int(input())+1))

# def fib(n: int):
#     out = [0,1]
#     for i in range(2,n+1):
#         out.append(out[i-1]+out[i-2])
#     return out[len(out)-1]

# print(fib(int(input())+1))