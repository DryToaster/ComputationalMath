# lineReg
**Function Name:** linereg  
**Author:** Nathan Nelson  
**Language:** Python  
**Description/Purpose:** This function uses least-squares regression to find a line of best fit given points of data.  
**Input:** This function accepts two `list`s of values; the first is the list of x-values, and the second is the list of corresponding y-values.  
**Output:** A tuple of two floats is returned; the first value in the tuple is the y-intercept b, and the second is the slope a.  
**Usage/Example:** All inputs are taken as arguments:  
`params = linereg(xlist, ylist)`  
**Implementation/Code:** This is the function implementation in Python:  
```
def linereg(xlist: list, ylist: list):
    if len(xlist)!=len(ylist):
        print("xlist and ylist are not of matching size")
        return None

    # 'a' represents entries of A, which is a label for the matrix (X'X)
    a00 = len(xlist)
    a10 = 0
    for i in range(len(xlist)):
        a10 += xlist[i]
    a11 = 0
    for i in range(len(xlist)):
        a11 += xlist[i]*xlist[i]

    # 'c_n' represents the nth component of c which is a label for the vector(X'y)    
    c0 = 0
    for i in range(len(ylist)):
        c0 += ylist[i]
    c1 = 0
    for i in range(len(ylist)):
        c1 += ylist[i]*xlist[i]

    detA = (a00*a11)-(a10*a10)

    # entries of A^-1
    ai00 = a11/detA
    ai10 = -1*a10/detA
    ai11 = a00/detA

    #entries of beta
    b0 = (c0*ai00)+(c1*ai10) # intercept
    b1 = (c0*ai10)+(c1*ai11) # slope

    return b0, b1


```
**Last Modified:** 10/19/22