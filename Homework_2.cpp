

#include <iostream>
struct Node {
	int data;
	Node *next;
};
struct Queue {
	Node* first;
	Node* last;
	void create();
	void close();
	void enqueue(int);
	int dequeue();
	bool isEmpty();
};
struct Stack {
	Queue k1, k2;
	void create();
	void close();
	void push(int);
	int pop();
	bool isEmpty();
	int top();
	void print();
	int count;
};
// Queue fonksiyonları
void Queue::create()
{
	first = NULL;
	last = NULL;

}
void Queue::close()
{
	Node *p;
	while (first)
	{
		p = first;
		first = first->next;
		delete p;
	}

}
void Queue::enqueue(int data)
{
	Node* newNode = new Node;
	newNode->data = data;
	newNode->next = NULL;
	if (first == NULL)
	{
		first = newNode;
		last = first;
	}
	else
	{
		last->next = newNode;
		last = newNode;
	}
}
int Queue::dequeue()
{
	Node *topNode;
	int temp;
	topNode = first;
	first = first->next;
	temp = topNode->data;
	delete topNode;
	return temp;
	
}
bool Queue::isEmpty()
{
	return first == NULL;
}
// Stack fonksiyonları
void Stack::create()
{
	count = 0;
	k1.create();
	k2.create();
}
void Stack::close()
{

}
void Stack::push(int x)
{
	count++;
	k2.enqueue(x);
	while (!k1.isEmpty())
	{
		k2.enqueue(k1.first->data);
		k1.dequeue();
	}
	Queue k = k1;
	k1 = k2;
	k2 = k;
}
int Stack::pop()
{
	if (k1.isEmpty())
	{
		return -1;
	}
	count--;
	return k1.dequeue();
}
bool Stack::isEmpty()
{
	return (k1.isEmpty() && k2.isEmpty());
}
int Stack::top()
{
	if (k1.isEmpty())
	{
		return -1;
	}
	return k1.first->data;
}
void Stack::print()
{
	Node* temp;
	temp = k1.first;
	while (temp != NULL)
	{
		std::cout << temp->data << " ";
		temp = temp->next;
	}
	std::cout << std::endl << std::endl << std::endl << std::endl << std::endl;
}
void sortedInsert(Stack **s, int x)
{
	if ((*s)->isEmpty() || x > (*s)->top()) 
	{
		(*s)->push(x);
		return;
	}

	int temp = (*s)->pop();
	sortedInsert(s, x);
	(*s)->push(temp);
}
void sortStack(Stack** s)
{
	if (!(*s)->isEmpty()) 
	{
		int x = (*s)->pop();
		sortStack(s);
		sortedInsert(s, x);
	}

}

int main()
{
	Stack *y = new Stack;
	y->create();
	y->push(3);
	y->push(1);
	y->push(7);
	y->push(4);
	y->push(8);
	std::cout << "Original Stack" << std::endl;
	y->print();
	std::cout << "-- sorting --" << std::endl << std::endl << std::endl << std::endl << std::endl;
	sortStack(&y);
	std::cout << "Sorted Stack" << std::endl;
	y->print();
	return 0;
}
