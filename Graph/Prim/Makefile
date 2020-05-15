# all 编译多个执行文件
all: test #other_projexes
.PHONY : all

PROJ = test
OBJS = test.o prim.o 
SRCS := $(OBJS:.o=.cpp)
# $(CXX)是make隐含规则使用的g++命令,make使用隐含规则自动推断.o的依赖,
# 而且会自动执行!!!!$(CXX) -c $(CPPFLAGS) $(CFLAGS)命令生成目标.o文件
# 但是只用下面的链接+隐含规则,没有各自不同的依赖.hpp，所以任何hpp文件改动后make都无法检测更新并编译
# 所以引入g++ -MM生产的 .d文件，导入各自的.hpp依赖!!!!
# https://akaedu.github.io/book/ch22s04.html
CXX  := g++ -std=c++11 -pedantic -Wall -Wextra
INSTALL_PATH = ./exe

#target ... : prerequisites ...
#   command
# 1.检查target是否存在，若无，则执行命令
# 2.若存在，则prerequisites中如果有一个以上的文件比target文件要新的话，则执行command
# 查找更新源->执行对应的命令

# g++ -c src.cpp 执行时，预编译时会把include的头文件的声明进行复制到，ｓrc.cpp 编译，　.ｏ文件里只有该声明(地址)，无具体实现
# 所以g++ 会自动找hpp文件, 无需添加　g++ -c src.cpp　src.hpp

# $(<function> <arguments>) == function(args)
# 比如$(wildcard *.c)
# $(origin <variable>) == $(val)
# 变量宏替换
# 变量使用时是$(val), or ${val} 就地展开替换
# 但最好用小括号 () 或是大括号 {} 最好用大括号，因为cmake变量用{}
# $(notdir <names...>)
# 在Makefile中的命令，必须要以 Tab 键开始。
# 缺省make make == make $(target) 即第一个 target

$(PROJ): $(OBJS)
	$(CXX) -o $@ $^
#	$(MAKE) clean #不能删除.o文件，一旦删除，.o文件不存在, 故每次make都会重新编译

# 自动生成的.d文件　test.o test.d : test.cpp prim.hpp
#test.o: test.cpp prim.hpp
#	$(CXX)  -c $<
#prim.o: prim.cpp prim.hpp
#	$(CXX)  -c $<

include $(SRCS:.cpp=.d)
# 等效于 导入以下规则
# test.d prim.d 两个文件，文件内容是下面的依赖, 
# include test.d 粘贴复制到当前的makefile文件作为真正的依赖规则
# test.d -> test.o test.d : test.cpp prim.hpp
# prim.d -> prim.o prim.d : prim.cpp prim.hpp

# 为每个源文件自动生成　依赖文件.d 
# g++ -std=c++11 -MM -Iinclude path/src.cpp 
# path指明源文件路径， -Iinclude指明头文件路径,所以可以在任意目录位置打印任意源文件的依赖，多目录自动生成依赖的原理
%.d: %.cpp
	set -e; rm -f $@; \
	$(CXX) -MM $(CXXFLAGS) $< > $@.$$$$; \
	sed 's,\($*\)\.o[ :]*,\1.o $@ : ,g' < $@.$$$$ > $@; \
	rm -f $@.$$$$


# <targets ...> : <target-pattern> : <prereq-patterns ...>
#    <commands>
# <targets ...> : <target-pattern> 一起当做新的目标数组
# 无法找打各自不同的依赖.hpp
# %.o 的 %, 即%匹配相同的字符, 一一对应
#$(objs): %.o : %.cpp
#	$(CXX) -c $< -o $@

# install --help == cp src dest_path
.PHONY : install
install:
	install $(PROJ) $(INSTALL_PATH)
# 通常，make会把其要执行的命令行在命令执行前输出到屏幕上
# @ 字符在命令行前，那么， 这个命令将不被make显示出来,
# 不加@echo 会显示两次信息，一次make打印,一次echo显示
	@echo "cp completed"

#.PHONY 表示 clean 是一个“伪目标”。即无论有没有clean为名的文件，都会执行下面的命令
# 如果目标即clean文件不存时，则执行下面命令,touch clean,新建clean 文件
# 而在 rm 命令前面加了一个小减号的 意思就是，也许某些文件出现问题，但不要管，继续做后面的事。
.PHONY : clean 
clean: 
	-rm -f $(OBJS)
	touch clean 


.PHONY : clear
clear: 
	$(MAKE) -f my_makefile clean
	-rm -f $(SRCS:.cpp=.d)

#-----------------------------------------总结---------------------------
# %自动变量：表示替换当前命令对应的目标或依赖
# $@ : all, 表示目标集,目标数组，自带 for ecah, 执行时调用 $@数组中每个目标对象
# $< : 表示替换依赖链表的第一个文件, 即%.cpp[0]
# $^ : 替换当前目标后的，所有的依赖文件, 以空格分隔。如果在依赖目标中有多个重复的，那么这个变量会去除 重复的依赖目标，只保留一份
# $? : 所有比目标新的依赖目标的集合。以空格分隔
# %.cpp 则取模式 %.o 的 %, 即%匹配相同的字符
# := 这种方法，前面的变量不能使用后面的变量，只能使用前面已定义好了的变量, 不能嵌套递归定义
# main: main.o stack.o maze.o
#	gcc main.o stack.o maze.o -o main
# main: main.o stack.o maze.o
#	gcc $^ -o $@    # $^ = main.o stack.o maze.o, $@ = main

# foo := a.o b.o c.o
# .o=.c 替换时不能有空字符空格，！！！！
# bar := $(foo:.o=.c) #$(foo)中所有以 .o 字串“结尾”全部替换成 .c

#----------------------------常用的make命令行选项-------------------------------
# make -n : 选项只打印要执行的命令，而不会真的执行命令，这个选项有助于我们检查Makefile写得是否正确，由于Makefile不是顺序执行的，用这个选项可以先看看命令的执行顺序，确认无误了再真正执行命令。
# make -f  使用别的文件名且有makefiel规则来当作Makefile 使用
# make -C subdir/ == cd subdir && $(MAKE) 调用目标目录下subdir的makefile, $(MAKE) -C subdir