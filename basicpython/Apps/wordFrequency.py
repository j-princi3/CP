def wordFrequency(str):
  str = str.split()
  str1 = []

  for i in str:
    if(i not in str1):
      str1.append(i)
 
  for i in range(0, len(str1)):
    print(str1[i], str.count(str1[i]))

str = "hello world hello Qualcomm Training at Qualcomm"
wordFrequency(str)

      