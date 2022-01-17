#include <iostream>
using namespace std;
class Room
{
	int temp;
public:
	Room()
	{
		this->temp = 25;
	}
	void Hight()
	{
		this->temp++;
	}
	int getTemp()
	{
		return this->temp;
	}
};
class Kond
{
	double temp;
	bool on_off;
public:
	Kond()
	{
		this->temp = 20;
		this->on_off = false;
	}
	void Hight(Room &room)
	{
		while (this->temp != room.getTemp())
		{
			room.Hight();
		}
		this->temp++;
	}
	void Low()
	{
		this->temp--;
	}
	void On()
	{
		this->on_off = true;
	}
	void Off()
	{
		this->on_off = false;
	}
	void Print()
	{
		cout << "Kond: " << this->on_off << "\tTemp: " << this->temp << "\n";
	}
};
class Pult
{
public:
	void On(Kond& kond) {
		kond.On();
	}
	void Off(Kond& kond)
	{
		kond.Off();
	}
	void Hight(Kond& kond,Room &room)
	{
		kond.Hight(room);
	}
	void Low(Kond& kond)
	{
		kond.Low();
	}
};

int main()
{
	Kond kond;
	Room room;
	/*kond.Print();
	kond.Hight();
	kond.Print();
	kond.On();
	kond.Print();*/
	Pult pult;
	pult.On(kond);
	pult.Hight(kond,room);
	kond.Print();
	cout << room.getTemp();

}
