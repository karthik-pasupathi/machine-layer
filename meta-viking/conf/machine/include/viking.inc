DISTROOVERRIDES .= ":viking"

MACHINE_FEATURES += "\
        obmc-bmc-state-mgmt \
        obmc-phosphor-fan-mgmt \
        obmc-phosphor-flash-mgmt \
        "

VIRTUAL-RUNTIME_skeleton_workbook = "${MACHINE}-config"

PREFERRED_PROVIDER_virtual/obmc-chassis-mgmt = "packagegroup-vk-apps"
PREFERRED_PROVIDER_virtual/obmc-fan-mgmt = "packagegroup-vk-apps"
PREFERRED_PROVIDER_virtual/obmc-flash-mgmt = "packagegroup-vk-apps"
PREFERRED_PROVIDER_virtual/obmc-inventory-data ?= "${VIRTUAL-RUNTIME_skeleton_workbook}"
PREFERRED_PROVIDER_virtual/obmc-system-mgmt = "packagegroup-vk-apps"

IMAGE_FEATURES:remove = "obmc-ikvm"
IMAGE_FEATURES:append = " allow-root-login"

# Most of our hardware uses the default ttyS4 but at 57600.
SERIAL_CONSOLES:viking = "57600;ttyS4"
