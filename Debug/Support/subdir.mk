################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Support/AoE.cpp \
../Support/convertPositions.cpp \
../Support/enterPause.cpp \
../Support/inputPositions.cpp \
../Support/inputSelectEnemy.cpp 

OBJS += \
./Support/AoE.o \
./Support/convertPositions.o \
./Support/enterPause.o \
./Support/inputPositions.o \
./Support/inputSelectEnemy.o 

CPP_DEPS += \
./Support/AoE.d \
./Support/convertPositions.d \
./Support/enterPause.d \
./Support/inputPositions.d \
./Support/inputSelectEnemy.d 


# Each subdirectory must supply rules for building sources it contributes
Support/%.o: ../Support/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cygwin C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


