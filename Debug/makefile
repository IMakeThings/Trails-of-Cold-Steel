################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Support/subdir.mk
-include Quartz/subdir.mk
-include MasterQuartz/Force/subdir.mk
-include MasterQuartz/subdir.mk
-include Map/subdir.mk
-include Game/subdir.mk
-include Equipment/Weapon/subdir.mk
-include Equipment/Shoes/subdir.mk
-include Equipment/Armour/subdir.mk
-include Equipment/subdir.mk
-include Entity/Enemy/subdir.mk
-include Entity/Character/subdir.mk
-include Entity/subdir.mk
-include Dice/subdir.mk
-include Crafts/subdir.mk
-include Console/subdir.mk
-include Arts/subdir.mk
-include AI/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: TrailsofColdSteel.exe

# Tool invocations
TrailsofColdSteel.exe: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: Cygwin C++ Linker'
	g++  -o "TrailsofColdSteel.exe" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(CC_DEPS)$(C++_DEPS)$(EXECUTABLES)$(OBJS)$(C_UPPER_DEPS)$(CXX_DEPS)$(CPP_DEPS)$(C_DEPS) TrailsofColdSteel.exe
	-@echo ' '

.PHONY: all clean dependents

-include ../makefile.targets
