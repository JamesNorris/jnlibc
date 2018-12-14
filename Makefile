.DEFAULT_GOAL := library

BASE_DIR=$(PWD)
SRC_DIR=$(PWD)/src
TEST_DIR=$(PWD)/test

LIBNAME=jnlibc
TEST_EXE=test.exe
TARFILE=$(LIBNAME).tar.gz

LIBRARY_FILE=$(BASE_DIR)/lib$(LIBNAME).so

HEADERS=$(wildcard $(SRC_DIR)/*.h)
SOURCES=$(wildcard $(SRC_DIR)/*.c)
OUTPUTS=$(patsubst %.c,%.o,$(SOURCES))

TEST_SOURCES=$(wildcard $(TEST_DIR)/*.c)
TEST_OUTPUTS=$(wildcard $(TEST_DIR)/*.o)

archive:
	tar -czvf $(TARFILE) $(SRC_DIR)

library:
	$(MAKE) library-outputs
	$(MAKE) library-file

library-outputs:
	cd $(SRC_DIR) && \
	gcc -c -fpic $(HEADERS) $(SOURCES)

library-file: $(OUTPUTS)
	gcc -shared -o $(LIBRARY_FILE) $(OUTPUTS)

tests:
	gcc -I$(SRC_DIR) $(HEADERS) $(SOURCES) $(TEST_SOURCES) -o $(BASE_DIR)/$(TEST_EXE)

clean:
	rm -rf *.gch $(OUTPUTS) $(TEST_OUTPUTS) $(LIBRARY_FILE) $(TARFILE) $(TEST_EXE)