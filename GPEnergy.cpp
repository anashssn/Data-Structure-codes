#include <iostream>
using namespace std;

class Gravitational_Potential_Energy
{
private:
	float mass, height;
	float gravity = 9.8;
public:
	Gravitational_Potential_Energy(double m, double h)
	{
		mass = m;
		height = h;
	}
	void formula()
	{
		cout << "Gravitational Potential Energy: " << (mass * gravity * height) << " kg.m^2/s^2" << endl;
	}
};
int main()
{
	cout << "Enter the mass in kg: " << endl;
	float m;
	cin >> m;

	cout << "Enter the height in metres:" << endl;
	float h;
	cin >> h;

	Gravitational_Potential_Energy gpe(m, h);
	gpe.formula();
	return 0;
}


