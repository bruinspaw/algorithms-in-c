CMAKE_MINIMUM_REQUIRED(VERSION 2.8)
PROJECT(SinglyLinkedList)
SET(ROOT ../../..)
INCLUDE_DIRECTORIES(${ROOT}/include)
SET(SOURCES
	main.c
	${ROOT}/src/SinglyLinkedList.c
)
ADD_EXECUTABLE(slist ${SOURCES})
