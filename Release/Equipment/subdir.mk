################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Equipment/Equipment.cpp \
../Equipment/EquipmentFactory.cpp 

OBJS += \
./Equipment/Equipment.o \
./Equipment/EquipmentFactory.o 

CPP_DEPS += \
./Equipment/Equipment.d \
./Equipment/EquipmentFactory.d 


# Each subdirectory must supply rules for building sources it contributes
Equipment/%.o: ../Equipment/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cygwin C++ Compiler'
	g++ -O3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


