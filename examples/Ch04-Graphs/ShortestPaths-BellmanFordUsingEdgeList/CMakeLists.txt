CMAKE_MINIMUM_REQUIRED(VERSION 2.8)
PROJECT(BellmanFord1)
SET(ROOT ../../..)
INCLUDE_DIRECTORIES(${ROOT}/include)
SET(SOURCES
	main.c
	${ROOT}/src/IntrusiveLinkedList.c
	${ROOT}/src/Graph.c
	${ROOT}/src/IntegerSequence.c
	${ROOT}/src/DisjointSet.c
	${ROOT}/src/EdgeListGraph.c
)
ADD_EXECUTABLE(bellman1 ${SOURCES})
