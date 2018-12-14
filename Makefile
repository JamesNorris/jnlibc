.DEFAULT_GOAL := library

BASE_DIR=$(PWD)
SRC_DIR=$(PWD)/src
TEST_DIR=$(PWD)/test

LIBNAME=jnlibc
TEST_EXE=test.exe
TARFILE=$(LIBNAME).tar.gz

HEADERS=$(wildcard $(SRC_DIR)/*.h)
SOURCES=$(wildcard $(SRC_DIR)/*.c)
OUTPUTS=$(wildcard $(SRC_DIR)/*.o)

TEST_SOURCES=$(wildcard $(TEST_DIR)/*.c)
TEST_OUTPUTS=$(wildcard $(TEST_DIR)/*.o)

archive:
	tar -czvf $(TARFILE) $(SRC_DIR)

library:
	gcc -c $(HEADERS) $(SOURCES)
	gcc -shared -fpic -o $(BASE_DIR)/lib$(LIBNAME).so $(OUTPUTS)

tests:
	gcc -I$(SRC_DIR) $(HEADERS) $(SOURCES) $(TEST_SOURCES) -o $(BASE_DIR)/$(TEST_EXE)

clean:
	rm -rf list_test.exe *.gch $(OUTPUTS) $(TEST_OUTPUTS) lib$(LIBNAME).so $(TARFILE) $(TEST_EXE)