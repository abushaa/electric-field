//
// Created by Алина Бадамшина on 17.05.17.
//
#include <iostream>
#include <map>
using namespace std;

struct Node       //Структура являющаяся звеном списка
{
    Node()
    {
        x = 0;
        y = 0;
        next = nullptr;
        prev = nullptr;
    }
    Node(int a, int b)
    {
        x = a;
        y = b;
        next = nullptr;
        prev = nullptr;
    }
    int x;
    int y;     //Значение x будет передаваться в список
    Node *next,*prev; //Указатели на адреса следующего и предыдущего элементов списка
};


struct List   //Создаем тип данных Список
{
    Node *head;
    Node *tail;  //Указатели на адреса начала списка и его конца
    List() {
        head = tail = nullptr;
    }
};


void add( List *list, int x, int y )
{
    Node *temp = new Node(); // Выделение памяти под новый элемент структуры
    temp->next = nullptr;       // Указываем, что изначально по следующему адресу пусто
    temp->x = x;
    temp->y = y;             // Записываем значение в структуру

    if ( list->head != nullptr ) // Если список не пуст
    {
        temp->prev = list->tail; // Указываем адрес на предыдущий элемент в соотв. поле
        list->tail->next = temp; // Указываем адрес следующего за хвостом элемента
        list->tail = temp;       //Меняем адрес хвоста
    }
    else //Если список пустой
    {
        temp->prev = nullptr; // Предыдущий элемент указывает в пустоту
        list->head = list->tail = temp;    // Голова=Хвост=тот элемент, что сейчас добавили
    }
}


void printList( List * list )
{
    Node * temp = list->head;  // Временно указываем на адрес первого элемента
    while( temp != nullptr )      // Пока не встретим пустое значение
    {
        cout << "(" << temp->x << ";" << temp->y << ")" << " "; //Выводим значение на экран
        cout << "\n";
        temp = temp->next;     //Смена адреса на адрес следующего элемента
    }
}





void insert (List *list, Node *node, int i)  // 4
{
    Node *temp = list->head;
    while ((i > 1) && (temp)) {
        temp= temp->next;
        i--;
    }
    if (temp) {
        if (list->tail == temp) {
            list->tail = node;
        }
        if (list->head == temp) {
            list->head = node;
        }
        node->prev = temp->prev;
        node->next = temp;
        if (temp->prev != nullptr) {
            temp->prev->next = node;
        }
        temp->prev = node;
    } else {
        add(list, node->x, node->y);
    }
}

void  delete_from_list(List *list, int i)  // 5
{
    Node *temp = list->head;
    while ((i > 1) && (temp)) {
        temp= temp->next;
        i--;
    }
    if (temp != nullptr) {
        if (list->tail == temp) {
            list->tail = temp->prev;
        }
        if (list->head == temp) {
            list->head = temp->next;
        }
        if (temp->prev != nullptr) {
            temp->prev->next = temp->next;
        }
        if(temp->next != nullptr) {
            temp->next->prev = temp->prev;
        }
        delete temp;
    }
}


int main(){
    //Matrix matrix;
    double matrix[3][3];
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> matrix[i][j];
        }
    }
    map<double, List> pots;
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            if (matrix[i][j] != -1) { //тут должна быть проверка на null
                List list = List();
                double temp = matrix[i][j];
                for (int k = 0 ; k < 3; k++) {
                    for (int h = 0; h < 3; h++) {
                        if (matrix[k][h] == temp){
                            add(&list, k, h);
                            matrix[k][h] = -1;
                        }
                    }
                }
                pots[temp]=list;
                };
            }
        }
    }

    /*double temp=getItem(matrix,n,m);
    for (int i; i <= getNumberofStrings(matrix); i++){
        for (int j; j<= getNumberofColumns(matrix); j++){
            if (getItem(matrix,i,j)==temp){
                add(&list, i, j);
                getItem(matrix,i,j)= nullptr;
            }
        }

    }*/
}

