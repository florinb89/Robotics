################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Joints.cpp \
../L298MotorShield.cpp \
../Motor.cpp \
../Sensor.cpp \
../ServoMessageParser.cpp \
../StringUtils.cpp 

OBJS += \
./Joints.o \
./L298MotorShield.o \
./Motor.o \
./Sensor.o \
./ServoMessageParser.o \
./StringUtils.o 

CPP_DEPS += \
./Joints.d \
./L298MotorShield.d \
./Motor.d \
./Sensor.d \
./ServoMessageParser.d \
./StringUtils.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


