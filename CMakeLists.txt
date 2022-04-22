#CMAKE 最低版本要求
CMAKE_MINIMUM_REQUIRED(VERSION 3.0.0)

#设置工程名
PROJECT(Tutorial VERSION 0.1)

# ****该选项需要放置在configure_file命令之前
#将库设置为可选项
OPTION(USE_MYMATH "Use tutorail provided math implementation" ON)
IF(USE_MYMATH)
    ADD_SUBDIRECTORY(math)
    LIST(APPEND EXTRA_LIBS MathFunctions)
ENDIF()

#添加配置文件，编译后 TutorialConfig.h.in 将被转化成 TutorialConfig.h 文件 
#该文件位于项目文件的根目录 
CONFIGURE_FILE(
              ${PROJECT_SOURCE_DIR}/TutorialConfig.h.in 
              ${PROJECT_BINARY_DIR}/TutorialConfig.h
              )

#查找当前目录下的所有源文件
AUX_SOURCE_DIRECTORY(. DIR_SRCS)


#添加可执行文件
ADD_EXECUTABLE(${PROJECT_NAME} ${DIR_SRCS})

#添加头文件
TARGET_INCLUDE_DIRECTORIES(${PROJECT_NAME}
                        PUBLIC
                        #存放编译产物会放到该路径,build路径
                        ${PROJECT_BINARY_DIR}                         
                        )

#添加库文件
TARGET_LINK_LIBRARIES(${PROJECT_NAME}
                      PUBLIC
                      ${EXTRA_LIBS}
                      )

#指定C++标准
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g")
set(CMAKE_CXX_STANDARD_REQUIRED True)
