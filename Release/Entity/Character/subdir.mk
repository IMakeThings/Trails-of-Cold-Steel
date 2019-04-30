################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Entity/Character/Character.cpp \
../Entity/Character/CharacterFactory.cpp \
../Entity/Character/Greatsword.cpp \
../Entity/Character/Tachi.cpp 

OBJS += \
./Entity/Character/Character.o \
./Entity/Character/CharacterFactory.o \
./Entity/Character/Greatsword.o \
./Entity/Character/Tachi.o 

CPP_DEPS += \
./Entity/Character/Character.d \
./Entity/Character/CharacterFactory.d \
./Entity/Character/Greatsword.d \
./Entity/Character/Tachi.d 


# Each subdirectory must supply rules for building sources it contributes
Entity/Character/%.o: ../Entity/Character/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cygwin C++ Compiler'
	g++ -O3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


