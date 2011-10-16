################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Tools/Sound.cpp 

OBJS += \
./src/Tools/Sound.o 

CPP_DEPS += \
./src/Tools/Sound.d 


# Each subdirectory must supply rules for building sources it contributes
src/Tools/%.o: ../src/Tools/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: bada C++ Compiler'
	arm-samsung-nucleuseabi-g++ -D_DEBUG -DSHP -I"C:/DEV/bada/2.0.2/include" -I"C:/DEV/bada/Workspace/KawaiiZombie/inc" -I"C:/DEV/bada/Workspace/KawaiiZombie/inc/Tools" -O0 -g -Wall -c -funsigned-char -fshort-wchar -fpic -march=armv7-a -mthumb -mthumb-interwork -mfpu=vfpv3 -mfloat-abi=hard -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	arm-samsung-nucleuseabi-g++ -D_DEBUG -DSHP -I"C:/DEV/bada/2.0.2/include" -I"C:/DEV/bada/Workspace/KawaiiZombie/inc" -I"C:/DEV/bada/Workspace/KawaiiZombie/inc/Tools" -O0 -g -Wall -E -funsigned-char -fshort-wchar -fpic -march=armv7-a -mthumb -mthumb-interwork -mfpu=vfpv3 -mfloat-abi=hard -o"C:/DEV/bada/Workspace/repository/KawaiiZombie/Target-Debug/$(notdir $(basename $@).i)" "$<"
	@echo 'Finished building: $<'
	@echo ' '


