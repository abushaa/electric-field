import matplotlib.pyplot as plt

input_txt = open('potentials.txt', 'r')
input_potentials = input_txt.readlines()
input_txt.close()
potentials = []
i = 0
while i != len(input_potentials):
    line = input_potentials[i].rstrip()
    if line[len(line) - 1] == ':':
        potential_x = []
        potential_y = []
        i += 1
        line = input_potentials[i].rstrip()
        while line[len(line) - 1] != ':':
            potential = [int(x) for x in line.rstrip().split()]
            potential_x.append(potential[0])
            potential_y.append(potential[1])
            i += 1
            if i == len(input_potentials):
                break
            else:
                line = input_potentials[i].rstrip()
        potentials.append((potential_x,potential_y))
for i in range(len(potentials)):
    plt.plot(potentials[i][0], potentials[i][1]) #, '0'
plt.show()
#plt.savefig('plot_2.pdf', format='pdf')
