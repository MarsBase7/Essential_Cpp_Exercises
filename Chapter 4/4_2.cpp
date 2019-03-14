/*
练习4.2
扩展Stack的功能，以支持find()和count()两个操作。
(1) find()会查看某值是否存在而返回true或false。
(2) count()返回某字符串的出现次数。
重新实现练习4.1的main()，让它调用这两个函数。
*/

# include "Stack2.cpp"

int main()
{
    Stack st;
    string str;
    while ( cin >> str && ! st.full() )
        st.push( str );

    if ( st.empty() ){
        cout << '\n' << "Oops: no strings were read -- bailing out\n";
        return 0;
    }

    st.peek( str );
    if ( st.size() == 1 && str.empty() ) {
        cout << '\n' << "Oops: no strings were read -- bailing out\n";
        return 0;
    }

    cout << "\n" << "Read in " << st.size() << " strings!\n";
    cin.clear();

    cout << "What word to search for? ";
    cin >> str;

    bool found = st.find( str );
    int count = found ? st.count( str ) : 0;

    cout << str << ( found ? " is " : " isn\'t " ) << "in the stack. ";
    if( found )
        cout << "It occurs " << count << " times\n";
}
