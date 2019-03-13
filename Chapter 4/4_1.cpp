/*
练习4.1
建立Stack.h和Stack.suffix，此处的suffix是编译器所能接受的扩展名，或是项目所使用的扩展名。
编写main()函数，练习操作Stack的所有公开接口，并加以编译执行。程序代码文件和main()都必须包含Stack.h: 
# include "Stack.h"
*/

# include "Stack1.cpp"

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

    cout << '\n' << "Read in " << st.size() << " strings!\n"
         << "The strings, in reverse order: \n";

    while ( st.size() )
        if ( st.pop( str ) )
            cout << str << ' ';

    cout << '\n' << "There are now "<< st.size()
         << " elements in the stack!\n";
}
