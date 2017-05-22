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

input_txt = open('q.txt', 'r')
input_data = input_txt.readlines()
input_txt.close()
#Напишем

Y, X = np.mgrid[0:100:10j, 0:100:10j]
n = 0
U = 0
V = 0
while n < len(input_data):
    string = input_data[n].rstrip()
    data = [float(x) for x in string.rstrip().split()]
    q = int(data[1])
    x0 = int(data[2])
    y0 = int(data[3])
    distance = ((x0-X)**2 + (y0-Y)**2)**0.5
    U += q*(Y-y0)/(distance**3)
    V += q * (X - x0) / (distance ** 3)
    n+=1

speed = np.sqrt(U*U + V*V)
fig0, ax0 = plt.subplots()
strm = ax0.streamplot(X, Y, V, U, color=speed, linewidth=2, cmap=plt.cm.autumn)
fig0.colorbar(strm.lines)
plt.title('Распределение напряженности электрического поля')
plt.show()
