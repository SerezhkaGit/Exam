#pragma once
#include "sor2.h"

void launcher()
{
	bool k = true;
	LIST l;
	int num;

	while (k == true)
	{
		cout << endl;
		cout << "\nTASKS LIST";
		cout << "\nEnter 0 if you want to leave";
		cout << "\nEnter 1 if you want to add task";
		cout << "\nEnter 2 if you want to show task";
		cout << "\nEnter 3 if you want to delete task";
		cout << "\nEnter 4 if you want to edit task";
		cout << "\nEnter 5 if you want to find task";
		cout << "\nEnter 6 if you want to display tasks";
		cout << endl;
		cin >> num;
		while (num < 0 || num > 6)
		{
			cin >> num;
		}
		if (num == 0)
		{
			k = false;
		}
		else if (num == 1)
		{
			l.add_task(l.list, l.kil,l.m);
		}
		else if (num == 2)
		{
			l.show_list(l.list, l.kil);
		}
		else if (num == 3)
		{
			l.delete_task(l.list, l.kil);
		}
		else if (num == 4)
		{
			l.edit_task(l.list, l.kil);
		}
		else if (num == 5)
		{
			l.search_by_criteria(l.list, l.kil);
		}
		else if (num == 6)
		{
			l.display_tasks(l.list, l.kil);
		}

	}
}