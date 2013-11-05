#include<iostream>
using std::cout;

namespace lnn
{
   void fainal( char *old );
   int length( const char *ptr );
   char *dump( const char *src );
   char *append( const char *dst, const char *src);
   bool contain( const char *str, char c );
   bool compare( const char *lhs, const char *rhs);
   const char *find( const char *text, const char *target, bool opt = false );
}
int main()
{
   
   
   
   
   lnn::fainal( p );

   return 0;
}
namespace lnn
{
   void fainal( char *old )
   {
      if( old ) delete old;
      else cout << "Failed" << '\n';
   }
   int length(const char *ptr)
   {
      if ( !*ptr ) return -1;
      int cnt = 0;
      while(*ptr++, cnt++);
      return cnt;
   }
   char *dump(const char *src)
   {
      int cnt = 0;
      char *chr = 0;
      while( *(src + cnt) ) cnt++;
      chr = new char[cnt++];

      chr[cnt] = '\0';
      while( *chr++, *src++ ) *chr = *src;

      chr -= cnt;
      return chr;
   }
   char *append(const char *dst, const char *src)
   {
      int i, cnt;
      char *chr = 0;
      i = cnt = 0;

      while( *(dst + i) ) i++;
      while( *(src + cnt) ) cnt++;
      
      cnt += i;
      chr = new char[cnt + 1];
      chr[cnt] = '\0';

      int idx = 0;
      while( chr[idx] = *dst++ ) idx++;
      while( chr[idx] = *src++ ) idx++;

      chr - cnt;
      return chr;
      
   }
   bool contain(const char *str, char c)
   {
      for ( int i = 0; *(str + i); i++ )
         if ( *(str + i) == c ) return true;
      return false;
   }
 　 bool compare( const char *lhs, const char *rhs)
   {
      bool find = true;
      int idx = 0;

      while( *lhs == *rhs )
      {
          if( !lhs[idx] && !rhs[idx] ) break;
          if( lhs[idx] != rhs[idx] )
          {
             find = false; 
             break;
          }
          idx++;
      }
      return find;
   }

}
