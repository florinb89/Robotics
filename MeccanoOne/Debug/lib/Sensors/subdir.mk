################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../lib/Sensors/HCSR04Ultrasonic.cpp 

OBJS += \
./lib/Sensors/HCSR04Ultrasonic.o 

CPP_DEPS += \
./lib/Sensors/HCSR04Ultrasonic.d 


# Each subdirectory must supply rules for building sources it contributes
lib/Sensors/%.o: ../lib/Sensors/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


