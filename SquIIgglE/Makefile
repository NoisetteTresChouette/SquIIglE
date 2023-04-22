CC=gcc
CFLAGS= -Wall -Wextra

OBJ= ./Source/hub.o ./Source/draw.o ./Source/color.o ./Source/bucket.o ./Source/pixel.o ./Source/layer.o ./Source/canvas.o ./Source/cursor.o

all: SquIIgglE.exe

./Source/hub.o: ./Source/hub.c ./Source/draw.h ./Source/cursor.h ./Source/canvas.h
	$(CC) $(CFLAGS) -c -o $@ $<

./Source/draw.o: ./Source/draw.c ./Source/draw.h ./Source/layer.h
	$(CC) $(CFLAGS) -c -o $@ $<

./Source/color.o: ./Source/color.c ./Source/color.h
	$(CC) $(CFLAGS) -c -o $@ $<

./Source/bucket.o: ./Source/bucket.c ./Source/bucket.h ./Source/color.h
	$(CC) $(CFLAGS) -c -o $@ $<

./Source/pixel.o: ./Source/pixel.c ./Source/pixel.h ./Source/bucket.h
	$(CC) $(CFLAGS) -c -o $@ $<

./Source/layer.o: ./Source/layer.c ./Source/layer.h ./Source/pixel.h
	$(CC) $(CFLAGS) -c -o $@ $<

./Source/canvas.o: ./Source/canvas.c ./Source/canvas.h ./Source/layer.h
	$(CC) $(CFLAGS) -c -o $@ $<

./Source/cursor.o: ./Source/cursor.c ./Source/cursor.h
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f ./*.o

SquIIgglE.exe: $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^