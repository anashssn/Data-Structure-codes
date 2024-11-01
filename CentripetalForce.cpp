#include <iostream>
using namespace std;

class CentripetalForce
{
private:
	int mass, velocity, radius;
public: 
	CentripetalForce(int m, int v, int r)
	{
		mass = m;
		velocity = v;
		radius = r;
	}
	void formula()
	{
		cout << "Centripetal Force: " << (mass*((velocity*velocity) / radius)) << "N" << endl;
	}
};
int main()
{
	cout << "Enter the mass of the object: " << endl;
	int m;
	cin >> m;
	cout << "Enter the velocity of the object: " << endl;
	int v;
	cin >> v;
	cout << "Enter the radius of the objecy:" << endl;
	int r;
	cin >> r;
	CentripetalForce CF(m,v,r);
	CF.formula();
	return 0;
}