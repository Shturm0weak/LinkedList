#include <iostream>

namespace data {

    template<class T>
    struct Node {
    public:

        T m_Data;
        Node* m_Next = nullptr;
        Node* m_Previous = nullptr;
    };

    template<class T>
    struct LinkedList {
    private:

        Node<T>* m_FirstNode = nullptr;
        Node<T>* m_LastNode = nullptr;
        size_t m_Size = 0;

    public:

        ~LinkedList()
        {
            Clear();
        }

        inline Node<T>* First() { return m_FirstNode; }
        inline Node<T>* Last() { return m_LastNode; }

        Node<T>* PushFront(T data) {
            Node<T>* node = new Node<T>;
            node->m_Data = data;
            node->m_Next = m_FirstNode;
            if (m_FirstNode != nullptr) m_FirstNode->m_Previous = node;
            if (m_LastNode == nullptr) m_LastNode = node;
            m_FirstNode = node;
            m_Size++;
            return node;
        }

        Node<T>* PushBack(T data) {
            Node<T>* node = new Node<T>;
            node->m_Data = data;
            node->m_Previous = m_LastNode;
            if (m_LastNode != nullptr) m_LastNode->m_Next = node;
            if (m_FirstNode == nullptr) m_FirstNode = node;
            m_LastNode = node;
            m_Size++;
            return node;
        }

        Node<T>* Insert(T data, size_t index) {
            if (index == 0 || index == m_Size) throw std::string("You are trying to insert into first or last position, use PushFront or PushBack instead!");
            if (m_Size == 0 || index > m_Size) throw std::string("Index out of range!");
            Node<T>* node = new Node<T>;
            node->m_Data = data;
            Node<T>* currentNode = m_FirstNode;
            for (size_t i = 0; i < index - 1; i++)
            {
                currentNode = currentNode->m_Next;
            }
            Node<T>* nextNode = currentNode->m_Next;
            currentNode->m_Next = node;
            nextNode->m_Previous = node;
            node->m_Previous = currentNode;
            node->m_Next = nextNode;
            m_Size++;
            return node;
        }

        void Erase(size_t index) {
            if (index == m_Size - 1) PopBack();
            if (index == 0) PopFront();
            if (m_Size == 0 || index > m_Size - 1) throw std::string("Index out of range!");
            Node<T>* currentNode = m_FirstNode;
            for (size_t i = 0; i < index; i++)
            {
                currentNode = currentNode->m_Next;
            }
            Node<T>* nextNode = currentNode->m_Next;
            Node<T>* previousNode = currentNode->m_Previous;
            delete currentNode;
            if(previousNode != nullptr) previousNode->m_Next = nextNode;
            nextNode->m_Previous = previousNode;
            m_Size--;
        }

        void Clear() {
            m_Size = 0;
            Node<T>* currentNode = m_FirstNode;
            Node<T>* temp = nullptr;
            while (currentNode != nullptr)
            {
                temp = currentNode;
                currentNode = currentNode->m_Next;
                delete temp;
            }
            m_FirstNode = nullptr;
            m_LastNode = nullptr;
        }

        void PopBack()
        {
            if (m_LastNode == nullptr) return;
            if (m_Size > 1)
            {
                Node<T>* lastNode = m_LastNode->m_Previous;
                lastNode->m_Next = nullptr;
                delete m_LastNode;
                m_LastNode = lastNode;
            }
            else
            {
                m_FirstNode = nullptr;
                delete m_LastNode;
            }
            m_Size--;
        }

        void PopFront()
        {
            if (m_FirstNode == nullptr) return;
            if (m_Size > 1)
            {
                Node<T>* firstNode = m_FirstNode->m_Next;
                firstNode->m_Previous = nullptr;
                delete m_FirstNode;
                m_FirstNode = firstNode;
            }
            else
            {
                m_LastNode = nullptr;
                delete m_FirstNode;
            }
            m_Size--;
        }

        void Print()
        {
            Node<T>* currentNode = m_FirstNode;
            while (currentNode != nullptr)
            {
                std::cout << "Data: " << currentNode->m_Data << std::endl;
                currentNode = currentNode->m_Next;
            }
        }

        inline size_t Size() { return m_Size; }
    };

}