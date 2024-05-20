#include <iostream>
#include "Task.h"
using namespace std;



int main()
{
    int size = 0;
    Task* list_task = new Task[size];
    
    bool program_is_active = true;
    while (program_is_active) {
        cout << "Menu:\n" << "1.Add task\n" << "2.Delete task\n" << "3.Show task\n" << "4.Show all task\n" << "5.Quit\n";
        int action;
        cin >> action;
        string title, description;
        bool completed;
        switch (action)
        {
        case 1:
            cout << "Enter title: ";
            cin.ignore();
            getline(cin, title);
            cout << "Enter description: ";
            getline(cin, description);

            int status;
            do {
                cout << "Is this task complete:\n" << "1.Yes\n" << "2.No\n";
                cin >> status;
            } while (status != 1 && status != 2);
            if (status == 1) 
                completed = true;
            else
                completed = false;

            list_task = add_task(list_task, size, title, description, completed);
            break;
        case 2:
            if (size == 0)
                cout << "------------\n" << "There is not task\n" << "------------\n";
            else
                list_task = del_task(list_task, size);
            break;
        case 3:
            if (size == 0)
                cout << "------------\n" << "There is not task\n" << "------------\n";
            else {
                int num;
                do {
                    cout << "Which task do you wand to review: ";

                    cin >> num;
                } while (num < 1 || num > size);
                cout << "------------\n";
                list_task[num - 1].show_info();
                cout << "------------\n";
            }
            break;
        case 4:
            if (size == 0)
                cout << "------------\n" << "There is not task\n" << "------------\n";
            else {
                for (int i = 0; i < size; i++) {
                    cout << "-----------\n" << (i + 1) << ". Task" << endl;
                    list_task[i].show_info();
                    cout << "-----------\n";
                }
            }
            break;
        case 5:
            program_is_active = false;
            break;
        default:
            break;
        }
    }
    






















    /*list_task = add_task(list_task, size, "tee", "mach tee", true);
    list_task = add_task(list_task, size, "Cofeee", "mach tee", true);
    list_task[0].show_info();
    list_task[1].show_info();

    list_task = del_task(list_task, size);
    list_task[0].show_info();
    list_task[1].show_info();*/


    delete[] list_task;

}
