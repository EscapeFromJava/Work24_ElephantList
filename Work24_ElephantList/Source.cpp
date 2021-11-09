//Пример создания списка Слонов, добавлления и удаления оттуда элементов

#include <string>
#include <iostream>
using namespace std;

int numEl = 5;

struct Elephant {
    string name;
    int age;
    float weight;
};

Elephant inputElephant(int number);
string elephantToString(Elephant el);

struct ElephantListElement {
    Elephant value;
    ElephantListElement* pnext;
};

void insertFirst(ElephantListElement** pPhead);         //добавление слона в список с вводом
void insertFirst(ElephantListElement** pPhead, Elephant e); //добавление имеющегося слона в список
void printList(ElephantListElement* phead);
void printListReverse(ElephantListElement* phead);
void clearList(ElephantListElement** pPhead);

void averageWeightElephants(ElephantListElement* phead, int numEl);
void oldestElephant(ElephantListElement* phead, int numEl);
void swapElems(ElephantListElement* x, ElephantListElement* y);
void swapElephants(ElephantListElement* phead, int a, int b);
void deleteElephants(ElephantListElement* phead, int a);

int main()
{
    setlocale(LC_ALL, "rus");
    ElephantListElement* phead = nullptr;
    //insertFirst(&phead);
    //insertFirst(&phead);
    
    for (int i = 0; i < numEl; i++)
    {
        Elephant el = inputElephant(i);
        insertFirst(&phead, el);
    }

    printList(phead);
    printListReverse(phead);
    averageWeightElephants(phead, numEl);
    oldestElephant(phead, numEl);
    //cout << "Каких слонов необходимо поменять местами? " << endl;
    //int a, b;
    //cin >> a >> b;
    //swapElephants(phead, a, b);
    cout << "Какого слонов необходимо удалить? " << endl;
    int a;
    cin >> a;
    deleteElephants(phead, a);
    printList(phead);
    clearList(&phead);
}


Elephant inputElephant(int number)
{
    Elephant resultElephant;
    cout << "Enter name of " << number << " Elephant: ";
    cin >> resultElephant.name;
    cout << "Enter age of " << number << " Elephant: ";
    cin >> resultElephant.age;
    cout << "Enter weight of " << number << " Elephant: ";
    cin >> resultElephant.weight;
    return resultElephant;
}


string elephantToString(Elephant el)
{
    return "<Elephant> " + el.name + " " + to_string(el.age) + " " + to_string(el.weight) + "</Elephant>";
}

//функция, добавляющая элемент в голову списка
void insertFirst(ElephantListElement** pPhead)
{
    //ElephantListElement* phead = *pPhead;
    //if (*pPhead == nullptr)
    //{  // список был пустым, нужно просто добавить элемент и его адрес записать в голову
    //    *pPhead = new ElephantListElement;
    //    (*pPhead)->value = inputElephant(1);
    //    (*pPhead)->pnext = nullptr;
    //}
    //else {
        //список был непустым. Адрес головного элемента нужно не потерять
    ElephantListElement* p = new ElephantListElement;
    p->value = inputElephant(1);
    p->pnext = *pPhead;
    *pPhead = p;
    //}
}

void insertFirst(ElephantListElement** pPhead, Elephant e)
{
    ElephantListElement* p = new ElephantListElement;
    p->value = e;
    p->pnext = *pPhead;
    *pPhead = p;
}

void printList(ElephantListElement* phead)
{
    float averageWeight = 0;
    cout << "List begin" << endl;
    for (ElephantListElement* p = phead; p != nullptr; p = p->pnext) {
        cout << elephantToString(p->value) << endl;
        averageWeight += phead->value.weight;
    }
    cout << "List end" << endl; 
}

void printListReverse(ElephantListElement* phead)
{
    if (phead != nullptr)
    {
        printListReverse(phead->pnext);
        cout << elephantToString(phead->value) << endl;
    }
}

void clearList(ElephantListElement** pPhead)
{
    if (*pPhead != nullptr)
    {
        clearList(&((*pPhead)->pnext));
        delete* pPhead;
        *pPhead = nullptr;
    }
}

void averageWeightElephants(ElephantListElement* phead, int numEl)
{
    float averageWeight = 0;
    for (ElephantListElement* p = phead; p != nullptr; p = p->pnext)
        averageWeight += p->value.weight;
    averageWeight /= numEl;
    cout << "Средний вес слонов: " << averageWeight << endl;
}

void oldestElephant(ElephantListElement* phead, int numEl)
{
    int count = 0;
    int maxAge = phead->value.age;
    ElephantListElement* oldestElephant = phead;
    for (ElephantListElement* p = phead; p != nullptr; p = p->pnext) {
        if (count < numEl - 1) {
            if (p->pnext->value.age > maxAge) {
                maxAge = p->pnext->value.age;
                oldestElephant = p->pnext;
            }
            count++;
        }
    }
    cout << "Указатель на самого старого слона: " << oldestElephant << endl;
}

void swapElems(ElephantListElement* x, ElephantListElement* y)
{
    ElephantListElement t = *x;
    *x = *y;
    *y = t;
}

void swapElephants(ElephantListElement* phead, int a, int b)
{
    int countForA = 1, countForB = 1;
    ElephantListElement* elA = phead; 
    ElephantListElement* elB = phead;
    for (ElephantListElement* p = phead; p != nullptr; p = p->pnext) {
        if (countForA == a) {
            elA = p;
        }
        if (countForB == b) {
            elB = p;
        }
        countForA++;
        countForB++;
    }
    //swapElems(elA, elB);
}

void deleteElephants(ElephantListElement* phead, int a)
{
    int count = 1;
    ElephantListElement* elA = phead;
    for (ElephantListElement* p = phead; p != nullptr; p = p->pnext) {
        if (count == a) {

        }
        count++;
    }
    
}