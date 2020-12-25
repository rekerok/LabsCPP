#include <iostream>
#include <windows.h>
#include <time.h>
using namespace std;

template <typename T>
class List {
private:
	string example;
	struct Node {
		T element;
		Node* next = NULL;
	};
	Node* Head = NULL;
	void show(Node*);
	int count = 0;
	bool isBracket(char el);
	bool openOrClose(char el);
public:
	List();
	List(string);
	void addElement(char);
	void deleteHead();
	void showAll();
	T GetHead();
	bool isEmpty();
	void checkBrackets();
	int getLengthList();
	void operator + (const List & list);
	~List();
};

template <typename T>
List<T>::List() {

}

template <typename T>
List<T>::List(string example) {
	this->example = example;
}

template <typename T>
void List<T>::addElement(char element) {
	Node* node = new Node;
	node->element = element;
	node->next = Head;
	Head = node;
	count++;
}

template <typename T>
void List<T>::deleteHead()
{
	if (!isEmpty())
	{
		if (Head->next == NULL)
		{
			delete Head;
			Head = NULL;
		}
		else {
			Node* tmp = Head->next;
			delete Head;
			this->Head = tmp;
		}
		count--;
	}
	
}

template <typename T>
void List<T>::show(Node* node) {
	cout << node->element << '\t';
}

template <typename T>
void List<T>::showAll() {
	Node* tmp = Head;
	while (tmp) {
		show(tmp);
		tmp = tmp->next;
	}
	cout << '\n';
}

template <typename T>
T List<T>::GetHead() { return Head->element; }

template <typename T>
bool List<T>::isEmpty() {
	if (Head == NULL)
		return true;
	else
		return false;
}

template <typename T>
bool List<T>::isBracket(char el) {
	char arrBr[6] = { '(', '{', '[', ')', '}', ']' };
	for (int i = 0; i < sizeof(arrBr) / sizeof(char); i++)
	{
		if (el == arrBr[i])
			return true;
	}
	return false;
}

template <typename T>
bool List<T>::openOrClose(char el) {
	char open[3] = { '(', '{', '[' };
	char close[3] = { ')', '}', ']'};
	for (int i = 0; i < sizeof(open) / sizeof(char); i++)
	{
		if (el == open[i])
			return true;
	}
	return false;
}

template <typename T>
void List<T>::checkBrackets() {
	int openBr, closeBr;
	openBr = closeBr = 0;
	for (int i = 0; i < example.length(); i++)
	{
		if (example[i] == '(' ||
			example[i] == '[' ||
			example[i] == '{') {
			addElement(example[i]);
		}
		else if (Head != NULL)
		{

			if (Head->element == '(' && example[i] == ')') {
				deleteHead();
			}
			else if (Head->element == '[' && example[i] == ']') {
				deleteHead();
			}
			else if (Head->element == '{' && example[i] == '}') {
				deleteHead();
			}
		}

		if (!isEmpty())
			showAll();

		if (isBracket(example[i]))
		{
			(openOrClose(example[i])) ? openBr++ : closeBr++;
		}
	}
	
	if (!isEmpty() || openBr != closeBr) {
		cout << "Error";
	}
	else {
		cout << "All bracket closed";
	}
	cout << '\n';
}

template <typename T>
int List<T>::getLengthList() {
	return count;
}

template <typename T>
void List<T>::operator +(const List& list) {
	Node* tmp = list.Head;
	for (int i = 0; i < count; i++)
		while (tmp)
		{
			this->addElement(tmp->element);
			tmp = tmp->next;
		}
}

template <typename T>
List<T>::~List() {
	if (!isEmpty())
	{
		Node* tmp = Head;
		while (tmp)
		{
			tmp = Head->next;
			delete Head;
			Head = tmp;
		}
	}
	
}

int main() {
	List <char>a("())");
	cout << "LIST AAAA\n";
	a.checkBrackets();

	return 0;
	system("pause");
}