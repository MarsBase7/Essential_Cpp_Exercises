/*
练习1.7
使用编辑工具输入两行（或更多）文字并存盘。然后编写一个程序，打开该文本文件，将其中每个字都读取到一个vector对象中。遍历该vector，将内容显示到cout。然后利用泛型算法sort()，对所有文字排序：
# include <algorithm>
sort(container.begin(), container.end())
再将排序后的结果输出到另一个文件。
*/

# include <iostream>
# include <fstream>
# include <algorithm>
# include <string>
# include <vector>

using namespace std;

int main()
{
    ifstream in_file("1_7.text");
    if (! in_file)
        { cerr << "Oops! unable to open input file.\n"; return -1; }

    ofstream out_file("1_7.sort");
    if (! out_file)
        { cerr << "Oops! unable to open output file.\n"; return -1; }
    
    string word;
    vector<string> text;

    while( in_file >> word )
        text.push_back(word);
    
    cout << "unsorted text :" << endl;
    for (int i=0; i < text.size(); i++)
        cout << " " << text[i];
    cout << endl;

    sort(text.begin(), text.end());

    out_file << "Sorted text: ";
    for (int i=0; i < text.size(); i++)
        out_file << text[i] << " ";
    out_file << endl;

    return 0;

}
