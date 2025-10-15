TARGET1 = deadline
TARGET2 = setpriority

BUILDROOT_DIR := ..
COMPILER := $(BUILDROOT_DIR)/output/host/bin/i686-buildroot-linux-gnu-gcc

INSTALL_DIR := $(BUILDROOT_DIR)/output/target/usr/bin

all:
	$(COMPILER) -o $(TARGET1) $(TARGET1).c
	cp $(TARGET1) $(INSTALL_DIR)

	$(COMPILER) -o $(TARGET2) $(TARGET2).c
	cp $(TARGET2) $(INSTALL_DIR)

clean:
	rm -f $(TARGET1)
	rm -f $(TARGET2)