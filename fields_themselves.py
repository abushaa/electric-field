"""
Demo of the `streamplot` function.

A streamplot, or streamline plot, is used to display 2D vector fields. This
example shows a few features of the stream plot function:

    * Varying the color along a streamline.
    * Varying the density of streamlines.
    * Varying the line width along a stream line.
"""
import numpy as np
import matplotlib.pyplot as plt

#Напишем
data = [[1,2,0.20,0.50],[1,10,0.70,0.50]]

Y, X = np.mgrid[0:1:100j, 0:1:100j]
n = 0
U = 0
V = 0
while n < len(data):
    q = data[n][1]
    x0 = data[n][2]
    y0 = data[n][3]
    distance = ((x0-X)**2 + (y0-Y)**2)**0.5
    U += q*(Y-y0)/(distance**3)
    V += q * (X - x0) / (distance ** 3)
    n+=1
#U = -1 - X**2 + 2*Y
#V = 1 + 2*X - Y**2
speed = np.sqrt(U*U + V*V)

fig0, ax0 = plt.subplots()
strm = ax0.streamplot(X, Y, U, V, color=U, linewidth=2, cmap=plt.cm.autumn)
fig0.colorbar(strm.lines)

#fig1, (ax1, ax2) = plt.subplots(ncols=2)
#ax1.streamplot(X, Y, U, V, density=[0.5, 1])

#lw = 5*speed / speed.max()
#ax2.streamplot(X, Y, U, V, density=0.6, color='k', linewidth=lw)

plt.show()
