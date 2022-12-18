import matplotlib.pyplot as mpl
import numpy as np

def plotLineReg(xlist: list, ylist: list, a: float, b: float):
    xpoints = np.array(xlist)
    ypoints = np.array(ylist)

    mpl.plot(xpoints, ypoints, 'o')
    
    leftx = xpoints[0]
    rightx = xpoints[len(xpoints)-1]
    mpl.plot([leftx, rightx],[leftx*a+b,rightx*a+b])
    
    mpl.show()

def plotPoints(xlist: list, ylist: list):
    xpoints = np.array(xlist)
    ypoints = np.array(ylist)

    mpl.plot(xpoints, ypoints, 'o')
    mpl.show()

def plotPointsLL(xlist: list, ylist: list):
    xpoints = np.array(xlist)
    ypoints = np.array(ylist)

    mpl.loglog(xpoints, ypoints, 'o')
    mpl.show()

if __name__=='__main__':
    print(mpl.rcParams['backend'])



