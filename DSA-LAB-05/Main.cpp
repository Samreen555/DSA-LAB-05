/*implementation of the priority queue using student faculty admisnistrations(insert student teacher administration)
menu based
validation
proper program
*/
#include<iostream> //
#include<string> //using for the string functions
using namespace std;
typedef struct
{
	string name;
	string role;  // "Student" or "Faculty" or "Administ"
} Itemtype;
class Queue {
private:
	int front, rear, maxQueue, count;
	Itemtype* items;
public:
	Queue(int size) {
		front = rear = -1;
		maxQueue = size;
		count = 0;
		items = new Itemtype[maxQueue];
	}
	~Queue()
	{
		delete[] items;
	}
	bool isEmpty()
	{
		return (count == 0);
	}
	bool isFull()
	{
		return (count == maxQueue);
	}
	int getPriority(string role) {
		if (role == "Administ")
			return 1;
		else if (role == "Faculty")
			return 2;
		else
			return 3; // Student has the lowest priority
	}
	void enqueue(Itemtype item) {
		if (isFull()) {
			cout << "Queue is full, can't insert more elements.\n";
			return;
		}
		int priority = getPriority(item.role);
		int i;
		for (i = count - 1; (i >= 0 && getPriority(items[(front + i) % maxQueue].role) > priority); i--) {
			items[(i + 1) % maxQueue] = items[(front + i) % maxQueue];
		}

		items[(i + 1) % maxQueue] = item; // Insert the new item
		count++;

		if (front == -1) { // Set front to 0 when the first element is added
			front = 0;
		}
		rear = (rear + 1) % maxQueue; // Update rear
		cout << "Inserted: " << item.name << " (" << item.role << ")\n";
	}
		Itemtype dequeue()
	{
		if (isEmpty()) {
			cout << "Queue is empty, can't remove elements.\n";
			return { "", "" };  // Return an empty item
		}
		int HighestPriorityIndex = front;
		for (int i = 1; i < count; i++) {
			int current_index = (front + i) % maxQueue;
			if (getPriority(items[current_index].role) < getPriority(items[HighestPriorityIndex].role)) {
				HighestPriorityIndex = current_index;
			}
		}
		
			Itemtype item = items[HighestPriorityIndex];
			cout << "Removed:"<<item.name<<"("<<item.role<<")"<<endl;
			for (int i = HighestPriorityIndex; i != rear; i = (i + 1) % maxQueue) {
				items[i] = items[(i + 1) % maxQueue];
			}
			rear = (rear - 1 + maxQueue) % maxQueue;
			count--;
			if (isEmpty()) { // Reset the queue if it becomes empty
				front = rear = -1;
			}
			return item;
		
	}

	void display() {
		if (isEmpty()) {
			cout << "Queue is empty.\n";
		}
		else {
			cout << "Current Queue:\n";
			for (int i = 0; i < count; i++) {
				int index = (front + i) % maxQueue;
				cout << items[index].name << " (" << items[index].role << ")\n";
			}
		}
	}
};
int main()
{
	int maxSize;
	cout << "Enter the maximum size of the queue: ";
	cin >> maxSize;

	Queue q(maxSize);
	Itemtype newStudent, newFaculty, newAdmin;
	int choice;
	do
	{
			cout << "MENU: ";
	cout << "\n1. Insert a new student.";
	cout << "\n2. Insert a new faculty member.";
	cout << "\n3. Insert a new administration member.";
	cout << "\n 4.Delete.";
	cout << "\n5.Display the queue.";
	cout << "\n6. Exit\n";
		cout << "Enter your choice:";
		cin >> choice;
		switch (choice)
		{
		case 1:
			cout << "Enter student name: ";
			cin.ignore();
			getline(cin, newStudent.name);
			newStudent.role = "Student";
			q.enqueue(newStudent);
			break;
		case 2:
			cout << "Enter faculty name: ";
			cin.ignore();
			getline(cin, newFaculty.name);
			newFaculty.role = "Faculty";
			q.enqueue(newFaculty);
			break;
		case 3:
			cout << "Enter admin name: ";
			cin.ignore();
			getline(cin, newAdmin.name);
			newAdmin.role = "Administ";
			q.enqueue(newAdmin);
			break;
			case 4:
		q.dequeue();
		break;
	case 5:
		q.display();
		break;
	case 6:
		cout << "Exiting...\n";
		break;
	default:
		cout << "Invalid choice.\n";
		break;
	}
} while (choice != 6);

	return 0;
}
