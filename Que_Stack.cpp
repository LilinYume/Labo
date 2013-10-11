#include <iostream>
using namespace std;
/*
   Que char型 
    要素数3個 固定
    init関数によって配列の要素を全てnullで初期化しておく
    Queに3文字を超えた入力がされた場合、入力が古いものを破棄 : FIFO
     Ex : 　enq a, enq b, enq c -> |abc|
            enq d -> a|bcd|  ここであふれた'a'は捨てる

   Stack
    char型 要素数3個 固定 : FILO
    3文字で満杯になったら入力をさせない。
*/
   //============================================================
   //                      Global
   //============================================================
   const int SIZE = 3;
   //                      Daclaration
   struct dd
   {
      char chr[SIZE];
   } Que, Stack;
   
   void init();
   void enq( char dt );
   char deq();
   void put( char dt );
   char pop();
   //============================================================
   //                   main() start
   //============================================================
   int main()
   {
      init();
      
      enq( 'a' );    // a\0\0
      enq( 'b' );    // ab\0
      enq( '\0' );
      enq( 'c' );    //  abc
      enq( 'd' );    //(a)bcd

      cout << Que.chr[0] << endl;
      cout << Que.chr[1] << endl;
      cout << Que.chr[2] << endl;

      cout << endl;
      
      cout << deq() << endl;
      cout << deq() << endl;
      cout << deq() << endl;
      cout << deq() << endl;

      put( 'a' );
      put( 'b' );
      put( 'c' );

      cout << Stack.chr[0];
      cout << Stack.chr[1];
      cout << Stack.chr[2];

      pop( );
      pop( );
      pop( );
      pop( );
      
      return 0;
   }
   //============================================================
   //                   Function Define
   //============================================================
   //                      int()
   //============================================================
   void init()
   {
      for ( int i = 0; i < SIZE; i++ )
      {
         Que.chr[ i ] = '\0';
         Stack.chr[ i ] = '\0';
      }
   }
   //============================================================
   //                      enq()
   //============================================================
   /* FIFO */
   void enq( char dt )
   {
      char *p = 0;
      static int i = 0; /* 複数回の呼び出しでもインデックスを維持する
                           関数の呼び出し回数が配列のインデックス   */

      p = Que.chr + i; // 現在ポイントしている要素のアドレスを代入

      while( *p ) 
      {
         // nullでなければ ポイント位置すすめ、次の要素位置のインデックスを用意
         p++; 
         i++;

         // 配列要素がFullの場合、インデックスを先頭へ戻す
         if ( i > SIZE - 1 ) i = 0;
      }
      // 引数に指定された文字をQueに格納
      Que.chr[ i ] = dt;
   }
   /* もっとシンプルな方法
   void enq( char dt )
   {
      // 関数を抜けてもインデックスを保持
      static int j = 0;

      // 保持されているインデックスに値を代入
      Que.chr[ j ] = dt;

      // 配列要素がFullになったらインデックスを先頭に戻す
      if ( j >= SIZE - 1 ) j = 0;

      // 次の要素がnullであれば、インデックスを一つ進める
      if ( !Que.chr[ j + 1 ] ) j++;
   }
   */
   //============================================================
   //                      deq()
   //============================================================
   char deq()
   {
      char value = Que.chr[ 0 ];
      int tail = SIZE - 1;
      char *p = 0;

      p = Que.chr;

      // Queが空っぽならnullを返して抜ける
      if ( !Que.chr[0] )
      {
         value = 0;
         return value;
      }
      // ポインタ位置を先頭要素にリセット
      p = Que.chr;

      for ( int i = 0; tail > 0 ; i++ )
      {
         // 先頭要素を取り出した分要素をそれぞれ1つずつシフトして詰める
         Que.chr[ i ] = Que.chr[ i + 1 ];
         Que.chr[ i + 1 ] = '\0';
         tail--;
      }
      return value;
   }
   //============================================================
   //                      puts()
   //============================================================
   void put( char dt )
   {
      // インデックス先頭から値を入れる
      // put関数を抜けてもインデックスを保持
      static int j = 0;

      // 配列要素がFullの場合、値をこれ以上入力させない。
      if ( j >= SIZE )
      { 
         cout << "Over Capacity" << endl;
         return;
      }
      // 保持されているインデックスに値を代入
      Stack.chr[ j ] = dt;

      // 次の要素がnullであれば、インデックスを一つ進める
      if ( !Stack.chr[ j + 1 ] ) j++;
   }
   //============================================================
   //                      pop()
   //============================================================
   /* FILO */
   char pop()
   {
      // 配列要素を逆順に並び替える
      // つくりかけ
     

      return ;
   }
