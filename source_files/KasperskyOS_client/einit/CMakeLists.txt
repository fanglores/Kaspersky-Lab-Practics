project (einit)

# Tools for using NK parser.
# Инструментарий для работы с парсером NK.
include (platform/image)

# Set compile flags.
# установка флагов компиляции.
project_header_default ("STRICT_WARNINGS:NO")

set (ENTITIES Client)

set (SECURITY_PSL_FILE "src/security_arm.psl")

build_kos_qemu_image (kos-qemu-image
                      EINIT_ENTITY EinitQemu
                      CONNECTIONS_CFG "src/init.yaml.in"
                      SECURITY_PSL ${SECURITY_PSL_FILE}
                      IMAGE_FILES ${ENTITIES})

# KasperskyOS image for target hardware platform
# Образ KasperskyOS для аппаратной платформы.
# NOTE: Не все платформы имеют HW реализацию gpio.
build_kos_hw_image (kos-image
                    EINIT_ENTITY EinitHw
                    CONNECTIONS_CFG "src/init.yaml.in"
                    SECURITY_PSL ${SECURITY_PSL_FILE}
                    IMAGE_FILES ${ENTITIES})
