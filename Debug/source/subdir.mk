################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../source/MIMXRT1024_Project_spi.c \
../source/ioexpander.c \
../source/semihost_hardfault.c 

C_DEPS += \
./source/MIMXRT1024_Project_spi.d \
./source/ioexpander.d \
./source/semihost_hardfault.d 

OBJS += \
./source/MIMXRT1024_Project_spi.o \
./source/ioexpander.o \
./source/semihost_hardfault.o 


# Each subdirectory must supply rules for building sources it contributes
source/%.o: ../source/%.c source/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -D__REDLIB__ -DCPU_MIMXRT1024CAG4B -DCPU_MIMXRT1024CAG4B_cm7 -DSDK_OS_BAREMETAL -DSERIAL_PORT_TYPE_UART=1 -DXIP_EXTERNAL_FLASH=1 -DXIP_BOOT_HEADER_ENABLE=1 -DSDK_DEBUGCONSOLE=1 -DCR_INTEGER_PRINTF -DPRINTF_FLOAT_ENABLE=0 -D__MCUXPRESSO -D__USE_CMSIS -DDEBUG -I"D:\Workspace\spi github\spi\board" -I"D:\Workspace\spi github\spi\source" -I"D:\Workspace\spi github\spi\drivers" -I"D:\Workspace\spi github\spi\component\serial_manager" -I"D:\Workspace\spi github\spi\device" -I"D:\Workspace\spi github\spi\component\uart" -I"D:\Workspace\spi github\spi\CMSIS" -I"D:\Workspace\spi github\spi\xip" -I"D:\Workspace\spi github\spi\utilities" -I"D:\Workspace\spi github\spi\component\lists" -O0 -fno-common -g3 -gdwarf-4 -Wall -c -ffunction-sections -fdata-sections -ffreestanding -fno-builtin -fmerge-constants -fmacro-prefix-map="$(<D)/"= -mcpu=cortex-m7 -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -D__REDLIB__ -fstack-usage -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-source

clean-source:
	-$(RM) ./source/MIMXRT1024_Project_spi.d ./source/MIMXRT1024_Project_spi.o ./source/ioexpander.d ./source/ioexpander.o ./source/semihost_hardfault.d ./source/semihost_hardfault.o

.PHONY: clean-source

