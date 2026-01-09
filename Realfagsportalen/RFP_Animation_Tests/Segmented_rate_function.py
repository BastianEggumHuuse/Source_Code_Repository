import numpy as np
import matplotlib.pyplot as plt

def rate_func(t,l = 1):
    #return np.exp(t * l) / np.exp(l)
    return(t)

rf = lambda t : rate_func(t,4)

slices = [
    0,
    2,
    5,
    8,
    10
    ]#np.arange(0,11,2)

X = []
Y = []

for i in range(len(slices)-1):

    a = slices[i]
    b = slices[i+1]
    B = slices[-1]
    d = b - a

    X_i = []
    Y_i = []

    Y_i_2 = [] # With removals
    Y_i_3 = [] # With norms

    for i in np.linspace(0,1,100):

        X_i.append(a + i*d)
        Y_i.append(rf((a + i*d)/B))
        Y_i_2.append(rf((a + i*d)/B) - rf(a/B))
        Y_i_3.append((rf((a + i*d)/B) - rf(a/B)) / (rf((b)/B) - rf(a/B)))

    X += X_i
    Y += Y_i

    plt.plot(X_i,Y_i)
    #plt.show()

#plt.plot(X,Y)
plt.show()

#plt.plot(np.linspace(0,1,100),rate_func(np.linspace(0,1,100),rate_length))
#plt.show()