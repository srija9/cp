cha = input()
b = input()

#diction = { 1:'A', 2:'B', 3:'C', }
low = cha.islower()
# 65 to 90 - upper
# 97 to 122 - lower

value = ord(cha) + int(b) 


if low==False:
    bound = 90
    if value <= 90:
        result = chr(value)
    else:
        result = chr(value - bound + 65 -1)
else:
    bound = 122
    if value <= 122:
        result = chr(value)
    else:
        result = chr(value - bound + 97 -1)

print(result)

