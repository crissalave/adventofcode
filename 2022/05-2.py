tmpCargo = []
cargo = []
procedures = []
lineLen = 0

with open("05-input.txt") as input:
    content = input.read().splitlines()
    lineLen = len(content[0])
    for line in content:
        if (line.startswith("move")):
            p = line.replace(" ", "").replace("move", "").replace("from", " ").replace("to", " ").split()
            procedures.append(p)
            continue

        tmpCargo.append([*line])

for i in tmpCargo[len(tmpCargo)-2]:
    if (ord(i) in range(65, 91)):
        cargo.append([])

for crave in tmpCargo:
    craveIdx = 0
    for i in range(1, lineLen, 4):
        if (ord(crave[i]) in range(65, 91)):
            cargo[craveIdx].insert(0, crave[i])
        craveIdx += 1


def crateMover9001(quanitity, _from, _to):
    craveStack = []
    if (quanitity == 1):
        crave = cargo[_from].pop()
        cargo[_to].append(crave)
        return

    for i in range(quanitity):
        crave = cargo[_from].pop()
        craveStack.insert(0, crave)
    
    cargo[_to] += craveStack

for p in procedures:
    crateMover9001(int(p[0]), int(p[1])-1, int(p[2])-1)

answer = ""
for crave in cargo:
    answer += crave[len(crave)-1]

print("Answer: " + answer)