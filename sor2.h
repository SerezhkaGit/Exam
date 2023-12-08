#pragma once
#include "sor1.h"

struct LIST
{
	int kil = 0;
	int m = 0;
	
	TASK* list = new TASK[kil];


	void add_task(TASK* &list, int& kil, int& m)
	{
		int i = 0;
		int size = kil + 1;
		TASK* tmp = new TASK[size];
		
		if (i < m)
		{
			for (i; i < m; i++)
			{
				tmp[i] = list[i];
			}
			
		}

		
		
			for (i = m; i < size; i++)
			{
				tmp[i].tasknumber = i + 1;

				cout << "\nEnter task name: ";
				cin >> tmp[i].t_name;

				cout << "\nEnter prioritet: ";
				cin >> tmp[i].prioriter;

				cout << "\nEnter description: ";
				cin >> tmp[i].description;

				cout << "\nEnter data: ";
				cin >> tmp[i].data;

				cout << "\nEnter chas_vukonan: ";
				cin >> tmp[i].chas_vukonan_dni;
			}
		
		m++;
		kil = size;
		delete[]list;
		list = tmp;
	}

	void show_list(TASK*& list, int& kil)
	{
		for (int i = 0; i < kil; i++)
		{
			cout << "\n----Task: "<<list[i].tasknumber <<"----";
			
			cout << "\ntask name: ";
			cout << list[i].t_name;

			cout << "\nprioritet: ";
			cout <<list[i].prioriter;

			cout << "\ndescription: ";
			cout <<list[i].description;

			cout << "\ndata: ";
			cout << list[i].data;

			cout << "\nchas_vukonan: ";
			cout <<list[i].chas_vukonan_dni;
			cout << endl;
		}
	}

	void delete_task(TASK*& list, int& kil)
	{
		


		int size = kil - 1;
		TASK *tmp = new TASK[size];
		for (int i = 0; i < size; i++)
		{
			tmp[i] = list[i];
		}

		kil = size;
		delete[]list;
		list = tmp;
	}


	void edit_task(TASK*& list, int& kil)
	{
		int k;
		

		for (int i = 0; i < kil; i++)
		{
			cout << "\nEnter task number you want to edit: ";
			cin >> k;
			while (k == 0 || k > kil+1)
			{
				cin >> k;
			}
			k--;
				cout << "\nEnter task name: ";
				cin >> list[k].t_name;

				cout << "\nEnter prioritet: ";
				cin >> list[k].prioriter;

				cout << "\nEnter description: ";
				cin >> list[k].description;

				cout << "\nEnter data: ";
				cin >> list[k].data;

				cout << "\nEnter chas_vukonan: ";
				cin >> list[k].chas_vukonan_dni;

				break;
			
			
		}
		
	}
	
	void search_by_criteria(TASK*& list, int& kil)
	{
		int choice;
		cout << "\nSearch by criteria options:";
		cout << "\n1. Search by name";
		cout << "\n2. Search by priority";
		cout << "\n3. Search by description";
		cout << "\nEnter your choice: ";
		cin >> choice;

		char keyword[100];
		cout << "Enter keyword to search: ";
		cin >> keyword;

		bool found = false;

		for (int i = 0; i < kil; i++)
		{
			switch (choice)
			{
			case 1:
				if (strstr(list[i].t_name, keyword) != nullptr)
				{
					cout << "\n----Task: " << list[i].tasknumber << "----";
					cout << "\ntask name: " << list[i].t_name;
					cout << "\nprioritet: " << list[i].prioriter;
					cout << "\ndescription: " << list[i].description;
					cout << "\ndata: " << list[i].data;
					cout << "\nchas_vukonan: " << list[i].chas_vukonan_dni;
					cout << endl;
					found = true;
				}
				break;
			case 2:
				if (list[i].prioriter == atoi(keyword))
				{
					cout << "\n----Task: " << list[i].tasknumber << "----";
					cout << "\ntask name: " << list[i].t_name;
					cout << "\nprioritet: " << list[i].prioriter;
					cout << "\ndescription: " << list[i].description;
					cout << "\ndata: " << list[i].data;
					cout << "\nchas_vukonan: " << list[i].chas_vukonan_dni;
					cout << endl;
					found = true;
				}
				break;
			case 3:
				if (strstr(list[i].description, keyword) != nullptr)
				{
					cout << "\n----Task: " << list[i].tasknumber << "----";
					cout << "\ntask name: " << list[i].t_name;
					cout << "\nprioritet: " << list[i].prioriter;
					cout << "\ndescription: " << list[i].description;
					cout << "\ndata: " << list[i].data;
					cout << "\nchas_vukonan: " << list[i].chas_vukonan_dni;
					cout << endl;
					found = true;
				}
				break;
			default:
				cout << "Invalid choice!" << endl;
				return;
			}
		}

		if (!found)
		{
			cout << "No tasks found with the given keyword." << endl;
		}
	}

	void display_tasks(TASK*& list, int& kil)
	{
		int period;
		cout << "Enter the period (1 for day, 7 for week, 31 for month): ";
		cin >> period;

		int startDay = 1;
		int endDay = (period == 1) ? 1 : ((period == 7) ? 7 : 31);

		bool tasksFound = false;

		
		for (int i = 1; i < kil; i++)
		{
			TASK key = list[i];
			int j = i - 1;

			while (j >= 0 && list[j].prioriter > key.prioriter)
			{
				list[j + 1] = list[j];
				j = j - 1;
			}

			list[j + 1] = key;
		}

		for (int i = 0; i < kil; i++)
		{
			
			if (list[i].chas_vukonan_dni >= startDay && list[i].chas_vukonan_dni <= endDay)
			{
				if (!tasksFound)
				{
					cout << "Tasks for the selected period sorted by priority:\n";
					tasksFound = true;
				}

				
				std::cout << "\n----Task " << list[i].tasknumber << "----";
				std::cout << "\nTask name: " << list[i].t_name;
				std::cout << "\nPriority: " << list[i].prioriter;
				std::cout << "\nDescription: " << list[i].description;
				std::cout << "\nDate: " << list[i].data;
				std::cout << "\nDue time: " << list[i].chas_vukonan_dni << " days\n";
			}
		}

		if (!tasksFound)
		{
			std::cout << "No tasks found for the selected period.\n";
		}
	}


};