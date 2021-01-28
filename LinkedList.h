#include <iostream>

namespace custom {

    template<class T>
    struct Node {
    public:

        T m_Data;
        Node* m_Next = nullptr;
        Node* m_Previous = nullptr;

        ~Node() {};// std::cout << "node destroyed\n";}
        Node() {};// std::cout << "node created\n"; }

    };

    template<class T>
    struct List {
    private:

        Node<T>* m_Nodes = nullptr;
        Node<T>* m_TempBuffer = nullptr;
        uint64_t m_Size = 0;

        static Node<T>* Create(uint64_t size) {
            if (size == 0)
                return nullptr;
            Node<T>* nodes = new Node<T>[size];
            for (uint64_t i = 1; i < size - 1; i++)
            {
                nodes[i].m_Next = &nodes[i + 1];
                nodes[i].m_Previous = &nodes[i - 1];
            }
            if (size > 1) {
                nodes[0].m_Next = &nodes[1];
                nodes[size - 1].m_Previous = &nodes[size - 2];
            }
            return nodes;
        }

    public:

        List(uint64_t size = 0) {
            m_Size = size;
            if (m_Size == 0)
                return;
            m_Nodes = Create(m_Size);
        }

        Node<T>* PushFront(T node) {
            m_TempBuffer = m_Nodes;
            m_Nodes = Create(m_Size + 1);
            for (uint64_t i = 1; i < m_Size + 1; i++) {
                m_Nodes[i].m_Data = std::move(m_TempBuffer[i - 1].m_Data);
            }
            m_Nodes[0].m_Data = std::move(node);
            delete[] m_TempBuffer;
            m_Size++;
            return &m_Nodes[m_Size - 1];
        }

        Node<T>* PushBack(T node) {
            m_TempBuffer = m_Nodes;
            m_Nodes = Create(m_Size + 1);
            for (uint64_t i = 0; i < m_Size; i++) {
                m_Nodes[i].m_Data = std::move(m_TempBuffer[i].m_Data);
            }
            if (m_Size > 1) {
                m_Nodes[m_Size].m_Previous = &m_Nodes[m_Size - 1];
                m_Nodes[m_Size - 1].m_Next = &m_Nodes[m_Size];
            }
            m_Nodes[m_Size].m_Data = std::move(node);
            delete[] m_TempBuffer;
            m_Size++;
            return &m_Nodes[m_Size - 1];
        }

        Node<T>* Insert(T node, uint64_t index) {
            if (index > m_Size - 1)
                return nullptr;
            m_TempBuffer = m_Nodes;
            m_Nodes = Create(m_Size + 1);
            for (uint64_t i = 0; i < index; i++) {
                m_Nodes[i].m_Data = std::move(m_TempBuffer[i].m_Data);
            }
            for (uint64_t i = index + 1; i < m_Size; i++) {
                m_Nodes[i - 1].m_Data = std::move(m_TempBuffer[i].m_Data);
            }
            if (m_Size > 1) {
                m_Nodes[m_Size].m_Previous = &m_Nodes[m_Size - 1];
                m_Nodes[m_Size - 1].m_Next = &m_Nodes[m_Size];
            }
            m_Nodes[index].m_Data = std::move(node);
            delete[] m_TempBuffer;
            m_Size++;
            return &m_Nodes[index];
        }

        bool Erase(uint64_t index) {
            if (index > m_Size - 1)
                return false;
            m_TempBuffer = m_Nodes;
            m_Nodes = Create(m_Size - 1);
            m_Nodes = new Node<T>[m_Size - 1];
            for (uint64_t i = 0; i < index; i++) {
                m_Nodes[i].m_Data = std::move(m_TempBuffer[i].m_Data);
            }
            for (uint64_t i = index + 1; i < m_Size; i++) {
                m_Nodes[i - 1].m_Data = std::move(m_TempBuffer[i].m_Data);
            }
            if (m_Size > 1) {
                m_Nodes[m_Size - 2].m_Previous = &m_Nodes[m_Size - 3];
                m_Nodes[m_Size - 3].m_Next = &m_Nodes[m_Size - 2];
            }
            delete[] m_TempBuffer;
            m_Size--;
            return true;
        }

        void Resize(uint64_t size) {
            m_TempBuffer = m_Nodes;
            m_Nodes = Create(size);
            uint64_t minSize = std::min(size, m_Size);
            for (uint64_t i = 0; i < minSize; i++)
            {
                m_Nodes[i].m_Data = m_TempBuffer[i].m_Data;
            }
            m_Size = size;
            delete[] m_TempBuffer;
        }

        void Clear() {
            m_Size = 0;
            delete[] m_Nodes;
        }

        inline Node<T>& Front() {
            return m_Nodes[0];
        }

        inline Node<T>& Back() {
            return m_Nodes[m_Size - 1];
        }

        void PrintList() {
            for (uint64_t i = 0; i < m_Size; i++)
            {
                std::cout << "Id: " << &m_Nodes[i].m_Data << std::endl;
                std::cout << "Next: " << m_Nodes[i].m_Next << std::endl;
                std::cout << "Previous: " << m_Nodes[i].m_Previous << std::endl;
                std::cout << std::endl;
            }
        }

        inline Node<T>& operator[](uint64_t index) { return m_Nodes[index]; }
        inline uint64_t Size() { return m_Size; }
    };

}