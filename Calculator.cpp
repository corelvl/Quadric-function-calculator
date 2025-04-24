#include <iostream>
#include <cstdlib>
#include <chrono>
#include <thread>
#include "functions.h"
#include <windows.h>


using namespace std;

int main()
{
	while (true) {


		cls();
		cmdc(9);
		cout << "=====================================================================\n";
		cout << "IT IS HIGHLY RECOMMENDED THAT YOU RUN THE PROGRAM IN FULLSCREEN MODE!\n";
		cout << "=====================================================================\n";
		cout << "\n\n";
		cout << "See readme.md for chnagelog, usage and roadmap!\n\n";
		cout << "===========================\n";
		cout << "Quadric function calculator\n";
		cout << "Verision: 1.0.1\n";
		cout << "===========================\n";
		cout << "1.See formulas\n";
		cout << "2.See quadric function information\n";
		cout << "3.Quadric function\n";
		cout << "4.Exit\n";

		int ch;
		cout << ">";
		cin >> ch;


		if (cin.fail())
		{
			cin.clear();
			cin.ignore(1000,'\n');

			cls();
			cout << "Input has to be an integer!\n";
			cout << "Getting back to the menu in 3 seconds....";
			this_thread::sleep_for(chrono::seconds(3));
			continue;

		}
		else
		{
			switch (ch)
			{
			case 1:
				formulas();
				break;
			case 2:
				information();
				break;
			case 3:
				function();
				break;
			case 4:
				exit(0);
			}
		}
	}
}

