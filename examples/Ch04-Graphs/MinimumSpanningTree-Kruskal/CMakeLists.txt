CMAKE_MINIMUM_REQUIRED(VERSION 2.8)
PROJECT(Kruskal)
SET(ROOT ../../..)
INCLUDE_DIRECTORIES(${ROOT}/include)
SET(SOURCES
	main.c
	${ROOT}/src/EdgeListGraph.c
	${ROOT}/src/IntegerSequence.c
	${ROOT}/src/DisjointSet.c
	${ROOT}/src/GraphReader.c
	${ROOT}/src/exception.c
)
ADD_EXECUTABLE(kruskal ${SOURCES})
