#include <iostream>
using namespace std;
/*
   Que
    char型 要素数3個 固定 : FIFO
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


      cout << "enq(\'a\') enq(\'b\') enq(\'\\0\'); enq(\'c\'); enq(\'d\')" << endl;

      cout << "Deque" << ":\t";
      cout << deq() << ' ';
      cout << deq() << ' ';
      cout << deq() << endl;

      cout << endl;

      put( 'a' );      put( 'b' );      put( 'c' );

      cout << "put(\'a\') put(\'b\') put(\'c\')" << endl;
      cout << "push from stack" << " : ";
      
      cout << pop( ) << ' ';
      cout << pop( ) << ' ';
      cout << pop( ) << endl;

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

      // nullでなければ ポイント位置すすめ、次の要素位置のインデックスを用意
      while( *p ) 
      {
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

      // Queが空っぽなら-1を返して抜ける
      if ( !Que.chr[0] )
      {
         value = 0;
         return -1;
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
   //                      put()
   //============================================================
   /* FILO */ // 末尾から追加 値は右づめで残りはnullか、値が満杯かのいずれか。
   void put( char dt )
   {

      // 先頭要素が在るとういことは既に満杯なので関数を抜ける
      if ( Stack.chr[0] ) return;

      int tail = SIZE - 1; // 配列末尾のインデックス
      int counter = 0;     // nullの数を数える用


      // 先頭からnullをサーチし、その数をかそえる。
      // このループ内では、要素か空のときを想定し、末尾までnullか判定、カウントする。
      for ( int i = 0; i < tail; i++ )
      {
         if ( !Stack.chr[ i ] ) counter++;
         
      }
      // 既に末尾に値がある場合、その分余計にカウントしたnullカウンをひとつ引く
      if ( Stack.chr[ tail ] ) counter--;

      Stack.chr[ counter ] = dt;

      //int j = 0;
      //// 要素nullのインデックスをスキップ
      //for ( int i = 0; Stack.chr[ i ]; i++ ) j++;

      //// 配列要素がFullの場合、値をこれ以上入力させない。
      //if ( j >= SIZE )
      //{ 
      //   cout << "Over Capacity" << endl;
      //   return;
      //}
      //// ポイントしているインデックスに値を代入
      //Stack.chr[ j ] = dt;
   }
   //============================================================
   //                      pop()
   //============================================================
   /* FILO */ // 先頭からnullではない、値を取り出す。
   char pop()
   {
      static int index = 0;
      char fetch = 0;

      // 値が在るインデックスをサーチ
      if ( Stack.chr[ index ] )
      {
         fetch = Stack.chr[ index ];
         index++;
      }
      if ( index > SIZE ) 
      {
         index = 0;
         return -1;
      }
      return fetch;
   }
