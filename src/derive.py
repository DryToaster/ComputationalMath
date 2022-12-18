import numpy as np
from plotfit import plotLineReg, plotPoints

def approxD2(f, x_0, h):
    return (f(x_0+h) - 2*f(x_0) + f(x_0-h))/(h*h)

def approxD2iter(f, x_0, h, tol, maxiters):
    iters = 0
    err = 10*tol
    a = x_0
    appxList = []
    while(err>tol and iters<maxiters):
        b = approxD2(f, x_0, h)
        err = np.abs(a-b)
        iters += 1
        h *= 0.5
        a = b
        appxList.append([h,a])
    return appxList

def testf(x):
    return ((x-np.pi/2)*(np.tan(x)**2))/(x**2+65)

if __name__=='__main__':
    # test func
    approxList = approxD2iter(testf, np.pi/4, .125, .0001, 200)
    print("h, approx")
    xlist = []
    ylist = []
    for i in range(len(approxList)):
        print(approxList[i])
        xlist.append(approxList[i][0])
        ylist.append(approxList[i][0])

    plotPoints(xlist, ylist)
    

    
