#include "SinglyOrderedList.h"

#include <iostream>

// Конструктор перемещения 
SinglyOrderedList::SinglyOrderedList(SinglyOrderedList&& other) noexcept :
	head_(other.head_)
{
	other.head_ = nullptr;
}

void SinglyOrderedList::swap(SinglyOrderedList &other) noexcept
{
	std::swap(head_, other.head_);
}

// Оператор перемещающего присваивания 
SinglyOrderedList &SinglyOrderedList::operator=(SinglyOrderedList &&right) noexcept
{
	if (this != &right) {
		swap(right);
	}
	return *this;
}

bool SinglyOrderedList::endInsert(Node x)
{
	if (head_ != nullptr)
	{
		
	}
	else
	{
		head_ = std::move(x);
	}
	return true;
}


bool SinglyOrderedList::insertNode(Node *x)
{
	if (head_ != nullptr) // Список не пуст
	{
		Node *current = std::move(head_);

		if (x->item_ < current->item_) // Если да, вставляем в начало списка
		{
			current->next_ = std::move(current);
			current->item_ = std::move(x->item_);
			head_ = std::move(current);
			return true;
		}

		while (current != nullptr) // Пока не конец списка
		{
			if (x->item_ == current->item_) // Если вставляемый элемент уже есть в списке, то ничего вставлять не надо
			{
				std::cout << "Such item is already in list\n";
				return false;
			}
			if (x->item_ > current->item_) // Список должен быть упорядоченным
			{
				if (current->next_ == nullptr) // Если вставляем элемент в конец списка, то всё напрямую
				{
					current->next_ = std::move(x);
					head_ = std::move(current);
					return true;
				}
				if (x->item_ < (current->next_)->item_) // Если элемент вставляем не в конец списка, то нужно сохранить значение другого элемента
				{
					x->next_ = std::move(current->next_);
					current->next_ = std::move(x);
					head_ = current;
					return true;
				}
			}
			SinglyOrderedList tempList;
			tempList.endInsert(std::move(current->item_));
			current = std::move(current->next_);
		}

	}
	else
	{
		head_ = std::move(x);
	}
	return true;
}

void SinglyOrderedList::deleteNode(Node *x)
{
	if (x == nullptr) {
		throw ("SinglyOrderedList::deleteNode  - неверно задан адрес удаляемого узла");
	}

	if (x == head_)
	{
		head_ = head_->next_;
	}
	else
	{
		Node* current = head_;

		while (current->next_ != x)
		{
			current = current->next_;
		}

		if (x->next_ != nullptr)
		{
			current->next_ = x->next_;
		}
		else
		{
			current->next_ = nullptr;
		}
	}
	delete x;
}

// Поиск узла (адрес) с заданным значением  
SinglyOrderedList::Node *SinglyOrderedList::searchNode(int item)
{
	Node *current = head_;
	while (current != nullptr && current->item_ != item) {
		current = current->next_;
	}
	return current;
}

// Замена информации узла на новое 
SinglyOrderedList::Node *SinglyOrderedList::replaceNode(SinglyOrderedList::Node *x, int item)
{
	x->item_ = item;
	return x;
}

// Доступ к информации головного узла списка
int SinglyOrderedList::headItem() const
{
	if (head_ != nullptr) {
		return head_->item_;
	}
	throw ("headItem - список пуст!");
}

int& SinglyOrderedList::headItem()
{
	if (head_ != nullptr) {
		return head_->item_;
	}
	throw ("headItem - список пуст!");
}

// Добавление элемента в голову списка
void SinglyOrderedList::insertItem(int item)
{
	insertNode(new Node(item));
}

// Удаление узла с заданным значением  
bool SinglyOrderedList::deleteItem(const int item)
{
	Node *search = searchNode(item);
	if (search != nullptr)
	{
		deleteNode(search);
		return true;
	}
	return false;
}

// Поиск записи с заданным значением  
bool SinglyOrderedList::searchItem(int item)
{
	return (searchNode(item) != nullptr);
}

// Замена информации узла на новое 
bool SinglyOrderedList::replaceItem(int itemOld, int itemNew)
{
	Node *search = searchNode(itemOld);
	if (search != nullptr)
	{
		replaceNode(search, itemNew);
		return true;
	}
	return false;
}

void SinglyOrderedList::addList(SinglyOrderedList &&other) noexcept
{
	while (other.head_ != nullptr)
	{
		Node* current = std::move(other.head_);
		while (current != nullptr && current->item_ != item) 
		{
			if (current->item_ == )
			current = current->next_;
		}
		return current;
		bool search = searchItem(other.head_->item_);
		if (search == false)
		{
			insertItem(other.head_->item_);
		}
		//other.deleteNode(other.head_);

		if (head_ != nullptr) // Список не пуст
		{
			Node* current = head_;

			if (x->item_ < current->item_) // Если да, вставляем в начало списка
			{
				Node* temp = head_;
				head_ = x;
				head_->next_ = temp;
				return true;
			}

			while (current != nullptr) // Пока не конец списка
			{
				if (x->item_ == current->item_) // Если вставляемый элемент уже есть в списке, то ничего вставлять не надо
				{
					std::cout << "Such item is already in list\n";
					return false;
				}
				if (x->item_ > current->item_) // Список должен быть упорядоченным
				{
					if (current->next_ == nullptr) // Если вставляем элемент в конец списка, то всё напрямую
					{
						current->next_ = x;
						return true;
					}
					if (x->item_ < (current->next_)->item_) // Если элемент вставляем не в конец списка, то нужно сохранить значение другого элемента
					{
						Node* temp = current->next_;
						x->next_ = temp;
						current->next_ = x;
						return true;
					}
				}
				current = current->next_;
			}
		}
		else
		{
			head_ = x;
		}
		return true;
	}
}

void SinglyOrderedList::removeFromList(SinglyOrderedList &&other) noexcept
{
	Node *current = std::move(other.head_);
	while (current != nullptr)
	{
		Node* search = searchNode(current->item_);
		if (search != nullptr)
		{
			deleteItem(current->item_);
		}
		current = current->next_;
	}
}

// Вывод элементов списка в текстовом виде в стандартный выходной поток 
void SinglyOrderedList::outAll()
{
	Node *current = head_;
	while (current != nullptr) 
	{
		std::cout << current->item_ << ' ';
		current = current->next_;
	}
	std::cout << "\n";
}

// Оператор "=="
bool SinglyOrderedList::operator == (const SinglyOrderedList &other)
{
	Node* current = head_;
	Node* currentOther = other.head_;

	if ((current == nullptr) || (currentOther == nullptr))
	{
		std::cout << "One or both lists are empty\n";
		return false;
	}

	while (current != nullptr) {
		if (current->item_ != currentOther->item_)
		{
			return false;
		}
		current = current->next_;
		currentOther = currentOther->next_;
	}
	return true;
}

// Оператор вывода списка в терминал
std::ostream &operator <<(std::ostream &out, const SinglyOrderedList &list)
{
	SinglyOrderedList::Node *current = list.head_;
	if (current == nullptr)
	{
		out << "List is empty\n";
	}
	else
	{
		while (current)
		{
			out << current->item_ << " ";
			current = current->next_;
		}
		out << "\n";
	}
	return out;
}

SinglyOrderedList crossLists(SinglyOrderedList&& first, SinglyOrderedList&& second)
{
	SinglyOrderedList list;
	SinglyOrderedList::Node *secondHead = second.head_;
	while (secondHead != nullptr)
	{
		bool search = first.searchItem(secondHead->item_);
		if (search == true)
		{
			list.insertItem(secondHead->item_);
		}
		secondHead = secondHead->next_;
	}
	return list;
}

SinglyOrderedList::~SinglyOrderedList()
{
	Node *current = nullptr;
	Node *next = head_;
	while (next != nullptr)
	{
		current = next;
		next = next->next_;
		delete current;
	}
}