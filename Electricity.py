import matplotlib.pyplot as plt
import math

def BubbleSort(list):
    n = 1 
    while n < len(list):
        for j in range(len(list)-n):		
            if list[j] > list[j+1]:
                list[j],list[j+1] = list[j+1],list[j]
        n += 1
    return list

def list_cut(list, portion):
    return_list = []
    for i in range(math.floor(len(list)*portion), len(list)): 
        return_list.append(list[i])
    return return_list

input_txt = open('potentials.txt', 'r')
input_potentials = input_txt.readlines()
input_txt.close()
potentials = []
quantities = [] #
current_quantity  = 0 #
i = 0
while i != len(input_potentials):
    line = input_potentials[i].rstrip()
    if line[len(line) - 1] == ':':
        potential_x = []
        potential_y = []
        i += 1
        potential_string = [float(x) for x in line.rstrip(':').split()]# Добавляем в отдельный список все значения потенциалов
        quantities.append(potential_string[0])#
        current_quantity = potential_string[0]# Зарегистрируем текущее значение потенциала
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
        potentials.append([potential_x,potential_y, current_quantity, True]) ##ищменил кортеж на список

quantities = BubbleSort(quantities) #сортируем значения потенциалов по значениям
quantities_to_be_cut = []
quantities_to_be_cut = list_cut(quantities, 1/6) # выделяем те потенциалы, которые не будем визуализировать

##print(quantities)
##print(quantities_to_be_cut)
#print(potentials)
# Теперь развесим флаги в тех кортежах, в которых присутствует нежелаемый к визуализации потенциал
for i in range(len(potentials)):
     if potentials[i][2] in quantities_to_be_cut:
         potentials[i][3] = False
     print(potentials[i][2])
for i in range(len(potentials)):
    if (potentials[i][3] == True) or ( potentials[i][2] == 'inf') or ( i%5 == 0 ):
        plt.plot(potentials[i][0], potentials[i][1],'o')
plt.show()
#plt.savefig('plot_2.pdf', format='pdf')
