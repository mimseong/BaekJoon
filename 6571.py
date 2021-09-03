def solve(v, a, b):
    
    ans = 0
    for i in range(1001):
        if (int(a) <= v[i] <= int(b)):
            ans += 1;
    print(ans)
    
    

def main(v):
    while True:
        a, b = list(input().split())
        
        if a == "0" and b == "0":
            break;
        
        solve(v, a, b)

v = []
n1 = 1
n2 = 2
v.append(n1)
v.append(n2)
for i in range(1001):
    v.append(n1 + n2)
    tmp = n1
    n1 = n2
    n2 = tmp + n1

main(v)