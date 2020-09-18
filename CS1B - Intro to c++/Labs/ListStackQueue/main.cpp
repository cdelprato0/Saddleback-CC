
#include "Header.h"
#include "List.h"
#include "Stack.h"
#include "Queue.h"
using namespace std;

int main()
{
	Person Homer;
	Person Marge;
	Person Bart;
	Person Lisa;
	Person Maggie;
	List simpsonFamilyList;
	Stack simpsonFamilyStack;
	Queue simpsonFamilyQueue;

	Homer.SetName("Homer");
	Homer.SetAge(47);

	Marge.SetName("Marge");
	Marge.SetAge(46);

	Bart.SetName("Bart");
	Bart.SetAge(12);

	Lisa.SetName("Lisa");
	Lisa.SetAge(8);

	Maggie.SetName("Maggie");
	Maggie.SetAge(1);

	simpsonFamilyList.InsertHead(Homer);
	simpsonFamilyList.InsertTail(Maggie);
	simpsonFamilyList.InsertHead(Marge);
	simpsonFamilyList.InsertHead(Bart);
	simpsonFamilyList.InsertTail(Lisa);

	cout << "List DEMO\n\n";

	simpsonFamilyList.Display();

	cout << "\nThe size of the Simpson Family is " << simpsonFamilyList.Size()
		 << endl << endl;

	simpsonFamilyList.ClearList();

	simpsonFamilyList.Display();

	cout << "\nThe size of the Simpson Family is " << simpsonFamilyList.Size()
		 << endl << endl;

	cout << "Stack DEMO\n\n";


	simpsonFamilyStack.Push(Homer);
	simpsonFamilyStack.Push(Maggie);
	simpsonFamilyStack.Push(Marge);
	simpsonFamilyStack.Push(Bart);
	simpsonFamilyStack.Push(Lisa);

	simpsonFamilyStack.Display();

	cout << "\nThe size of the Simpson Family is " << simpsonFamilyStack.Size()
		 << endl << endl;

	simpsonFamilyStack.ClearStack();

	simpsonFamilyStack.Display();

	cout << "\nThe size of the Simpson Family is " << simpsonFamilyStack.Size()
		 << endl << endl;

	cout << "Queue DEMO\n\n";

	simpsonFamilyQueue.Enqueue(Homer);
	simpsonFamilyQueue.Enqueue(Maggie);
	simpsonFamilyQueue.Enqueue(Marge);
	simpsonFamilyQueue.Enqueue(Bart);
	simpsonFamilyQueue.Enqueue(Lisa);

	simpsonFamilyQueue.Display();

	cout << "\nThe size of the Simpson Family is " << simpsonFamilyQueue.Size()
		 << endl << endl;

	simpsonFamilyQueue.ClearQueue();

	simpsonFamilyQueue.Display();

	cout << "\nThe size of the Simpson Family is " << simpsonFamilyQueue.Size()
		 << endl << endl;


	return 0;
}
