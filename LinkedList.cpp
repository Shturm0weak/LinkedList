//#include "LinkedList.h"
//
//using namespace custom;
//
//
//template<typename T>
//void custom::List<T>::PushBack(Node<T>& node)
//{
//	Node<T>* newNodes = Create(m_Size + 1);
//	for (uint64_t i = 0; i < m_Size; i++) {
//		newNodes[i].m_Data = m_Nodes[i].m_Data;
//	}
//	newNodes[m_Size].m_Previous = &newNodes[m_Size - 1];
//	newNodes[m_Size - 1].m_Next = &newNodes[m_Size];
//	delete[] m_Nodes;
//	m_Nodes = newNodes;
//	m_Size++;
//	return &newNodes[m_Size - 1];
//}
//
//template<typename T>
//void custom::List<T>::PrintList()
//{
//	for (uint64_t i = 0; i < m_Size; i++)
//	{
//		std::cout << "Id: " << m_Nodes[i].m_Data << std::endl;
//		if (m_Nodes[i].m_Next != nullptr)
//			std::cout << "Next: " << m_Nodes[i].m_Next->m_Data << std::endl;
//		if (m_Nodes[i].m_Previous != nullptr)
//			std::cout << "Previous: " << m_Nodes[i].m_Previous->m_Data << std::endl;
//		std::cout << std::endl;
//	}
//}
//
//template<typename T>
//Node<T>* custom::List<T>::Create(uint64_t size)
//{
//	Node<T>* nodes = new Node<T>[size];
//	for (uint64_t i = 1; i < size - 1; i++)
//	{
//		nodes[i].m_Next = &nodes[i + 1];
//		nodes[i].m_Previous = &nodes[i - 1];
//	}
//	if (size > 1) {
//		nodes[0].m_Next = &nodes[1];
//		nodes[size - 1].m_Previous = &nodes[size - 2];
//	}
//	return nodes;
//}