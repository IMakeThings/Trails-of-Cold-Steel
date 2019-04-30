################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Entity/Enemy/Enemy.cpp \
../Entity/Enemy/EnemyFactory.cpp \
../Entity/Enemy/FlyingFeline.cpp 

OBJS += \
./Entity/Enemy/Enemy.o \
./Entity/Enemy/EnemyFactory.o \
./Entity/Enemy/FlyingFeline.o 

CPP_DEPS += \
./Entity/Enemy/Enemy.d \
./Entity/Enemy/EnemyFactory.d \
./Entity/Enemy/FlyingFeline.d 


# Each subdirectory must supply rules for building sources it contributes
Entity/Enemy/%.o: ../Entity/Enemy/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cygwin C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


