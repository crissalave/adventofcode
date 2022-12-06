datastream = open("06-input").read()

startOfPacket = 0
datastreamLen = len(datastream)

for i in range(datastreamLen):
    marker = datastream[i:i+4]
    if (len(set(marker)) == 4):
        startOfPacket = datastream.find(marker) + 4
        break

print(startOfPacket)