target = test
objs = dijkstra.o test.o
CXX = g++ -std=c++11 -pedantic -Wall -Wextra

#target ... : prerequisites ...
#   command
# prerequisites中如果有一个以上的文件比target文件要新的话，command所定义的命令就会被执行
# 查找更新源->执行对应的命令

#g++ -c src.cpp 执行时，预编译时会把include的头文件的声明进行复制到，ｓrc.cpp 编译，　.ｏ文件里只有该声明(地址)，无具体实现
#所以g++ 会自动找hpp文件, 无需添加　g++ -c src.cpp　src.hpp

# 变量宏替换
# 变量使用时是$(val), $()字符替换函数，替换宏定义
# 每个函数的参数字符串都会被当做一个或是一系列的文件名来对待
# $(notdir <names...>)
$(target): $(objs)
# 在Makefile中的命令，必须要以 Tab 键开始。
	$(CXX) -o $(target) $(objs)

test.o: test.cpp dijkstra.hpp
	$(CXX)  -c test.cpp
dijkstra.o: dijkstra.cpp dijkstra.hpp
	$(CXX)  -c dijkstra.cpp

# <targets ...> : <target-pattern> : <prereq-patterns ...>
#    <commands>
# $< 表示第一个依赖文件 也就是objs中$.o的.cpp文件
# $@ 表示目标集
# %.cpp 则取模式 %.o 的 %, 即%匹配相同的字符
# 无法找打各自不同的依赖.hpp
#$(objs): %.o : %.cpp
#	$(CXX) -c $< -o $@



#.PHONY 表示 clean 是一个“伪目标”。
#而在 rm 命令前面加了一个小减号的 意思就是，也许某些文件出现问题，但不要管，继续做后面的事。
.PHONY : clean
clean:
	-rm -f *.o $(target)
	
# := 这种方法，前面的变量不能使用后面的变量，只能使用前面已定义好了的变量, 不能嵌套递归定义
# $^ : 所有的依赖目标的集合, 以空格分隔。如果在依赖目标中有多个重复的，那么这个变量会去除 重复的依赖目标，只保留一份
# $? : 所有比目标新的依赖目标的集合。以空格分隔