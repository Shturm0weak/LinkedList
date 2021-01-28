#include <iostream>
#include "LinkedList.h"
#include <vector>

using namespace custom;

class TestClass {
public:

    int m_Value = 0;

    TestClass(){}
    TestClass(int value) : m_Value(value) {}

};

int main()
{
    //All list methods;
    //List<TestClass> list(0);
    //list.Erase(0);
    //list.PushBack(value);
    //list.PushFront(value);
    //list.Erase(index);
    //list.Insert(index);
    //list.Resize(new size);
    //list.Clear();
    //list.Back();
    //list.Front();
    //list.Size();
    //list[index];
    //list.PrintList();

    for (uint64_t i = 0; i < list.Size(); i++)
    {
        std::cout << "Id: " << list[i].m_Data.m_Value << std::endl;
        if (list[i].m_Next != nullptr)
            std::cout << "Next: " << list[i].m_Next->m_Data.m_Value << std::endl;
        if(list[i].m_Previous != nullptr)
            std::cout << "Previous: " << list[i].m_Previous->m_Data.m_Value << std::endl;
        std::cout << std::endl;
    }

    
}