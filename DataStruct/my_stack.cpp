#include "my_que_stack.h"
#include "mincio.h"
namespace lnn_stack
{
   dd_s *create()
   {
      dd_s *stck;
      stck = new dd_s;
      return stck;
   }
   void fainal( const dd_s *st )
   {
      if( st )
      {
         delete st;
         cout << "Deleted!" << '\n';
      }
   }
   void push_int( dd_s *dt, int val )
   {
      int idx = 0;
      while( !dt-> Int[++idx] );
      --idx;
      if ( idx < 0 )
      {
         return;
         cout << "Full" << '\n';
      }
      dt-> Int[idx] = val;
   }
   void push_chr( dd_s *dt, int val )
   {
      int idx = 0;
      while( !dt-> Chr[++idx] );
      --idx;
      if ( idx < 0 )
      {
         return;
         cout << "Full" << '\n';
      }
      dt-> Chr[idx] = val;
   }
   void push_dbl( dd_s *dt, int val )
   {
      int idx = 0;
      while( !dt-> Dbl[++idx] );
      --idx;
      if ( idx < 0 )
      {
         return;
         cout << "Full" << '\n';
      }
      dt-> Dbl[idx] = val;
   }
   int pop_int( dd_s *dt )
   {
      int idx, fetch;
      idx = fetch = 0;
      while( dt-> Int[++idx] );

      fetch = dt-> Int[idx];
      dt-> Int[idx] = 0;

      return fetch;
   }
   char pop_chr( dd_s *dt )
   {
      int idx; char fetch;
      idx = fetch = 0;
      while( dt-> Chr[++idx] );

      fetch = dt-> Chr[idx];
      dt-> Chr[idx] = 0;

      return fetch;
   }
   double pop_dbl( dd_s *dt )
   {
      int idx; double fetch;
      idx = 0; fetch = 0.0;
      while( dt-> Dbl[++idx] );

      fetch = dt-> Dbl[idx];
      dt-> Dbl[idx] = 0.0;

      return fetch;
   }
}
