################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Crafts/AutumnLeafCutter.cpp \
../Crafts/BasicAttack.cpp \
../Crafts/CraftFactory.cpp \
../Crafts/Crafts.cpp \
../Crafts/DoubleKittyKick.cpp \
../Crafts/Motivate.cpp 

OBJS += \
./Crafts/AutumnLeafCutter.o \
./Crafts/BasicAttack.o \
./Crafts/CraftFactory.o \
./Crafts/Crafts.o \
./Crafts/DoubleKittyKick.o \
./Crafts/Motivate.o 

CPP_DEPS += \
./Crafts/AutumnLeafCutter.d \
./Crafts/BasicAttack.d \
./Crafts/CraftFactory.d \
./Crafts/Crafts.d \
./Crafts/DoubleKittyKick.d \
./Crafts/Motivate.d 


# Each subdirectory must supply rules for building sources it contributes
Crafts/%.o: ../Crafts/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cygwin C++ Compiler'
	g++ -O3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


