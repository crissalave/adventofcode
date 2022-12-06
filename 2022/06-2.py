datastream = open("06-input").read()

startOfMessage = 0
datastreamLen = len(datastream)

for i in range(datastreamLen):
    marker = datastream[i:i+14]
    if (len(set(marker)) == 14):
        startOfMessage = datastream.find(marker) + 14
        break

print(startOfMessage)