// 未完成
// 型：intのみ
// サイズ：5個固定
// 構造体変数のアクセスレベル：ローカル

//現在の問題
//エンキュー デキューした後 更にエンキューすると挿入位置がおかしい

//enque()
// 先頭から追加
// 一度の呼び出しにつき 値をひとつ追加

//deque()
// 一度の呼び出しにつき 値をひとつ取り出し
 
#include <iostream>
using namespace std;

const int SIZE = 5;
const int TAIL = SIZE - 1;

struct dd
{
	int data[SIZE];
	int count;
};
void init(dd &dt);
void enque( dd &dt, int value );
void deque( dd &dt, int &fetch);

int main()
{
	dd que;
	init( que );

	enque( que , 1 );
	enque( que , 2 );
	enque( que , 3 );
	enque( que , 4 );
	enque( que , 5 );

	int r = 0;

	deque( que, r );
	deque( que, r );
	deque( que, r );

	enque( que , 3 );

	deque( que, r );

	/*for( int i = 0; i < SIZE; i++)
		cout << que.data[i] << endl;*/

	return 0;
}
void init(dd &dt)
{
	for(int i = 0; i < SIZE; i++) dt.data[i] = 0;
	dt.count = 0;
}
void enque( dd &dt, int value )
{
	int index = 0;
	if( dt.count == SIZE )
	{
		cout << "Full\n";
		return;
	}
	index = dt.count;
	dt.data[index] = value;
	dt.count++;
}
void deque( dd &dt, int &fetch )
{
	int empty, target, offset;

	if ( !dt.count )
	{
		cout << "Empty\n";
		return;
	}
	empty = SIZE - dt.count;
	target = dt.count - 1;
	offset = TAIL - empty - 1;
		
	fetch = dt.data[target];
	
	for(int i = 0; i < dt.count; i++)
	{
		dt.data[TAIL - i] = dt.data[offset];
		offset--;
		if( offset < 0 ) break;
	}
	dt.count--;
}
