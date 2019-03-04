/*
写一个函数，以局部静态(local static)的vector储存Pentagonal数列元素。此函数返回一个const指针，指向该vector。如果vector的大小小于指定的元素个数，就扩充vector的大小。
接下来再实现第二个函数，接受一个位置值，返回该位置上的元素。
最后，编写main()测试这些函数。
*/

# include <iostream>
# include <vector>

using namespace std;

inline bool check_valid( int );
const vector<int>* pent_seq( int );
bool pent_elem( int, vector<int> & );

inline bool check_valid( int pos )
{
    const int max_size = 64;
    return ( pos <= 0 || pos > max_size ) ? false : true;
}

const vector<int>* pent_seq( int pos )
{
    static vector<int> _elems;

    if ( check_valid(pos) && ( pos > _elems.size() ) ){
        for ( int i=_elems.size()+1; i<=pos; i++ )
            _elems.push_back( i*(3*i-1)/2 );
    }
    return &_elems;
}

bool pent_elem( int pos, int &elem )
{
    if ( !check_valid(pos) ){
        cerr << "pent_seq(): oops: invalid size: " << pos << " -- can't fulfill request.\n";
        elem = 0;
        return false;
    }
    const vector<int> *pent = pent_seq( pos );
    elem = (*pent)[pos-1];
    return true;
}

int main()
{
    int elem, pos;

    cout << "Please enter a position of Pentagonal Serial: ";
    while( cin >> pos ){
        if ( pent_elem( pos, elem ) )
            cout << "element " << pos << " of Pentagonal is: " << elem << endl;
        cout << "Please enter a position of Pentagonal Serial: ";
    }
}
