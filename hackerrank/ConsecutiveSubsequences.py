for _ in range(int(input())):
    n,k=map(int,input().split())
    list1=list(map(int,input().split()))
    dict1={0:1}
    sum1,res=0,0
    for i in range(len(list1)):
        sum1+=list1[i] 
        t=sum1%k
        if t in dict1: 
            res+=dict1[t]
            dict1[t]+=1
        else:
            dict1[t]=1
    print(res)

# this is hacker rank question
