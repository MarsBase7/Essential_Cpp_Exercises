/*
练习3.3
定义一个map，以家庭姓氏为key，value是家庭所有小孩的名字。令此map至少容纳六笔数据。
允许用户根据姓氏来查询，并得以打印map内的每一笔数据。
*/

# include <map>
# include <string>
# include <vector>
# include <iostream>
# include <fstream>

using namespace std;

typedef vector<string> vstring;
map< string, vstring > families;

void populate_map( ifstream &nameFile, map<string, vstring> &families )
{
    string textline;

    while ( getline( nameFile, textline ) )
    {
        string fam_name;
        vector<string> child;
        string::size_type pos = 0, prev_pos = 0, text_size = textline.size();

        while ( ( pos = textline.find_first_of( ' ', pos ) ) != string::npos )
        {
            string::size_type end_pos = pos - prev_pos;

            if ( ! prev_pos )
                fam_name = textline.substr( prev_pos, end_pos );
            else 
                child.push_back( textline.substr( prev_pos, end_pos ) );
            prev_pos = ++pos;
        }

        if ( prev_pos < text_size )
            child.push_back( textline.substr( prev_pos, pos - prev_pos ) );

        if ( ! families.count( fam_name ) )
            families[fam_name] = child;
        else
            cerr << "Oops! We already have a " << fam_name << " family in our map! \n";
    }
}

void display_children( const string &family_name, const vector<string> &family, ostream &os )
{


    os << "The " << family_name << " family has ";
    if ( family.empty() )
        os << "no children\n";
    else
    {
        os << family.size() << " children: ";
        vector<string>::const_iterator
                    _it = family.begin(),
                    _end_it = family.end();
        while ( _it != _end_it ){
            os << *_it << " ";
            _it++;
        }
        os << endl;
    }
}

void display_map( const map<string, vstring> &families, ostream &os )
{
    map< string, vstring>::const_iterator
                            it = families.begin(),
                            end_it = families.end();

    while ( it != end_it )
    {
        display_children( it->first, it->second, cout );
        it++;
    }
}

void query_map( const string &family, const map<string, vstring> &families )
{
    map<string, vstring>::const_iterator
    it = families.find( family );

    if ( it == families.end() ){
        cout << "Sorry. The " << family << " is not currently entered. \n";
        return;
    }

    display_children( it->first, it->second, cout );
}

int main()
{
    map< string, vstring > families;
    ifstream nameFile( "3_3.txt" );

    if ( ! nameFile ){
        cerr << "Unable to find families file. Bailing Out!\n";
        return -1;
    }

    populate_map( nameFile, families );

    string family_name;
    while ( 1 ){
        cout << "Please enter a family name : (q to quit) ";
        cin >> family_name;

        if ( family_name == "q" )
            break;

        query_map( family_name, families );
    }
    cout << " ------ " << endl;
    cout << "Here is the Family Map :" << endl;
    display_map( families, cout );
}
