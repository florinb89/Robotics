################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../lib/Communication/PortCommunication.cpp \
../lib/Communication/PortMessage.cpp 

OBJS += \
./lib/Communication/PortCommunication.o \
./lib/Communication/PortMessage.o 

CPP_DEPS += \
./lib/Communication/PortCommunication.d \
./lib/Communication/PortMessage.d 


# Each subdirectory must supply rules for building sources it contributes
lib/Communication/%.o: ../lib/Communication/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


