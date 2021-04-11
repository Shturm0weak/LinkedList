#include <iostream>
#include "LinkedList.h"
#include <vector>

using namespace data;

int main()
{
    //All list methods;
    LinkedList<int> linkedList;
    linkedList.PushBack(3);
    linkedList.PushFront(1);
    linkedList.Insert(2, 1);
    linkedList.Erase(1);
    linkedList.PopFront();
    linkedList.PopBack();
    linkedList.Print();
    std::cout << linkedList.Size() << std::endl;
    linkedList.Clear();
}