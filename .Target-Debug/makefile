################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

REPOSITORY_ROOT := C:/DEV/bada/Workspace/repository/KawaiiZombie/Target-Debug

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir.mk
-include src/subdir.mk
-include src/Tools/subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: KawaiiZombie.exe

# Tool invocations
KawaiiZombie.exe: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: bada C++ Linker'
	@echo 'ldflags: -L"C:/DEV/bada/2.0.2/Model/WaveWVGA/Target" -L"C:/DEV/bada/Workspace/KawaiiZombie/lib" -shared -march=armv7-a -mthumb -mthumb-interwork -mfpu=vfpv3 -mfloat-abi=hard -o"KawaiiZombie.exe" ./src/BaseController.o ./src/Dart.o ./src/FormCredits.o ./src/FormHelp.o ./src/FormHome.o ./src/FormScore.o ./src/GameTimer.o ./src/GameView.o ./src/KImage.o ./src/KawaiiZombie.o ./src/KawaiiZombieEntry.o ./src/Nurse.o ./src/World.o ./src/Zombie.o ./src/Tools/Sound.o '
	arm-samsung-nucleuseabi-g++ @ldflags @ldobjs  $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(OBJS)$(C++_DEPS)$(C_DEPS)$(CC_DEPS)$(CPP_DEPS)$(CXX_DEPS)$(C_UPPER_DEPS) KawaiiZombie.exe $(REPOSITORY_ROOT)/temp/*  $(REPOSITORY_ROOT)/*
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
