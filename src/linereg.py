#B = (X'X)^-1 X' y
from plotfit import plotLineReg
from derive import approxD2iter, testf

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

if (__name__=='__main__'):
    # Test method
    #xlist = [1,2,3,4,5,6,7,8,9]
    #ylist = [1,2,3,4,5,6,7,8,9]
    
    pointslist = approxD2iter(testf, 1.0, .125, .000001, 200)
    xlist = []
    ylist = []
    for i in range(len(pointslist)):
        xlist.append(pointslist[i][0])
        ylist.append(pointslist[i][1])
    b, a = linereg(xlist, ylist)
    print("a: ",a,"b: ",b)
    plotLineReg(xlist, ylist, a, b)
    
    
    
    
    
