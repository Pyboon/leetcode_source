### CPP中类型转换以及补码存储
```cpp
#include <stdio.h>
#include <iostream>

using namespace std;

void main()
{

	//做这类题目抓住两点：第一、无论是以进制表示还是整数形式赋值给变量，都要根据变量相应
	//的数据类型，表示为补码的形式存储进计算机内存中；第二、无论是在做数据类型强制转换（
	//内存存储形式没有改变，这一点可以通过查看Memory得到）还是做位运算的时候，实际上都是对
	//内存中存储的数进行的操作（也可以查看Memory得到），至于呈现的时候就是根据设定的数据类
	//型把内存中存储的二进制数字进行相应规则的呈现即可

	//cout << sizeof(long long) << endl;

	//注意，计算机存储的都是数的补码，无论是正数还是负数，另外要注意数据类型的长度
	short int a = 0x8000;//有符号数则表示-32768（计算机就存这个数，它是补码，要算实际代表的数要运算）
	short int b = 0x7000;//有符号数表示28672
	unsigned short int c = 0x8000;//无符号数则表示32768，是正数

	short int d = c;
	unsigned short int e = a;

	cout << a << endl;//应输出-32768，因为是有符号数
	cout << b << endl;//应输出28762，应为是正数
	cout << c << endl;//应输出32768，因为是无符号数
	cout << d << endl;//应输出-32768，因为强制转换成了有符号数
	cout << e << endl;//应输出32768，因为强制转换成了无符号数
	//感觉强制转换的时候在内存存储形式并没有任何改变，只是呈现的形式改变而已,按照需要的数据类型格式进行呈现
	//任何的位操作都是对内存中存储的数进行的操作。

	short int pre = -3;					//在内存中的表示为1111 1111 1111 1101是它的补码形式，即0xfffd
	unsigned short int trans = pre;		//0xfffd无符号数应表示的是65533，注意内存内形式不变
	short int m = ~pre;					//直接操作的是内存中存储的形式，按位取反后是0000 0000 0000 0010，即0x0002
	unsigned short int n = ~pre;		//实际上之后的形式还是0x0002

	cout << pre << endl;
	cout << trans << endl;
	cout << m << endl;
	cout << n << endl;

	cout << "/*********************************************************************************/" << endl;
	unsigned char ch = 'F';
	//其实下面一行代码做了三步操作
	//第一、首先把ch按位取反，之后在内存中的形式变为1011 1001
	//第二、把内存中的这个值先进行扩位，扩充成short类型的，扩位的时候是看做有符号数进行的，
	//扩位之后为1111 1111 1011 1001，即：0xffb9
	//第三、把0xffb9按照无符号数规则进行呈现
	unsigned short int p = ~ch;
	unsigned short int q = (unsigned)~ch;

	cout << ch << endl;
	cout << p << endl;
	cout << q << endl;

	cout << "/**************************************************************************/" << endl;
	unsigned short int p1;
	short int p2;

	//有符号字符扩充为无符号和有符号short int
	char ch1 = 'F';
	p1 = ~ch1;
	p2 = ~ch1;
	cout << p1 << endl;
	cout << p2 << endl;

	//无符号字符扩充为无符号和有符号short int
	unsigned char ch2 = 'F';
	p1 = ~ch2;
	p2 = ~ch2;
	cout << p1 << endl;
	cout << p2 << endl;


	/******测试有符号数和无符号数的强制转换和扩位******/
	cout << "/**************************************************************************/" << endl;
	int nn = 0;
	unsigned int nn1 = 0;

	//无符号数（正）扩充为有符号数和无符号数
	unsigned short int mm1 = 0x7000;  //28672
	nn = ~mm1;
	nn1 = ~mm1;

	cout << nn << endl;
	cout << nn1 << endl;

	short int aaa = 0x8000;
	long long bbb = ~aaa;

	//无符号数（负）扩充为有符号数和无符号数
	unsigned short int mm3 = 0x8000;   //32768
	nn = mm3;
	nn1 = mm3;

	cout << nn << endl;
	cout << nn1 << endl;

	//有符号数（正）扩充为有符号数和无符号数
	short int mm2 = 0x7000;             //+28672
	nn = mm2;
	nn1 = mm2;

	cout << nn << endl;
	cout << nn1  << endl;

	//有符号数（负）扩充为有符号数和无符号数
	short int mm4 = 0x8000;				//-32768
	nn = mm4;
	nn1 = mm4;

	cout << nn << endl;
	cout << nn1  << endl;

}
```
