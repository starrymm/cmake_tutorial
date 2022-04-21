#CMAKE 最低版本要求
CMAKE_MINIMUM_REQUIRED(VERSION 3.00)

#设置工程名
PROJECT(Tutorial VERSION 0.1)
CONFIGURE_FILE(TutorialConfig.h.in TutorialConfig.h)

#查找当前目录下的所有源文件
AUX_SOURCE_DIRECTORY(. DIR_SRCS)

#添加math子目录
ADD_SUBDIRECTORY(math)

#添加可执行文件
ADD_EXECUTABLE(${PROJECT_NAME} ${DIR_SRCS})

TARGET_INCLUDE_DIRECTORIES(${PROJECT_NAME}
                        PRIVATE
                        ${PROJECT_SOURCE_DIR}/math
                        ${PROJECT_SOURCE_DIR}/include
                        ${PROJECT_BINARY_DIR}  #存放编译产物会放到该路径,build路径
                        )

#添加库文件
TARGET_LINK_LIBRARIES(${PROJECT_NAME} MathFunctions)

#指定C++标准
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)
