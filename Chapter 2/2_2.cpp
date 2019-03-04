/*
Pentagonal数列的求值公式是P(n)=n(3n-1)/2，借此产生1,5,12,22,35等元素值。
编写一个函数，利用上述公式，将产生的元素放到vector中，元素个数由用户指定。（检查元素个数的有效性，太大则可能引发overflow问题。）
编写第二个函数，能够将给定的vector的所有元素一一打印出来。此函数的第二个参数接受一个字符串，表示存放在vector内的数列的类型。
最后再写一个main()，测试上述两个函数。
*/

# include <iostream>
# include <string>
# include <vector>

using namespace std;

bool calc_elems( vector<int> &vec, int pos );
void disp_elems( vector<int> &vec, const string &title);

int main()
{
	int pos;
	vector<int> pent;
	const string title("Pentagonal Numeric Series");

    cout << "Please enter a position : ";
    
    while( cin >> pos ){
    	if ( calc_elems( pent, pos ) )
    		disp_elems( pent, title );
    	cout << "Please enter a position : ";
    }

    return 0;
}

bool calc_elems( vector<int> &vec, int pos )
{
	const int max_size = 64;

	if ( pos <=0 || pos > max_size ){
		cerr << "Sorry. Invalid position: " << pos << endl;
		return false;
	}

	for ( int i=vec.size()+1; i<=pos; i++)
		vec.push_back( i*(3*i-1)/2 );

	return true;
}

void disp_elems( vector<int> &vec, const string &title )
{
	cout << "\n" << title << "\n\t";
	for (int i=0; i<vec.size(); i++)
		cout << vec[i] << " ";
	cout << endl;
}
