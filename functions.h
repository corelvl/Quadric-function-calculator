#pragma once
#include <cmath>
#include <windows.h>

using namespace std;
//Colors in cmd using windows api.
void cmdc(int color) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

//Clear screen.
void cls() {
	system("cls");
}

//Utility function for getting back to the menu.
void get_back() {
	cmdc(9);
	cout << "\n\n\n";
	cout << "Please provide any input to get back to the menu......";
	cin.get();
	cin.ignore();
}

//Information about quadric function.
void information() {
	cls();
	cmdc(11);
	cout << "Discriminant information:\n";
	cout << "- If Discriminant > 0: 2 roots\n";
	cout << "- If Discriminant = 0: 1 root\n";
	cout << "- If Discriminant < 0: 0 roots\n";
	cout << "\n\n";
	cmdc(10);
	cout << "Parabola openings:";
	cout << " - If a > 0: Parabola opens upward\n";
	cout << " - If a < 0: Parabola opens downward\n";

	get_back();
}
//Formulas for quadric function
void formulas() {
	cls();
	cmdc(9);
	cout << "=========================\n";
	cout << "  Quadratic Formulas    \n";
	cout << "=========================\n";
	cout << "\n\n";

	cmdc(11);
	cout << "Delta  =  b^2 - 4 * a * c\n";
	cout << "-------------------------\n";
	cout << "\n\n";
	cmdc(10);
	cout << "x0     =  -b / (2 * a)\n";
	cout << "--------------------------------------\n";
	cout << "x1     =  (-b - sqrt(delta)) / (2 * a)\n";
	cout << "x2     =  (-b + sqrt(delta)) / (2 * a)\n";
	cout << "--------------------------------------\n";
	cout << "\n\n";
	cmdc(14);
	cout << "p      =  -b / (2 * a)\n";
	cout << "q      =  -delta / (4 * a)\n";
	cout << "-------------------------\n";
	cout << "\n\n";
	cmdc(9);
	cout << "=========================\n";
	cout << "     Quadratic Forms     \n";
	cout << "=========================\n";
	cout << "\n\n";
	cmdc(15);
	cout << "Standard Form:\n";
	cout << "y = a * x^2 + b * x + c\n";
	cout << "-------------------------\n";
	cout << "\n\n";
	cmdc(12);
	cout << "Factored Form (delta > 0):\n";
	cout << "y = a * (x - x1)(x - x2)\n";
	cout << "-------------------------\n";
	cout << "\n\n";
	cout << "Factored Form (delta == 0):\n";
	cout << "y = a * (x - x0)^2\n";
	cout << "-------------------------\n";
	cout << "\n\n";
	cmdc(13);
	cout << "Vertex Form:\n";
	cout << "y = a * (x - p)^2 + q\n";
	cout << "=========================\n";


	get_back();
}


//Functions not written by me, these functions change decimals in to fractions.
int gcd(int a, int b) {
	return b == 0 ? a : gcd(b, a % b);
}

void decimalToFraction(double value, int max_denominator = 1000) {
	int sign = (value < 0) ? -1 : 1;
	value = fabs(value);

	int best_numerator = 1;
	int best_denominator = 1;
	double best_error = fabs(value - 1.0);

	for (int denom = 1; denom <= max_denominator; ++denom) {
		int num = round(value * denom);
		double error = fabs(value - (double)num / denom);

		if (error < best_error) {
			best_numerator = num;
			best_denominator = denom;
			best_error = error;
		}

		if (best_error < 1e-6) break;
	}

	int common = gcd(best_numerator, best_denominator);
	best_numerator /= common;
	best_denominator /= common;

	if (sign < 0) best_numerator *= -1;

	cout << best_numerator << "/" << best_denominator;
}
//Functions not written by me, these functions change decimals in to fractions.


//The main logic of the program, it does the calculations after providing a,b and c.
void function_math(int a, int b, int c) {
	bool running = false;
	cls();
	cmdc(9);
	cout << "==================\n";
	cout << "Values:\n";
	cout << "a: " << a << "\n";
	cout << "b: " << b << "\n";
	cout << "c: " << c << "\n";
	cout << "==================\n\n\n";
	
	double delta;
	delta = b * b - 4 * a * c;
	cmdc(11);
	cout << "========================\n";
	cout << "Delta = " << delta << "\n";
	cout << "========================\n\n";

	double x0 = -b / (2 * a);
	double x1 = (-b - sqrt(delta)) / (2 * a);
	double x2 = (-b + sqrt(delta)) / (2 * a);
	if (delta > 0){
		
		if (x1 != (int)x1) {
			cmdc(10);
			cout << "========================\n";
			cout << "x1 = ";
			decimalToFraction(x1);
			cout << "\n";
			cout << "========================\n\n";
		}

		else {
			cmdc(10);
			cout << "========================\n";
			cout << "x1 = " << x1 << endl;
			cout << "========================\n\n";
		}

		if (x2 != (int)x2) {
			cmdc(10);
			cout << "========================\n";
			cout << "x2 = ";
			decimalToFraction(x2);
			cout << "\n";
			cout << "========================\n\n";
		}
		else {
			cmdc(10);
			cout << "========================\n";
			cout << "x2 = " << x2 << endl;
			cout << "========================\n\n";
		}

	}
	else if (delta == 0)
	{
		if (x0 != (int)x0) {
			cmdc(10);
			cout << "========================\n";
			cout << "x0 = ";
			decimalToFraction(x0);
			cout << "\n";
			cout << "========================\n\n";
		}

		else {
			cmdc(10);
			cout << "========================\n";
			cout << "x0 = " << x0 << endl;
			cout << "========================\n\n";
		}	
	}
	else
	{
		bool noroots = true;
		cmdc(10);
		cout << "========================\n";
		cout << "No roots!\n";
		cout << "========================\n\n";
		
	}
	double p = static_cast<double>(- b) / (2 * a);
	double q = static_cast<double>(- delta) / (4 * a);

	if (p != static_cast<int>(p)){
		cmdc(14);
		cout << "========================\n";
		cout << "p = ";
		decimalToFraction(p);
		cout << "\n";
		cout << "========================\n\n";
	}
	else
	{
		cmdc(14);
		cout << "========================\n";
		cout << "p = " << p << endl;
		cout << "========================\n\n";
	}

	if (q != static_cast<int>(q)) {
		cmdc(14);
		cout << "========================\n";
		cout << "q = " ;
		decimalToFraction(q);
		cout << "\n";
		cout << "========================\n\n";
	}
	else
	{
		cmdc(14);
		cout << "========================\n";
		cout << "q = " << q << endl;
		cout << "========================\n\n";
	}


	cmdc(9);
	cout << "=======================\n";
	cout << "Forms of the function:\n";
	cout << "=======================\n\n";

	cmdc(15);
	cout << "Standard form:\n";
	cout << "y = ";
	cout << a << "x^2 ";
	if (b > 0)
	{
		cout << "+ " << b << "x ";
	}
	else if (b == 0)
	{
		cout << "+ " << b << "x ";
	}
		
	else
	{
		cout << b << "x ";
	}
	if (c > 0)
	{
		cout << "+ ";
		cout << c;
	}
	else if (c == 0)
	{
		cout << "+ " << c;
	}
	else
	{
		cout << c;
	}
	cout << "\n\n";
	if (delta > 0)
	{


		cmdc(12);
		cout << "Factored form:\n";
		cout << "y = ";
		cout << a;
		cout << "(x ";

		if (x1 > 0)
		{
			if (x1 != static_cast<int>(x1))
			{
				cout << "- ";
				decimalToFraction(x1);
				cout << ")";
			}
			else
			{
				cout << "- ";
				cout << x1;
				cout << ")";
			}
		}
		else if (x1 == 0)
		{

			cout << "- ";
			cout << x1;
			cout << ")";
		}
		else if (x1 < 0)
		{
			if (x1 != static_cast<int>(x1))
			{
				cout << "+ ";
				decimalToFraction(x1);
				cout << ")";
			}
			else
			{
				cout << "+ ";
				cout << x1;
				cout << ")";
			}
		}
		cout << "(x ";

		if (x2 > 0)
		{
			if (x2 != static_cast<int>(x2))
			{
				cout << "- ";
				decimalToFraction(x2);
				cout << ")";
			}
			else
			{
				cout << "- ";
				cout << x2;
				cout << ")";
			}
		}
		else if (x2 == 0)
		{

			cout << "- ";
			cout << x2;
			cout << ")";
		}
		else if (x2 < 0)
		{
			if (x2 != static_cast<int>(x2))
			{
				cout << "+ ";
				decimalToFraction(x2);
				cout << ")";
			}
			else
			{
				cout << "+ ";
				cout << x2;
				cout << ")";
			}
		}
		
		
	}
	else if (delta == 0)
	{
		cout << "y = ";
		cout << a;
		cout << "(x ";
		if (x0 > 0)
		{
			if (x0 != static_cast<int>(x0))
			{
				cout << "- ";
				decimalToFraction(x0);
				cout << ")";
			}
			else
			{
				cout << "- ";
				cout << x0;
				cout << ")^2";
			}
	
		}
		else if (x0 == 0)
		{
			cout << "- ";
			cout << x0;
			cout << ")^2";
		}
		else
		{
			if (x0 != static_cast<int>(x0))
			{
				cout << "- ";
				decimalToFraction(x0);
				cout << ")";
			}
			else
			{
				cout << "+ ";
				cout << x0;
				cout << ")^2";
			}
		}
	}
	else
	{
		cout << "No factored form!";
		cout << "\n\n";
	}
	
	cmdc(13);
	cout << "\n\n";
	cout << "Vertex form:\n";
	cout << "y = ";
	cout << a;
	cout << "(x ";
	if (p > 0)
	{
		if (p != static_cast<int>(p))
		{
			cout << "- ";
			decimalToFraction(p);
			cout << ")^2 ";
		}
		else
		{
			cout << "- ";
			cout << p;
			cout << ")^2 ";

		}
	}
	else if (p == 0)
	{
			cout << "- ";
			cout << p;
			cout << ")^2 ";

	}
	else
	{
		if (p != static_cast<int>(p))
		{
			cout << "+ ";
			decimalToFraction(p);
			cout << ")^2 ";
		}
		else
		{
			cout << "+ ";
			cout << p;
			cout << ")^2 ";

		}
	}
	if (q > 0)
	{
		if (q != static_cast<int>(q))
		{
			cout << "+ ";
			decimalToFraction(q);
		}
		else
		{
			cout << "+ ";
			cout << q;
		}
	}
	else if (q == 0)
	{
		cout << "+ ";
		cout << q;
	}
	else
	{
		if (q != static_cast<int>(q))
		{
			cout << "- ";
			decimalToFraction(q);	
		}
		else
		{
			cout << "- ";
			cout << q;
		}
	}

	cmdc(4);
	cout << "\n\n";
	cout << "WARNING:\n";
	cout << "If the output includes something like:\n";
	cout << "    y = (x + -5)^2 - -5\n\n";
	cout << "Dont worry this is mathematically correct.\n";
	cout << "The program uses full formulas, so expressions like (+ -5) or (- -5)\n";
	cout << "appear because the signs come directly from calculations.\n\n";
	cout << "The first operator (like '+') is part of the formula.\n";
	cout << "The second sign (like '-5') is the actual number being inserted.\n\n";
	cout << "It's not a bug it's just how the computer writes it out.\n";

	get_back();

}

//This function allows user to change the values of a, b and c.
void fix(int a, int b, int c) {
	bool running = false;

	cls();

	cmdc(9);
	cout << "FIX MODE\n";
	cout << "Values:\n";
	cout << "a: " << a << "\n";
	cout << "b: " << b << "\n";
	cout << "c: " << c << "\n";
	cout << "===========================\n";
	cout << "Curent value of a:" << a << "\n";
	cout << "FIX>";
	cin >> a;
		
	cls();
	cout << "FIX MODE\n";
	cout << "Values:\n";
	cout << "a: " << a << "\n";
	cout << "b: " << b << "\n";
	cout << "c: " << c << "\n";
	cout << "===========================\n";
	cout << "Curent value of b:" << b << "\n";
	cout << "FIX>";
	cin >> b;
		
	cls();
	cout << "FIX MODE\n";
	cout << "Values:\n";
	cout << "a: " << a << "\n";
	cout << "b: " << b << "\n";
	cout << "c: " << c << "\n";
	cout << "===========================\n";
	cout << "Curent value of c:" << c << "\n";
	cout << "FIX>";
	cin >> c;
	function_math(a, b, c);
		
}



//This function allows the user to input a, b and c.
void function() {
	bool running = true;
	while (running)
	{

		cls();

		int a;
		int b;
		int c;

		cout << "Provide a:\n";
		cin >> a;

		cls();

		cout << "a: " << a << "\n";
		cout << "Provide b:\n";
		cin >> b;

		cls();

		cout << "a: " << a << "\n";
		cout << "b: " << b << "\n";

		cout << "Provide c:\n";
		cin >> c;

		cls();

		cout << "Are these values correct?\n";
		cout << "Values:\n";
		cout << "a: " << a << "\n";
		cout << "b: " << b << "\n";
		cout << "c: " << c << "\n";
		cout << "===========================\n";

		cout << "1.Correct\n";
		cout << "2.I want to make a change\n";

		cout << ">";
		int ch;
		cin >> ch;

		if (cin.fail())
		{
			cin.clear();
			cin.ignore(1000, '\n');

			cls();
			cout << "Input has to be an integer!\n";
			cout << "Getting back to the menu in 3 seconds....";
			this_thread::sleep_for(chrono::seconds(3));
			continue;

		}

		bool running = false;
		switch (ch)
		{
		case 1:
			function_math(a,b,c);
			return;
		case 2:
			fix(a,b,c);
			return;
		}
	}

}


