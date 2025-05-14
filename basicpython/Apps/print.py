s="genesis"

"""
Name s is attached to 'genesis' string. When you call str(s) the 
interpreter puts 'genesis' instead of s and then calls str('genesis').
"""

print(str(s))
print(repr(s))

for x in range(1, 5):
  print(str(x).rjust(2), str(x*x).rjust(3), sep=";", end=' ')
  # Note use of 'end' in the above
  print(str(x*x*x).rjust(4))

print()
for x in range(1, 5):
  print('{0:2d} {1:3d} {2:4d}'.format(x, x*x, x*x*x))

print()
print('12'.zfill(5))
print('3.14159265'.zfill(5))
print('-3.14'.zfill(7))

print('{0:12} and {1:10}'.format('company', 'Genesis'))

print()

print('PI value is approximately {0:.3f}'.format(3.14159265))

print('{0} is {1}'.format('Country', 'India'))
print('{1} is {0}'.format('Country', 'India'))
print('Our {key} is {data}'.format(key='country', data='india'))

print('{0} {company}'.format('Genesis', company='InSoft'))
