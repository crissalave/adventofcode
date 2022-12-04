with open("04-input") as input:
    content = input.read().splitlines()

totalOverlaps = 0

for line in content:
    pairsList = line.split(",")
    n = []

    for p in pairsList:
        pair = p.split("-")
        n.append(int(pair[0]))
        n.append(int(pair[1]))

    if (n[1] >= n[2] and n[3] >= n[0]):
        totalOverlaps += 1 

print(totalOverlaps)