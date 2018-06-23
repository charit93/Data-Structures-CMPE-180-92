################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/AvlTree.cpp \
../src/BSTApp.cpp \
../src/BinaryNode.cpp \
../src/BinarySearchTree.cpp 

OBJS += \
./src/AvlTree.o \
./src/BSTApp.o \
./src/BinaryNode.o \
./src/BinarySearchTree.o 

CPP_DEPS += \
./src/AvlTree.d \
./src/BSTApp.d \
./src/BinaryNode.d \
./src/BinarySearchTree.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -std=c++0x -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


