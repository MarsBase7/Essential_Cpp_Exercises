# < Essential C++ > 习题及代码
> Stanley B. Lippman

<br/>

## Basic C++ Programming

* [练习 1.4](https://github.com/MarsBase7/Essential_Cpp_Exercises/blob/master/Chapter%201/1_4.cpp)

（1）要求用户同时输入名字（first name）和姓氏（last name）    
（2）修改输出结果，同时打印姓氏和名字

* [练习1.5](https://github.com/MarsBase7/Essential_Cpp_Exercises/blob/master/Chapter%201/1_5.cpp)

编写一个程序，能够询问用户的姓名，并读取用户所输入的内容。请确保用户输入的名称长度大于两个字符。如果用户的确输入了有效名称，就响应一些信息。（推荐使用string对象）

* [练习1.6](https://github.com/MarsBase7/Essential_Cpp_Exercises/blob/master/Chapter%201/1_6.cpp)

编写一个程序，从标准输入设备读取一串整数，并将读入的整数依次放到容器，然后遍历容器，求取数值总和。将总和及平均值输出至标准输出设备。（推荐使用vector）

* [练习1.7](https://github.com/MarsBase7/Essential_Cpp_Exercises/blob/master/Chapter%201/1_7.cpp)

使用编辑工具输入两行（或更多）文字并存盘。然后编写一个程序，打开该文本文件，将其中每个字都读取到一个vector<string>对象中。遍历该vector，将内容显示到cout。然后利用泛型算法sort()，对所有文字排序：
```
# include <algorithm>
sort( container.begin(), container.end() )
```
再将排序后的结果输出到另一个文件。

* [练习 1.8](https://github.com/MarsBase7/Essential_Cpp_Exercises/blob/master/Chapter%201/1_8.cpp)

某个游戏，会根据用户答错的次数提供不同的安慰语句。    
请以array存储四种不同的字符信息，并以用户答错次数作为array的索引值，以此方式来显示安慰语句。

---

<br/>

## Procedural Programming

* [练习2.1](https://github.com/MarsBase7/Essential_Cpp_Exercises/blob/master/Chapter%202/2_1.cpp)

编写一个程序，根据用户输入的位置值，返回斐波那契数列的该位置的值，且允许用户不断输入位置值，直到用户希望停止为止。

* [练习2.2](https://github.com/MarsBase7/Essential_Cpp_Exercises/blob/master/Chapter%202/2_2.cpp)

Pentagonal数列的求值公式是P(n)=n(3n-1)/2，借此产生1,5,12,22,35等元素值。    
(1) 编写一个函数，利用上述公式，将产生的元素放到vector中，元素个数由用户指定。（检查元素个数的有效性，太大则可能引发overflow问题。）    
(2) 编写第二个函数，能够将给定的vector的所有元素一一打印出来。此函数的第二个参数接受一个字符串，表示存放在vector内的数列的类型。    
最后再写一个main()，测试上述两个函数。

* [练习2.3](https://github.com/MarsBase7/Essential_Cpp_Exercises/blob/master/Chapter%202/2_3.cpp)

将练习2.2的Pentagonal数列求值函数拆分为两个函数，其中之一为inline，用来检验元素个数是否合理。如果的确合理，而且尚未被计算，便执行第二个函数，执行实际的求值工作。

* [练习2.4](https://github.com/MarsBase7/Essential_Cpp_Exercises/blob/master/Chapter%202/2_4.cpp)

(1) 写一个函数，以局部静态(local static)的vector储存Pentagonal数列元素。此函数返回一个const指针，指向该vector。如果vector的大小小于指定的元素个数，就扩充vector的大小。    
(2) 接下来再实现第二个函数，接受一个位置值，返回该位置上的元素。    
最后，编写main()测试这些函数。

* [练习2.5](https://github.com/MarsBase7/Essential_Cpp_Exercises/blob/master/Chapter%202/2_5.cpp)

实现一个重载的max()函数，让它接受以下参数：
(a)两个整数，    
(b)两个浮点数，    
(c)两个字符串，    
(d)一个整数vector，    
(e)一个浮点数vector，    
(f)一个字符串vector，    
(g)一个整数数组，以及一个表示数组大小的整数值，    
(h)一个浮点数数组，以及一个表示数组大小的整数值，    
(i)一个字符串数组，以及一个表述数组大小的整数值，    
最后，编写main()测试这些函数。

* [练习2.6](https://github.com/MarsBase7/Essential_Cpp_Exercises/blob/master/Chapter%202/2_6.cpp)

以template重新完成练习2.5，并对main()函数做适度的修改。

---

<br/>

## Generic Programming

* [练习3.1](https://github.com/MarsBase7/Essential_Cpp_Exercises/blob/master/Chapter%203/3_1.cpp)

(1) 写一个读取文本文件的程序，将文件中的每个单字存入map。（map的key是单字，map的value是该单字在文本文件中出现的次数。）    
(2) 再定义一份由“排除字集”组成的set，其中包含诸如a、an、or、the、and和but之类的单字。将某单字放入map之前，先确定该单字并不存在于“排除字集”中。    
(3) 一旦文本文件读取完毕，请显示一份单字清单，并显示各单字的出现次数。    
(4) 对程序加以扩展，在显示单字之前，允许用户查询某个单字是否出现于文本文件中。

* [练习3.2](https://github.com/MarsBase7/Essential_Cpp_Exercises/blob/master/Chapter%203/3_2.cpp)

(1) 读取文本文件内容（同练习3.1）并将内容存储于vector。    
(2) 以字符串长度为依据，对vector排序。    
(3) 定义一个function object并传给sort()；这个function object接受两个字符串，当第一个字符串的长度小于第二个字符串的长度时，就返回true。    
(4) 打印排序后的vector内容。（在字符串长度相等的情况下，以其字母顺序排序）

* [练习3.3](https://github.com/MarsBase7/Essential_Cpp_Exercises/blob/master/Chapter%203/3_3.cpp)

(1) 定义一个map，以家庭姓氏为key，value是家庭所有小孩的名字。        
(2) 允许用户根据姓氏来查询，并得以打印map内的每一笔数据。

* [练习3.4](https://github.com/MarsBase7/Essential_Cpp_Exercises/blob/master/Chapter%203/3_4.cpp)

编写一个程序，
(1) 利用istream_iterator从标准输入设备读取一连串整数。    
(2) 利用ostream_iterator将其中的奇数写至某个文件，每个数值皆以空格分隔。    
(3) 再利用ostream_iterator将偶数写到另一个文件，每个数值单独放在一行中。    

---

<br/>

## Object-Based Programming

* [练习4.1](https://github.com/MarsBase7/Essential_Cpp_Exercises/blob/master/Chapter%204/4_1.cpp)

(1) 建立Stack.h和Stack.suffix，此处的suffix是编译器所能接受的扩展名，或是项目所使用的扩展名。    
(2) 编写main()函数，练习操作Stack的所有公开接口，并加以编译执行。程序代码文件和main()都必须包含Stack.h:     
`# include "Stack.h"`

* [练习4.2](https://github.com/MarsBase7/Essential_Cpp_Exercises/blob/master/Chapter%204/4_2.cpp)

扩展Stack的功能，以支持find()和count()两个操作。    
(1) find()会查看某值是否存在而返回true或false。    
(2) count()返回某字符串的出现次数。    
重新实现练习4.1的main()，让它调用这两个函数。

* [练习4.3](https://github.com/MarsBase7/Essential_Cpp_Exercises/blob/master/Chapter%204/4_3.cpp)

考虑以下所定义的全局(global)数据：
```
string program_name;
string version_stamp;
int version_number;
int tests_run;
int tests_passed;
```
编写一个用以包装这些数据的类。
