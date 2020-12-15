CPP := g++
CPPFlags := -g -I/usr/include/python3.8
INCLUDES := -lpython3.8

driver.o : DriverComponents/driver.cpp DriverComponents/driver.h
	$(CPP) $(CPPFlags) DriverComponents/driver.cpp $(INCLUDES)
