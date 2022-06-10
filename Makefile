cc = gcc

prom = example
deps = $(shell find ./ -name "*.h")
src  = $(shell find ./ -name "*.c")

obj = $(src:%.c=%.o)
LIBS:= -std=c17
CFLAGS:=-g -Wall -O0

$(prom): $(obj)
	$(cc) -o $(prom) $(obj) $(LIBS) $(CFLAGS) $(LIBS)

%.o: %.c $(deps)
	$(cc) $(CFLAGS) -c $< -o $@ $(LIBS)

clean:
	rm -rf $(prom)
	rm -rf *.o
	rm -rf ./src/*.o
