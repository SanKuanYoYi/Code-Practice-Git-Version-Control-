# 编译器
CXX = g++

# 编译选项：-std=c++11 支持 stoi，-Wall 显示所有警告
CXXFLAGS = -std=c++11 -Wall

# 目标可执行文件名
TARGET = calculator

# 需要的所有 .o 文件（由 .cpp 编译而来）
OBJS = main.o caculate.o pipe.o

# 默认执行的目标：生成可执行文件
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# 规则：每个 .cpp 文件编译成对应的 .o 文件
# 并且依赖于 head_files.h（如果头文件改了，所有 .cpp 都得重新编译）
main.o: main.cpp head_files.h
	$(CXX) $(CXXFLAGS) -c main.cpp

caculate.o: caculate.cpp head_files.h
	$(CXX) $(CXXFLAGS) -c caculate.cpp

pipe.o: pipe.cpp head_files.h
	$(CXX) $(CXXFLAGS) -c pipe.cpp

# 清理中间文件（方便重新编译）
clean:
	rm -f $(OBJS) $(TARGET)
