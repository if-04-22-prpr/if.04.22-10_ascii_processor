CC              = gcc
CCLINK          = g++
LIBS            =
CCOPTIONS       = -Wall -pedantic -std=gnu11 -g
LDOPTIONS       =

BUILD_DIR       = build

TEST    = ascii_processor_test_app
PROGRAM = ascii_processor_app

COMMON_HDRS      = general.h 
LIBRARY_FILES    = shortcut
ASSIGNMENT_HDRS  = 
ASSIGNMENT_FILES = ascii_processor
TEST_FILES       = test_ascii_processor
MAIN_DRIVER      = ascii_processor_app
TEST_DRIVER      = ascii_processor_test_driver

LIBRARY_H        = $(addsuffix .h, $(LIBRARY_FILES))
ASSIGNMENT_H     = $(addsuffix .h, $(ASSIGNMENT_FILES)) $(ASSIGNMENT_HDRS)
ASSIGNMENT_C     = $(addsuffix .c, $(ASSIGNMENT_FILES)) $(MAIN_DRIVER).c

HDRS			 = $(ASSIGNEMT_H) $(SHARED_HDRS) $(COMMON_HDRS) $(LIBRARY_H)
TESTOBJECT       = $(addprefix $(BUILD_DIR)/, $(TEST_DRIVER).o)
MAINOBJECT       = $(addprefix $(BUILD_DIR)/, $(MAIN_DRIVER).o)
LIBRARY_OBJS     = $(addprefix $(BUILD_DIR)/, $(addsuffix .o, $(LIBRARY_FILES)))
TEST_OBJS        = $(addprefix $(BUILD_DIR)/, $(addsuffix .o, $(TEST_FILES)))
MAIN_OBJ         = $(addprefix $(BUILD_DIR)/, $(addsuffix .o, $(ASSIGNMENT_FILES)))
OBJS             = $(LIBRARY_OBJS) $(MAIN_OBJ) $(TEST_OBJS)

DOXY             = doxygen

all: $(PROGRAM)
	./$(PROGRAM)

$(TEST): $(BUILD_DIR) $(OBJS) $(TESTOBJECT)
	$(CCLINK) -o $@ $(LDOPTIONS) $(OBJS) $(TESTOBJECT)

$(PROGRAM): $(BUILD_DIR) $(OBJS) $(MAINOBJECT)
	$(CCLINK) -o $@ $(LDOPTIONS) $(OBJS) $(MAINOBJECT)

.PHONY: clean cleanall doxy test setsample setassignment definesample defineassignment assignmentfolder

clean:
	rm -f $(PROGRAM) $(TEST) $(TESTOBJECT) $(MAINOBJECT) $(OBJS)
	rm -rf $(BUILD_DIR)
	rm -f ./ascii_art/*.rle
	rm -f *.o

cleanall: clean
	rm -f index.html
	rm -rf html


doxy:
	$(DOXY)
	rm -f index.html
	ln -s html/index.html index.html

test: $(TEST)
	./$(TEST)

cleantest: clean
	clear
	make test

$(BUILD_DIR): 
	mkdir -p $(BUILD_DIR)

$(BUILD_DIR)/%.o: %.c
	$(CC) $(CCOPTIONS) -c -o $@ $<

#sets project as sample solution
setsample:
	$(foreach name, $(ASSIGNMENT_H) $(ASSIGNMENT_C), cp $(name).sample $(name);)

#sets project as assignment
setassignment:
	$(foreach name, $(ASSIGNMENT_H) $(ASSIGNMENT_C), cp $(name).assignment $(name);)

# defines current state of project as sample solution
definesample:
	$(foreach name, $(ASSIGNMENT_H) $(ASSIGNMENT_C), cp $(name) $(name).sample;)

# defines current sate of project as assignment
defineassignment :
	$(foreach name, $(ASSIGNMENT_H) $(ASSIGNMENT_C), cp $(name) $(name).assignment;)

# creates a folder which can serve as a publishable assignment
assignmentfolder:
	make setassignment
	make doxy
	rm -rf ../assignment
	mkdir ../assignment
	cp -R * ../assignment
	cp .gitignore ../assignment
	rm ../assignment/*.sample
	rm ../assignment/*.assignment
	make cleanall
