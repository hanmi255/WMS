# CMakeList.txt: test-bcrypt 的 CMake 项目，在此处包括源代码并定义项目特定的逻辑。

# 设置文件名称
set (tbcrypt test-bcrypt)

# 添加可执行文件
add_executable (${tbcrypt} "test-bcrypt.cpp")