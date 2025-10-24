TARGET = script

BUILDROOT_DIR := ..
COMPILER := $(BUILDROOT_DIR)/output/host/bin/i686-buildroot-linux-gnu-gcc

INSTALL_DIR := $(BUILDROOT_DIR)/output/target/usr/bin

all:
	$(COMPILER) -o $(TARGET) $(TARGET).c
	cp $(TARGET) $(INSTALL_DIR)

clean:
	rm -f $(TARGET)