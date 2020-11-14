case1 = int(input())

_list = []

for _ in range(case1):
    _list.append(input())

dic = dict()

for case in _list:
    case = case.split()

    if case[0] in dic.keys():
        dic[case[0]].append(int(case[1]))
    else:
        dic[case[0]] = [int(case[1])]

# sort
for k, v in dic.items():
    v.sort()

case2 = int(input())

queries = []

for _ in range(case2):
    queries.append(input())

for query in queries:
    query = query.split()
    print(dic[query[0]][int(query[1])-1])
