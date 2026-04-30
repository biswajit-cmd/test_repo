################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../startup/startup_mimxrt1024.c 

C_DEPS += \
./startup/startup_mimxrt1024.d 

OBJS += \
./startup/startup_mimxrt1024.o 


# Each subdirectory must supply rules for building sources it contributes
startup/%.o: ../startup/%.c startup/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -D__REDLIB__ -DCPU_MIMXRT1024CAG4B -DCPU_MIMXRT1024CAG4B_cm7 -DSDK_OS_BAREMETAL -DSERIAL_PORT_TYPE_UART=1 -DXIP_EXTERNAL_FLASH=1 -DXIP_BOOT_HEADER_ENABLE=1 -DSDK_DEBUGCONSOLE=1 -DCR_INTEGER_PRINTF -DPRINTF_FLOAT_ENABLE=0 -D__MCUXPRESSO -D__USE_CMSIS -DDEBUG -I"D:\Workspace\New folder\test_repo\board" -I"D:\Workspace\New folder\test_repo\source" -I"D:\Workspace\New folder\test_repo\drivers" -I"D:\Workspace\New folder\test_repo\component\serial_manager" -I"D:\Workspace\New folder\test_repo\device" -I"D:\Workspace\New folder\test_repo\component\uart" -I"D:\Workspace\New folder\test_repo\CMSIS" -I"D:\Workspace\New folder\test_repo\xip" -I"D:\Workspace\New folder\test_repo\utilities" -I"D:\Workspace\New folder\test_repo\component\lists" -O0 -fno-common -g3 -gdwarf-4 -Wall -c -ffunction-sections -fdata-sections -ffreestanding -fno-builtin -fmerge-constants -fmacro-prefix-map="$(<D)/"= -mcpu=cortex-m7 -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -D__REDLIB__ -fstack-usage -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-startup

clean-startup:
	-$(RM) ./startup/startup_mimxrt1024.d ./startup/startup_mimxrt1024.o

.PHONY: clean-startup

