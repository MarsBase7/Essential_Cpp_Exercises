/*
练习3.4
编写一个程序，利用istream_iterator从标准输入设备读取一连串整数。
利用ostream_iterator将其中的奇数写至某个文件，每个数值皆以空格分隔。
再利用ostream_iterator将偶数写到另一个文件，每个数值单独放在一行中。
*/

# include <iterator>
# include <vector>
# include <iostream>
# include <algorithm>
# include <fstream>

using namespace std;

class even_elem {
public:
	bool operator() ( int elem )
		{ return elem % 2 ? false : true; }
};


int main()
{
	vector<int> input;
	cout << "Please input some integers : ";
	istream_iterator<int> in( cin ), eos;
	copy( in, eos, back_inserter( input ) );

	ofstream even_file("even_file"), 
	         odd_file("odd_file");

	if ( ! even_file || ! odd_file ){
		cerr << "Arghh!! Unable to open the output files. Bailing Out!\n";
		return -1;
	}

	vector<int>::iterator division = stable_partition( input.begin(), input.end(), even_elem() );

	ostream_iterator<int> even_iter( even_file, "\n" ),
						  odd_iter( odd_file, " ");

	copy( input.begin(), division, even_iter );
	copy( division, input.end(), odd_iter );
}
