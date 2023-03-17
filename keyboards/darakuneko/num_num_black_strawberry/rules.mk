# MCU name
MCU = atmega32u4

# Bootloader selection
BOOTLOADER = caterina


LTO_ENABLE = yes
POINTING_DEVICE_ENABLE = yes
POINTING_DEVICE_DRIVER = custom
SEND_STRING_ENABLE = yes
# CONSOLE_ENABLE = yes

SRC += iqs5xx.c i2c_master.c qmk_rc.c
