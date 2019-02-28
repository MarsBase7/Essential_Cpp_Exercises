/*
练习1.6
编写一个程序，从标准输入设备读取一串整数，并将读入的整数依次放到容器，然后遍历容器，求取数值总和。将总和及平均值输出至标准输出设备。
*/

# include <iostream>
# include <vector>

using namespace std;

int main()
{
    vector<int> ivec;
    int ival;

    cout << "Please input some integer numbers: " << endl;
    while( cin >> ival)
        ivec.push_back(ival);
    
    int sum = 0;
    for (int i = 0; i < ivec.size(); i++)
        sum += ivec[i];

    int average = sum / ivec.size();

    cout << "Sum of " << ivec.size()
         << " elements: " << sum
         << ". Average: " << average << endl;
    
    return 0;
}
