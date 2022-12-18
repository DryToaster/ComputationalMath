import numpy as np
from plotfit import plotPoints
import matplotlib.pyplot as mpl
from rootfinding import solvesecant

def logiGenerator(a, b):
    # Describes logistic function with given parameters in the form dx/dt=f(t,x(t))
    def dx(t, p):
        return a*p - b*p*p
    return dx

def dlogiGenerator(a, b):
    def ddx(t, p):
        return a-2*b*p
    return ddx


def eulerexp(dy, P0: float, t0: float, tol: float, h: float, maxiters: int):
    pointsTP = [[t0, P0]]
    x0 = t0
    y0 = P0

    iters = 0
    err = 10*tol

    while (iters<maxiters and err>tol):
        y1 = y0 + dy(x0, y0)*h
        x1 = x0+h
        #print(y1)

        pointsTP.append([x1, y1])
        err = np.abs(y0-y1)
        y0 = y1
        x0 = x1
        iters += 1

    return pointsTP

def eulerimp(dy, P0: float, t0: float, tol: float, h: float, maxiters: int):
    
    def makeimp(F, t_1: float, h: float, P_0: float):
        def func(P_1):
            return (P_0 - P_1 + h * (F(t_1, P_1)))
        return func

    iters = 0
    err = 10*tol
    pointlist = [[t0, P0]]

    while (err>tol and iters<maxiters):
        target = makeimp(dy, t0+h, h, P0)

        P1 = solvesecant(target, P0, P0+2*h, .0001, 200, False)
        #print(P1)
        err = np.abs(P1-P0)
        iters += 1
        t0 = t0+h
        P0 = P1
        pointlist.append([t0, P0])
    return pointlist


def solveLogiexp(a: float, b: float, P0: float, t0: float, tol: float, h: float, maxiters: int):
    return eulerexp(logiGenerator(a, b), P0, t0, tol, h, maxiters)
def solveLogiimp(a: float, b: float, P0: float, t0: float, tol: float, h: float, maxiters: int):
    return eulerimp(logiGenerator(a, b), P0, t0, tol, h, maxiters)
def solveAnalyticLogi(t, P0, a, b):
    A = P0/(b*P0-a)
    return(A*a*np.exp(a*t))/(b*(A*np.exp(a*t)) - 1)

if __name__=='__main__':
    #test func
    pointListexp = solveLogiexp(.2, .0005, 10.0, 0.0, .0000001, .1, 2000)
    pointListimp = solveLogiimp(.2, .0005, 10.0, 0.0, .0000001, .1, 2000)
    pointListanl = []
    t0 = 0
    P0 = 10.0
    a = .2
    b = .0005
    for i in range(2000):
        pointListanl.append([t0, solveAnalyticLogi(t0, P0, a, b)])
        #print(solveAnalyticLogi(t0, P0, a, b))
        t0 += .1
    xlistexp = []
    ylistexp = []
    for i in range(len(pointListexp)):
        xlistexp.append(pointListexp[i][0])
        ylistexp.append(pointListexp[i][1])
    xlistimp = []
    ylistimp = []
    for i in range(len(pointListimp)):
        xlistimp.append(pointListimp[i][0])
        ylistimp.append(pointListimp[i][1])
    xlistanl = []
    ylistanl = []
    for i in range(len(pointListanl)):
        xlistanl.append(pointListanl[i][0])
        ylistanl.append(pointListanl[i][1])

    mpl.loglog(np.array(xlistexp), np.array(ylistexp), 'o', color = 'b')
    mpl.loglog(np.array(xlistimp), np.array(ylistimp), 'o', color = 'r')
    mpl.loglog(np.array(xlistanl), np.array(ylistanl), color = 'g')
    mpl.show()

    #allx = [] + xlistexp + xlistimp + xlistanl
    #ally = [] + ylistexp + ylistimp + ylistanl

    #plotPoints(allx, ally)
    

    
    
                     
    
    
