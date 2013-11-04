#include "my_que_stack.h"
#include "mincio.h"
int main()
{
   lnn_que::dd_q members;
   lnn_que::dd_q *q;
   q = &members;
 
   q = lnn_que::create();
   lnn_que::enq_int( q, 5 );
   lnn_que::enq_int( q, 7 );
   lnn_que::enq_int( q, 9 );

   int r = lnn_que::deq_int( q );

   cout << r << '\n';

   cout << q-> Int[0] << '\n';
   cout << q-> Int[1] << '\n';
   cout << q-> Int[2] << '\n';

   fainal( q );

   return 0;
}
