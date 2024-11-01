#include <iostream>
using namespace std;

class Power_Dissipation
{
private:
	float current, voltage;
public:
	Power_Dissipation(float c, float v)
	{
		current = c;
		voltage = v;
	}
	void formula()
	{
		cout << "Power Dissipation: " << (current * voltage) << " Watt" << endl;
	}
};
int main()
{
	cout << "Enter the current: " << endl;
	float c;
	cin >> c;

	cout << "Enter the voltage:" << endl;
	float v;
	cin >> v;

	Power_Dissipation pd(c, v);
	pd.formula();
	return 0;
}

