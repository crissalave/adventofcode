with open("04-input") as input:
    content = input.read().splitlines()

totalContains = 0

for line in content:
    pairsList = line.split(",")
    n = []

    for p in pairsList:
        pair = p.split("-")
        n.append(int(pair[0]))
        n.append(int(pair[1]))

    if ((n[0]<=n[2] and n[1]>=n[3]) or (n[0]>=n[2] and n[1]<=n[3])):
        totalContains += 1

print(totalContains)