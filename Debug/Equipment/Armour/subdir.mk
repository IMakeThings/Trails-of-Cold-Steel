################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Equipment/Armour/Armour.cpp 

OBJS += \
./Equipment/Armour/Armour.o 

CPP_DEPS += \
./Equipment/Armour/Armour.d 


# Each subdirectory must supply rules for building sources it contributes
Equipment/Armour/%.o: ../Equipment/Armour/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cygwin C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


