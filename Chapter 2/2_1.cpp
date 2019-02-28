/*
练习 2.1
编写一个程序，根据用户输入的位置值，返回斐波那契数列的该位置的值，且允许用户不断输入位置值，直到用户希望停止为止。
*/
# include <iostream>

using namespace std;

extern bool fibon_elem( int pos, int & elem )
{
    if ( pos <= 0 || pos > 32 )  //检查位置合理性，限制最大允许的位置值为32
        { elem = 0; return false; }
    
    elem = 1;
    int n_2 = 1, n_1 = 1;

    for ( int i=3; i<=pos; i++ ){
        elem = n_2 + n_1;
        n_2 = n_1;
        n_1 = elem;
    }
    
    return true;
}

int main()
{
    int pos, elem;
    char ch;
    bool more = true;

    while ( more ){
        cout << "Please enter a position of Fibonacci Sequence : ";
        cin >> pos;

        if ( fibon_elem( pos, elem ) )
            cout << "element #" << pos << " is " << elem << endl;
        else cout << "Sorry. Could not calculate element # " << pos << endl;
            
        cout << "would you like to try again ? (y/n) :";
        cin >> ch;
        if ( ch != 'y' && ch != 'Y' )
            more = false;
    }

    return 0;
}
