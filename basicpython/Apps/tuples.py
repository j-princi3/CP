t1 = (12,5,8)
print(t1[1])
print(len(t1), max(t1), min(t1))
# t1[0] = 10 # illegal, due to immutability

t2 = ("hello", 5)
t3 = t1 + t2
print(t3)

print(5 in t1)

for val in t1:
  print(val)

print(t1[1:])
del t1
print(t3)
# print(t1)
