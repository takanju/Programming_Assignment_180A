################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../\ Factorial.cpp 

OBJS += \
./\ Factorial.o 

CPP_DEPS += \
./\ Factorial.d 


# Each subdirectory must supply rules for building sources it contributes
\ Factorial.o: ../\ Factorial.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF" Factorial.d" -MT"\ Factorial.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


