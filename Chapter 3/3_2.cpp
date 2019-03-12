/*
练习3.2
读取文本文件内容（同练习3.1）并将内容存储于vector。
以字符串长度为依据，对vector排序。
定义一个function object并传给sort()；这个function object接受两个字符串，当第一个字符串的长度小于第二个字符串的长度时，就返回true。
最后，打印排序后的vector内容。
*/

# include <string>
# include <iostream>
# include <fstream>
# include <vector>

using namespace std;

class LessThan {
public:
    bool operator() ( const string & s1, const string & s2 ){
        return s1.size() < s2.size();
    }
};

template <typename elemType>
void display_vector( const vector<elemType> &vec, ostream &os=cout, int len=8 )
{
    vector<string>::const_iterator
                        iter = vec.begin(),
                        end_it = vec.end();

    int elem_cnt = 1;
    while ( iter != end_it )
        os << *iter++ << ( !(elem_cnt++ % len ) ? "\n" : " " );
    os << endl;
}


int main()
{
    ifstream ifile( "3_1.txt" );
    ofstream ofile( "3_2.sort" );

    if ( ! ifile || ! ofile ){
        cerr << "Unable to open file -- bailing out!" << endl;
        return -1;
    }

    vector<string> text;
    string word;
    int len;

    while ( ifile >> word )
        text.push_back( word );

    sort( text.begin(), text.end(), LessThan() );

    cout << "The text is sorted. \n"
         << "How many words to display in one line? : (1-20) ";
    cin >> len;

    display_vector( text, ofile, len );
}
