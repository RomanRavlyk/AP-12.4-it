#include <iostream>

using namespace std;

typedef int Info;

struct Elem {
	Elem* link;
	Info info;
};

void insert(Elem*& L, Info value)
{
	Elem* tmp = new Elem; // 1
	tmp->info = value; // 2
	if (L != NULL)
	{
		Elem* T = L;
		while (T->link != L)
			T = T->link; // 3
		T->link = tmp; // 4
	}
	else
	{
		L = tmp; // 5
	}
	tmp->link = L; // 6
}

void print(Elem* start) {
	if (start == nullptr) {
		cout << "list is empty";
		return;
	}

	Elem* current = start;

	do {
		cout << current->info << " ";
		current = current->link;
	} while (current != start);

	cout << endl;
}

Info* Count(Elem* L, int& count) {
	if (L == nullptr) {
		count = 0;
		return nullptr;
	}

	Elem* current = L;
	int size = 10;
	Info* repeatedElements = new Info[size];
	int repeatedCount = 0;

	bool* checkedIndices = new bool[size];
	for (int i = 0; i < size; ++i) {
		checkedIndices[i] = false;
	}

	do {
		Elem* checker = current->link;
		while (checker != current) {
			if (checker->info == current->info && !checkedIndices[checker->info]) {

				repeatedElements[repeatedCount++] = current->info;

				checkedIndices[checker->info] = true;
				break;
			}
			checker = checker->link;
		}
		current = current->link;
	} while (current != L);

	delete[] checkedIndices;

	count = repeatedCount;
	return repeatedElements;
}

int main() {
	Elem* list = nullptr;

	for (int i = 0; i < 10; i++) {
		int x;
		cout << "Which num you want to insert?: ";  cin >> x;
		insert(list, x);
	}
	cout << endl;
	cout << "Your list: ";  print(list);;
	int count;
	Info* repeatedElements = Count(list, count);
	cout << "Number of tuple elements: " << count << endl;
	cout << "Tuple Elements: ";
	for (int i = 0; i < count; i++) {
		cout << repeatedElements[i] << " ";
	}

	return 0;
}