#pragma once
#include <string>
using namespace std;


struct Task
{
	string title;
	string description;
	bool is_completed;

	void add_value(string ttl, string dscrip, bool is_compl){
		title = ttl;
		description = dscrip;
		is_completed = is_compl;
	}

	void show_info() {
		cout << "Title: " << title << endl;
		cout << "Description: " << description << endl;
		if(is_completed)
			cout << "The task is completed" << endl;
		else
			cout << "The task is not completed" << endl;
	}
};

Task* add_task(Task* arr, int& size, string ttl, string dscrip, bool is_compl)
{
	Task* new_task = new Task[size + 1];
	for (int i = 0; i < size; i++) {
		new_task[i] = arr[i];
	}
	delete[] arr;

	new_task[size].add_value(ttl, dscrip, is_compl);
	size++;

	return new_task;
}

Task* del_task(Task* arr, int& size)
{
	Task* new_task = new Task[size - 1];
	for (int i = 0; i < (size - 1); i++)
		new_task[i] = arr[i];
	delete[] arr;
	size--;
	return new_task;
}

