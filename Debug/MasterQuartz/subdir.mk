################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../MasterQuartz/MasterQuartz.cpp \
../MasterQuartz/MasterQuartzFactory.cpp 

OBJS += \
./MasterQuartz/MasterQuartz.o \
./MasterQuartz/MasterQuartzFactory.o 

CPP_DEPS += \
./MasterQuartz/MasterQuartz.d \
./MasterQuartz/MasterQuartzFactory.d 


# Each subdirectory must supply rules for building sources it contributes
MasterQuartz/%.o: ../MasterQuartz/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cygwin C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


