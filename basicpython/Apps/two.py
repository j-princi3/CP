# Using Backslash to continue statements
import os

a = 2 + \
1.5 * 3
print("a = ", a)
b = eval("3.2") + 3
print("b = ", b)

print(eval("4 < 10"))
print(eval("'hello ' * 5"))
print(eval("abs(-11)"))
print(eval('"hello".upper()'))
print(eval('os.getcwd()'))

c = eval("2.3") + 2
print("c = ", c, type(c))
d = "3.2" + "3"
print("d = ", d, type(d))

# use the implicit continuation inside parenthesis
e = ([5, 12, 13, 
200])
print("e1 = ", e)
