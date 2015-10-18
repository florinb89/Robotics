################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../arduino/CDC.cpp \
../arduino/HID.cpp \
../arduino/HardwareSerial.cpp \
../arduino/HardwareSerial0.cpp \
../arduino/HardwareSerial1.cpp \
../arduino/HardwareSerial2.cpp \
../arduino/HardwareSerial3.cpp \
../arduino/IPAddress.cpp \
../arduino/Print.cpp \
../arduino/Stream.cpp \
../arduino/Tone.cpp \
../arduino/USBCore.cpp \
../arduino/WMath.cpp \
../arduino/WString.cpp \
../arduino/abi.cpp \
../arduino/main.cpp \
../arduino/new.cpp 

C_SRCS += \
../arduino/WInterrupts.c \
../arduino/hooks.c \
../arduino/wiring.c \
../arduino/wiring_analog.c \
../arduino/wiring_digital.c \
../arduino/wiring_pulse.c \
../arduino/wiring_shift.c 

OBJS += \
./arduino/CDC.o \
./arduino/HID.o \
./arduino/HardwareSerial.o \
./arduino/HardwareSerial0.o \
./arduino/HardwareSerial1.o \
./arduino/HardwareSerial2.o \
./arduino/HardwareSerial3.o \
./arduino/IPAddress.o \
./arduino/Print.o \
./arduino/Stream.o \
./arduino/Tone.o \
./arduino/USBCore.o \
./arduino/WInterrupts.o \
./arduino/WMath.o \
./arduino/WString.o \
./arduino/abi.o \
./arduino/hooks.o \
./arduino/main.o \
./arduino/new.o \
./arduino/wiring.o \
./arduino/wiring_analog.o \
./arduino/wiring_digital.o \
./arduino/wiring_pulse.o \
./arduino/wiring_shift.o 

C_DEPS += \
./arduino/WInterrupts.d \
./arduino/hooks.d \
./arduino/wiring.d \
./arduino/wiring_analog.d \
./arduino/wiring_digital.d \
./arduino/wiring_pulse.d \
./arduino/wiring_shift.d 

CPP_DEPS += \
./arduino/CDC.d \
./arduino/HID.d \
./arduino/HardwareSerial.d \
./arduino/HardwareSerial0.d \
./arduino/HardwareSerial1.d \
./arduino/HardwareSerial2.d \
./arduino/HardwareSerial3.d \
./arduino/IPAddress.d \
./arduino/Print.d \
./arduino/Stream.d \
./arduino/Tone.d \
./arduino/USBCore.d \
./arduino/WMath.d \
./arduino/WString.d \
./arduino/abi.d \
./arduino/main.d \
./arduino/new.d 


# Each subdirectory must supply rules for building sources it contributes
arduino/%.o: ../arduino/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

arduino/%.o: ../arduino/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


