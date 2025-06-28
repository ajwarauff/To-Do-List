#include<iostream>
#include<string>
#include<Windows.h>
using namespace std;

class todolist {
private:
	string tasks[100];
	int taskcount;
	string status[100];
public:
	todolist() :taskcount(0) {}
	void addtask(string task, string s) {
		cout << "-----------------ADD TASK------------------\n";
		if (taskcount < 100) {
			tasks[taskcount] = task;
			status[taskcount] = s;
			taskcount++;
		}
		else {
			cout << "Task list is full.\n";
		}
		cout << "Task added successfully.\n";
	}
	void removetask(int index) {
		cout << "-----------------REMOVE TASK------------------\n";
		if (index >= 0 && index < taskcount) {
			for (int i = index; i < taskcount - 1; i++) {
				tasks[i] = tasks[i + 1];
			}
			for (int i = index; i < taskcount - 1; i++) {
				status[i] = status[i + 1];
			}
			taskcount--;
		}
		else {
			cout << "Invalid task index." << endl;
		}
		cout << "Task removed successfully.\n";
	}
	void displaytasks() {
		cout << "-----------------TASK LIST------------------\n";
		if (taskcount == 0) {
			cout << "No tasks available." << endl;
		}
		else {
			for (int i = 0; i < taskcount; i++) {
				cout << i + 1 << ". " << tasks[i] << endl;
				cout << "Status: " << status[i] << endl;
			}
		}
		cout << "---------------------------------------------\n";
	}
	void updatetask(int index, string newstatus) {
		cout << "-----------------UPDATE TASK STATUS------------------\n";
		if (taskcount == 0) {
			cout << "No tasks available to update." << endl;
			return;
		}
		if (index >= 0 && index < taskcount) {
			status[index] = newstatus;
		}
		else {
			cout << "Invalid task index." << endl;
		}
		cout << "Task status updated successfully.\n";
	}

};

int main() {
	todolist mylist;
	int choice;
	string task, status;
	int index;
	do {
		cout << "-----------------TO-DO LIST MENU------------------\n";
		cout << "1. Add Task\n2. Remove Task\n3. Display Tasks\n4. Update Task Status\n5. Exit\n";
		cout << "Enter your choice: ";
		cin >> choice;
		cin.ignore();
		switch (choice) {
		case 1:
			system("cls");
			cout << "Enter task: ";
			getline(cin, task);
			cout << "Enter status: ";
			getline(cin, status);
			mylist.addtask(task, status);
			break;
		case 2:
			system("cls");
			mylist.displaytasks();
			cout << "Enter task index to remove: ";
			cin >> index;
			cin.ignore();
			mylist.removetask(index - 1);
			break;
		case 3:
			system("cls");
			mylist.displaytasks();
			break;
		case 4:
			system("cls");
			mylist.displaytasks();
			cout << "Enter task index to update: ";
			cin >> index;
			cin.ignore();
			cout << "Enter new status: ";
			getline(cin, status);
			mylist.updatetask(index - 1, status);
			break;
		case 5:
			system("cls");
			cout << "Exiting program." << endl;
			break;
		default:
			system("cls");
			cout << "Invalid choice. Please try again." << endl;
		}
	} while (choice != 5);
	return 0;
}