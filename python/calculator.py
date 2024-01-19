x = int(input("x: "))
y = int(input("y: "))

print (x + y)

#or

x = input("x: ")
y = input("y: ")

print (int(x) + int(y))

#ISSUE WHEN STRING INPUT
#> python calculator.py
#>x: cat
#>y: cat
#>Traceback (most recent call last):
#>  File "/workspaces/personal_testing/python/calculator.py", line 4, in <module>
#>    print (int(x) + int(y))
#>ValueError: invalid literal for int() with base 10: 'cat'
-------------------------------------------------------------------------------------
#from lib import int_perso or if want to use
# the int_perso fonction from the library and not one made by the user

import lib

x = lib.int_perso("x: ")
y = lib.int_perso("y: ")

print (x + y)