################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Arts/ArtFactory.cpp \
../Arts/Arts.cpp \
../Arts/FireBolt.cpp 

OBJS += \
./Arts/ArtFactory.o \
./Arts/Arts.o \
./Arts/FireBolt.o 

CPP_DEPS += \
./Arts/ArtFactory.d \
./Arts/Arts.d \
./Arts/FireBolt.d 


# Each subdirectory must supply rules for building sources it contributes
Arts/%.o: ../Arts/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cygwin C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


