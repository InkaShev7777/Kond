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
	void Low()
	{
		this->temp--;
	}
	int getTemp()
	{
		return this->temp;
	}
};
class Kond
{
	int temp;
	bool on_off;
public:
	Kond()
	{
		this->temp = 20;
		this->on_off = false;
	}
	void Hight(Room &room)
	{
		this->temp++;
		while (this->temp != room.getTemp())
		{
			if(room.getTemp()>this->temp)
			room.Low();
			else
			{
				room.Hight();
			}
		}
	}
	void Low(Room &room)
	{
		this->temp--;
		while (room.getTemp()!=this->temp)
		{
			if (room.getTemp() > this->temp)
				room.Low();
			else
				room.Hight();
		}
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
	bool getOn_Off()
	{
		return this->on_off;
	}
	int getTemp()
	{
		return this->temp;
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
	void Low(Kond& kond,Room &room)
	{
		kond.Low(room);
	}
};

int main()
{
	setlocale(0, "");
	Kond kond;
	Room room;
	Pult pult;
	int vibor;
	do
	{
		cout << "\t\tМеню\n";
		cout << "1 - ВКЛ\n";
		cout << "2 - ВЫКЛ\n";
		cout << "3 - Повысить температуру\n";
		cout << "4 - Понизить температуру\n";
		cout << "5 - Вывод всей информации\n";
		cout << "0 - Выход\n";
		cout << "Ваш выбор: ";
		cin >> vibor;
		switch (vibor)
		{
		case 1:
			system("cls");
			pult.On(kond);
			cout << "Кондиционер Вкл.\n";
			system("pause");
			system("cls");
			break;
		case 2:
			system("cls");
			pult.Off(kond);
			cout << "Кондиционер Выкл.\n";
			system("pause");
			system("cls");
			break;
		case 3:
			system("cls");
			pult.Hight(kond, room);
			cout << "Вы повылили температуру на один градус!\nСкоро температура в комноте станет как на кондиционере\n";
			system("pause");
			system("cls");
			break;
		case 4:
			system("cls");
			cout << "Вы понизили температуру на один градус!\nСкоро температура в комноте станет как на кондиционере\n";
			pult.Low(kond, room);
			system("pause");
			system("cls");
			break;
		case 5:
			system("cls");
			if (kond.getOn_Off() == true)
			{
				cout << "Кондиционер: Вкл.\t" << "Температура кондиционера: " << kond.getTemp() << "\tТемпература в комнате: " << room.getTemp() << "\n";
			}
			else
			{
				cout << "Кондиционер: Выкл.\t" << "Температура кондиционера: " << kond.getTemp() << "\tТемпература в комнате: " << room.getTemp() << "\n";
			}
			system("pause");
			system("cls");
			break;
		}
	} while (vibor != 0);
}
