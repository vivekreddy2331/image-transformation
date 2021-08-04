LIBDIR := libs
LIBDIRD := libd
OBJDIR := obj
OBJSD  := objs
EXEDIR := bin

EXE1    := $(EXEDIR)/calc
EXE2    := $(EXEDIR)/calc
LIBS   := $(addprefix $(LIBDIR)/,libiarith.a)
LIBD   := $(addprefix $(LIBDIRD)/,libiarith.so)
OBJS   := $(addprefix $(OBJSD)/,$(patsubst src/%.c,%.o,$(wildcard src/*.c)))
OBJD   := $(addprefix $(LIBDIRD)/,$(patsubst src/%.c,%.o,$(wildcard src/*.c)))

vpath %.c src
vpath %.h include

all: $(EXE1) $(EXE2)
	@echo "Finished Successfully"

$(EXE1): obj/main.o $(LIBS)  | $(EXEDIR)
	gcc -o $@ -I include $< -L libs -liarith

$(EXE2): objs/main.o $(LIBD) | $(EXEDIR)
	gcc -fPIC -o $@ -I include $< -L libd -liarith

$(OBJDIR)/%.o: %.c filter.h | $(OBJDIR)
	gcc -o $@ -c -I include $<

$(OBJSD)/%.o: %.c filter.h | $(OBJSD)
	gcc -fPIC -o $@ -c -I include $<

$(LIBDIR)/libiarith.a: obj/gray.o obj/multiply.o obj/r_w.o obj/blur.o| $(LIBDIR)
	ar rcs $@ $^

$(LIBDIRD)/libiarith.so: objs/gray.o objs/multiply.o objs/r_w.o objs/blur.o | $(LIBDIRD)
	ar rcs $@ $^

liba: $(LIBS)

libso: $(LIBD)

$(OBJDIR):
	mkdir -p $(OBJDIR)

$(OBJSD):
	mkdir -p $(OBJSD)

$(LIBDIR):
	mkdir -p $(LIBDIR)

$(EXEDIR):
	mkdir -p $(EXEDIR)

$(LIBDIRD):
	mkdir -p $(LIBDIRD)

run:
	./bin/calc
test1:
	./bin/calc < ./test1.txt
test2:
	./bin/calc < ./test2.txt
test3:
	./bin/calc < ./test3.txt
T1:
	./bin/calc < ./T1.txt

T2:
	./bin/calc < ./T2.txt

tests: test1 test2 test3

objdump:
	objdump -d $(EXE2) > dynamic.txt

objdump1:
	objdump -d $(EXE1) > static.txt

.PHONY: clean
clean:
	rm -rf $(EXEDIR) $(OBJDIR) $(LIBDIR) $(OBJSD) $(LIBDIRD)

