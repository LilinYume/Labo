// 未完成
// 型：intのみ
// サイズ：5個固定
// 構造体変数のアクセスレベル：ローカル
// 満杯になったところに更に追加はできない

// TODO
// エンキュー デキューを交互に繰り返したとき正しく動作するか確認する
// Queの内容を表示する関数の作成

//enque()
// 一度の呼び出しにつき 値をひとつ追加
// 先頭から追加
// 値がセットされたらその都度 値を配列末尾の方へ詰める
// 値の数を保持する構造体メンバcountをインクリメント

//deque()
// 一度の呼び出しにつき 値をひとつ取り出し
// 末尾から取り出し
// 取り出しの都度 値を右詰めにしておく
// // 値の数を保持する構造体メンバcountをデクリメント
// 詰めた左側には移動元のコピーが残ったまま
 
#include <iostream>
using namespace std;

const int SIZE = 5;
const int HEAD = 0;
const int TAIL = SIZE - 1;

struct dd
{
	int value[SIZE];
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
	//enque( que , 6 ); 満杯にする
	int r[SIZE];

	for(int i =0; i < SIZE; i++) r[i] = -1;

	deque( que, r[0] );
	deque( que, r[1] );
	deque( que, r[2] );
	deque( que, r[3] );
	deque( que, r[4] );

	for( int i = 0; i < SIZE; i++)
	{
		cout << que.value[i] << " ";
		cout << '\t' << r[i] << " " << endl;
	}
	return 0;
}
void init(dd &dt)
{
	for(int i = 0; i < SIZE; i++) dt.value[i] = 0;
	dt.count = 0;
}
void enque( dd &dt, int value )
{
	// 満杯
	if ( dt.count == SIZE )
	{
		cout << "Full\n";
		return;
	}
	dt.value[ HEAD ] = value;

	/* 値を右詰め */
	if( dt.count == TAIL ) // 空きが一つならシフトしない
	{
		dt.count++;
		return;
	}
	dt.value[ TAIL - dt.count ] = dt.value[ HEAD ];
	dt.count++;
}
void deque( dd &dt, int &fetch )
{
	int empty = 0;

	// 取り出す値がない
	if( dt.count == 0 )
	{
		cout << "Empty\n";
		return;
	}
	fetch = dt.value[ TAIL ];	// 取り出し

	/* 値を右詰め */
	if( dt.count == 1 )	// 値が一つだけの場合シフトしない
	{
		dt.count--;
		return;
	}
	empty = SIZE - dt.count;	// 空きの数
	int incr = 0;
	for( int i = empty; i < TAIL; i++ )
	{
		dt.value[ TAIL - incr ] = dt.value[ TAIL - (incr + 1) ];
		incr++;
	}
	dt.count--;
}
