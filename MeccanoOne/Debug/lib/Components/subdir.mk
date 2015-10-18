################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../lib/Components/UltrasonicServoHead.cpp 

OBJS += \
./lib/Components/UltrasonicServoHead.o 

CPP_DEPS += \
./lib/Components/UltrasonicServoHead.d 


# Each subdirectory must supply rules for building sources it contributes
lib/Components/%.o: ../lib/Components/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


