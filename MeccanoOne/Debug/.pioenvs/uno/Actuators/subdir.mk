################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
O_SRCS += \
../.pioenvs/uno/Actuators/ServoMechanism.o \
../.pioenvs/uno/Actuators/ServoMotor.o 

CPP_SRCS += \
../.pioenvs/uno/Actuators/ServoMechanism.cpp \
../.pioenvs/uno/Actuators/ServoMotor.cpp 

OBJS += \
./.pioenvs/uno/Actuators/ServoMechanism.o \
./.pioenvs/uno/Actuators/ServoMotor.o 

CPP_DEPS += \
./.pioenvs/uno/Actuators/ServoMechanism.d \
./.pioenvs/uno/Actuators/ServoMotor.d 


# Each subdirectory must supply rules for building sources it contributes
.pioenvs/uno/Actuators/%.o: ../.pioenvs/uno/Actuators/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


