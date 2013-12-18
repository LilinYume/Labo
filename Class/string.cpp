#include <iostream>
#include <cstdlib>
using std::cout;
using std::endl;

class String
{
	char *data;
	int size;
public:
	String( const char *str );
	String( const String &obj );
	~String();
};
String::String( const char *str )
{
	size = 0;
	if ( *str )
	{
		// サイズをカウント
		while( *(str + size++) );
		data = new char[size];

		// 値をコピー
		while ( *data++ = *str++ );
		str -= size;
		data -= size;
	}
	else data = new char;

	if ( !data )
	{
		cout << "Allocation Failed\n";
		exit(1);
	}
}
String::String( const String &obj )
{
	size = obj.size;
	if ( size > 0 )
		data = new char[size];
	else
		data = new char;

	if ( !data )
	{
		cout << "Allocation Failed\n";
		exit(1);
	}
	for( int i = 0; i < size; i++ )
		data[i] = obj.data[i];
}
String::~String()
{
	delete data;
}

int main()
{
	char *t = "abc";
	String str1(t);
	String str2(str1);

	return 0;
}
