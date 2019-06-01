cmake_minimum_required(VERSION 2.8) #Проверка версии CMake.

set(PROJECT_NAME 381706-1_Alllabs_Suslov) #Создаем обычную локальную переменную с именем проекта
project(${PROJECT_NAME}) # Название проекта

set(MyExceptionLib MyExceptionLib)#Переменная с именем библиотеки

set(Vector Vector)
set(VectorLib VectorLib)
set(VectorTest VectorTest) 
 
set(Matrix Matrix)
set(MatrixLib MatrixLib)
set(MatrixTest MatrixTest)

set(Stack Stack)
set(StackLib StackLib)
set(StackTest StackTest)

set(Queue Queue)
set(QueueLib QueueLib)
set(QueueTest QueueTest)

set(ArrayList ArrayList)
set(ArrayListLib ArrayListLib)
set(ArrayListTest ArrayListTest)

set(List List)
set(ListLib ListLib)
set(ListTest ListTest)

set(MultiStack MultiStack)
set(MultiStackLib MultiStackLib)
set(MultiStackTest MultiStackTest)

set(Polinomial Polinomial)
set(PolinomialLib PolinomialLib)
set(PolinomialTest PolinomialTest)

set(StackList StackList)
set(StackListLib StackListLib)
set(StackListTest StackListTest)



set(Polish Polish)
set(PolishLib PolishLib)
set(PolishTest PolishTest)



#set(Text Text)
#set(TextLib TextLib)
#set(TextTest TextTest)

set(Plex Plex)
set(PlexLib PlexLib)
set(PlexTest PlexTest)

set(ScanTable ScanTable)
set(ScanTableLib ScanTableLib)
set(ScanTableTest ScanTableTest)

set(SortTable SortTable)
set(SortTableLib SortTableLib)
set(SortTableTest SortTableTest)

set(TreeTable TreeTable)
set(TreeTableLib TreeTableLib)
set(TreeTableTest TreeTableTest)

set(HashTable HashTable)
set(HashTableLib HashTableLib)
set(HashTableTest HashTableTest)

 
set(CMAKE_CONFIGURATION_TYPES "Debug;Release" CACHE STRING "Configs" FORCE) #Создается переменная CMAKE_CONFIGURATION_TYPES со значением "Debug;Release" и меткой/разделом Configs, переменная сохраниется в специальном файле доступном из всех файлов,
if(NOT CMAKE_BUILD_TYPE) # проверка имеющихся у компилятора вариантов сборки
  set(CMAKE_BUILD_TYPE Release) #Если нет то устанавливаем Release
endif()
file(GLOB hdrs "*.h*") #Добавляем в переменную hdrs все файлы с расширением .h
file(GLOB srcs "*.cpp") #Добавляем в переменную srcs все файлы с расширением .cpp

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/gtest)
add_subdirectory(gtest)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/MyExceptionLib)
add_subdirectory(MyExceptionLib)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/VectorLib)
add_subdirectory(Vector)
add_subdirectory(VectorLib)
add_subdirectory(VectorTest)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/MatrixLib)
add_subdirectory(Matrix)
add_subdirectory(MatrixLib)
add_subdirectory(MatrixTest)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/StackLib)
add_subdirectory(Stack)
add_subdirectory(StackLib)
add_subdirectory(StackTest)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/QueueLib)
add_subdirectory(Queue)
add_subdirectory(QueueLib)
add_subdirectory(QueueTest)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/ArrayListLib)
add_subdirectory(ArrayList)
add_subdirectory(ArrayListLib)
add_subdirectory(ArrayListTest)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/ListLib)
add_subdirectory(List)
add_subdirectory(ListLib)
add_subdirectory(ListTest)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/MultiStackLib)
add_subdirectory(MultiStack)
add_subdirectory(MultiStackLib)
add_subdirectory(MultiStackTest)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/PolinomialLib)
add_subdirectory(Polinomial)
add_subdirectory(PolinomialLib)
add_subdirectory(PolinomialTest)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/StackListLib)
add_subdirectory(StackList)
add_subdirectory(StackListLib)
add_subdirectory(StackListTest)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/PolishLib)
add_subdirectory(Polish)
add_subdirectory(PolishLib)
add_subdirectory(PolishTest)



#include_directories(${CMAKE_CURRENT_SOURCE_DIR}/TextLib)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/PlexLib)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/ScanTableLib)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/SortTableLib)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/TreeTableLib)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/HashTableLib)

#add_subdirectory(Text)
#add_subdirectory(TextLib)
#add_subdirectory(TextTest)

add_subdirectory(Plex)
add_subdirectory(PlexLib)
add_subdirectory(PlexTest)

add_subdirectory(ScanTable)
add_subdirectory(ScanTableLib)
add_subdirectory(ScanTableTest)

add_subdirectory(SortTable)
add_subdirectory(SortTableLib)
add_subdirectory(SortTableTest)

add_subdirectory(TreeTable)
add_subdirectory(TreeTableLib)
add_subdirectory(TreeTableTest)

add_subdirectory(HashTable)
add_subdirectory(HashTableLib)
add_subdirectory(HashTableTest)


