CC = gcc
TARGET = exe
all: main.o password.o add_contact.o search.o delete_contact.o edit_contact.o group_making.o starring.o view.o group_viewing.o print2D.o print2Dgroup.o string_compare.o partial_compare.o merge_contact.o
	$(CC) main.c password.c add_contact.c search.c delete_contact.c edit_contact.c group_making.c starring.c view.c group_viewing.c print2D.c print2Dgroup.c string_compare.c partial_compare.c merge_contact.c -o $(TARGET)

clean :
	rm *o exe
