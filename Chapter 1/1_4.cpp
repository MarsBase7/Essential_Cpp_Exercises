/*
练习 1.4
（1）要求用户同时输入名字（first name）和姓氏（last name）
（2）修改输出结果，同时打印姓氏和名字
*/

# include <iostream>
# include <string>

using namespace std;

int main()
{
    string first_name, last_name;

    cout << "Please enter your first name: ";
    cin >> first_name;

    cout << "Hi, " << first_name << ". Please enter your last name: ";
    cin >> last_name;

    cout << '\n';
    cout << "Hello, "
         << first_name << " " << last_name
         << " ... and goodbye!" << endl;
    
    return 0;
}
