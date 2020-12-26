#include <iostream>
using namespace std;

class CPU
{
public:
	virtual void calculate() = 0;
};

class GPU
{
public:
	virtual void display() = 0;
};

class Men
{
public:
	virtual void storage() = 0;
};

class Computer
{
public:
	Computer(CPU* cpu, GPU* gpu, Men* men)
	{
		this->cpu = cpu;
		this->gpu = gpu;
		this->men = men;
	}

	~Computer()
	{
		if (cpu != NULL)
		{
			delete cpu;
			cpu == NULL;
		}
		if (gpu != NULL)
		{
			delete gpu;
			gpu == NULL;
		}
		if (men != NULL)
		{
			delete men;
			men == NULL;
		}
	}

	void work()
	{
		cpu->calculate();
		gpu->display();
		men->storage();
	}

private:
	CPU* cpu;
	GPU* gpu;
	Men* men;
};

class IntelCPU :public CPU
{
public:
	void calculate()
	{
		cout << "Intel��CPU��ʼ����" << endl;
	}
};

class IntelGPU :public GPU
{
public:
	void display()
	{
		cout << "Intel���Կ���ʼ��Ⱦ" << endl;
	}
};

class IntelMen :public Men
{
public:
	void storage()
	{
		cout << "Intel���ڴ�����ʼ�洢" << endl;
	}
};

class LenovoCPU :public CPU
{
public:
	void calculate()
	{
		cout << "Lenovo��CPU��ʼ����" << endl;
	}
};

class LenovoGPU :public GPU
{
public:
	void display()
	{
		cout << "Lenovo���Կ���ʼ��Ⱦ" << endl;
	}
};

class LenovoMen :public Men
{
public:
	void storage()
	{
		cout << "Lenovo���ڴ�����ʼ�洢" << endl;
	}
};

void test_50()
{
	Computer* computer = new Computer(new IntelCPU, new IntelGPU, new IntelMen);
	computer->work();
	delete computer;

	cout << "----------------- computer2 ----------------" << endl;
	Computer* computer2 = new Computer(new LenovoCPU, new LenovoGPU, new LenovoMen);
	computer2->work();
	delete computer2;

	cout << "----------------- computer3 ----------------" << endl;
	Computer* computer3 = new Computer(new IntelCPU, new IntelGPU, new LenovoMen);
	computer3->work();
	delete computer3;
}

int main50()
{
	test_50();

	system("pause");
	return 0;
}