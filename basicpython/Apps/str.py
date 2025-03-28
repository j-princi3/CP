str1 = "Genesis"
str2 = "Genesis"
print(id(str1), id(str2))
# str1[1] = 'a'      # illegal, since strings are immmutable

# str is really a pointer, and we are simply pointing it to a 
# new string created from old ones
str1 = str1[:1] + 'i' + str1[6:] 

print(str1, str2)
print(id(str1), id(str2))

str = "Genesis"
print(str.index('e'))
print(str.index('es'))
print('a' in str)

print(str.upper(), str.lower())
print(str.replace('a', 'b'))
str=";"
print(str.join(('Insoft', 'hyd', 'india')))
str="Genesis"
print(str*3, len(str))
print(str[2:10])

str = "hello123"
print(str.isalnum(), str.isalpha())

val = "123"
print(val.isdigit())
str = "Genesis"
print(str.isalpha())
