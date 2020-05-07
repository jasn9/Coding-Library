
# for a given n and m, construct n arrays such that choosing any m arrays and their union contains all element contain in array, also
# and this condition should not be followed in choosing any m-1 arrays ans so on.

def solution(num_buns, num_required):

    dp = []

    for i in range(num_buns+1):
        arr = []
        for j in range(num_required+1):
            arr += [[]]
        #print(arr)
        dp += [arr]

    #print(dp)
    ar = []
    for i in range(0,num_buns+1):
        for j in range(num_required+1):
            if(j==0 or i<j):
                dp[i][j] = ar
            else:
                ans = []
                arr1 = dp[i-1][j]
                arr2 = dp[i-1][j-1]
                #printi(dp)
                #print(i,j,arr1,arr2)
                ma = 0;
                for x in arr1:
                    for y in x:
                       ma = max(ma,y)
                arr = []

                for k in range(ma+1):
                    arr += [k]
                ans += [arr]
    
                for k in range(i-1):
                    arr2[k] = [h+ma+1 for h in arr2[k]]
                    ans += [arr1[k]+arr2[k]]

                dp[i][j] = ans
        ar += [[]]
                
                
            
    #printi(dp)

    return dp[num_buns][num_required]
                
