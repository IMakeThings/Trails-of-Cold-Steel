################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../MasterQuartz/Force/ForceLvl1.cpp 

OBJS += \
./MasterQuartz/Force/ForceLvl1.o 

CPP_DEPS += \
./MasterQuartz/Force/ForceLvl1.d 


# Each subdirectory must supply rules for building sources it contributes
MasterQuartz/Force/%.o: ../MasterQuartz/Force/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cygwin C++ Compiler'
	g++ -O3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


