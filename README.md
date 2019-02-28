# < Essential C++ > 习题及解答
> Stanley B. Lippman

<br/>

### Basic C++ Programming
---
* [练习 1.4](https://github.com/MarsBase7/Essential_Cpp_Exercises/blob/master/Chapter%201/1_4.cpp)

（1）要求用户同时输入名字（first name）和姓氏（last name）    
（2）修改输出结果，同时打印姓氏和名字

* [练习1.5](https://github.com/MarsBase7/Essential_Cpp_Exercises/blob/master/Chapter%201/1_5.cpp)

编写一个程序，能够询问用户的姓名，并读取用户所输入的内容。请确保用户输入的名称长度大于两个字符。如果用户的确输入了有效名称，就响应一些信息。（推荐使用string对象）

* [练习1.6](https://github.com/MarsBase7/Essential_Cpp_Exercises/blob/master/Chapter%201/1_6.cpp)

编写一个程序，从标准输入设备读取一串整数，并将读入的整数依次放到容器，然后遍历容器，求取数值总和。将总和及平均值输出至标准输出设备。（推荐使用vector）

* [练习1.7]

使用编辑工具输入两行（或更多）文字并存盘。然后编写一个程序，打开该文本文件，将其中每个字都读取到一个vector<string>对象中。遍历该vector，将内容显示到cout。然后利用泛型算法sort()，对所有文字排序：
```
# include <algorithm>
sort( container.begin(), container.end() )
```
再将排序后的结果输出到另一个文件。
