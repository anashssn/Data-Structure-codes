#include <iostream>
using namespace std;

class Capacitance
{
private:
	float Eo = 8.84E-12;
	float area, distance;
public:
	Capacitance(int a, int d)
	{
		area = a;
		distance = d;
	}
    void formula()
	{
		cout << "Capacitance: " << (Eo * area) / distance << " F" << endl;
	}
};
int main()
{
	cout << "Enter the area in meter square: " << endl;
	float a;
	cin >> a;

	cout << "Enter the distance in meters:" << endl;
	float d;
	cin >> d;

	Capacitance co(a, d);
	co.formula();
	return 0;
}


