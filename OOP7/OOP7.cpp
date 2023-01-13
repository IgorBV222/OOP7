#include <iostream>
#include<vector>
#include<list>
#include<forward_list>
#include<map>
#include<utility> //std::pair
#include<unordered_map>
#include "Race.h"

//��� ������ � ���� ���� ����������� ������ list
template <typename T>
struct Node {
	T val; // �������� ���� (����� ���������� ������)
	Node<T>* prev; // ���������� �����
	Node<T>* next; // ��������� �����
};

//��� forward_list
template <typename T>
struct Node_of_forward_list {
	T val;
	Node_of_forward_list<T>* next; // ��������� ����� � ��� ����������� ���
};


//��������� ����� �����������
template <typename T>
class �alculator {
public:
	�alculator(){}

	void sum(T& num1, T& num2) {
		return num1 + num2;
	}

	void dif(T& num1, T& num2) {
		return num1 - num2;
	}

	void multiply(T& num1, T& num2) {
		return num1 * num2;
	}
	void div(T& num1, T& num2) {
		if (num2 = 0) {
			std::cout << "�� ���� ������ ������" << '\n';
		}
		return num1 / num2;
	}

};

int main() {
	//list - ���������� ������ (����� ��������� ������ � �����). ������ ������� �� ����� "Node"
	std::list<int> myList; 

	myList.push_back(1);
	myList.push_back(2);
	myList.push_back(3);

	for (const auto& el : myList) {
		std::cout << el << " ";
	}
	std::cout << '\n';

	myList.push_front(0);
	myList.push_front(-1);
	myList.push_front(-2);

	for (const auto& el : myList) {
		std::cout << el << " ";
	}
	std::cout << '\n';
	
	//��� �������� ������
	Node<int>* n = new Node<int>();
	std::vector<int> vec2;
	vec2.push_back(n->val);
	while (n->next != nullptr) {
		vec2.push_back(n->next->val);
		n = n->next;
	}

	//forward_list - ����������� ������
	std::forward_list<int> fwl;
	fwl.push_front(1);
	fwl.push_front(2);
	fwl.push_front(3);
	for (const auto& el : fwl) {
		std::cout << el << " ";
	}
	std::cout << '\n';

	//map - �������������
	std::map<int, std::string> mymap;
	mymap[27] = "abc";
	mymap.insert({ 5, "Bob" });
	mymap.insert(std::make_pair(5, "Bob"));

	//�������� ����
	std::pair<int, std::string> mypair;
	mypair.first = 5;
	mypair.second = "Tanya";
	mymap.insert(mypair);//������� ���� � map

	for (const auto& [key, value] : mymap) {
		std::cout << key << " " << value << '\n';
	}
	//���
	for (const auto& el : mymap) {
		std::cout << el.first << " " << el.second << '\n';
	}

	std::map<int, std::string> mymap2;
	mymap2.insert({ 5, "abc" });
	//mymap2.insert({ 5, "dfg" });
	//�������� ������� � ���� 5
	const auto& [it, isInserted] = mymap2.insert({ 5, "dfg" });
	std::cout << "isInserted: " << isInserted << std::endl; // �� ������� dfg
	
	//unordered_map - ���������������, ��������������� ������� ��� map
	//�������� ����� ������ (��-�� ����) �� ������� ��������
	std::unordered_map<int, std::string> umap;
	umap.insert({ 1,"hello" });
	umap.insert({ 35,"how are you" });
	umap.insert({ 2,"ok" });
	// 3 -> hash (3) = hjrhgtbf - ���������� ��� ����� (���������� � ��� �������)
	umap.find(3);

	for (const auto& [key, value] : umap) {
		std::cout << key << " " << value << '\n';
	}


	Race<Car> myRace;
	Car c1(50, "BMW");
	Car c2(70, "AUDI");
	myRace.race(c1,c2);


}