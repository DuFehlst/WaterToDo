/*
WaterToDo
周涵轶 THU 航05 2020013488
*/

#include <iostream>
#include <string>
#include <string.h>
#include <stdlib.h>
#include <iomanip>

using namespace std;

#if 0
Q1：
严重性	代码	说明	项目	文件	行	禁止显示状态
错误	LNK2019	无法解析的外部符号 "class NewTask __cdecl A(void)" (? A@@YA ? AVNewTask@@XZ)，函数 _main 中引用了该符号	WaterToDo	C : \Users\10378\source\repos\WaterToDo\WaterToDo.obj	1
解决方式：
莫名其妙重新定义了一下NewTask类就过了, 可能是引用参数问题；
#endif

int _cin1;//StartTable输入的全局变量
int _cin2;//MenuTable输入的全局变量

#if 0
设置时钟的类;
1.当前时间；
2.DDL时间；

可以考虑用union，共用当前时间；

经过一段时间修改后：
目前没啥用，也不知道之后会不会用到
#endif
struct clock//目前没啥用，也不知道之后会不会用到
{
	int hour;
	int minute;
	int second;
	clock() :hour(), minute(), second() {}
	void setClock(int, int, int);
	void showClock();
};

void clock::setClock(int a, int b, int c)
{
	hour = a;
	minute = b;
	second = c;
}

void clock::showClock()
{
	cout << hour << ":" << minute << ":" << second << endl;
}

#if 0
创建新任务;
功能：
1创建名字；
2创建DDL；
3是否完成；
4备注；
#endif
struct NewTask
{public:
	char taskName[10];
	char detail[30];
	struct clock deadline;
	bool isFinished = 0;
};

class NewTask Task[100];
int taskcount = 0;

#if 0
Q：taskname无法赋值，最后os都是空字符串；
#endif

#if 0
后续还要补充年月日；
#endif

#if 0
4.27
命名法则太乱；
#endif

void CreateTask()
{
	cout << endl << "\tTaskName:";
	cin >> Task[taskcount].taskName;

	cout << endl << "\tDetail：";
	cin >> Task[taskcount].detail;

	cout << endl << "\tHour Minute Second:";
	cin >> Task[taskcount].deadline.hour >> Task[taskcount].deadline.minute >> Task[taskcount].deadline.second;
	taskcount++;
}
#if 0
界面设置：
创建（新任务）	查看（全部任务）	调用（关键字搜索任务）
实现：
输入命令 >> 进行下一步操作；
#endif

void ModifyTask()
{
	;
}
void ShowAll()
{
	char finiSymble[5];
	cout << "All the Task: " << endl;
	cout << left;
	cout <<setw(5)<<" "<< setw(20) << "TaskName" << setw(40) << "Detail" << setw(40) << "Deadline:Hour Minute Second" << endl;
	for (int begin = 0; begin <= taskcount; begin++)
	{
		if (Task[begin].isFinished = 0) cout << '1';
		if (Task[begin].isFinished = 1) cout << '0';

		cout <<setw(5)<<finiSymble<< setw(20) <<Task[begin].taskName<< setw(40) << Task[begin].detail <<"         "<< setw(5) << Task[begin].deadline.hour<<setw(7)<< Task[begin].deadline.minute<<setw(7)<< Task[begin].deadline.minute << endl;
	}
}

void TaskSetting()
{
	cout << "TaskSetting: ①创建		②修改" << endl;
	BEGIN2:
	cin >> _cin2;
	switch(_cin2)
	{
	case 1:
		CreateTask();
		break;
	case 2:
		ModifyTask();
			break;
	default:
		cout << "Aha,Can you input again?" << endl;
		goto BEGIN2;
	}
}

void MenuTable()
{
	cout << "菜单：	①ShowAll		②TaskSetting" << endl;
	BEGIN:
	cin >> _cin1;
	switch (_cin1)
	{case 1:
		system("cls");
		ShowAll();
		system("pause");
		break;
	case 2:
		system("cls");
		TaskSetting();
		system("pause");
		break;
	default:
		cout << "Aha,Can you input again?" << endl;
		goto BEGIN;
	}
}


#if 0
Q1:
怎么将前面创建的task保存下来；
尝试1：
四维数组，名字，完成否，DDl，备注（确实不知道怎么实现）
#endif

#if 0
Q2：
怎么保持界面一直都在；
我的操作：
最外面套一个while(1)的循环；
#endif

#if 0
Q3:
设置界面怎么返回
goto？？？
#endif

int main()
{
	while (1)
	{
		system("cls");
		cout << "Water To Do" << endl;
		MenuTable();
	}
	return 0;
}