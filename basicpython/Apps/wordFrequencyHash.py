def wordFrequency(str):
  words = str.split()
  counts = dict()

  for word in words:
    if(word in counts):
      counts[word] += 1
    else:
      counts[word] = 1
 
  for key in counts:
    print(key, counts[key])

str = "hello world hello Qualcomm Training at Qualcomm"
wordFrequency(str)

      