################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Node.cpp \
../SortedList.cpp \
../SortedVector.cpp \
../TestDriver.cpp \
../TestSuite.cpp \
../Timer.cpp 

OBJS += \
./Node.o \
./SortedList.o \
./SortedVector.o \
./TestDriver.o \
./TestSuite.o \
./Timer.o 

CPP_DEPS += \
./Node.d \
./SortedList.d \
./SortedVector.d \
./TestDriver.d \
./TestSuite.d \
./Timer.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


