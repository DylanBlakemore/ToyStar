################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/ToyStar.cpp \
../src/csv.cpp \
../src/particle.cpp \
../src/solver.cpp 

OBJS += \
./src/ToyStar.o \
./src/csv.o \
./src/particle.o \
./src/solver.o 

CPP_DEPS += \
./src/ToyStar.d \
./src/csv.d \
./src/particle.d \
./src/solver.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


