#include "my_que_stack.h"
#include "mincio.h"
namespace lnn_que
{
   dd_q *create()
   {
      dd_q val;
      dd_q *obj;
      obj = &val;

      obj = new dd_q;
      if( !obj ) return 0;

      for( int i = 0; i < SIZE; i++)
      {
         obj-> Int[i] = 0;
         obj-> Chr[i] = 0;
         obj-> Dbl[i] = 0;
      }
      return obj;
   }
   void fainal( const dd_q *st )
   {
      if( st )
      {
         delete st;
         cout << "Deleted!" << '\n';
      }
   }
   void enq_int( dd_q *dt, int val )
   {
      int idx = 0;
      while( !dt-> Int[++idx] );
      
      if (!idx)
      {
         cout << "Full" << '\n'; return;
      }
      --idx;
      dt-> Int[idx] = val;
   }
   void enq_chr( dd_q *dt, char val )
   { 
      int idx = 0;
      while( !dt-> Chr[++idx] );
      
      if (!idx)
      {
         cout << "Full" << '\n'; return;
      }
      --idx;
      dt-> Chr[idx] = val;
   }
   void enq_dbl( dd_q *dt, double val )
   {
      int idx = 0;
      while( !dt-> Dbl[++idx] );
      
      if (!idx)
      {
         cout << "Full" << '\n'; return;
      }
      --idx;
      dt-> Dbl[idx] = val;
   }
   int deq_int( dd_q *dt )
   {
      int idx = 0;
      int fetch = 0;
      for(int idx = TAIL; !dt-> Int[idx]; --idx);
      fetch = dt-> Int[idx];
      dt-> Int[idx] = 0;

      if ( idx < 0 )
      {
         cout << "Empty" << '\n'; return 0;
      }
      return fetch;
   }
   char deq_chr( dd_q *dt )
   {
      int idx = 0;
      char fetch = 0;
      for(int idx = TAIL; !dt-> Chr[idx]; --idx);

      fetch = dt-> Chr[idx];
      dt-> Chr[idx] = 0;

      if ( idx < 0 )
      {
         cout << "Empty" << '\n'; return 0;
      }
      return fetch;
   }
   double deq_dbl( dd_q *dt )
   {
      int idx = 0;
      double fetch = 0;
      for(int idx = TAIL; !dt-> Dbl[idx]; --idx);
   
      fetch = dt-> Dbl[idx];
      dt-> Dbl[idx] = 0;

      if ( idx < 0 )
      {
         cout << "Empty" << '\n'; return 0;
      }
      return fetch;
   }
}
