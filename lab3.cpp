#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Lab4 
{
public:

	void generation_mass() {
		for (int i = 0; i <= 18; i++)
		{
			mass_x[i] = i - 6;
			mass_y[i] = autofunc(i - 6);
		}
	}

	void zapis() {

		ofstream out;
		out.open("textfile.txt");

		for (int i = 0; i <= 18; i++)
		{
			string filestring{ "X:= " + to_string(mass_x[i]) + "\tY: = " + to_string(mass_y[i])};

			out << filestring << endl;
		}

		out.close();
	}

	void chtenie() {
		ifstream in("textfile.txt");
		string line;
		while (getline(in, line)) cout << line << endl;
	}

private:

	int mass_x[19] = {};
	int mass_y[19] = {};

	float autofunc(float x) {
		float y = 0;
		if (x < -4) y = -2;
		else if (x < 0) y = x / 4;
		else if (x < 2) y = x * x;
		else y = (x - 10) / -2;
		return y;
	}
};




int main() {

	Lab4 test;

	test.generation_mass();
	test.zapis();
	test.chtenie();
	
	return 0;
}