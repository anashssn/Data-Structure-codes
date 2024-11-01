#include <iostream>
using namespace std;

class Momentum
{
private:
	int mass;
	int velocity;
public:
	Momentum(int m, int v)
	{
		mass = m;
		velocity = v;
	}
	void formula()
	{
		cout << "Linear momentum: " << (mass*velocity) <<  " kg.m/s" << endl;
	}
};

int main()
{
	cout << "Enter the mass: " << endl;
	int m;
	cin >> m;

	cout << "Enter the velocity:" << endl;
	int v;
	cin >> v;

	Momentum m1(m,v);
	m1.formula();

}
