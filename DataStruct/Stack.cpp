#include <iostream>
using namespace std;

const int SIZE = 5;
const int TAIL = SIZE - 1;
const int HEAD = 0;

struct dd
{
	int value[SIZE];
	int count;
};

void init( dd &dt );
void push( dd &dt, int data );
void pop( dd &dt, int &fetch );

int main()
{
	dd stack;
	init( stack );
	
	int r[SIZE];
	for (int i = 0; i < SIZE; ++i) r[i] = -1;
	
	push( stack, 1 );
	push( stack, 2 );
	push( stack, 3 );
	push( stack, 4 );
	push( stack, 5 );

	pop( stack, r[0] );
	pop( stack, r[1] );
	pop( stack, r[2] );
	pop( stack, r[3] );
	pop( stack, r[4] );
	
	for (int i = 0; i < SIZE; ++i)
	{
		cout << stack.value[i] << '\t';
		cout << r[i] << endl;
	}
	return 0;
}
void init( dd &dt )
{
	for(int i = 0; i < SIZE; i++) dt.value[i] = -1;
	dt.count = 0;
}
void push( dd &dt, int data )
{
	// 満杯
	if (dt.count == SIZE)
	{
		cout << "Full\n";
		return;
	}
	dt.value[HEAD] = data;
	
	// 値のシフトなし
	if (dt.count == TAIL)
	{
		dt.count++;
		return;
	}
	// 値を右に詰める
	dt.value[TAIL - dt.count] = dt.value[HEAD];
	dt.count++;
}
void pop( dd &dt, int &fetch )
{
	int empty = 0;
	
	// 空
	if (dt.count == 0)
	{
		cout << "Empty\n";
		return;
	}
	fetch = dt.value[HEAD];
	dt.count--;
	
	// 値のシフトなし
	if (dt.count == 1)
	{
		dt.count--;
		return;
	}
	// 値を左寄せ ～～ここからまだ～～
	int incr = 1;
	for (int i = 0; i < dt.count - 1; ++i)
	{
		dt.value[ HEAD + i ] = dt.value[ HEAD + incr ];
		incr++;
	}
}
