val = int(input("Enter your value:"))
if val>=0 and val<=511:
    for indx,i in enumerate(bin(val)[2:].zfill(9)):
        if i=='0':
            print("0",end=" ")
        else:
            print("1",end=" ")
        if indx %3==2:
            print(" ",end="")
    print()
else:
    print("Invalid Input")