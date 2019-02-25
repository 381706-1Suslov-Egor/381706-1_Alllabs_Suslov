file(GLOB hdrs "*.h*") 
file(GLOB srcs "*.cpp")

add_executable(${Polynom} ${srcs} ${hdrs}) 
target_link_libraries(${Polynom} ${PolynomLib}) 


