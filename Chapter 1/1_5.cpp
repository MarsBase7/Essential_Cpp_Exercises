/*
练习1.5
编写一个程序，能够询问用户的姓名，并读取用户所输入的内容。请确保用户输入的名称长度大于两个字符。如果用户的确输入了有效名称，就响应一些信息。（推荐使用string对象）
*/

# include <iostream>
# include <string>

using namespace std;

int main()
{
    string user_name;

    cout << "Please enter your name: ";
    cin >> user_name;

    
    switch ( user_name.size() )
    {
        case 0:
            cout << "Ah, the user with no name. "
                 << "Well, ok, hi, user with no name." << endl;
            break;
        
        case 1:
            cout << "A 1-charater name? Hmm, have you read Kafka? : "
                 << "Hello, " << user_name << endl;
            break;
    
        default:
            cout << "Hello, " << user_name
                 << " -- happy to make your acquaintance!" << endl;
            break;
    }
    return 0;
}
