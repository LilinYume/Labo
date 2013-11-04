namespace lnn_que
{
   const int SIZE = 3;
   const int TAIL = SIZE - 1;

   struct dd_q
   {
      int Int[SIZE];
      char Chr[SIZE];
      double Dbl[SIZE];
   };

   dd_q *create();
   void fainal( const dd_q *st );
   void enq_int( dd_q *dt, int val );
   void enq_chr( dd_q *dt, char val );
   void enq_dbl( dd_q *dt, double val );

   int deq_int( dd_q *dt );
   char deq_chr( dd_q *dt );
   double deq_dbl( dd_q *dt );
}

namespace lnn_stack
{
   const int SIZE = 3;

   struct dd_s
   {
      int Int[SIZE];
      char Chr[SIZE];
      double Dbl[SIZE];
   };

   dd_s *create();
   void fainal( const dd_s *st );
   void push_int( dd_s *dt, int val );
   void push_chr( dd_s *dt, char val );
   void push_dbl( dd_s *dt, double val );

   int pop_int( dd_s *dt );
   char pop_chr( dd_s *dt );
   double pop_dbl( dd_s *dt );
}
