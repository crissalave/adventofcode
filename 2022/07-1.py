from collections import defaultdict
input = open("07-input.in").read().splitlines()

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
        print(path, size)
        for i in range(len(path)+1):
            fileSystem['/'.join(path[:i])] += size
    except:
        pass

total = 0
for k, v in fileSystem.items():
    print(k, v)
    if v <= 100000:
        total += v

print(total)