#INCLUDE_DIRECTORIES(/tmp/usr/include/hello)
FIND_PATH(header hello.h)
IF(header)
    INCLUDE_DIRECTORIES(${header})
ENDIF(header)
LINK_DIRECTORIES(/tmp/usr/lib)

ADD_EXECUTABLE(main main.c)
TARGET_LINK_LIBRARIES(main hello)

