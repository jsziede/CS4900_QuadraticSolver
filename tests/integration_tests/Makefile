SRC_DIR = ../../src

.PHONY: default all clean test_int_all quad_solver

default: test_int_all
all: default

# This will always run make in src
quad_solver:
	make -C $(SRC_DIR)

test_int_all: quad_solver
	./test_ranges.sh $(SRC_DIR)
	./test_examples.sh $(SRC_DIR)

# Clean does nothing for now
clean:
	rm -f *.tmp
