from collections import defaultdict
input = open("7-input.in").read().splitlines()

fileSystem = defaultdict(int)
path = []

for lines in input:
    if lines.startswith("$ cd"):
        if lines.endswith(".."):
            cdb = path.pop()
            continue
        else:
            path.append(lines.split()[2])
            continue

    if lines.startswith("$ ls"):
        continue

    try:
        l = lines.split()
        size = int(l[0])
        for i in range(len(path)+1):
            fileSystem['/'.join(path[:i])] += size
    except:
        pass

usedSpace = fileSystem['/']
gs = []

for v in fileSystem.values():
    if 70000000 - (usedSpace - v) >= 30000000:
        gs.append(v)

sor = sorted(gs)
print(sor[0])