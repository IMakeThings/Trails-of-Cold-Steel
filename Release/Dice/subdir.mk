################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Dice/Dice.cpp 

OBJS += \
./Dice/Dice.o 

CPP_DEPS += \
./Dice/Dice.d 


# Each subdirectory must supply rules for building sources it contributes
Dice/%.o: ../Dice/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cygwin C++ Compiler'
	g++ -O3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


