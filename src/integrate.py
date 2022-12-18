import numpy as np
from plotfit import plotPoints, plotPointsLL


def trapint(f, a: float, b: float, i: int):
    h = (b-a)/float(i)
    c = 1
    midsum = (f(a)+f(b))/2
    
    while c < i:
        midsum += f(a+c*h)
        c += 1
    return midsum*h


def simpint(f, a: float, b: float, i: int):
    f_oddsum = 0.0
    f_evensum = 0.0
    h = (b-a)/i

    x = a + h
    while x+2*h<b:
        f_oddsum += f(x)
        f_evensum += f(x+h)
        x += 2*h
    return (h/3.0)*(f(a) + f(b) + 4*f_oddsum + 2*f_evensum)

        
def testf(x: float):
    return np.e**(-1*x**2)

def testg(x: float):
    return x**3-x**2+x-1

if __name__=="__main__":
    print(trapint(testf, 0.0, np.pi/4, 2))
    print(trapint(testf, 0.0, np.pi/4, 4))
    print(trapint(testf, 0.0, np.pi/4, 8))
    print(trapint(testf, 0.0, np.pi/4, 16))
    print(trapint(testf, 0.0, np.pi/4, 32))
    print(trapint(testf, 0.0, np.pi/4, 64))
    print(trapint(testf, 0.0, np.pi/4, 128))
    print(trapint(testf, 0.0, np.pi/4, 256))
    
    
    hlist = []
    ylist = []

    h = 0.25

    for i in range(16):
        hlist.append(h)
        ylist.append(0.65 - simpint(testf, 0.0, np.pi/4.0, np.round((np.pi/4.0)/h)))
        h /= 2.0
    plotPointsLL(hlist, ylist)
                             
    

    
