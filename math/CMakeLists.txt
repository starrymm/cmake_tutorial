# 查找当前目录下的所有源文件
# 并将名称保存到 DIR_LIB_SRCS 变量
AUX_SOURCE_DIRECTORY(. DIR_LIBS_SRCS)

# 生成链接库
ADD_LIBRARY(MathFunctions ${DIR_LIBS_SRCS})


#添加库的使用要求
# INTERFACE是指消费者需要，生产者不需要的东西
TARGET_INCLUDE_DIRECTORIES(MathFunctions
        INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}
        )

#安装库文件和头文件
INSTALL(TARGETS MathFunctions 
        DESTINATION lib)
INSTALL(FILES MathFunctions.h 
        DESTINATION include)

