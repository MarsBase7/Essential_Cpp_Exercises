/*
练习3.1
写一个读取文本文件的程序，将文件中的每个单字存入map。（map的key是单字，map的value是该单字在文本文件中出现的次数。）
再定义一份由“排除字集”组成的set，其中包含诸如a、an、or、the、and和but之类的单字。将某单字放入map之前，先确定该单字并不存在于“排除字集”中。
一旦文本文件读取完毕，请显示一份单字清单，并显示各单字的出现次数。
可以再加以扩展，在显示单字之前，允许用户查询某个单字是否出现于文本文件中。
*/

# include <map>
# include <set>
# include <string>
# include <iostream>
# include <fstream>

using namespace std;

void initialize_exclusion_set( set<string> & );
void process_file( map<string, int> &, const set<string> &, ifstream & );
void user_query( const map<string, int> & );
void display_word_count( const map<string, int> &, ofstream & );

int main()
{
    ifstream ifile( "3_1.txt" );
    ofstream ofile( "3_1.map" );

    if ( ! ifile || ! ofile ){
        cerr << "Unable to open file -- bailing out!" << endl;
        return -1;
    }

    set<string> exclude_set;
    initialize_exclusion_set( exclude_set );

    map<string, int> word_count;
    process_file( word_count, exclude_set, ifile );
    user_query( word_count );
    display_word_count( word_count, ofile );
}

void initialize_exclusion_set( set<string> &exs )
{
    static string _excluded_word[25] = {
        "the", "and", "but", "that", "then", "are", "been",
        "can", "a", "could", "did", "for", "of",
        "had", "have", "him", "his", "her", "its", "is",
        "were", "which", "when", "with", "would"
    };

    exs.insert( _excluded_word, _excluded_word+25 );
}

void process_file( map<string, int> &word_count, const set<string> &exclude_set, ifstream &ifile )
{
    string word;
    while ( ifile >> word )
    {
        if ( exclude_set.count( word ) )
            continue;
        word_count[ word ]++;
    }
}

void user_query( const map<string, int> &word_map )
{
    string search_word;
    cout << "Please. enter a word to search: (q to quit)";
    cin >> search_word;

    while ( search_word.size() && search_word != "q" ).
    {
        map<string, int>::const_iterator it;
        if ( (it = word_map.find( search_word )) != word_map.end() )
            cout << "Found! " << it->first << " occurs " << it->second << " times." << endl;
        else cout << search_word << " was not found in text." << endl;
        cout << "\nAnother search? (q to quit)";
        cin >> search_word; 
    }
}

void display_word_count( const map<string, int> &word_map, ofstream &os )
{
    map<string, int>::const_iterator
                        iter = word_map.begin(),
                        end_it = word_map.end();

    while ( iter != end_it ){
        os << iter->first << " ( " << iter->second << " ) " << endl;
        iter++;
    }
    os << endl;
}


