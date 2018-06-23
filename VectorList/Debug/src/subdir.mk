################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Constitution.cpp \
../src/TimedContainer.cpp \
../src/Word.cpp \
../src/WordMap.cpp \
../src/WordVector.cpp 

OBJS += \
./src/Constitution.o \
./src/TimedContainer.o \
./src/Word.o \
./src/WordMap.o \
./src/WordVector.o 

CPP_DEPS += \
./src/Constitution.d \
./src/TimedContainer.d \
./src/Word.d \
./src/WordMap.d \
./src/WordVector.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


