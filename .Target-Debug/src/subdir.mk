################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Dart.cpp \
../src/GameTimer.cpp \
../src/GameView.cpp \
../src/KImage.cpp \
../src/KawaiiZombie.cpp \
../src/KawaiiZombieEntry.cpp \
../src/Nurse.cpp \
../src/World.cpp \
../src/Zombie.cpp 

OBJS += \
./src/Dart.o \
./src/GameTimer.o \
./src/GameView.o \
./src/KImage.o \
./src/KawaiiZombie.o \
./src/KawaiiZombieEntry.o \
./src/Nurse.o \
./src/World.o \
./src/Zombie.o 

CPP_DEPS += \
./src/Dart.d \
./src/GameTimer.d \
./src/GameView.d \
./src/KImage.d \
./src/KawaiiZombie.d \
./src/KawaiiZombieEntry.d \
./src/Nurse.d \
./src/World.d \
./src/Zombie.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: bada C++ Compiler'
	arm-samsung-nucleuseabi-g++ -D_DEBUG -DSHP -I"C:/bada/2.0.2/include" -I"C:/Users/Fradow/Desktop/Git/KawaiiZombie/inc" -O0 -g -Wall -c -funsigned-char -fshort-wchar -fpic -march=armv7-a -mthumb -mthumb-interwork -mfpu=vfpv3 -mfloat-abi=hard -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	arm-samsung-nucleuseabi-g++ -D_DEBUG -DSHP -I"C:/bada/2.0.2/include" -I"C:/Users/Fradow/Desktop/Git/KawaiiZombie/inc" -O0 -g -Wall -E -funsigned-char -fshort-wchar -fpic -march=armv7-a -mthumb -mthumb-interwork -mfpu=vfpv3 -mfloat-abi=hard -o"C:/Users/Fradow/Desktop/Git/repository/KawaiiZombie/Target-Debug/$(notdir $(basename $@).i)" "$<"
	@echo 'Finished building: $<'
	@echo ' '


