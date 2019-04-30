################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Quartz/Attack1.cpp \
../Quartz/Quartz.cpp \
../Quartz/QuartzFactory.cpp 

OBJS += \
./Quartz/Attack1.o \
./Quartz/Quartz.o \
./Quartz/QuartzFactory.o 

CPP_DEPS += \
./Quartz/Attack1.d \
./Quartz/Quartz.d \
./Quartz/QuartzFactory.d 


# Each subdirectory must supply rules for building sources it contributes
Quartz/%.o: ../Quartz/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cygwin C++ Compiler'
	g++ -O3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


