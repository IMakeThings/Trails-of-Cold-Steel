################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../AI/PlayerAI.cpp \
../AI/PlayerAISwarm.cpp \
../AI/sigmoid.cpp 

OBJS += \
./AI/PlayerAI.o \
./AI/PlayerAISwarm.o \
./AI/sigmoid.o 

CPP_DEPS += \
./AI/PlayerAI.d \
./AI/PlayerAISwarm.d \
./AI/sigmoid.d 


# Each subdirectory must supply rules for building sources it contributes
AI/%.o: ../AI/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cygwin C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


