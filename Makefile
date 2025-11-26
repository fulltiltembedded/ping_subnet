CPP = g++
STD = c++14
CPPFLAGS = -Wall -g3 --std=$(STD) -pthread
CPPFLAGS += -Isrc
INSTALL_DIR = /usr/bin

# IMPORTANT: Each target to be listed here
PING_SUBNET = ping_subnet
TARGETS = \
	$(PING_SUBNET) \

# IMPORTANT: Each target needs to have a similar variable: [target_name]_DEPS
$(PING_SUBNET)_DEPS = $(filter %.o, $(patsubst src/%.cpp, build/%.o, $(wildcard src/*)))

.PHONY: all clean install uninstall

all: $(TARGETS)

# Generate target-specific rules.
define BUILD_TARGET

$(1): build/$(1)

build/$(1): $$($(1)_DEPS)
	@echo "\n------Finishing build for [$(1)]------"
	@mkdir -p $$(dir $$@)
	$(CPP) $$^ -o $$@ $(CPPFLAGS)

build/%.o: $$(addprefix src/, %.cpp %.h)
	@echo "\n------Building $$(notdir $$<) for [$(1)]------"
	@mkdir -p $$(dir $$@)
	$(CPP) -c $$< -o $$@ $(CPPFLAGS)

endef
# WARNING: dont add space after BUILD_TARGET's comma otherwise everything will break!
$(foreach TARGET, $(TARGETS), $(eval $(call BUILD_TARGET,$(TARGET))))

clean:
	rm -rf build

# Install / uninstall.
BINARIES = $(foreach TARGET, $(TARGETS), $(wildcard build/$(TARGET)))
install: $(addprefix install_, $(BINARIES))
uninstall: $(addprefix uninstall_, $(BINARIES))

define INSTALL_BINARY
install_$(1):
	@echo "Installing $(notdir $(1))..."
	@sudo setcap CAP_NET_RAW=eip $(1)
	@sudo ln -f $(1) $(INSTALL_DIR)/$(notdir $(1))

uninstall_$(1):
	@echo "Uninstalling $(1)..."
	@sudo rm -f $(INSTALL_DIR)/$(notdir $(1))
endef
$(foreach BINARY, $(BINARIES), $(eval $(call INSTALL_BINARY,$(BINARY))))
