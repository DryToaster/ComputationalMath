import sys
import numpy as np

def abserr(u: float, v: float) -> float:
    if (u>v):
        return u-v
    else:
        return v-u

def relerr(u: float, v: float) -> float:
    if (u==0):
        return sys.maxint
    if (u>v):
        return (u-v)/u
    else:
        return (v-u)/u

def precision(u: float, v: float) -> int:
    diff = np.abs(u-v)
    dpower = np.log10(diff)
    upower = np.log10(u)
    return np.floor(upower - dpower)

if __name__== '__main__':
    #test func
    u = 5.0
    v = 4.999999999999
    print(abserr(u, v))
    print(relerr(u, v))
    print(precision(u, v))
