# --------------------------------------------------
# Minimal Makefile to compile and run "qN.c" with:
#    make run q1
#    make run q2
#    ...
# --------------------------------------------------

# Variables
CC      = gcc
CFLAGS  = -Wall -Wextra

# Our second word in MAKECMDGOALS (e.g., 'q1') 
Q = $(word 2, $(MAKECMDGOALS))

# Default "all" just prints usage
.PHONY: all
all:
	@echo "Usage:"
	@echo "  make run q1"
	@echo "  make run q2"
	@echo "  etc."

# Pattern rule to build an executable named 'q1' from 'q1.c'
# (works similarly for q2, q3, etc.)
%: %.c
	$(CC) $(CFLAGS) -o $@ $<

# "run" target:
#  - ensures user typed something like 'make run q1'
#  - builds the corresponding target
#  - runs the resulting executable
.PHONY: run
run:
	@if [ -z "$(Q)" ]; then \
		echo "Usage: make run q1"; \
		exit 1; \
	fi
	@echo "Building $(Q)..."
	$(MAKE) $(Q)
	@echo "Running ./$(Q)..."
	./$(Q)

# Dummy rule so Make doesn't try to build 'q1' or 'q2' as separate targets before 'run'.
$(Q):
	@: