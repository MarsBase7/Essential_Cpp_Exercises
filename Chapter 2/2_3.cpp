/*
练习2.3
将练习2.2的Pentagonal数列求值函数拆分为两个函数，其中之一为inline，用来检验元素个数是否合理。如果的确合理，而且尚未被计算，便执行第二个函数，执行实际的求值工作。
*/

# include <iostream>
# include <string>
# include <vector>

using namespace std;

extern void real_calc_elems( vector<int> &, int );
inline bool calc_elems( vector<int> &vec, int pos );
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
    if ( pos<=0 || pos > max_size ){
        cerr << "Sorry. Invalid position: " << pos << endl;
        return false;
    }
    if ( vec.size() < pos )
        real_calc_elems( vec, pos );
    return true;
}

void real_calc_elems( vector<int> &vec, int pos )
{

    for ( int i=vec.size()+1; i<=pos; i++)
        vec.push_back( i*(3*i-1)/2 );
}

void disp_elems( vector<int> &vec, const string &title )
{
    cout << "\n" << title << "\n\t";
    for (int i=0; i<vec.size(); i++)
        cout << vec[i] << " ";
    cout << endl;
}


