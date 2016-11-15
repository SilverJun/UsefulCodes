#include <iostream>
#include <conio.h>

class Command
{
public:
	virtual void Execute() = 0;
};

class Command_A : public Command {
public:
	virtual void Execute() override{
		std::cout << "Command_A Press!!" << std::endl;
	}
};

class Command_B : public Command {
public:
	virtual void Execute() override {
		std::cout << "Command_B Press!!" << std::endl;
	}
};

class Input
{
	Command* _buttonA;
	Command* _buttonB;
	
public:
	Input()
	{
		_buttonB = new Command_B();
		_buttonA = new Command_A();
	}
	~Input()
	{
		delete _buttonB;
		delete _buttonA;
	}

	void updateInput()
	{
		if (_kbhit())
		{
			int ch = getch();
			switch (ch)
			{
			case 'a': _buttonA->Execute(); break;
			case 'b': _buttonB->Execute(); break;
			}
		}
	}
};
