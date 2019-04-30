################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Equipment/Shoes/Shoes.cpp 

OBJS += \
./Equipment/Shoes/Shoes.o 

CPP_DEPS += \
./Equipment/Shoes/Shoes.d 


# Each subdirectory must supply rules for building sources it contributes
Equipment/Shoes/%.o: ../Equipment/Shoes/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cygwin C++ Compiler'
	g++ -O3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


