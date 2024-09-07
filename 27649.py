
def solve(string, token):
    result = []

    split_res = string.split(token)

    for s in split_res:
        result.append(s)
        result.append(token)

    result.pop()
    return result

def solves(lst, token):
    result = []
    for l in lst:
        ss = solve(l, token)
        for s in ss:
            result.append(s)

    return result

s = input()

result = solve(s, '<')
result = solves(result, '>')
result = solves(result, '&&')
result = solves(result, '||')
result = solves(result, '(')
result = solves(result, ')')
result = solves(result, ' ')

result = [v.strip() for v in result if v]
# print(result)

result = [v for v in result if v]
# print(result)

print(*result, sep=' ')

